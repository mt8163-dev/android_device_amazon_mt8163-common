#!/sbin/sh

PAYLOAD_BLOCK=223223

dd if=/dev/block/platform/mtk-msdc.0/by-name/recovery_amonet of=/tmp/recovery_amonet.hdr bs=512 count=1
dd if=/dev/block/platform/mtk-msdc.0/by-name/recovery_amonet of=/tmp/recovery_amonet.payload bs=512 skip=$PAYLOAD_BLOCK
dd if=/dev/block/platform/mtk-msdc.0/by-name/boot_amonet of=/tmp/boot_amonet.hdr bs=512 count=1
dd if=/dev/block/platform/mtk-msdc.0/by-name/boot_amonet of=/tmp/boot_amonet.payload bs=512 skip=$PAYLOAD_BLOCK

diff /tmp/recovery_amonet.hdr /tmp/boot_amonet.hdr && diff /tmp/recovery_amonet.payload /tmp/boot_amonet.payload

if [ $? -ne 0 ] ; then
    echo "Detected overwritten boot-exploit, restoring from recovery" > /tmp/restore_bootpatch.log
    dd if=/tmp/recovery_amonet.hdr of=/dev/block/platform/mtk-msdc.0/by-name/boot_amonet bs=512 count=1
    dd if=/tmp/recovery_amonet.payload of=/dev/block/platform/mtk-msdc.0/by-name/boot_amonet bs=512 seek=$PAYLOAD_BLOCK
fi
