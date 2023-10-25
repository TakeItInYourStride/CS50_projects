#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

string get_text(void);
int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
int calculate_grade(int count_letters, int count_words, int count_sentences);

int main(void)
{
    string text = get_text();

    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    int grade = calculate_grade(letters, words, sentences);

    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
}
// Get Text
string get_text(void)
{
    string text;
    do
    {
        text = get_string("Text: ");
    }
    while (strlen(text) < 1);
    return text;
}
// Count Letters
int count_letters(string text)
{
    int l = 0;
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (isalpha(text[i]))
        {
            l++;
        }
    }
    return l;
}
// Count Words
int count_words(string text)
{
    int words = 1;
    for (int spaces = 0; text[spaces] != '\0'; spaces++)
    {
        if (text[spaces] == 32)
        {
            words++;
        }
    }
    return words;
}
// Count Sentences
int count_sentences(string text)
{
    int sentences = 0;
    for (int punct = 0; text[punct] != '\0'; punct++)
    {
        if (text[punct] == 46 || text[punct] == 33 || text[punct] == 63)
        {
            sentences++;
        }
    }
    return sentences;
}
// Calculate Grade
int calculate_grade(int count_letters, int count_words, int count_sentences)
{
    double grade_double =
        (0.0588 * (count_letters / (double) count_words * 100) - 0.296 * (count_sentences / (double) count_words * 100) - 15.8);
    int grade = round(grade_double);
    return grade;
}