#include "StoringFunction.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

void printAsciiArt() {
    printf("  .--.--.       ___                                                                                                 ___                       ____          \n");
    printf(" /  /    '.   ,--.'|_                      ,--,                                                                   ,--.'|_                   ,'  , `.        \n");
    printf("|  :  /`. /   |  | :,'   ,---.    __  ,-.,--.'|         ,---,                                                     |  | :,'               ,-+-,.' _ |        \n");
    printf(";  |  |--`    :  : ' :  '   ,'\\ ,' ,'/ /||  |,      ,-+-. /  |  ,----._,.          .--.--.              .--.--.   :  : ' :            ,-+-. ;   , ||        \n");
    printf("|  :  ;_    .;__,'  /  /   /   |'  | |' |`--'_     ,--.'|'   | /   /  ' /         /  /    '       .--, /  /    '.;__,'  /     ,---.  ,--.'|'   |  ||        \n");
    printf(" \\  \\    `. |  |   |  .   ; ,. :|  |   ,',' ,'|   |   |  ,\"' ||   :     |        |  :  /`./     /_ ./||  :  /`./|  |   |     /     \\|   |  ,', |  |,        \n");
    printf("  `----.   \\:__,'| :  '   | |: :'  :  /  '  | |   |   | /  | ||   | .\\  .        |  :  ;_    , ' , ' :|  :  ;_  :__,'| :    /    /  |   | /  | |--'         \n");
    printf("  __ \\  \\  |  '  : |__'   | .; :|  | '   |  | :   |   | |  | |.   ;  ';  |         \\  \\    `./___/ \\: | \\  \\    `. '  : |__ .    ' / |   : |  | ,            \n");
    printf(" /  /`--'  /  |  | '.'|   :    |;  : |   '  : |__ |   | |--'   `---`-'| |          `----.   \\.  \\  ' |  `----.   \\|  | '.'|'   ;   /|   : |  |/             \n");
    printf("'--'.     /   ;  :    ;\\   \\  / |  , ;   |  | '.'||   | |  |/ '   .   . |         /  /`--'  / \\  ;   : /  /`--'  /;  :    ;'   |  / |   | |`-'              \n");
    printf("  `--'---'    |  ,   /  `----'   ---'    ;  :    ;|   |/       .'__/'\\_: |        '--'.     /   \\  \\  ;'--'.     / |  ,   / |   :    |   ;/                  \n");
    printf("               ---`-'                    |  ,   / '---'        |   :    :          `--'---'     :  \\  \\ `--'---'   ---`-'   \\   \\  /'---'                   \n");
    printf("                                          ---`-'                \\   \\  /                         \\  ' ;                      `----'                         \n");
    printf("                                                                 `--`-'                           `--'                                                       \n");
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
