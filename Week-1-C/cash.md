# Cash Solution by CS50

## Description:
*The Cash program calculates the minimum number of coins needed to make up a given amount of change in cents. It considers four denominations of coins: quarters, dimes, nickels, and pennies.*


### Function:
```c
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
```

### Visualization:
```
Change Owed: 70

Denomination: 25
Step 1: Quarters = 70 / 25 = 2
Step 2: Remaining Cents = 70 % 25 = 20

Denomination: 10
Step 1: Dimes = 20 / 10 = 2
Step 2: Remaining Cents = 20 % 10 = 0

Denomination: 5
Step 1: Nickels = 0 / 5 = 0
Step 2: Remaining Cents = 0 % 5 = 0

Denomination: 1
Step 1: Pennies = 0 / 1 = 0
Step 2: Remaining Cents = 0 % 1 = 0

Minimum Coins Needed:
- Quarters: 2
- Dimes: 2
- Nickels: 0
- Pennies: 0

```

*This markdown provides a clear description of the Cash problem, the function implementation, an example, and instructions on how to use the function in a C program.*

*For a detailed walkthrough and the complete code [cash.c](https://github.com/Lei0x1/cs50-2024/blob/main/Week-1-C/src/cash.c)*