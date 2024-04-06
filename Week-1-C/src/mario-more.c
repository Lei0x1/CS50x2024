#include <stdio.h>
#include <cs50.h>

// Function prototype
void MarioRightAlign(int num);

int main(void) {
    int num;

    // Prompt user to enter the height of the pyramid
    do {
        num = get_int("Height: ");

        // Display error message for invalid input
        if (num < 1 || num > 8) {
            printf("Please enter a number between (1-8).");
            printf("\n");
        }

    } while (num < 1 || num > 8);

    // Call the function to print the right-aligned pyramid
    MarioRightAlign(num);

    return 0;
}

// Function to print a right-aligned pyramid
void MarioRightAlign(int num) {
    for (int i = 0; i < num; i++) {
        // print spaces to right-align the pyramid
        for (int k = 0; k < num - i - 1; k++) {
            printf(" ");
        }
        // print '#' character for the right pyramid
        printf("#");

        // Print additional '#'s for the right pyramid
        for (int j = 0; j < i; j++) {
            printf("#");
        }

        // Print space between the right and left alignments
        for (int kk_m = 0; kk_m < 2; kk_m++) {
            printf(" ");
        }

        // Print '#' for the left pyramid
        for (int jj = 0; jj < i + 1; jj++) {
            printf("#");
        }

        printf("\n");
    }
}