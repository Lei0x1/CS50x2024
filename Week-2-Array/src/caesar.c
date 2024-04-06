#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    // Check if the program was run with exactly one command-line argument
    if (argc != 2) {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Check if every character in argv[1] is a digit
    for (int i = 0; argv[1][i] != '\0'; i++) {
        // Check if the current character is not a digit
        if (!isdigit(argv[1][i])) {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    // Convert argv[1] from a `string` to an `int` (the key for the Caesar cipher)
    int key = atoi(argv[1]);

    // Prompt the user for plaintext
    string text = get_string("plaintext: ");
    int length = strlen(text);

    printf("ciphertext: ");

    // Encrypt each character in the plaintext using the Caesar cipher algorithm
    for (int i = 0; i < length; i++)
    {
        // Check if the current character is a letter
        if (isalpha(text[i]))
        {
            // Preserve case and shift characters accordingly
            if (isupper(text[i])) // Check if the character is uppercase
            {
                // Encrypt the uppercase character using the Caesar cipher formula
                char encrypted_char = ((text[i] - 'A' + key) % 26) + 'A';
                printf("%c", encrypted_char);
            }
            else if (islower(text[i])) // Check if the character is lowercase
            {
                // Encrypt the lowercase character using the Caesar cipher formula
                char encrypted_char = ((text[i] - 'a' + key) % 26) + 'a';
                printf("%c", encrypted_char);
            }
        }
        else
        {
            // Print non-alphabetic characters as they are (e.g., spaces, punctuation)
            printf("%c", text[i]);
        }
    }
    printf("\n");

    return 0;
}