#include <stdio.h>
#define MIN_WHOLE -999999
#define MAX_WHOLE 9999999

int main(){
	int a = 0;
	int b = 0;
	int c = 0;
	int z = 0;
	int i = 0;


	//Prasoma a ivestis (validacija)
	printf("\nPrograma is userio papraso 3 sveiku skaiciu. Juos gavus, bus atspausdinti visi teigiami sveiki skaiciai is intervalo (a;b], kurie dalijasi is skaiciaus c su liekana 1");
	printf("\n\nPrasome ivesti 3 sveikus skaicius a, b, c:\n");
	while(z == 0){
		printf("a: ");
		if (scanf("%d", &a) == 1 && a >= MIN_WHOLE && a <= MAX_WHOLE && getchar() == '\n'){
			printf("a ivestis issaugota (a = %d)\n", a);
			++z;
		}else{
			printf("a ivestis neissaugota, neatitinka reziu [%d;%d], prasome ivesti sveika skaiciu atitinkanti rezius.\n", MIN_WHOLE, MAX_WHOLE);
			while(getchar() != '\n')
				;
		}
	}
	
	//Prasoma b ivestis (validacija)
	z = 0;
	while(z == 0){
		printf("b: ");
		if (scanf("%d", &b) == 1 && b >= MIN_WHOLE && b <= MAX_WHOLE && getchar() == '\n'){
			printf("b ivestis issaugota (b = %d)\n", b);
			++z;
		}else{
			printf("b ivestis neissaugota, neatitinka reziu [%d;%d], prasome ivesti sveika skaiciu atitinkanti rezius.\n", MIN_WHOLE, MAX_WHOLE);
			while(getchar() != '\n')
				;
		}
	}
	
	//prasoma c ivestis
	z = 0;
	while(z == 0){
		printf("c: ");
		if (scanf("%d", &c) == 1 && c >= MIN_WHOLE && c <= MAX_WHOLE && getchar() == '\n'){
			printf("c ivestis issaugota (c = %d)\n", c);
			++z;
		}else{
			printf("c ivestis neissaugota, neatitinka reziu [%d;%d], prasome ivesti sveika skaiciu atitinkanti rezius.\n", MIN_WHOLE, MAX_WHOLE);
			while(getchar() != '\n')
				;
		}
	}
	
	// jeigu b < a
	if (b < a){
		printf("\nSkaicius a didesnis uz skaiciu b, gaunasi neteisingas intervalas (%d;%d]", a, b);
		return 0;
	}
	
	if(a > i)
		i = a;
	
	//rezultatai
	printf("\n\nVisi teigiami sveiki skaiciai reziuose (%d;%d], kurie dalinasi is skaiciaus %d su liekana 1:\n", a, b, c);
	for(; i < b; ){
		if(++i % c == 1)
			printf("%d ", i);
	}
	
	return 0;	
}