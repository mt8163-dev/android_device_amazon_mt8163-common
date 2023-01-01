#!/system/bin/sh

function logi() {
    /system/bin/log -t "mac_idme" -p i "$1"
}

function main_thread() {
    # Get the MAC address from /proc/idme/bt_mac_addr.
    mac=$(cat /proc/idme/bt_mac_addr)
    if [ -z "$mac" ]; then
        logi "Unable to read MAC address from /proc/idme/bt_mac_addr"
        exit 1
    fi

    # Since the IDME format doesn't contain colons, we need to add them
    # to the MAC address. The format is 6 bytes, 2 bytes per octet.
    mac=$(echo $mac | sed 's/\(..\)\(..\)\(..\)\(..\)\(..\)\(..\)/\1:\2:\3:\4:\5:\6/')

    # This shouldn't be needed (since it's already done in the main .rc file), but
    # just in case, we'll make sure the directory exists.
    if [ ! -d /data/vendor/bluedroid ]; then
        mkdir -p /data/vendor/bluedroid
        chown bluetooth:bluetooth /data/vendor/bluedroid
        chmod 0770 /data/vendor/bluedroid
    fi

    # Write the MAC address to the /data/vendor/bluedroid/macbt.
    echo $mac > /data/vendor/bluedroid/macbt
    if [ $? -ne 0 ]; then
        logi "Unable to write MAC address to /data/vendor/bluedroid/macbt"
        exit 1
    fi
    logi "MAC address written to /data/vendor/bluedroid/macbt"

    # We're not done yet, we need to make sure ro.bt.bdaddr_path is actually set.
    # This should be done in build.prop (since it's a read-only value).
    if [ -z "$(getprop ro.bt.bdaddr_path)" ]; then
        setprop ro.bt.bdaddr_path /data/vendor/bluedroid/macbt
    fi

    # Make sure macbt is owned by bluetooth:bluetooth and has the correct
    # permissions.
    chown bluetooth:bluetooth /data/vendor/bluedroid/macbt
    chmod 0660 /data/vendor/bluedroid/macbt

    # All done, exit.
    exit 0
}

main_thread
