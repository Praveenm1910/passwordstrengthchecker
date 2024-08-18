#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <regex.h>

// Function prototyping
int pass_score(const char *password);
int strength(const char *password);
int caps(const char *password);
int low(const char *password);
int symbol(const char *password);
int seq(const char *password);
int match_regex(const char *pattern, const char *text);

int main() {
    printf("--------------------------------------------------------------------------------------\n");
    printf("Welcome to my Password Strength Checker Tool\n");
    printf("This is a basic tool that helps you to know the strength of your passwords.\n");
    printf("This tool will review and return your password strength in points ranging from 1 to 10.\n");
    printf("This tool will analyze the strength of your password based on the following:\n");
    printf("1. Your password length should be at least 8 characters long: 1 point.\n");
    printf("2. Password must contain at least one uppercase letter: 1 point.\n");
    printf("3. If the password has three or more lowercase letters: 4 points.\n");
    printf("4. If the password contains at least one special symbol: 1 point.\n"); 
    printf("5. If the password contains 3 or more digits that are not sequential: 3 points.\n");
    printf("--------------------------------------------------------------------------------------\n");

    // Get the input from the user securely 
    char *pass = getpass("Enter your password: ");
    if (pass == NULL) {
        fprintf(stderr, "Error: Unable to read password input.\n");
        exit(EXIT_FAILURE);
    }

    // Calculate and display the password strength
    int score = pass_score(pass);
    printf("\nPassword strength score: %d out of 10\n", score);

    // Clear the password from memory
    memset(pass, 0, strlen(pass));

    return 0;
}

// Calculate overall password score based on various checks
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

    // If there are 3 or more digits
    if (digit_count >= 3) {
        // Check for 3 consecutive or identical digits
        if (match_regex("(\\d)\\1{2}|(\\d)(\\d)\\2", password)) {
            printf("\nPassword contains a sequence of 3 consecutive or identical numbers.");
            return 0;
        }
        printf("\nPassword includes 3 or more non-consecutive numbers.");
        return 3;
    } 
    // If there are 2 digits
    else if (digit_count == 2) {
        // Check for 2 consecutive or identical digits
        if (match_regex("(\\d)\\1", password)) {
            printf("\nPassword has a sequence of 2 consecutive or identical numbers.");
            return 0;
        }
        printf("\nPassword has 2 non-consecutive numbers.");
        return 2;
    } 
    // If there is 1 digit
    else if (digit_count == 1) {
        printf("\nPassword has only 1 digit.");
        return 0;
    }
    // If there are no digits
    else {
        printf("\nPassword has no digits.");
        return 0;
    }
}

// Function to compile and execute a regex pattern
int match_regex(const char *pattern, const char *text) {
    regex_t regex;
    int result;

    // Compile the regex pattern
    result = regcomp(&regex, pattern, REG_EXTENDED);
    if (result) {
        char error_message[100];
        regerror(result, &regex, error_message, sizeof(error_message));
        fprintf(stderr, "Regex compilation failed: %s\n", error_message);
        return 0;
    }

    // Execute the regex
    result = regexec(&regex, text, 0, NULL, 0);
    regfree(&regex);
    
    // Return whether the pattern matched
    return !result;
}
