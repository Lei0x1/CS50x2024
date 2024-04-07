#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

// Function prototypes
bool validate_key(string key);
void encipher(string plaintext, string key);

int main(int argc, string argv[]) {
    // Check if the user provided a key as a command-line argument
    if (argc != 2) {
        printf("Usage: ./substitution key\n");
        return 1;  // Return an error code
    }

    // Get Key
    string key = argv[1];
    // Validate Key
    if (!validate_key(key)) {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    // Key is valid, continue with your program logic
    int length = strlen(key);  // Check key length

    // Get Plaintext
    string plaintext = get_string("plaintext: ");

    // Encipher
    encipher(plaintext, key);

    return 0;
}

bool validate_key(string key) {
    int char_count[26] = {0};
    int length = strlen(key);

    if (length != 26) {
        return false;  // Key length should be exactly 26 characters
    }

    // Check if key contains only alphabetic characters and count occurrences of each character
    for (int i = 0; i < length; i++) {
        if (!isalpha(key[i])) {
            return false;  // Key contains a non-aplhabetic character
        }

        // Convert the character to lowercase
        char lowercase_char = tolower(key[i]);

        // Calculate index based on lowercase character
        int index = lowercase_char - 'a';

        // Check for repetition based on lowercase index
        if (char_count[index] > 0) {
            return false;  // Key contains repeated characters
        }

        char_count[index]++;
    }

    return true;  // Key is valid
}

void encipher(string plaintext, string key) {
    // Initialize a buffer to store the ciphertext
    char ciphertext[strlen(plaintext) + 1];  // Add 1 for the null terminator

    // Iterate through each character in the plaintext
    for (int i = 0; i < strlen(plaintext); i++) {
        char current_char = plaintext[i];
        char encrypted_char = current_char;  // Initialize to the current character

        // Check if the current character is an alphabetic character
        if (isalpha(current_char)) {
            // Determine the case of the current character
            bool is_uppercase = isupper(current_char);

            // Convert the character to lowercase for indexing
            current_char = tolower(current_char);

            // Determine the index of the current character in the alphabet
            int index = current_char - 'a';

            // Apply the substitution cipher encryption
            if (is_uppercase) {
                encrypted_char = toupper(key[index]);
            } else {
                encrypted_char = tolower(key[index]);  // Preserve lowercase in ciphertext
            }
        }

        // Store the encrypted character in the ciphertext buffer
        ciphertext[i] = encrypted_char;
    }

    // Null-terminate the ciphertext string
    ciphertext[strlen(plaintext)] = '\0';

    // Print the ciphertext
    printf("ciphertext: %s\n", ciphertext);
}
