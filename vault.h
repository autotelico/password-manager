#ifndef VAULT_H
#define VAULT_H
#define MAX_LEN 50

typedef struct
{
    char service[50];
    char username[50];
    char password[50];
} Entry;

int save_entry(const Entry* entry);
void list_entries();

#endif