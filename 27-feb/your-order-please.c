#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *order_words (char *ordered, const char *words);

int main() {
    const char words[] = "is2 Thi1s T4est 3a";
    char *ordered = (char*)calloc(strlen(words) + 1, sizeof(char));
    // address pointed by ordered is written, then the same address pointed to ordered is assigned to ordered
    // so nothing changes
    ordered = order_words(ordered, words);
    printf("%s\n", ordered);
    return 0;
}

char *order_words(char *ordered, const char *words)
{
    // write to ordered and return it
    // the size of 'ordered' is equal to 1 + strlen(words)
    int count = 1;
    char char_count = '1';
    int pos_in_words = 0; 
    int pos_in_ordered = 0;
    int len = strlen(words) + 1;

    while (pos_in_ordered < len) {
        char_count = count + '0';
        if (words[pos_in_words] == char_count) {
            if (pos_in_words != 0) {
                while (words[pos_in_words] != ' ') {
                    pos_in_words--;
                }
                pos_in_words++;
                while (words[pos_in_words] != ' ') {
                    ordered[pos_in_ordered] = words[pos_in_words];
                    pos_in_words++;
                    pos_in_ordered++;
                }
                ordered[pos_in_ordered] = ' ';
                count++;
                pos_in_words = 0;
            } else {
                while (words[pos_in_words] != ' ') {
                    ordered[pos_in_ordered] = words[pos_in_words];
                    pos_in_words++;
                    pos_in_ordered++;
                    pos_in_words = 0;
                }
            }
            
        } else {
            pos_in_words++;
        }
    }
	*ordered = '\0';
	return ordered;
}