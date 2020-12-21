/*
   Copyright (c) 2020 The Linux Foundation. All rights reserved.
   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are
   met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above
      copyright notice, this list of conditions and the following
      disclaimer in the documentation and/or other materials provided
      with the distribution.
    * Neither the name of The Linux Foundation nor the names of its
      contributors may be used to endorse or promote products derived
      from this software without specific prior written permission.
   THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
   WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
   ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
   BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
   BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
   WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
   OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
   IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#include "vendor_init.h"
#include "property_service.h"
#include "log.h"
#include "util.h"

#define _REALLY_INCLUDE_SYS__SYSTEM_PROPERTIES_H_
#include <sys/_system_properties.h>

#define TARGET_PLATFORM "mt8163"
#define BOOT_MODE_PATH "/sys/devices/virtual/BOOT/BOOT/boot/boot_mode"
#define CHUNK 1024

static void init_boot_mode_properties()
{
    /*
     * Set the ro.bootmode property based on the MediaTek's
     * BOOT_MODE kernel driver using the following structure:
     *
     *  - NORMAL_BOOT -> 0
     *  - META_BOOT -> 1
     *  - RECOVERY_BOOT -> 2
     *  - SW_REBOOT -> 3
     *  - FACTORY_BOOT -> 4
     *  - ADVMETA_BOOT -> 5
     *  - ATE_FACTORY_BOOT -> 6
     *  - KERNEL_POWER_OFF_CHARGING_BOOT -> 8
     *  - LOW_POWER_OFF_CHARGING_BOOT -> 9
     *  - UNKNOWN_BOOT_MODE -> -1/unknown
     */

    char boot_mode[CHUNK] = "unknown";
    FILE *sysfs_boot_mode;

    sysfs_boot_mode = fopen(BOOT_MODE_PATH, "r");

    if (sysfs_boot_mode != NULL)
    {
        INFO("Reading boot_mode status...\n");

        fscanf(sysfs_boot_mode, "%[^\n]", boot_mode);
        fclose(sysfs_boot_mode);

        INFO("Current boot_mode is %s\n", boot_mode);
    }

    if (strcmp(boot_mode, "unknown") == 0)
    {
        INFO("Couldn't read current boot_mode, guessing UNKNOWN_BOOT_MODE...\n");
        property_set("ro.bootmode", "unknown");
        return; // We're done here, bail out...
    }

    INFO("Setting ro.bootmode to %s...\n", boot_mode);
    property_set("ro.bootmode", boot_mode);
}
    
void property_override(char const prop[], char const value[])
{
    prop_info *pi;

    pi = (prop_info*) __system_property_find(prop);
    if (pi)
        __system_property_update(pi, value, strlen(value));
    else
        __system_property_add(prop, strlen(prop), value, strlen(value));
}

void vendor_load_properties()
{
    std::string platform;
    platform = property_get("ro.board.platform");

    if (strcmp(platform.c_str(), TARGET_PLATFORM) != 0)
        INFO("Platform assert does not match, bailing out...");
        return;

    init_boot_mode_properties();

    INFO("All done, exiting...");
}
