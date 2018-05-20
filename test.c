#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <gmp.h>
#include "paillier.h"

int main(){
	int modulus_bits = 2048;
	paillier_pubkey_t *ppk;
	paillier_prvkey_t *psk;
	
	paillier_keygen(modulus_bits, &ppk, &psk, paillier_get_rand_devrandom);
	
	paillier_plaintext_t *pt;
	char test[100] = "The Paillier encryption and decryption is correct.";
	pt = paillier_plaintext_from_bytes(test, 100);
	
	paillier_ciphertext_t *ct;
	ct = paillier_enc(NULL, ppk, pt, paillier_get_rand_devrandom);
	
	paillier_plaintext_t *pt_dec;
	pt_dec = paillier_dec(NULL, ppk, psk, ct);
	
	char *test_dec = paillier_plaintext_to_bytes(100, pt_dec);
	
	printf("%s\n", test_dec);
	
	return 0;
}
