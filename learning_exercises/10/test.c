#include <stdio.h>
#include <string.h>

void transform(char *arr) {
    // Convert to lowercase and remove consecutive duplicates
    for (int i = 0; arr[i] != '\0'; ++i) {
        if (arr[i] >= 'A' && arr[i] <= 'Z') {
            arr[i] = arr[i] + 32;
        }
    }

    for (int i = 0; arr[i] != '\0'; ++i) {
        if (arr[i] == arr[i+1]) {
            int j = i;
            for (; arr[j] != '\0'; ++j) {
                arr[j] = arr[j+1];
            }
            --i; // Adjust i to recheck the current position
        }
    }

    // Replace certain characters with space
    for (int i = 0; arr[i] != '\0'; ++i) {
        if ((arr[i] >= 33 && arr[i] <= 47) || (arr[i] >= 58 && arr[i] <= 64) ||
            (arr[i] >= 91 && arr[i] <= 96) || (arr[i] >= 123 && arr[i] <= 126)) {
            arr[i] = 32;
        }
    }

    // Remove leading spaces
    while (arr[0] == 32) {
        for (int j = 0; arr[j] != '\0'; ++j) {
            arr[j] = arr[j + 1];
        }
    }

    // Remove trailing spaces
    for (int len_arr = strlen(arr); len_arr > 0 && arr[len_arr - 1] == 32; --len_arr) {
        arr[len_arr - 1] = '\0';
    }
}

int main() {
    char array[] = " 3axxUUOaa55;…;oiiii10\n";
    transform(array);
    printf("%s", array);

    return 0;
}
