#include "password_strength.h"

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
        return EXIT_FAILURE;
    }

    // Calculate and display the password strength
    int score = pass_score(pass);
    printf("\nPassword strength score: %d out of 10\n", score);

    // Clear the password from memory
    memset(pass, 0, strlen(pass));

    return 0;
}
