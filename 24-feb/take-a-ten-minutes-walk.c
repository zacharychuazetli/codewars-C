#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isValidWalk(const char *walk);

int main() {
    const char *walk = "nsnsnsnsnsns";
    bool output = isValidWalk(walk);
    printf("%d\n", output);
    return 0;
}
// input is a null-terminated string

bool isValidWalk(const char *walk) {
    int position[] = {0, 0};

    if (strlen(walk) == 10){
        while (*walk) {
            switch (*walk) {
                case 'n':
                    position[0]++;
                    break;
                case 's':
                    position[0]--;
                    break;
                case 'w':
                    position[1]++;
                    break;
                case 'e':
                    position[1]--;
                    break;
            }
            walk++;
        }
        if (position[0] == 0 && position[1] == 0) {
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }

}