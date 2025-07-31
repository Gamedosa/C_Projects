/*
 * Guess the Number - Version 2
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
    printf("*************************\n");
    printf("* Welcome to Guess Game *\n");
    printf("*************************\n");

    int randonumber = rand();

    int seconds = time(0);
    srand(seconds);

    int secretNumber = randonumber % 100;
    int guess;
    int attempts = 1;
    double score = 1000;


    while (1) {
        printf("Attempt %d\n", attempts);
        printf("Enter your guess: \n");

        scanf("%d", &guess);

        if (guess < 0) {
            printf("You cannot enter negative numbers!\n");
            continue;
        }

        int isCorrect = (guess == secretNumber);
        int isGreater = guess > secretNumber;

        if (isCorrect) {
            printf("Congratulations! You guessed the number!\n");
            break;
        } else if (isGreater) {
            printf("Your guess is higher than the secret number.\n");
        } else {
            printf("Your guess is lower than the secret number.\n");
        }

        attempts++;

        double lostscore = abs(guess - secretNumber) / (double)2;
        score = score - lostscore;

    }

    printf("Game over!\n");
    printf("You guessed it in %d attempt(s).\n", attempts);
    printf("Your score is: %.2f\n ", score);
}
