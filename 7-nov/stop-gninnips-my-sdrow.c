#include <stdio.h>
#include <string.h>

void spin_words(const char *sentence, char *result);

int main()
{
    const char sentence[] = "Hey wollef sroirraw";
    // printf("%ld\n", strlen(sentence));
    // strlen only return length of the string excluding the null pointer
    char result[strlen(sentence) + 1];  // Allocate with space for the null terminator
    spin_words(sentence, result);
    printf("%s\n", result);

    return 0;
}

// constant data, modifiable pointer
void spin_words(const char *sentence, char *result) {
    int len = strlen(sentence);
    int c = 0;         // Current position in sentence
    int res_pos = 0;   // Current position in result

    while (c < len) {
        int word_start = c;

        // Find the end of the current word
        while (c < len && sentence[c] != ' ') {
            c++;
        }
        int word_length = c - word_start;

        // Reverse if word length is 5 or more, otherwise copy directly
        if (word_length >= 5) {
            for (int i = 0; i < word_length; i++) {
                result[res_pos] = sentence[word_start + word_length - 1 - i];
                res_pos++;
            }
        } else {
            for (int i = 0; i < word_length; i++) {
                result[res_pos] = sentence[word_start + i];
                res_pos++;
            }
        }

        // Add a space if we’re not at the end of the sentence
        if (c < len) {
            result[res_pos] = ' ';
            res_pos++;
            c++;  // Move past the space in the sentence
        }
    }

    result[res_pos] = '\0';  // Null-terminate the result string
}
