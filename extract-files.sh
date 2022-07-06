#!/bin/bash
#
# Copyright (C) 2016 The CyanogenMod Project
# Copyright (C) 2017-2020 The LineageOS Project
#
# SPDX-License-Identifier: Apache-2.0
#

set -e

VENDOR=amazon
DEVICE_COMMON=mt8163-common

# Load extract_utils and do some sanity checks
MY_DIR="${BASH_SOURCE%/*}"
if [[ ! -d "${MY_DIR}" ]]; then MY_DIR="${PWD}"; fi

ANDROID_ROOT="${MY_DIR}/../../.."
VENDOR_OUT="${ANDROID_ROOT}/vendor/${VENDOR}/${DEVICE_COMMON}"

HELPER="${ANDROID_ROOT}/tools/extract-utils/extract_utils.sh"
if [ ! -f "${HELPER}" ]; then
    echo "Unable to find helper script at ${HELPER}"
    exit 1
fi
source "${HELPER}"

# Default to sanitizing the vendor folder before extraction
CLEAN_VENDOR=true

ONLY_COMMON=
ONLY_TARGET=
KANG=
SECTION=

while [ "${#}" -gt 0 ]; do
    case "${1}" in
        --only-common )
                ONLY_COMMON=true
                ;;
        --only-target )
                ONLY_TARGET=true
                ;;
        -n | --no-cleanup )
                CLEAN_VENDOR=false
                ;;
        -k | --kang )
                KANG="--kang"
                ;;
        -s | --section )
                SECTION="${2}"; shift
                CLEAN_VENDOR=false
                ;;
        * )
                SRC="${1}"
                ;;
    esac
    shift
done

if [ -z "${SRC}" ]; then
    SRC="adb"
fi

function general_fixup() {
	for blob in $(find ${VENDOR_OUT}/proprietary | grep .so)
	do
		if grep -q "${1}" $blob; then
			if ! grep -q "${2}" $blob; then
				patchelf --add-needed "${2}" $blob
			fi
		fi
	done
}

function blob_fixup() {
    case "${1}" in
    	bin/amzn_dha_hmac|bin/amzn_dha_tool)
            patchelf --add-needed "libshim_crypto.so" "${2}"
            ;;
        lib/libdrmmtkutil.so|lib64/libdrmmtkutil.so)
            patchelf --add-needed "libshim_icuuc.so" "${2}"
            ;;
        lib/libasp.so|lib64/libasp.so|lib/libaspclient.so)
            patchelf --add-needed "libshim_binder.so" "${2}"
            ;;
        lib/hw/hwcomposer.mt8163.so|lib64/hw/hwcomposer.mt8163.so)
            sed -i 's|_ZN7android19GraphicBufferMapper4lockEPK13native_handleiRKNS_4RectEPPv|_ZN7android19GraphicBufferMapper4lockEPK13native_handlejRKNS_4RectEPPv|g' "${2}"
            patchelf --add-needed "libshim_ui.so" "${2}"
            ;;
        lib/libaudiocomponentengine.so|lib64/libaudiocomponentengine.so)
            patchelf --add-needed "libutilscallstack.so" "${2}"
            ;;
        lib/egl/libGLES_mali.so|lib64/egl/libGLES_mali.so)
            patchelf --add-needed "libutilscallstack.so" "${2}"
            ;;
        lib/hw/audio.primary.mt8163.so|lib64/hw/audio.primary.mt8163.so)
            patchelf --add-needed "libshim_binder.so" "${2}"
            ;;
        lib/libbwc.so|lib64/libbwc.so)
            patchelf --add-needed "libshim_binder.so" "${2}"
            ;;
        lib/libcam_utils.so|lib64/libcam_utils.so)
            patchelf --add-needed "libutilscallstack.so" "${2}"
            patchelf --add-needed "libshim_camera.so" "${2}"
            ;;
    esac
}

if [ -z "${ONLY_TARGET}" ]; then
    # Initialize the helper for common device
    setup_vendor "${DEVICE_COMMON}" "${VENDOR}" "${ANDROID_ROOT}" true "${CLEAN_VENDOR}"

    extract "${MY_DIR}/proprietary-files.txt" "${SRC}" "${KANG}" --section "${SECTION}"
fi

if [ -z "${ONLY_COMMON}" ] && [ -s "${MY_DIR}/../${DEVICE}/proprietary-files.txt" ]; then
    # Reinitialize the helper for device
    source "${MY_DIR}/../${DEVICE}/extract-files.sh"
    setup_vendor "${DEVICE}" "${VENDOR}" "${ANDROID_ROOT}" false "${CLEAN_VENDOR}"

    extract "${MY_DIR}/../${DEVICE}/proprietary-files.txt" "${SRC}" "${KANG}" --section "${SECTION}"
fi

# Since we can't preload shims anymore, link the shim ONLY to the affected libraries
general_fixup "__xlog_buf_printf"           "libshim_log.so"
general_fixup "lab126_log_write"            "libshim_log.so"
general_fixup "android_atomic_acquire_load" "libshim_atomic.so"

"${MY_DIR}/setup-makefiles.sh"