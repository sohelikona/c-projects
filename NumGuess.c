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
//         if (guessCount > random_number) {
//     printf("Too high. Try a lower number.\n");
// } else if (guessCount < random_number) {
//     printf("Too low. Try a higher number.\n");
// } 

        printf("Enter a number: ");
        scanf("%d", &number);
         if (number == random_number) {
            printf("Congratulations!!! You guessed the number🥳😇🥳\n\n");
            return 0; // End the program after correct guess
        } 
        else if (number > random_number) {
            printf("Too high😕 Try a lower number.\n");
        } 
        else {
            printf("Too low😟☹. Try a higher number.\n");
        }
        
        guessCount++; // Increment guess count after each guesses
    
}
    

        printf("Sorry😥 you've used all your guesses. The correct number is: %d\n", random_number);
    

    return 0;
}
