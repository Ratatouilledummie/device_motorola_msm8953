/*
 * Copyright (C) 2016 The CyanogenMod Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef _BDROID_BUILDCFG_H
#define _BDROID_BUILDCFG_H

#pragma push_macro("PROPERTY_VALUE_MAX")

#include <cutils/properties.h>
#include <string.h>

static inline const char* BtmGetDefaultName()
{
    char product_device[PROPERTY_VALUE_MAX];
    property_get("ro.product.device", product_device, "");

    if (strstr(product_device, "ali"))
        return "Moto G(6)";
    if (strstr(product_device, "albus"))
        return "Moto Z2 Play";
    if (strstr(product_device, "potter"))
        return "Moto G(5) Plus";
    if (strstr(product_device, "sanders"))
        return "Moto G(5S) Plus";

    // Fallback to ro.product.model
    return "Moto MSM8953";
}

#define BTM_DEF_LOCAL_NAME BtmGetDefaultName()
#define BLUETOOTH_QTI_SW TRUE

#define MAX_ACL_CONNECTIONS   16
#define MAX_L2CAP_CHANNELS    16
#define BLE_VND_INCLUDED TRUE
#define BTM_WBS_INCLUDED TRUE
#define BTIF_HF_WBS_PREFERRED TRUE
#define BTM_SCO_ENHANCED_SYNC_ENABLED FALSE

#pragma pop_macro("PROPERTY_VALUE_MAX")
#endif
