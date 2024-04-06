#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

// In the game of Scrabble, players create words to score points, and the number of points is the sum of the point values of each letter in the word.
//
// implement a program in C that determines the winner of a short Scrabble-like game. Your program should
// prompt for input twice: once for “Player 1” to input their word and once for “Player 2” to input their word. Then, depending on which player scores
// the most points, your program should either print “Player 1 wins!”, “Player 2 wins!”, or “Tie!” (in the event the two players score equal points).
//
// Scoring System:
//  A B C D E F G H I J K L M N O P Q  R S T U V W X Y Z
//  1 3 3 2 1 4 2 4 1 8 5 1 3 1 1 3 10 1 1 1 1 4 4 8 4 10
//
// For example, if we wanted to score the word “CODE”, we would note that the ‘C’ is worth 3 points, the ‘O’ is worth 1 point, the ‘D’ is worth 2 points,
// and the ‘E’ is worth 1 point. Summing these, we get that “CODE” is worth 7 points.
//

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Prompt the user for two words
    string player1 = get_string("Player 1: ");
    string player2 = get_string("Player 2: ");

    // Compute the score of each word
    int score1 = compute_score(player1);
    int score2 = compute_score(player2);

    // Print the winner
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    else if (score1 == score2)
    {
        printf("Tie!\n");
    }
}

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