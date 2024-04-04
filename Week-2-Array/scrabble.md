# Scrabble

## Description
*This program is designed to determine the winner of a short Scrabble-like game between two players. In Scrabble, players create words to score points, and the total points for a word are the sum of the point values of each letter in that word.*

### Function
```
int compute_score(string word)
{
    int score = 0;
    int length = strlen(word);

    for (int i = 0; i < length; i++)
    {
        if (isupper(word[i]))
        {
            score += POINTS[word[i] - 'A'];
        }
        else if (islower(word[i]))
        {
            score += POINTS[word[i] - 'a'];
        }
    }

    return score;
}
```

### Visualization
```
Here's an example of how the scoring is calculated for the word "CODE":

'C' is worth 3 points.
'O' is worth 1 point.
'D' is worth 2 points.
'E' is worth 1 point.
Thus, "CODE" is worth 7 points.
```

*This markdown provides a clear description of how the program calculates the score for a given word in a Scrabble-like game. The function implementation is included to demonstrate how the scoring logic works, and a visualization example is provided for better understanding.*

*To check the whole code click scrabble.c or click this [Link](https://github.com/Lei0x1/cs50-2024/blob/main/Week-2-Array/scrabble.c)*