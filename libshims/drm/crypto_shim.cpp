#include <openssl/rsa.h>
#include <openssl/mem.h>
#include <openssl/cipher.h>

extern "C" void CONF_modules_unload(int p) {}
extern "C" void OBJ_cleanup(void) {}

extern "C" void *CRYPTO_malloc(size_t size) {
	return OPENSSL_malloc(size);
}

extern "C" void *CRYPTO_realloc(void *ptr, size_t new_size) { 
	return OPENSSL_realloc(ptr, new_size);
}

extern "C" void CRYPTO_free(void *ptr) { 
	return OPENSSL_free(ptr);
}
