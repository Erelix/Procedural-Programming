#include <stdio.h>
#define MAX_NATURAL 9999999

int main(){
	int a = 0;
	int b = 0;
	int c = 0;
	int z = 0;
	int temp_b_saver;


	//Prasoma a ivestis (validacija)
	printf("\nPrograma is userio papraso 3 neneigiamu sveiku skaiciu. Ir atspausdina fc, kur fc yra c-asis fibonacio sekos skaicius, o f0 = a bei f1 = b.");
	printf("\n\nPrasome ivesti 3 neneigiamus sveikuosius skaicius a, b, c:\n");
	while(z == 0){
		printf("a: ");
		if (scanf("%d", &a) == 1 && a >= 0 && a <= MAX_NATURAL && getchar() == '\n'){
			printf("a ivestis issaugota (a = %d)\n", a);
			++z;
		}else{
			printf("a ivestis neissaugota, neatitinka reziu [0;%d], prasome ivesti sveika neneigiama skaiciu atitinkanti rezius.\n", MAX_NATURAL);
			while(getchar() != '\n')
				;
		}
	}
	
	//Prasoma b ivestis (validacija)
	z = 0;
	while(z == 0){
		printf("b: ");
		if (scanf("%d", &b) == 1 && b >= 0 && b <= MAX_NATURAL && getchar() == '\n'){
			printf("b ivestis issaugota (b = %d)\n", b);
			++z;
		}else{
			printf("b ivestis neissaugota, neatitinka reziu [0;%d], prasome ivesti sveika neneigiama skaiciu atitinkanti rezius.\n", MAX_NATURAL);
			while(getchar() != '\n')
				;
		}
	}
	
	//prasoma c ivestis
	z = 0;
	while(z == 0){
		printf("c: ");
		if (scanf("%d", &c) == 1 && c >= 0 && c <= MAX_NATURAL && getchar() == '\n'){
			printf("c ivestis issaugota (c = %d)\n", c);
			++z;
		}else{
			printf("c ivestis neissaugota, neatitinka reziu [0;%d], prasome ivesti sveika neneigiama skaiciu atitinkanti rezius.\n", MAX_NATURAL);
			while(getchar() != '\n')
				;
		}
	}
	
	//apskaiciuojama fc
	int temp_b = b;
	int temp_a = a;
	
	for (int i = 1; i < c; ++i){
		temp_b_saver = temp_b;
		temp_b = temp_a + temp_b;
		temp_a = temp_b_saver;

	}
	
	//rezultatai
	printf("\n\n---------------------------------------------------\n");
	printf("%d - asis fibonacio sekos skaicius, kai f0 = %d, o f1 = %d:\n", c, a, b);
	printf("\nf%d = %d", c, temp_b);
	
	
	return 0;
	
}