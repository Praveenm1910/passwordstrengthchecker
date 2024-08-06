# Password Strength Checker

## Overview
The Password Strength Checker is a vital tool designed to evaluate and bolster the security of user-created passwords. By assessing passwords through a range of security criteria, this project empowers users to craft robust passwords that protect against unauthorized access and potential security threats.

## Key Features
- **Comprehensive Length Check:** Ensures that passwords meet the minimum length requirement of 8 characters.
- **Uppercase Letter Detection:** Verifies the presence of at least one uppercase letter.
- **Lowercase Letter Analysis:** Requires a minimum of three lowercase letters.
- **Special Symbol Verification:** Encourages the inclusion of special symbols.
- **Numeric Sequence Evaluation:** Detects and penalizes consecutive numeric sequences.
- **Input Sanitization:** Validates passwords against allowed characters to prevent unsafe input.

## Technical Details
- **Language and Libraries:** Developed in C, utilizing standard libraries for efficient string manipulation and secure input handling.
- **Structured Design:** Modular approach with functions dedicated to evaluating specific aspects of password security.
- **Secure Input Handling:** Uses `getpass` to capture passwords without displaying them.

## Implementation
- **Functions:** `strength()`, `caps()`, `low()`, `symbol()`, `seq()`, and `sanitize_input()` assess password security.
- **Scoring System:** Each function contributes to an overall strength score out of 10.

## Getting Started
1. **Clone the Repository:**
    ```bash
    git clone https://github.com/yourusername/your-repo.git
    cd your-repo
    ```
2. **Compile the Code:**
    ```bash
    gcc -o password_checker password_checker.c
    ```
3. **Run the Program:**
    ```bash
    ./password_checker
    ```

## Contributing
Feel free to submit pull requests or open issues if you have suggestions for improvements or find bugs.

## License
This project is licensed under the MIT License - see the LICENSE file for details.

## Acknowledgements
A special thanks to **Sibidharan Nandhakumar** and the **Selfmade Ninja Academy** for the guidance in secure coding and vulnerability exploitation.

## Contact
For questions or feedback, please contact me at praveenm191004@gmail.com.

