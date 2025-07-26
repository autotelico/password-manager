#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vault.h"
#include "crypto.h"
#define KEY "somethingstrong"

int main(int argc, char **argv)
{
    while (1)
    {
        printf("Choose an option:\n");
        printf("0 - Exit\n");
        printf("1 - List saved entries\n");
        printf("2 - Save new entry\n");
        printf("3 - Delete entry\n");

        char userChoice;
        scanf(" %c", &userChoice);

        switch (userChoice)
        {
        case '0':
            printf("Finishing Password Manager...\n");
            printf("Finished with code 0.\n");
            return 0;
        case '1':
            printf("Listing saved entries:\n");
            list_entries();
            printf("\n");
            break;
        case '2':
            Entry entry = write_entry(KEY);
            save_entry(&entry);
            break;
        case '3':
            printf("What type of entry would you like to delete?\n");
            printf("1 - Service\n");
            printf("2 - Username\n");

            char entryType;
            scanf(" %c", &entryType);

            if (entryType != '1' && entryType != '0')
            {
                fprintf(stdout, "%c is not a valid option", entryType);
                exit(1);
            }

            printf("Input %s to delete: ", entryType == '1' ? "service" : "username");
            char serviceToDelete[MAX_LEN];
            scanf("%s", &serviceToDelete);
            int entryTypeInt = entryType - '0';
            delete_entry(serviceToDelete, entryTypeInt);
            break;

        default:
            printf("Invalid option\n");
        }
    }

    return 0;
}