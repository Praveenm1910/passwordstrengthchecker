#include "password_strength.h"

// Calculate overall password score
int pass_score(const char *password) {
    int score = 0;
    score += strength(password);
    score += caps(password);
    score += low(password);
    score += symbol(password);
    score += seq(password);
    return score;
}

// Check if password length is 8 or more
int strength(const char *password) {
    size_t length = strlen(password);
    printf("\nPassword length: %zu characters", length);
    if (length >= 8) {
        printf(" - Sufficient length.");
        return 1;
    } else {
        printf(" - Insufficient length.");
        return 0;
    }
}

// Check if password contains at least one uppercase letter
int caps(const char *password) {
    if (match_regex("[A-Z]", password)) {
        printf("\nPassword includes an uppercase letter.");
        return 1;
    }
    printf("\nPassword lacks uppercase letters.");
    return 0;
}

// Check if password contains at least three lowercase letters
int low(const char *password) {
    if (match_regex("([a-z].*){3,}", password)) {
        printf("\nPassword has three or more lowercase letters.");
        return 4;
    }
    printf("\nPassword needs more lowercase letters.");
    return 0;
}

// Check if password contains at least one special symbol
int symbol(const char *password) {
    if (match_regex("[!@#$%^&*(),.?\":{}|<>]", password)) {
        printf("\nPassword includes a special symbol.");
        return 1;
    }
    printf("\nPassword lacks special symbols.");
    return 0;
}

// Check if password has sequential digits
int seq(const char *password) {
    int digit_count = 0;

    // Count the number of digits in the password
    for (size_t i = 0; i < strlen(password); i++) {
        if (isdigit(password[i])) {
            digit_count++;
        }
    }

    if (digit_count >= 3) {
        if (match_regex("(\\d)\\1{2}|(\\d)(\\d)\\2", password)) {
            printf("\nPassword contains a sequence of 3 consecutive or identical numbers.");
            return 0;
        }
        printf("\nPassword includes 3 or more non-consecutive numbers.");
        return 3;
    } else if (digit_count == 2) {
        if (match_regex("(\\d)\\1", password)) {
            printf("\nPassword has a sequence of 2 consecutive or identical numbers.");
            return 0;
        }
        printf("\nPassword has 2 non-consecutive numbers.");
        return 2;
    } else if (digit_count == 1) {
        printf("\nPassword has only 1 digit.");
        return 0;
    } else {
        printf("\nPassword has no digits.");
        return 0;
    }
}

// Function to compile and execute a regex pattern
int match_regex(const char *pattern, const char *text) {
    regex_t regex;
    int result;

    result = regcomp(&regex, pattern, REG_EXTENDED);
    if (result) {
        char error_message[100];
        regerror(result, &regex, error_message, sizeof(error_message));
        fprintf(stderr, "Regex compilation failed: %s\n", error_message);
        return 0;
    }

    result = regexec(&regex, text, 0, NULL, 0);
    regfree(&regex);
    
    return !result;
}
