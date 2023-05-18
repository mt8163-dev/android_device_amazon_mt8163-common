#ifndef _BDROID_BUILDCFG_H
#define _BDROID_BUILDCFG_H

#include <stdint.h>
#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif
int property_get(const char *key, char *value, const char *default_value);
#ifdef __cplusplus
}
#endif

inline const char* BtmGetDefaultName()
{
	char device[92];
	property_get("ro.product.device", device, "");

        if (strstr(device, "douglas") != NULL) {
            return "Fire HD8 2017";
        } else if (strstr(device, "giza") != NULL) {
            return "Fire HD8 2016";
        }

	return "Fire HD8";
}

#define BTM_DEF_LOCAL_NAME   BtmGetDefaultName()

#define BTA_AV_MAX_A2DP_MTU  1788
#define BLE_INCLUDED TRUE
#define BTA_GATT_INCLUDED TRUE
#define SMP_INCLUDED TRUE

#endif
