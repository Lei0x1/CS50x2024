#include <cs50.h>
#include <stdio.h>

// Function prototype
int calculate_minimum_coins(int cents);

int main(void) {
    int cents;

    // Prompt the user until a valid input is received
    do {
        cents = get_int("Change owed (in cents): ");
    } while (cents < 0);

    // Calculate minimum coins needed and print the result
    int min_coins = calculate_minimum_coins(cents);
    printf("%d\n", min_coins);
}

// Function to calculate the minimum number of coins needed
int calculate_minimum_coins(int cents) {
    /* Define the denominations of coins
     *
     * 25 represent as quarters
     * 10 represent as dimes
     * 5  represent as nickels
     * 1  represent as pennies
     *
    */

    int denominations[] = {25, 10, 5, 1};
    int num_coins = 0;

    // Iterate through each denomination
    for (int i = 0; i < 4; i++) {
        // Calculate how many coins of this denomination can be used
        num_coins += cents / denominations[i];
        // Update the remaining cents
        cents %= denominations[i];
    }

    return num_coins;
}