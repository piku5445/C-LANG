#include <stdio.h>
#include <string.h>
#include <stdio.h>
void countCharacters(const char *str) {
    int charCount[256] = {0}; // Array to count occurrences of each character (ASCII range)
    for (int i = 0; str[i] != '\0'; i++) {
        charCount[str[i]]++;
    }

    
    printf("Character counts:\n");
    for (int i = 0; i < 256; i++) {
        if (charCount[i] > 0) {
            printf("'%c': %d\n", i, charCount[i]);
        }
    }
}

int main() {
    char string[100];

    printf("Enter a string: ");
    scanf("%s",&string); // Read input string


    countCharacters(string);

    return 0;
}