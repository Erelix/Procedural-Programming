#include <stdio.h>
#include <math.h>

#define MIN_WHOLE -999999
#define MAX_WHOLE 9999999

int main(){
	int a = 0;
	int b = 0;
	int c = 0;
	int z = 0;
	double x;
	double x1;
	double x2;
	double discriminant;
	
	//Prasoma a ivestis (validacija)
	printf("\nPrograma is userio papraso 3 sveiku skaiciu ir su jais paskaiciuja x reiksmes kvadratineje lygtije ax^2 + bx + c = 0\n");
	printf("\n\nPrasome ivesti 3 sveikus skaicius a, b, c:\n");
	while(z == 0){
		printf("a: ");
		if (scanf("%d", &a) == 1 && a>= MIN_WHOLE && a <= MAX_WHOLE && getchar() == '\n'){
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
		if (scanf("%d", &b) == 1 && b>= MIN_WHOLE && b <= MAX_WHOLE && getchar() == '\n'){
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
		if (scanf("%d", &c) == 1 && c>= MIN_WHOLE && c <= MAX_WHOLE && getchar() == '\n'){
			printf("c ivestis issaugota (c = %d)\n", c);
			++z;
		}else{
			printf("c ivestis neissaugota, neatitinka reziu [%d;%d], prasome ivesti sveika skaiciu atitinkanti rezius.\n", MIN_WHOLE, MAX_WHOLE);
			while(getchar() != '\n')
				;
		}
	}
	if (a == 0){
		printf("\nDalyba is nulio negalima, kadangi a = 0\n");
		return 0;
	}
	
	//diskriminantas
	discriminant = b * b - 4 * a * c; 
	printf("\nD = %lf\n", discriminant);
	
	// gautos x reiksmes
	if (discriminant < 0 )
		printf("\nDiskriminantas neigiamas, todel sprendiniu nera");
	else if(discriminant == 0){
		
		x = -b / (2 * a);
		printf("\nDiskriminantas lygus nuliui, todel yra tik vienas sprendinys x = %f", x);
	}else if (discriminant > 0){
		x1 = (-b+sqrt(discriminant)) / (2 * a);
		x2 = (-b-sqrt(discriminant)) / (2 * a);
		printf("\nDiskriminantas yra teigiamas, todel yra 2 sprendiniai:\nx1 = %f\nx2 = %f", x1, x2);
	}	
	return 0;
}