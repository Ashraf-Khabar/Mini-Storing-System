#include <stdio.h>
#include "StoringFunction.h"
#include <string.h>
#include <stdlib.h>
#define MAX_USERNAME_LENGTH 100
#define MAX_PASSWORD_LENGTH 100

void printMainMenu()
{
    printf("********************************\n");
    printf("*        Account System        *\n");
    printf("********************************\n");
    printf("1. Create Account\n");
    printf("2. Connect\n");
    printf("3. Reload\n");
    printf("4. Quit\n");
    printf("********************************\n");
    printf("Select an option: ");
}

int main()
{
    int check = 0, menu = 0;
    char *username = (char *)malloc(MAX_USERNAME_LENGTH * sizeof(char));
    char *password = (char *)malloc(MAX_PASSWORD_LENGTH * sizeof(char));

    printAsciiArt();

    while (menu != 4)
    {
        printMainMenu();
        scanf("%d", &menu);
        getchar(); // Clear newline character from input buffer

        switch (menu)
        {
        case 1:
            if (username == NULL || password == NULL)
            {
                printf("Memory allocation failed.\n");
                return 1;
            }
            printf("Enter the username: ");
            fgets(username, MAX_USERNAME_LENGTH, stdin);
            username[strcspn(username, "\n")] = '\0';

            printf("Enter the password: ");
            fgets(password, MAX_PASSWORD_LENGTH, stdin);
            password[strcspn(password, "\n")] = '\0';

            printf("\n");

            if (createAcount(username, password))
            {
                check = 1;
            }
            else
            {
                check = 0;
            }
            break;

        case 2:
            break;
        case 3:
            break;
        case 4:
            printf("Goodbye!\n");
            break;
        default:
            printf("Invalid option. Please select a valid option.\n");
        }

        printf("\n");
    }

    free(username);
    free(password);

    return 0;
}
