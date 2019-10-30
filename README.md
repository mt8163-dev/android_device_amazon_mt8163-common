# Amazon Fire HD8 2017

The Amazon Fire HD8 2017 (codenamed "douglas") is a low-range tablet from amazon announced in 2017.

Basic   | Spec Sheet
-------:|:--------------------------------------------------
CPU     | Quad (4x1.3 GHz Cortex-A35)
CHIPSET | Mediatek MT8163
GPU     | Mali 720
Memory  | 1,5GB RAM
Android | 5.1 (FireOS 5.X)
Storage | 16/32 GB
MicroSD | yes
MicroSD | yes
Battery | ? mAh
Display | 8"
Front Camera  | 2 MP
Rear Camera  | 2 MP

![Amazon Fire HD8 2017](https://media.wired.com/photos/5a2b2d4ea850e23a4736f3be/master/w_582,c_limit/amazonfire-TA.jpg "Amazon Fire HD8 2017")

This branch is for building CyanogenMod 12.1/LineageOS 12.1

# Download the sources
```
$ repo init -u https://github.com/cm12-amami/android.git -b cm-12.1 --groups=all,-notdefault,-darwin,-x86,-mips
$ cd .repo
$ git clone https://github.com/cm12-amami/local_manifests 
$ cd local_manifests 
$ git checkout cm-12.1 
$ cd ../.. 
$ repo sync --no-tags
```

# Build
```
$ git clone https://github.com/CM12-1-Douglas/android_device_amazon_douglas.git -b cm-12.1 device/amazon/douglas
$ chmod a+x device/amazon/douglas/setup-sources.sh && ./device/amazon/douglas/setup-sources.sh
$ source ./build/envsetup.sh
$ lunch cm_douglas-userdebug (or "-eng" for testing)
$ mka bacon -j8 (Specify your cores for the build) (If you run out memory, try with export LANG=C)
```
