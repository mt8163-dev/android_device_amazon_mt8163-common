extern "C" {
    extern int _ZNK7android6Parcel18readFileDescriptorEv();

    int _ZNK7android6Parcel24readParcelFileDescriptorERi(int& outCommChannel) {
        return _ZNK7android6Parcel18readFileDescriptorEv();
    }
}
