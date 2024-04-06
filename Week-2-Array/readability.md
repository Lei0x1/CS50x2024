# Readability

## Description
*This program calculates the approximate grade level required to comprehend a text based on the Coleman-Liau index algorithm. The index is calculated using the average number of letters and sentences per 100 words in the text.*

### Functions
- `CountLetters(string text)`: Counts the number of letters in the text.
- `CountWords(string text)`: Counts the number of words in the text.
- `CountSentences(string text)`: Counts the number of sentences in the text.

### Letter Count Function
```c
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
```

### Word Count Function
```c
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
```

### Sentence Count Function
```c
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
```

### Visualization
*Consider the following sample text: This is a sample sentence! It contains multiple words, such as 'apple' and 'banana'.*

#### Letter Count Function
*The `CountLetters` function would count the number of letters in the text, excluding spaces, punctuation, and other non-alphabetic characters. For the given text, the letter count would be:*

*- Letters: 51*

#### Word Count Function
*The `CountWords` function would count the number of words in the text. In this case, words are defined as sequences of characters separated by spaces. The word count for the given text would be:*

*- Words: 13*

#### Sentence Count Function
*The `CountSentences` function would count the number of sentences in the text. Sentences are identified by periods, exclamation points, or question marks. For the sample text, the sentence count would be:*

*- Sentences: 3*

### Conclusion
*Based on the counts obtained from the sample text, the program would calculate the Coleman-Liau index and determine the approximate grade level needed to comprehend the text.*

*This markdown provides the details of the three functions CountLetters, CountWords, and CountSentences along with their descriptions and implementations.*

*For a detailed walkthrough and the complete code [readability.c](https://github.com/Lei0x1/cs50-2024/blob/main/Week-2-Array/src/readability.c)*