#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string word = "amigo";

    for (int x = 0; x < 5; x++)
    {
        printf("%c\n", word[x]);
    }
}