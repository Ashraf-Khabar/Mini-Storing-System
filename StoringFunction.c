#include "StoringFunction.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <time.h>

void printAsciiArt()
{
    printf("  ______                 _                                                    \n");
    printf(" / _____) _             (_)                                 _                 \n");
    printf("( (____ _| |_ ___   ____ _ ____   ____     ___ _   _  ___ _| |_ _____ ____    \n");
    printf(" \\____ (_   _) _ \\ / ___) |  _ \\ / _  |   /___) | | |/___|_   _) ___ |    \\   \n");
    printf(" _____) )| || |_| | |   | | | | ( (_| |  |___ | |_| |___ | | |_| ____| | | |  \n");
    printf("(______/  \\__)___/|_|   |_|_| |_|\\___ |  (___/ \\__  (___/   \\__)_____)_|_|_|  \n");
    printf("                                (_____|       (____/                           \n");

    printf("CREATED BY : ACHRAF KHABAR                                DATE : 09/08/2023\n");
    printf("\n");
}

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
        return 1;
    }

    char line[100];
    while (fgets(line, sizeof(line), file))
    {
        char *existingUsername = strtok(line, ",");
        if (existingUsername != NULL && strcmp(existingUsername, username) == 0)
        {
            fclose(file);
            return 0;
        }
    }

    fclose(file);
    return 1;
}

int createAcount(char *username, char *password)
{
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

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

        fprintf(file, "%s,%s,%d-%02d-%02d,%02d:%02d:%02d\n", username, password, tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
        fclose(file);
        printf("The account was created successfully\n");
        printf("\n"); // Start a new line
        return 1;
    }
}
