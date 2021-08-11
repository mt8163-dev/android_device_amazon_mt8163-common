#!/bin/sh

rootdirectory="$PWD"
dirs="bionic frameworks/av frameworks/base frameworks/native system/core packages/apps/Settings external/wpa_supplicant_8"

RED='\033[0;31m'
NC='\033[0m'

for dir in $dirs ; do
	cd $rootdirectory
	cd $dir
	echo -e "${RED}Applying ${NC}$dir ${RED}patches...${NC}\n"
	git apply -v --check $rootdirectory/device/amazon/mt8163-common/patches/$dir/*.patch
done

# -----------------------------------
echo -e "Done !\n"
cd $rootdirectory

