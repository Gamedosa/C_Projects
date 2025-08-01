/*
 * Guess the Number - Version 3
 *
 * This is a simple number guessing game written in C.
 * It uses basic programming concepts such as:
 * - Variable declaration
 * - Conditional statements (if/else)
 * - Loops (while/for)
 * - Mathematical comparisons
 * - Stdlib included
 * - Abs function responsable for convert number signal
 * - casting used to convert int to double
 * - time library included to use the EPOCH time
 * - srand function used to generate random number to be guessed
 * -
 * The player tries to guess the correct number through repeated attempts.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Print game header
    printf(" __        __   _                            \n");
    printf(" \\ \\      / /__| | ___ ___  _ __ ___   ___   \n");
    printf("  \\ \\ /\\ / / _ \\ |/ __/ _ \\| '_ ` _ \\ / _ \\  \n");
    printf("   \\ V  V /  __/ | (_| (_) | | | | | |  __/  \n");
    printf("    \\_/\\_/ \\___|_|\\___\\___/|_| |_| |_|\\___|  \n");

    printf("\n\n");

    int randonumber = rand();

    int seconds = time(0);
    srand(seconds);

    int secretNumber = randonumber % 100;
    int guess;
    int attempts = 1;
    double score = 1000;

    int isCorrect = 0;

    int level;
    printf("Choose dificult level.\n");
    printf("(1) Easy (2) Medium (3) Hard\n\n ");
    printf("Choice: ");
    scanf("%d", &level);

    int attemptsToGuess;

    switch (level)
    {
    case 1:
        attemptsToGuess = 10;
        break;
    case 2:
        attemptsToGuess = 5;
        break;
    default:
        attemptsToGuess = 3;
        break;
    }

    for (int i = 1; i <= attemptsToGuess; i++)
    {
        printf("Attempt %d\n", attempts);
        printf("Enter your guess: \n");

        scanf("%d", &guess);

        if (guess < 0)
        {
            printf("You cannot enter negative numbers!\n");
            continue;
        }
        isCorrect = (guess == secretNumber);
        int isGreater = guess > secretNumber;

        if (isCorrect)
        {
            break;
        }
        else if (isGreater)
        {
            printf("Your guess is higher than the secret number.\n");
        }
        else
        {
            printf("Your guess is lower than the secret number.\n");
        }

        attempts++;

        double lostscore = abs(guess - secretNumber) / (double)2;
        score = score - lostscore;
    }

    printf("End Game!!!\n");

    if (isCorrect)
    {
        printf("             OOOOOOOOOOO               \n");
        printf("         OOOOOOOOOOOOOOOOOOO           \n");
        printf("      OOOOOO  OOOOOOOOO  OOOOOO        \n");
        printf("    OOOOOO      OOOOO      OOOOOO      \n");
        printf("  OOOOOOOO  #   OOOOO  #   OOOOOOOO    \n");
        printf(" OOOOOOOOOO    OOOOOOO    OOOOOOOOOO   \n");
        printf("OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO  \n");
        printf("OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO  \n");
        printf("OOOO  OOOOOOOOOOOOOOOOOOOOOOOOO  OOOO  \n");
        printf(" OOOO  OOOOOOOOOOOOOOOOOOOOOOO  OOOO   \n");
        printf("  OOOO   OOOOOOOOOOOOOOOOOOOO  OOOO    \n");
        printf("    OOOOO   OOOOOOOOOOOOOOO   OOOO     \n");
        printf("      OOOOOO   OOOOOOOOO   OOOOOO      \n");
        printf("         OOOOOO         OOOOOO         \n");
        printf("             OOOOOOOOOOOO              \n");
        printf("You Win!!! \n");
        printf("You guessed it in %d attempt(s).\n", attempts);
        printf("Your score is: %.2f\n ", score);
    }
    else
    {
        printf("       \\|/ ____ \\|/    \n");
        printf("        @~/ ,. \\~@      \n");
        printf("       /_( \\__/ )_\\    \n");
        printf("          \\__U_/        \n");
        printf("You lost! Try again!\n");
    }

    printf("Game over!\n");
}
