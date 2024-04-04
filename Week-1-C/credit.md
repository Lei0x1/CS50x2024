# Credit Card Checksum Calculation

## Description
*To calculate the checksum of a credit card number, the code follows the Luhn algorithm. After prompting the user for the credit card number,
the program calculates the checksum by iterating through each digit of the credit card number. The algorithm alternates between doubling
every other digit and summing the digits of the resulting numbers. Once the checksum is calculated, the program determines the
type of credit card based on its length and the initial digits.*

### Function
```Copy code
int CalculateChecksum(long creditCard) {
    int sum = 0;
    bool doubleAlternate  = false;

    // Iterate through each digit of the credit card number
    while (creditCard > 0) {
        int lastDigit = creditCard % 10;

        if (doubleAlternate) {
            sum += MultiplyAndSum(lastDigit); // Double and sum alternate digits
        } else {
            sum += lastDigit; // Add non-alternate digits directly
        }

        doubleAlternate = !doubleAlternate;
        creditCard /= 10;
    }

    return sum;
}
```

### Visualization:
```
                                          First                      Second
 creditCard = 1234567890    [lastDigit = creditCard % 10 = 0]   [sum = 0 + 0 = 0]
 creditCard = 123456789     [lastDigit = creditCard % 10 = 9]   [sum = 0 + 9 = 9]
 creditCard = 12345678      [lastDigit = creditCard % 10 = 8]   [sum = 9 + 8 = 17]
 creditCard = 1234567       [lastDigit = creditCard % 10 = 7]   [sum = 17 + 7 = 24]
 creditCard = 123456        [lastDigit = creditCard % 10 = 6]   [sum = 24 + 6 = 30]
 creditCard = 12345         [lastDigit = creditCard % 10 = 5]   [sum = 30 + 5 = 35]
 creditCard = 1234          [lastDigit = creditCard % 10 = 4]   [sum = 35 + 4 = 39]
 creditCard = 123           [lastDigit = creditCard % 10 = 3]   [sum = 39 + 3 = 42]
 creditCard = 12            [lastDigit = creditCard % 10 = 2]   [sum = 42 + 2 = 44]
 creditCard = 1             [lastDigit = creditCard % 10 = 1]   [sum = 44 + 1 = 45]
```

*This markdown provides a clear description of how the code calculates the checksum of a credit card number, along with
the function implementation and a visualization of the calculations for each step. Important lines within the function
are highlighted for better understanding.*

To check the whole code click credit.c or Click this [Link](https://github.com/Lei0x1/cs50-2024/blob/main/Week-1-C/credit.c)
