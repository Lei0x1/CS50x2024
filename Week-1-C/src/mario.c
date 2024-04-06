/*
 * Mario version 1: Pyramid should right align.
 * 1: Should prompt user for height with a limit of 1-8
 * 2: When user input less than 1 it should reprompt.
 *
*/

// Libraries
#include <stdio.h>
#include <cs50.h>

void MarioRightAlign(int num);
void MarioLeftAlign(int num);

int main(void) {
    int num;

    // Prompt user to enter number.
    do {
        num = get_int("Height: ");

        // Error input message
        if (num < 1 || num > 8) {
            printf("Please enter a valid number 1-8.");
            printf("\n");
        }

    } while (num < 1 || num > 8);

    MarioRightAlign(num);

    return 0;
}

void MarioLeftAlign(int num) {
    for (int i = 0; i < num; i++) {
        for (int j = 0; j < i; j++) {
            printf("#");
        }
        printf("\n");
    }
}

void MarioRightAlign(int num) {
    for (int i = 0; i < num; i++) {
        // Print spaces to right-align the pyramid
        for (int k = 0; k < num - i - 1; k++) {
            printf(" ");
        }
        // Print '#' character for the pyramid
        printf("#");
        for (int j = 0; j < i; j++) {
            printf("#");
        }

        printf("\n");
    }
}