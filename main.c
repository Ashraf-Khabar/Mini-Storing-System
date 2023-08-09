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
            // Implement the 'Create Account' functionality
            break;

        case 2:
            // Implement the 'Connect' functionality
            break;

        case 3:
            // Implement the 'Reload' functionality
            break;

        case 4:
            printf("Are you sure you want to quit the app? (y/n): ");
            char confirmation;
            scanf(" %c", &confirmation); // Leave a space before %c to consume newline

            if (confirmation == 'y' || confirmation == 'Y')
            {
                printf("Goodbye!\n");
                menu = 4; // Exit the loop and quit the app
            }
            else
            {
                printf("Continuing...\n");
            }
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
