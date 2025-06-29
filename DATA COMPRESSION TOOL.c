#include <stdio.h>
#include <string.h>

void runLengthEncode(const char *input, char *output) {
    int count, i = 0, j = 0;
    int len = strlen(input);

    while (i < len) {
        output[j++] = input[i];
        count = 1;

        // Count consecutive same characters
        while (i + 1 < len && input[i] == input[i + 1]) {
            count++;
            i++;
        }

        // Convert count to string and append
        if (count > 1) {
            j += sprintf(&output[j], "%d", count);
        }

        i++;
    }

    output[j] = '\0'; // Null-terminate the output string
}

int main() {
    char input[1000], output[1000];

    printf("Enter a string to compress (no spaces): ");
    scanf("%s", input);

    runLengthEncode(input, output);

    printf("Compressed string (RLE): %s\n", output);

    return 0;
}
