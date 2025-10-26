#include <stdio.h>
#include <string.h>
#include <ctype.h>

//********************************************
//TODO kiekvienas skaitmuo pakeičiamas jį atitinkančiu vokiečių kalbos žodžiu (susiraskite!) iš mažųjų raidžių, prasidedančiu didžiąja
//TODO po kiekvieno žodžio įterpiamas skaičius, nurodantis jo ilgį pradinėje eilutėje, laikant kad žodis – tai raide prasidedanti raidžių bei skaitmenų seka
// … - BLOGAI konvertuoja
//***************************

void transform(char *arr) {
	
	for (int i = 0; arr[i] != '\0'; ++i) {
		if (arr[i] >= 65 && arr[i] <= 90) {
			arr[i] = arr[i] + 32;
        } else if (arr[i] >= 97 && arr[i] <= 122) {
			arr[i] = arr[i] - 32;
		}
	}
	
	for (int i = 0; arr[i] != '\0'; ++i) {
		if (arr[i] == arr[i+1]) {
			int j = i;
			for (; arr[j] != '\0'; ++j) {
				arr[j] = arr[j+1];
			}
		}
	}
	
	for (int i = 0; arr[i] != '\0'; ++i) {
		if (arr[i] >= 33 && arr[i] <= 47) {
			arr[i] = 32;
        } else if (arr[i] >= 58 && arr[i] <= 64) {
			arr[i] = 32;
		} else if (arr[i] >= 91 && arr[i] <= 96) {
			arr[i] = 32;
		} else if (arr[i] >= 123 && arr[i] <= 126) {
			arr[i] = 32;
		}
	}
	
	while (isspace(arr[0])) {
		for (int j = 0; arr[j] != '\0'; ++j) {
			arr[j] = arr[j + 1];
		}
	}

	for (int len_arr = strlen(arr); len_arr > 0 && isspace(arr[len_arr - 1]); --len_arr) {
		arr[len_arr-1] = '\0';
	}
	
}

int main() {
    char array[] = "    13waHIEWUH aa df ff bb ODWfekj f  s;w'a;d*&^#@&(%^&!@*()   ";
    transform(array);
    printf("%s", array);

    return 0;
}
