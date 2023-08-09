#include <stdio.h>
#include "StoringFunction.h"
#include <string.h>
#include <stdlib.h>
#define MAX_USERNAME_LENGTH 100
#define MAX_PASSWORD_LENGTH 100

int main()
{
    int check = 0;
    char *username = (char *)malloc(MAX_USERNAME_LENGTH * sizeof(char));
    char *password = (char *)malloc(MAX_PASSWORD_LENGTH * sizeof(char));

    printAsciiArt();
    
    while (!check)
    {
        if (username == NULL || password == NULL)
        {
            printf("Memory allocation failed.\n");
            return 1;
        }
        printf("Enter the username: ");
        gets(username);

        printf("Enter the password: ");
        gets(password);

        printf("\n");

        if (createAcount(username, password))
        {
            check = 1;
        }
        else
        {
            check = 0;
        }
    }

    free(username);
    free(password);
}