#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "crypto.h"

void xor_cipher(char *password, const char *key)
{
    const int KEY_LEN = strlen(key);

    printf("password: %s\n", password);

    size_t passwordLength = strlen(password);

    for (size_t i = 0; i < passwordLength; i++)
    {
        password[i] = password[i] ^ key[i % KEY_LEN];
    }

}