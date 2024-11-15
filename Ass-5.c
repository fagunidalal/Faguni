#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define maxtry 3
#define wordsize 20

void displayWord(char *word, int *guessed, int length) 
{
    for(int i=0;i<length;i++) 
    {
        if (guessed[i]) 
        {
            printf("%c ", word[i]);
        } 
        else 
        {
            printf("_ ");
        }
    }
    printf("\n");
}

int isWordGuessed(int *guessed, int length) 
{
    for (int i=0;i<length;i++) 
    {
        if(!guessed[i]) 
        return 0;
    }
    return 1;
}

int main() 
{
    char word[wordsize];
    int guessed[wordsize]={0};
    int tries=0;
    char guess;
    int wordLength;
    
    printf("Enter the word to guess: ");
    scanf("%s", word);
    wordLength=strlen(word);

    //for cleaning screen to make game better
    system("cls");

    printf("Welcome to Hangman!\n");

    while (tries<maxtry) 
    {
        printf("\nWord: ");
        displayWord(word, guessed, wordLength);

        printf("Guess a letter: ");
        scanf(" %c", &guess);
        guess=tolower(guess);

        int found=0;
        for (int i=0;i<wordLength;i++) 
        {if(tolower(word[i])==guess) 
            {
            guessed[i]=1;
            found=1;
            }
        }

        if(!found) 
        {tries++;
         printf("Incorrect guess! Tries remaining: %d\n", maxtry-tries);
        }

        if (isWordGuessed(guessed, wordLength)) 
        {printf("\nCongratulations! you guessed the word: %s\n", word);
         break;
        }
    }

    if (tries==maxtry)
    {
     printf("\nYou lost! The word was: %s\n", word);
    }

    return 0;
}
