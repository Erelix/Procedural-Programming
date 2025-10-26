#include <stdio.h>
#define MAX_NATURAL 99999999

int main(){
	int a = 0;
	int b = 0;
	int c = 0;
	int z = 0;
	int j;
	int min;
	int max;
	int dbd = 0;
	int mbk = 0;


	//Prasoma a ivestis (validacija)
	printf("\nPrograma is userio papraso 3 naturaliu skaiciu. Juos gavusi, programa atspausdins siu skaiciu didziausia bendra dalikli(DBD) bei maziausia bendra kartotini(MBK).");
	printf("\n\nPrasome ivesti 3 naturlius skaicius a, b, c:\n");
	while(z == 0){
		printf("a: ");
		if (scanf("%d", &a) == 1 && a >= 0 && a <= MAX_NATURAL && getchar() == '\n'){
			printf("a ivestis issaugota (a = %d)\n", a);
			++z;
		}else{
			printf("a ivestis neissaugota, neatitinka reziu [0;%d], prasome ivesti naturalu skaiciu atitinkanti rezius.\n", MAX_NATURAL);
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
			printf("b ivestis neissaugota, neatitinka reziu [0;%d], prasome ivesti naturalu skaiciu atitinkanti rezius.\n", MAX_NATURAL);
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
			printf("c ivestis neissaugota, neatitinka reziu [0;%d], prasome ivesti naturalu skaiciu atitinkanti rezius.\n", MAX_NATURAL);
			while(getchar() != '\n')
				;
		}
	}
	
	//min ir max nustatymas
	switch(a > b){
		case 0: {
			switch(a > c){
				case 0:{
					min = a;
					switch(b > c){
						case 0: 
							max = c;
							goto further_on;
						case 1: 
							max = b; 
							goto further_on;
					}
				}
				case 1:{
					min = c;
					max = b;
					goto further_on;
				}
			}
		}
		case 1: {
			switch(a > c){
				case 0: {
					min = b;
					max = c;
					goto further_on;
				}
				case 1:{
					max = a;
					switch(b > c){
						case 0: 
							min = b;
							goto further_on;
						case 1:
							min = c;
							goto further_on;
					}
				}
			}
		}
	}
	
	further_on:
	
	printf("\n--------------------------------------------------------------");
	printf("\n\nNaturliu skaiciu (%d, %d, %d) didziausias bendras daliklis bei maziausias bendras kartotinis:\n", a, b, c);
	
	//DBD nustatymas ir atspausdinimas
	for(int i = 1; i <= max; ++i){
		if ((a%i == 0) && (b%i == 0) && (c%i == 0)){
			dbd = i;
		}

	}
	printf("\nDBD = %d", dbd);
	
	
	if (min == 0){
		printf("\nNulis neturi kartotiniu");
		return 0;
	}
	
	//MBK nustatymas ir atspausdinimas
	for(j = max; mbk == 0 && j < MAX_NATURAL; ++j){
		if ((j%a == 0) && (j%b == 0) && (j%c == 0)){
			mbk = j;
			
			printf("\nMBK = %d", mbk);
			return 0;
		}
	}
	if (j == MAX_NATURAL)
		printf("\nVirsyta talpa. MBK neisvedamas, kai MBK bus didesnis ar lygus %d", MAX_NATURAL);
	return 0;
	
}