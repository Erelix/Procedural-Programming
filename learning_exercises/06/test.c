#include <stdio.h>
#include <math.h>

#define MIN 10
#define MAX 1000

// Function to clear the input buffer
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    double num, before_comma;
    double after_comma = 1;
    int counter = 0;
    int digit_counter = 0;
    int end = 0;
    int num_int;
    FILE *inFile;
    int a = 0;
    char file_name[100];

    printf("Programa paima is in.txt irasyta realuji skaiciu ir patikrina ar jis ne mazesnis uz 10 ir ne didesnis uz 1000 bei ar su ne daugiau kaip 3 skaiciais po kablelio, jeigu ivestas skaicius neatitinka siu reikalavimu, yra prasoma pavadinimo txt failo, kur jau yra skaicius atitinkantis siuos reikalavimus\n\n");

    while (end == 0) {
        while (a == 0) {
            printf("\nPrasome ivesti failo varda, kuris bus skaitomas: ");
            if (scanf("%99s", file_name) == 1) {
                clearInputBuffer(); // Clear the rest of the input buffer
                inFile = fopen(file_name, "r");
                if (inFile == NULL) {
                    printf("\nToks failas neegzistuoja.");
                } else {
                    printf("\nFailas rastas\n");
                    ++a;
                }
            } else {
                printf("\nBloga ivestis.");
                clearInputBuffer(); // Clear the input buffer
            }
        }

        if (a == 1 && fscanf(inFile, "%lf", &num) == 1) {
            printf("\n%lf", num);

            if ((num > MIN) && (num < MAX)) {
                after_comma = modf(num, &before_comma);

                while (after_comma != 0 && counter <= 3) {
                    num *= 10;
                    after_comma = modf(num, &before_comma);
                    printf("\npries %lf, po %lf", before_comma, after_comma);
                    ++counter;
                }

                if (counter <= 3) {
                    printf("\nSkaicius po kablelio neturi daugiau 3 skaiciu.");
                    printf("\n%lf", num);
                    num_int = num;

                    for (digit_counter = 0; num_int > 0; ++digit_counter) {
                        num_int /= 10;
                    }

                    printf("\nSkaicius turi tiek skaitmenu: %d", digit_counter);
                    ++end;
                } else {
                    printf("\nSkaicius turi daugiau nei 3 skaicius po kablelio.");
                }
            } else {
                printf("\nSkaicius neatitinka reziu (%d;%d)", MIN, MAX);
            }
        } else if (a == 1) {
            printf("\nFaile %s ivestas ne skaicius.", file_name);
        }

        fclose(inFile);
        clearInputBuffer(); // Clear the input buffer before the next iteration
        a = 0; // Reset the 'a' flag to allow for a new file input
    }

    return 0;
}
