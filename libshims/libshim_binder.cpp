extern "C" {
    extern int _ZNK7android6Parcel18readFileDescriptorEv();
    extern int _ZN7android6Parcel25writeParcelFileDescriptorEib();

    int _ZNK7android6Parcel24readParcelFileDescriptorERi(int& outCommChannel) {
        return _ZNK7android6Parcel18readFileDescriptorEv();
    }

    int _ZN7android6Parcel25writeParcelFileDescriptorEii(int& outCommChannel) {
        return _ZN7android6Parcel25writeParcelFileDescriptorEib();
    }
}
