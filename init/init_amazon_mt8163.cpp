/*
   Copyright (C) 2007, The Android Open Source Project
   Copyright (c) 2016, The CyanogenMod Project
   Copyright (c) 2023, The LineageOS Project
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

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

#include <filesystem>
#include <fstream>
#include <iostream>

#include <android-base/file.h>
#include <android-base/logging.h>
#include <android-base/properties.h>
#include <android-base/strings.h>

#define _REALLY_INCLUDE_SYS__SYSTEM_PROPERTIES_H_
#include <sys/_system_properties.h>

#include "vendor_init.h"
#include "property_service.h"

using android::base::GetProperty;
using std::string;

void property_override(string prop, string value) {
    auto pi = (prop_info*) __system_property_find(prop.c_str());

    if (pi != nullptr)
        __system_property_update(pi, value.c_str(), value.size());
    else
        __system_property_add(prop.c_str(), prop.size(), value.c_str(), value.size());
}

std::string read_cmdline(const std::string& key) {
    std::ifstream cmdline("/proc/cmdline");
    std::string line;
    std::string value;

    if (cmdline.is_open()) {
        while (std::getline(cmdline, line)) {
            std::stringstream ss(line);
            std::string token;

            while (std::getline(ss, token, ' ')) {
                std::string::size_type pos = token.find(key);
                if (pos != std::string::npos) {
                    value = token.substr(pos + key.length() + 1);
                    return value;
                }
            }
        }
    }

    return value;
}

void vendor_load_properties() {
    // Amazon decided it was a good idea to kill offline
    // charging so we need to manually override whatever
    // the current boot mode is. Thankfully, the cmdline
    // exposes a 'bootreason' parameter which we can use
    // to decide whether this is a charger boot or not.
    std::string boot_reason = read_cmdline("androidboot.bootreason");

    // This can be done only once, so hope for the best.
    if (boot_reason == "usb") {
        property_override("ro.bootmode", "charger");
        LOG(INFO) << "Detected " << boot_reason << ", triggering charger!";
    }
}
