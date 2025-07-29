/*
 * Guess the Number - Version 1
 *
 * This is a simple number guessing game written in C.
 * It uses basic programming concepts such as:
 * - Variable declaration
 * - Conditional statements (if/else)
 * - Loops (while/for)
 * - Mathematical comparisons
 *
 * The player tries to guess the correct number through repeated attempts.
 */

#include <stdio.h>


int main()
{
    // Print game header
    printf("*************************\n");
    printf("* Welcome to Guess Game *\n");
    printf("*************************\n");

    int secretNumber = 42;
    int guess;
    int attempts = 1;

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
    }

    printf("Game over!\n");
    printf("You guessed it in %d attempt(s).\n", attempts);
}
