#!/bin/sh

rootdirectory="$PWD"
dirs="bionic frameworks/av frameworks/base frameworks/native system/core packages/apps/Settings external/wpa_supplicant_8"

for dir in $dirs ; do
	cd $rootdirectory
	cd $dir
	echo "Cleaning $dir patches..."
	git checkout -- . && git clean -df
done

echo "Done!"
cd $rootdirectory
