#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int random_number;
    int maxGuesses = 5;
    int guessCount = 0;
    int number;

    printf("*********************Welcome to Number Guessing game🥰🥰🥰❕❗❗❗*********************************\n\n\n");
    printf("*********************I'm thinking of a number between 1 and 10. Can you guess it🤔❓*********************************\n\n\n");

    srand(time(NULL));
    random_number = rand() % 10 + 1;
    // printf("Random number: %d\n", random_number);

    while (guessCount < maxGuesses) {
        printf("Enter a number: ");
        scanf("%d", &number);
        if (number == random_number) {
            printf("Congratulations!!! You guessed the number🥳😇🥳\n\n");
            break;
        } else {
            printf("Sooorrry😓 that's not the correct number. Try again\n");
            guessCount++;
        }
    }

    if (guessCount == maxGuesses) {
        printf("Sorry😥 you've used all your guesses. The correct number is: %d\n", random_number);
    }

    return 0;
}
