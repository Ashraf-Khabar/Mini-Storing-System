#include "sql.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

int isValidPassword(const char *password)
{
    int hasUppercase = 0;
    int hasLowercase = 0;
    int hasDigit = 0;
    int hasSpecialCharacter = 0;

    for (int i = 0; password[i] != '\0'; i++)
    {
        if (isupper(password[i]))
        {
            hasUppercase = 1;
        }
        else if (islower(password[i]))
        {
            hasLowercase = 1;
        }
        else if (isdigit(password[i]))
        {
            hasDigit = 1;
        }
        else if (!isalnum(password[i]))
        {
            hasSpecialCharacter = 1;
        }
    }

    return hasUppercase && hasLowercase && hasDigit && hasSpecialCharacter;
}

int isUsernameUnique(const char *username)
{
    FILE *file = fopen("./data/acounts.csv", "r");
    if (file == NULL)
    {
        return 1; // Assume unique if the file doesn't exist yet
    }

    char line[100]; // Adjust the buffer size as needed
    while (fgets(line, sizeof(line), file))
    {
        char *existingUsername = strtok(line, ",");
        if (existingUsername != NULL && strcmp(existingUsername, username) == 0)
        {
            fclose(file);
            return 0; // Username already exists
        }
    }

    fclose(file);
    return 1; // Username is unique
}

int createAcount(char *username, char *password)
{
    if (strlen(password) < 8)
    {
        printf("The password must have more than 8 characters\n");
        return 0;
    }
    else
    {
        if (!isValidPassword(password))
        {
            printf("The password must have at least one uppercase, one lowercase, one digit, and one special character\n");
            return 0;
        }

        if (!isUsernameUnique(username))
        {
            printf("The username already exists\n");
            return 0;
        }

        FILE *file = fopen("./data/acounts.csv", "a");
        if (file == NULL)
        {
            printf("Error opening file\n");
            return 0;
        }

        fprintf(file, "%s,%s\n", username, password);
        fclose(file);
        printf("The account was created successfully\n");
        return 1;
    }
}
