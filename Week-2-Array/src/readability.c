#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

// Cs50x2024 Readability
//
// Using Coleman-Liau index algorithm to calculate approximate grade level
// needed to comprehend some text.
//
// Longer words means higher reading level.
// More words per sentence means higher reading level.

int CountLetters(string text);
int CountWords(string text);
int CountSentences(string text);

int main(void)
{
    // Prompt the user for some text
    string text = get_string("Text: ");

    // Count the number of letters, words, and sentences in the text
    int letters = CountLetters(text);
    int words = CountWords(text);
    int sentences = CountSentences(text);

    // Compute the Coleman-Liau index.
    // Formula: index = 0.0588 * L - 0.296 * S - 15.8
    //  L = average number of letters per 100 words.
    //  S = average number of sentences per 100 words.
    //
    // Calculate CLI
    float L = (letters / (float) words) * 100;
    float S = (sentences / (float) words) * 100;
    float CLI = 0.0588 * L - 0.296 * S - 15.8;
    int index = round(CLI);

    // Print the grade level.
    // Be sure to round score to nearest whole number!.
    // Rmember: If output is less than 1, output "Before Grade 1".
    //          If output is 16 or higher, output "Grade 16+".
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }

    return 0;
}

// Count the numbers of uppercase and lowercase letters in a text.
int CountLetters(string text)
{
    int count = 0;
    int length = strlen(text);

    for (int i = 0; i < length; i++)
    {
        if (isalpha(text[i]))
        {
            count++;
        }
    }

    return count;
}

// Count the number of words in a sentence.
// A word is any sequence of characters separated by a space.
int CountWords(string text)
{
    int count = 0;
    int length = strlen(text);
    bool inWord = false;

    for (int i = 0; i < length; i++)
    {
        if (!isspace(text[i]) && !inWord)
        {
            count++;
            inWord = true;
        }
        else if (isspace(text[i]))
        {
            inWord = false;
        }
    }

    return count;
}

// For this problem, any period, exlamation point, or question mark indicates a sentence.
int CountSentences(string text)
{
    int count = 0;
    int length = strlen(text);

    for (int i = 0; i < length; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            count++;
        }
    }

    return count;
}