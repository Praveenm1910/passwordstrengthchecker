#include "password_strength.h"

int main() {
    printf("--------------------------------------------------------------------------------------\n");
    printf("Welcome to my Password Strength Checker Tool\n");
    printf("This tool reviews and returns your password strength (1 to 10).\n");
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
