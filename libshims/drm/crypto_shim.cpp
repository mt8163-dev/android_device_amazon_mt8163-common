#include <openssl/rsa.h>
#include <openssl/mem.h>
#include <openssl/cipher.h>

extern "C" int RSA_verify_PKCS1_PSS_mgf1(RSA *rsa, const uint8_t *mHash,
                              const EVP_MD *Hash, const EVP_MD *mgf1Hash,
                              const uint8_t *EM, int sLen);


extern "C" int RSA_verify_PKCS1_PSS(RSA *rsa, const unsigned char *mHash,
                         const EVP_MD *Hash, const unsigned char *EM,
                         int sLen) {
    return RSA_verify_PKCS1_PSS_mgf1(rsa, mHash, Hash, NULL, EM, sLen);
}

extern "C" int EVP_EncryptFinal_ex(EVP_CIPHER_CTX *ctx, uint8_t *out, int *out_len);

extern "C" int EVP_EncryptFinal(EVP_CIPHER_CTX *ctx, uint8_t *out, int *out_len) {
    int result = EVP_EncryptFinal_ex(ctx, out, out_len);
    EVP_CIPHER_CTX_cleanup(ctx);
    return result;
}

extern "C" void CONF_modules_unload(int p) {}

extern "C" {

#undef CRYPTO_malloc
#undef CRYPTO_realloc
#undef CRYPTO_free

void *CRYPTO_malloc(size_t size) {
	return OPENSSL_malloc(size);
}

void *CRYPTO_realloc(void *ptr, size_t new_size) { 
	return OPENSSL_realloc(ptr, new_size);
}
void CRYPTO_free(void *ptr) { 
	return OPENSSL_free(ptr);
}

void OBJ_cleanup(void) {}

}
