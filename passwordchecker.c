#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

// Function prototypes
int pass_score(char *password);
int strength(char *password);
int caps(char *password);
int low(char *password);
int symbol(char *password);
int seq(char *password);
int sanitize_input(char *password);

int main() {
    // Use getpass to securely capture user input without echoing
    
    printf("______________________________________________________________________________________\n");
    
    printf("Welcome my password Strength Checker Tool\n");
    printf("______________________________________________________________________________________\n");
 
    char *pass;
    pass = getpass("Enter your password: ");

    // Calculate and display the password strength
    int score = pass_score(pass);
    printf("\nPassword strength score: %d out of 10\n", score);
    return 0;
}

// Calculate total password score based on various checks
int pass_score(char *password) {
    if (!sanitize_input(password)) {
        printf("\nWarning: Password contains invalid characters. Please use safe characters only.\n");
        return 0;
    }

    int score = 0;
    score += strength(password);
    score += caps(password);
    score += low(password);
    score += symbol(password);
    score += seq(password);
    return score;
}

// Check if password contains only allowed characters
int sanitize_input(char *password) {
    // Allowed characters are alphanumeric and common special symbols
    const char *allowed_chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_+-=[]{};':\"\\|,.<>/?`~";

    for (int i = 0; i < strlen(password); i++) {
        if (!strchr(allowed_chars, password[i])) {
            printf("Error: Password contains disallowed characters!\n");
            return 0;
        }
    }
    return 1; // Password is safe
}

// Check if password length is 8 or more
int strength(char *password) {
    printf("\nPassword length: %zu characters", strlen(password));
    if (strlen(password) >= 8) {
        printf(" - Sufficient length.");
        return 1;
    } else {
        printf(" - Insufficient length.");
        return 0;
    }
}

// Check if password contains at least one uppercase letter
int caps(char *password) {
    for (int i = 0; i < strlen(password); i++) {
        if (isupper(password[i])) {
            printf("\nPassword includes an uppercase letter.");
            return 1;
        }
    }
    printf("\nPassword lacks uppercase letters.");
    return 0;
}

// Check if password contains at least three lowercase letters
int low(char *password) {
    int count = 0;
    for (int i = 0; i < strlen(password); i++) {
        if (islower(password[i])) {
            count++;
        }
        if (count >= 3) {
            printf("\nPassword has three or more lowercase letters.");
            return 4;
        }
    }
    printf("\nPassword needs more lowercase letters.");
    return 0;
}

// Check if password contains at least one special symbol
int symbol(char *password) {
    for (int i = 0; i < strlen(password); i++) {
        if (ispunct(password[i])) {
            printf("\nPassword includes a special symbol.");
            return 1;
        }
    }
    printf("\nPassword lacks special symbols.");
    return 0;
}

// Check if password has sequential digits and penalize for them
int seq(char *password) {
    int count = 0;
    for (int i = 0; i < strlen(password); i++) {
        if (isdigit(password[i])) {
            count++;
        }
    }

    if (count >= 3) {
        for (int i = 0; i < strlen(password) - 2; i++) {
            if (isdigit(password[i]) && isdigit(password[i + 1]) && isdigit(password[i + 2])) {
                int d1 = password[i];
                int d2 = password[i + 1];
                int d3 = password[i + 2];
                if ((abs(d2 - d1) == 1 || abs(d2 - d1) == 0) && (abs(d3 - d2) == 1 || abs(d3 - d2) == 0)) {
                    printf("\nPassword contains a sequence of 3 consecutive numbers.");
                    return 0;
                }
            }
        }
        printf("\nPassword includes 3 non-consecutive numbers.");
        return 3;
    } else if (count == 2) {
        for (int i = 0; i < strlen(password) - 1; i++) {
            if (isdigit(password[i]) && isdigit(password[i + 1])) {
                int d1 = password[i];
                int d2 = password[i + 1];
                if (abs(d2 - d1) == 1 || abs(d2 - d1) == 0) {
                    printf("\nPassword has a sequence of 2 consecutive numbers.");
                    return 0;
                }
            }
        }
        printf("\nPassword has 2 non-consecutive numbers.");
        return 2;
    } else {
        printf("\nPassword has fewer than 2 digits.");
        return 0;
    }
}
