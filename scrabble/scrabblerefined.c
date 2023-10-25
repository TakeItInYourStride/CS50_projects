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
        printf("It was a tie!\n");
    }
}

string get_word(string player)
{
    int is_valid; // sets to bool true (because it has a value == 1)
    string word;
    do
    {
        word = get_string("%s", player);
        is_valid = 1;

        for (int i = 0; word[i] != '\0'; i++)
        {
            if (!isalpha(word[i]))
            {
                is_valid = 0;
                break;
            }
        }
        if (!is_valid)
        {
            printf("Alphabetical only.\n");
        }
    }
    while (!is_valid);

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
        score += POINTS[word[x] - 'a'];
    }

    return score;
}
