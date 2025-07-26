#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef VAULT_H
#define VAULT_H
#define MAX_LEN 50

typedef struct
{
    char service[50];
    char username[50];
    char password[50];
} Entry;

Entry write_entry(const char *key);
int save_entry(const Entry* entry);
void list_entries();

/*
    Key: the value to be searched (service or username)
    Option: an integer representing whether it's a service (0) or a username (1).
 */
int delete_entry(char *key, int option);

#endif