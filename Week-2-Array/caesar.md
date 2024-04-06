# Caesar

## Description
*The Caesar cipher is a simple encryption technique that shifts each letter in a plaintext message by a fixed number of positions in the alphabet to generate the ciphertext. This program implements the Caesar cipher encryption algorithm, taking a command-line argument for the encryption key and prompting the user for a plaintext message to encrypt. It ensures that only alphabetic characters are encrypted while preserving their case, leaving non-alphabetic characters unchanged in the ciphertext.*

### Function
```c
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
```

### Visualization
*Consider the following plaintext message:*
```c
"This is a sample message for Caesar cipher encryption!"
```

*If we choose a key of 3 for encryption, the resulting ciphertext would be:*
```c
"Wklv lv d vdpsoh phvvdjh iru Fdvhdu fliudfw hqfubswlrq!"
```

*This markdown block provides an overview of the Caesar cipher encryption program, including its purpose, functionality, and the implementation of the Caesar cipher algorithm for encrypting plaintext messages.*

*For a detailed walkthrough and the complete code [caesar.c](https://github.com/Lei0x1/cs50-2024/blob/main/Week-2-Array/src/caesar.c)*