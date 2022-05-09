#!/sbin/sh

REAL_BOOT=`readlink -f /dev/block/platform/soc/by-name/boot_x`
REAL_RECOVERY=`readlink -f /dev/block/platform/soc/by-name/recovery_x`
AMONET_BOOT=`readlink -f /dev/block/platform/soc/by-name/boot`
AMONET_RECOVERY=`readlink -f /dev/block/platform/soc/by-name/recovery`
REAL_LK=`readlink -f /dev/block/platform/soc/by-name/lk`
REAL_PL_HDR0=`readlink -f /dev/block/platform/soc/by-name/boot0hdr0`
REAL_PL_HDR1=`readlink -f /dev/block/platform/soc/by-name/boot0hdr1`
REAL_PL_IMG0=`readlink -f /dev/block/platform/soc/by-name/boot0img0`
REAL_PL_IMG1=`readlink -f /dev/block/platform/soc/by-name/boot0img1`
REAL_TEE1=`readlink -f /dev/block/platform/soc/by-name/tee1`
REAL_TEE2=`readlink -f /dev/block/platform/soc/by-name/tee2`

rm /dev/block/platform/soc/by-name/boot
rm /dev/block/platform/soc/by-name/recovery
rm /dev/block/platform/soc/by-name/lk
rm /dev/block/platform/soc/by-name/boot0hdr0
rm /dev/block/platform/soc/by-name/boot0hdr1
rm /dev/block/platform/soc/by-name/boot0img0
rm /dev/block/platform/soc/by-name/boot0img1
rm /dev/block/platform/soc/by-name/tee1
rm /dev/block/platform/soc/by-name/tee2

ln -s $REAL_BOOT /dev/block/platform/soc/by-name/boot
ln -s $REAL_RECOVERY /dev/block/platform/soc/by-name/recovery
ln -s $AMONET_BOOT /dev/block/platform/soc/by-name/boot_amonet
ln -s $AMONET_RECOVERY /dev/block/platform/soc/by-name/recovery_amonet
ln -s $REAL_LK /dev/block/platform/soc/by-name/lk_real
ln -s $REAL_PL_HDR0 /dev/block/platform/soc/by-name/boot0hdr0_real
ln -s $REAL_PL_HDR1 /dev/block/platform/soc/by-name/boot0hdr1_real
ln -s $REAL_PL_IMG0 /dev/block/platform/soc/by-name/boot0img0_real
ln -s $REAL_PL_IMG1 /dev/block/platform/soc/by-name/boot0img1_real
ln -s $REAL_TEE1 /dev/block/platform/soc/by-name/tee1_real
ln -s $REAL_TEE2 /dev/block/platform/soc/by-name/tee2_real

ln -s /dev/null /dev/block/platform/soc/by-name/lk
ln -s /dev/null /dev/block/platform/soc/by-name/boot0hdr0
ln -s /dev/null /dev/block/platform/soc/by-name/boot0hdr1
ln -s /dev/null /dev/block/platform/soc/by-name/boot0img0
ln -s /dev/null /dev/block/platform/soc/by-name/boot0img1
ln -s /dev/null /dev/block/platform/soc/by-name/tee1
ln -s /dev/null /dev/block/platform/soc/by-name/tee2
