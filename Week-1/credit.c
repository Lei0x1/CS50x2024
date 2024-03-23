#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <stdbool.h>

/*
 * Function prototypes
 */
int CalculateChecksum(long credit_card);
int MultiplyAndSum(int last_number);
int CountDigits(long credit_card);
bool IsAmericanExpress(long credit_card, int counter);
bool IsMasterCard(long credit_card, int counter);
bool IsVisa(long credit_card, int counter);

/*
 * Main function
 */
int main(void) {
    long creditCard;

    // Prompt user for credit card number input
    do {
        creditCard = get_long("Number: ");
    } while (creditCard < 0);

    // Calculate the checksum of the credit card number
    int checksum = CalculateChecksum(creditCard);
    int digitCount = CountDigits(creditCard);

    // Check if the credit card is of any valid type
    if (checksum % 10 != 0) {
        printf("INVALID\n");
    } else if (IsAmericanExpress(creditCard, digitCount)) {
        printf("AMEX\n");
    } else if (IsMasterCard(creditCard, digitCount)) {
        printf("MASTERCARD\n");
    } else if (IsVisa(creditCard, digitCount)) {
        printf("VISA\n");
    } else {
        printf("INVALID\n");
    }

    return 0;
}

/*
 * Function to calculate the checksum of the credit card number
 */
int CalculateChecksum(long creditCard) {
    int sum = 0;
    bool doubleAlternate  = false;

    // Iterate through each digit of the credit card number
    while (creditCard > 0) {
        int lastDigit = creditCard % 10;

        if (doubleAlternate) {
            sum += MultiplyAndSum(lastDigit);
        } else {
            sum += lastDigit;
        }

        // Switch between doubling every other digit and adding them directly
        doubleAlternate = !doubleAlternate;
        creditCard /= 10;
    }

    return sum;
}

/*
 * Function to multiply the last digit by 2 and return the sum of its digits
 */
int MultiplyAndSum(int lastDigit) {
    int multiplied = lastDigit * 2;
    int sum = 0;

    // Calculate the sum of digits of the multiplied number
    while (multiplied > 0) {
        sum += multiplied % 10;
        multiplied /= 10;
    }

    return sum;
}

/*
 * Function to count the number of digits in the credit card number
 */
int CountDigits(long creditCard) {
    int count = 0;

    // Count the number of digits
    while (creditCard > 0) {
        count++;
        creditCard /= 10;
    }

    return count;
}

/*
 * Function to check if the credit card number is an American Express card
 */
bool IsAmericanExpress(long creditCard, int digitCount) {
    int firstTwoDigits = creditCard / pow(10, digitCount - 2);

    return (digitCount == 15) && (firstTwoDigits == 34 || firstTwoDigits == 37);
}

/*
 * Function to check if the credit card number is a MasterCard
 */
bool IsMasterCard(long creditCard, int digitCount) {
    int firstTwoDigits = creditCard / pow(10, digitCount - 2);

    return (digitCount == 16) && (firstTwoDigits >= 51 && firstTwoDigits <= 55);
}

/*
 * Function to check if the credit card number is a Visa
 */
bool IsVisa(long creditCard, int digitCount) {
    int firstDigit = creditCard / pow(10, digitCount - 1);

    return (digitCount == 13 || digitCount == 16) && (firstDigit == 4);
}
