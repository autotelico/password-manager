#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vault.h"
#include "crypto.h"

#define VAULT_FILE "vault.dat"
#define ENTRY_LIST_LENGTH 50
#ifndef KEY
    #define KEY "somethingstrong"
#endif

Entry write_entry(const char *key)
{
    Entry entry;
    printf("Enter service:");
    scanf("%s", entry.service);
    entry.service[strcspn(entry.service, "\n")] = '\0';
    
    printf("Enter username or email:");
    scanf("%s", entry.username);
    entry.username[strcspn(entry.username, "\n")] = '\0';

    printf("Enter password:");
    char password[MAX_LEN];
    scanf("%s", password);
    password[strcspn(password, "\n")] = '\0';

    xor_cipher(password, key);

    strcpy(entry.password, password);

    return entry;
}

int save_entry(const Entry *entry)
{
    FILE *file = fopen(VAULT_FILE, "ab");
    if (!file)
    {
        perror("No file found.");
        return 1;
    }
    fwrite(entry, sizeof(Entry), 1, file);
    fclose(file);

    return 0;
}

void list_entries()
{
    FILE *file = fopen(VAULT_FILE, "rb+");
    if (!file)
    {
        perror("No file found");
        return;
    }

    Entry entry;
    while (fread(&entry, sizeof(Entry), 1, file))
    {
        xor_cipher(entry.password, KEY);
        printf("Service: %s, Username: %s, Password: %s\n",
               entry.service, entry.username, entry.password);
    }
    fclose(file);
}

int delete_entry(char *key, int option)
{
    // int validOptions[] = {0, 1};
    // int validOptionsLength = sizeof(validOptions) / sizeof(validOptions[0]);
    // int optionIsValid = 0;

    // for (int i = 0; i < validOptionsLength; i++) {
    //     if (option == validOptions[i])
    //     {
    //         optionIsValid = 1;
    //         break;
    //     }
    // }

    // if (optionIsValid == 0)
    // {
    //     printf("invalid option passed\n");
    //     return 1;
    // }
    printf("Option passed: %d\n", option);
    FILE *file = fopen("vault.dat", "rb+");
    if (file == NULL)
    {
        perror("No file found for entry deletion");
        return 1;
    }

    Entry entryList[ENTRY_LIST_LENGTH];

    // Service
    if (option == 1)
    {
        int entryIndex = 0;
        size_t bytesRead;
        while (bytesRead = fread(&entryList[entryIndex], sizeof(Entry), 1, file))
        {
            printf("bytesRead: %d\n", bytesRead);
            Entry currentEntry = entryList[entryIndex];
            char decryptedPassword[MAX_LEN];
            xor_cipher(currentEntry.password, KEY);
            entryIndex++;
        }
        fclose(file);

        FILE *fileToWrite = fopen(VAULT_FILE, "w+");
        int count = 0;

        fseek(file, 0, SEEK_SET);

        while (count < entryIndex)
        {
            Entry currentEntry = entryList[count];
            printf("Service is %s and length is %d.\n", currentEntry.service, strlen(currentEntry.service));
            if (strcmp(currentEntry.service, key) == 0)
            {
                printf("Inside strcmp. Skipping\n");
                count++;
                continue;
            }
            fwrite(&currentEntry, sizeof(Entry), 1, fileToWrite);
            count++;
        }
        fclose(fileToWrite);

        return 0;
    }

    // Username
    if (option == 2)
    {
    }

    printf("Invalid option in delete_entry\n");
    return 1;
}