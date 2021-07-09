#!/bin/bash
#
# Copyright (C) 2020 The LineageOS Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
# http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

set -e

VENDOR=amazon
DEVICE_COMMON=mt8163-common

# Load extractutils and do some sanity checks
MY_DIR="${BASH_SOURCE%/*}"
if [[ ! -d "$MY_DIR" ]]; then MY_DIR="$PWD"; fi

LINEAGE_ROOT="$MY_DIR"/../../..
VENDOR_OUT="${LINEAGE_ROOT}/vendor/${VENDOR}/${DEVICE_COMMON}/proprietary"

HELPER="$LINEAGE_ROOT"/vendor/cm/build/tools/extract_utils.sh
if [ ! -f "$HELPER" ]; then
    echo "Unable to find helper script at $HELPER"
    exit 1
fi
. "$HELPER"

if [ $# -eq 0 ]; then
  SRC=adb
else
  if [ $# -eq 1 ]; then
    SRC=$1
  else
    echo "$0: bad number of arguments"
    echo ""
    echo "usage: $0 [PATH_TO_EXPANDED_ROM]"
    echo ""
    echo "If PATH_TO_EXPANDED_ROM is not specified, blobs will be extracted from"
    echo "the device using adb pull."
    exit 1
  fi
fi

function patch_sym() {
    if [ $# -eq 0 ]
      then
        echo "- No arguments supplied!"
    fi

    if [ $(expr length $1) != $(expr length $2) ]
      then
        echo "- Symbols length doesn't match: $(expr length $1) vs $(expr length $2)!"
        return
    fi

    MATCH=$(strings ${3} | grep ${1})
    if [ $? != 0 ]
      then
        echo "- Couldn't find ${1}..."
        return
    fi

    echo "- Patching ${3}: ${1} --> ${2}"
    sed -i s/$1/${2}/g ${3}
}

# Initialize the helper
setup_vendor "$DEVICE_COMMON" "$VENDOR" "$LINEAGE_ROOT" true

extract "$MY_DIR"/proprietary-files.txt "$SRC"

"$MY_DIR"/setup-makefiles.sh

# Force SW Decoding
patch_sym _ZN12DpBlitStream10invalidateEv _ZN12DpBlitStream10ievalidateEv ${VENDOR_OUT}/lib/libMtkOmxVdecEx.so

# Handle Missing GraphicBuffer Symbols
patch_sym _ZN7android19GraphicBufferMapper4lockEPK13native_handleiRKNS_4RectEPPv _ZN7android19GraphicBufferMapper4lockEPK13native_handlejRKNS_4RectEPPv ${VENDOR_OUT}/lib/hw/hwcomposer.mt8163.so
patch_sym _ZN7android19GraphicBufferMapper4lockEPK13native_handleiRKNS_4RectEPPv _ZN7android19GraphicBufferMapper4lockEPK13native_handlejRKNS_4RectEPPv ${VENDOR_OUT}/lib64/hw/hwcomposer.mt8163.so