#include <stdio.h>

#define MAX_WHOLE 9999999

int main(){

	int s = -1;
	int n = -1;
	int a = 0;

	int num = -1;
	int counter = 0;
	int icounter = 0;
	int jcounter = 0;
	
	printf("\nPrograma papraso vartotojo skaiciu s ir n, kur sveikas skaicius s (reziai [0;%d]) bus laikomas sandauga, kuria veliau bus atrenkamos skaiciu poros (xi, xj), o sveikas skaicius n (reziai [0;1000]) laikomas, kiek bus nuskaityta n teigiamu sveiku busimo masyvo x elementu. Siuos elementus uzpildo useris.\n", MAX_WHOLE);
	printf("\nPrasome ivesti du skaicius s ir n, kur s sveikas skaicius (reziai [0;%d]), o n sveikas skaicius (reziai [0;1000]):\n\n", MAX_WHOLE);
	
	// prasoma s ivestis (validacija)
	while(a == 0){
		printf("s: ");
		if (scanf("%d", &s) == 1 && s >= 0 && s <= MAX_WHOLE && getchar() == '\n'){
			printf("s ivestis issaugota (s = %d)\n", s);
			++a;
		}else{
			printf("s ivestis neissaugota, neatitinka reziu [0;%d], prasome ivesti sveika skaiciu atitinkanti rezius.\n", MAX_WHOLE);
			while(getchar() != '\n')
				;
		}
	}
	
	//prasoma n ivestis (validacija)
	a = 0;
	while(a == 0){
		printf("n: ");
		if (scanf("%d", &n) == 1 && n >= 0 && n <= 1000 && getchar() == '\n'){
			printf("n ivestis issaugota (n = %d)\n", n);
			++a;
		}else{
			printf("n ivestis neissaugota, neatitinka reziu [0;1000], prasome ivesti sveika skaiciu atitinkanti rezius.\n");
			while(getchar() != '\n')
				;
		}
	}
	
	int x[n];
	
	// prasomi ir validuojami n skaicius elementu

	printf("\n\nPrasome ivesti %d elementu(-us)(-a), kurie yra sveiki teigiami skaiciai tarp reziu (0;%d]\n", n, MAX_WHOLE);
	
	while(counter < n){  
	
	  printf("x%d: ", counter);
		if((scanf("%d", &num) == 1) && (getchar() == '\n')){
			if((num > 0) && (num <= MAX_WHOLE)){
				x[counter++] = num;
				printf("Skaicius ivestas teisingai (x%d = %d)\n\n", counter, num);	
			}else{
					printf("Virsyti masyvo reziai (0;%d]\n",MAX_WHOLE);
			}	
		}else{
			printf("Netinkama ivestis. Reikalingas teigiamas sveikas skaicius\n"); 
			while(getchar() != '\n')
				;
		}
	}
	
	//resultatas
	printf("\n\nVisos masyve esancios skaiciu poros (xi, xj), kad xi ir xj sanduga yra lygi s:\n");
	
	while (icounter < (n - 1)){
		jcounter = icounter + 1;
		while (jcounter < n){
			if((x[icounter] * x[jcounter]) == s){
				printf("(%d,%d) ", x[icounter], x[jcounter]);   
			}
			++jcounter;
		}
		++icounter;
	}
   
   return 0;
}