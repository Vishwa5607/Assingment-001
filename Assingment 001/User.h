#pragma once
#ifndef USER_H
#define USER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_USERNAME_LENGTH 10

typedef enum {
    RED,
    BLUE,
    GREEN
} Faction;

typedef struct {
    char username[MAX_USERNAME_LENGTH + 1];
    int level;
    Faction faction;
} User;

// Function to generate a random username
void generate_random_username(char* username);

#endif