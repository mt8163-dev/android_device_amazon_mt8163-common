#!/bin/sh

rootdirectory="$PWD"
dirs="bionic build/make/core build/soong frameworks/av frameworks/base frameworks/native hardware/interfaces system/core system/sepolicy system/bt external/wpa_supplicant_8"

for dir in $dirs ; do
	cd $rootdirectory
	cd $dir
	echo "Cleaning $dir patches..."
	git checkout -- . && git clean -df
done

echo "Done!"
cd $rootdirectory
