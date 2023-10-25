// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch

// a = 6 e = 3 i = 1 o = 0 (not U)

#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Error: One input only.\n");
        return 1;
    }

    string s = argv[1];
    int i = 0;

    while (s[i] != '\0')
    {
        switch (s[i])
        {
            case 'a':
            case 'A':
                printf("6");
                break;

            case 'e':
            case 'E':
                printf("3");
                break;

            case 'i':
            case 'I':
                printf("1");
                break;

            case 'o':
            case 'O':
                printf("0");
                break;

            default:
                printf("%c", s[i]);
                break;
        }
        i++;
    }
    printf("\n");
}
