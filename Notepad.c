
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

        file = fopen(filename, "w");
        if (file == NULL) {
            printf("Error opening file for writing.\n");
            return 1;
        }
        printf("File created successfully.\n");
    } else {

        file = fopen(filename, "a");
        if (file == NULL) {
            printf("Error opening file for appending.\n");
            return 1;
        }
        printf("File opened successfully. Editing existing content...\n");
        printf("Existing content:\n");
  
        while (fgets(text, MAX_TEXT_LENGTH, file) != NULL) {
            printf("%s", text);
        }
    }

    printf("\nEnter text to append (press Ctrl + c to save and exit):\n");
    while (fgets(text, MAX_TEXT_LENGTH, stdin) != NULL) {
        // Write text to file
        fputs(text, file);
    }

    fclose(file);
    printf("Text appended to %s\n", filename);
    return 0;
}
