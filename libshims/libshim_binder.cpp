#include <binder/IInterface.h>

extern "C" void _ZN7android10IInterface8asBinderEv(void *retval, void* self) {
    android::sp<android::IBinder> *ret = new(retval) android::sp<android::IBinder>;
    *ret = android::IInterface::asBinder((android::IInterface*)self);
}

extern "C" void _ZNK7android10IInterface8asBinderEv(void *retval, void *self) {
    android::sp<android::IBinder> *ret = new(retval) android::sp<android::IBinder>;
    *ret = android::IInterface::asBinder((android::IInterface*)self);
}

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
