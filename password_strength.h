#ifndef PASSWORD_STRENGTH_H
#define PASSWORD_STRENGTH_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <regex.h>

// Function prototypes
int pass_score(const char *password);
int strength(const char *password);
int caps(const char *password);
int low(const char *password);
int symbol(const char *password);
int seq(const char *password);
int match_regex(const char *pattern, const char *text);

#endif // PASSWORD_STRENGTH_H
