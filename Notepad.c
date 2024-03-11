

// #include <stdio.h>
// #include <stdlib.h>

// int main() {
//     char filename[100];
//     char text[1000];

//     printf("Enter the file name to save: ");
//     scanf("%s", filename);
//     printf("Enter text (press Ctrl + c to save and exit): \n");

//     char ch;
//     int i = 0;
//     while ((ch = getchar()) != EOF && i <sizeof(text) -1) {
//         text[i++] = ch;
//     }
//     text[i] = '\0';

//     FILE *file = fopen(filename, "w");
//     if (file != NULL) {
//         printf("Error opening file.\n");
//         return 1;
//     }

//     fputs(text, file);
//     fclose(file);
//     printf("Text saved to %s\n", filename);
//     return 0;

// }
#include <stdio.h>
#include <stdlib.h>

#define MAX_FILENAME_LENGTH 100
#define MAX_TEXT_LENGTH 1000

int main() {
    char filename[MAX_FILENAME_LENGTH];
    char text[MAX_TEXT_LENGTH];

    printf("Enter the file name to open or create: ");
    scanf("%s", filename);

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        // File does not exist, create it for writing
        file = fopen(filename, "w");
        if (file == NULL) {
            printf("Error opening file for writing.\n");
            return 1;
        }
        printf("File created successfully.\n");
    } else {
        // File exists, open for appending
        file = fopen(filename, "a");
        if (file == NULL) {
            printf("Error opening file for appending.\n");
            return 1;
        }
        printf("File opened successfully. Editing existing content...\n");
        printf("Existing content:\n");
        // Read and display existing content line by line
        while (fgets(text, MAX_TEXT_LENGTH, file) != NULL) {
            printf("%s", text);
        }
    }

    // Prompt user to enter text to append
    printf("\nEnter text to append (press Ctrl + c to save and exit):\n");
    while (fgets(text, MAX_TEXT_LENGTH, stdin) != NULL) {
        // Write text to file
        fputs(text, file);
    }

    // Close the file
    fclose(file);
    printf("Text appended to %s\n", filename);
    return 0;
}
