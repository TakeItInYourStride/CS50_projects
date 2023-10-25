#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

string get_word(string player);

int main(void)
{
    string word1 = get_word("Player 1: ");
    string word2 = get_word("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

string get_word(string player)
{
    string word = get_string("%s", player);

    for (int x = 0; word[x] != '\0'; x++)
    {
        word[x] = (char) tolower(word[x]);
    }
    return word;
}

int compute_score(string word)
{
    int score = 0;

    for (int x = 0; word[x] != '\0'; x++)
    {
        if (isalpha(word[x]))
        {
            score += POINTS[word[x] - 'a'];
        }
    }

    return score;
}
