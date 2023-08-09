#ifndef SQL_H
#define SQL_H

int isValidPassword(const char *password);
int createAcount(char *username, char *password);
int isUsernameUnique(const char *username);

#endif