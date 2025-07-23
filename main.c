#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vault.h"
#include "crypto.h"

int main(int argc, char **argv) {
    char password[] = "cookie";
    const char key[] = "mykey";
    xor_cipher(password, key);

    for (int i = 0; i < sizeof password / sizeof password[0]; i++) {
        printf("%02X ", (unsigned char)password[i]);
    }

    return 0;
}