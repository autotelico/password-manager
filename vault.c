#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vault.h"

#define VAULT_FILE "vault.dat"

int save_entry(const Entry* entry) {
    FILE* file = fopen(VAULT_FILE, "ab");
    if (!file) {
        perror("No file found.");
        return 1;
    }
    fwrite(entry, sizeof(Entry), 1, file);
    fclose(file);

    return 0;
}

void list_entries() {
    FILE *file = fopen(VAULT_FILE, "rb");
    if (!file) {
        perror("No file found");
        return;
    }

    Entry entry;
    while (fread(&entry, sizeof(Entry), 1, file)) {
        printf("Service: %s, Username: %s, Password: %s\n",
        entry.service, entry.username, entry.password);
    }
    fclose(file);
}