cd .. && cd .. && cd ..
echo "Cloning system_core..."
rm -rf system/core && git clone https://github.com/CM12-1-Douglas/android_system_core.git -b cm-12.1 system/core
echo "Cloning frameworks_av..."
rm -rf frameworks/av && git clone https://github.com/CM12-1-Douglas/android_frameworks_av.git -b cm-12.1 frameworks/av
echo "Cloning vendor tree..."
git clone https://github.com/CM12-1-Douglas/android_vendor_amazon_douglas.git vendor/amazon/douglas
echo "Done! You can start building now."
