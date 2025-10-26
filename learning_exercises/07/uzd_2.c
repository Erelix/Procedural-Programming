#include <stdio.h>

#define MAX_FAC_NUM 12

//Su rekursija
int factorial = 0;

int getFactorial(int number){
	if(number > 0 && number <= MAX_FAC_NUM){
		if(factorial == 0)
			++factorial;
			
		factorial *= number--;
		getFactorial(number);
	}else
		return(factorial);
}

//Be rekursijos
int getFactorialOther(int number){
	int factorial = 0;
	if(number > 0 && number <= MAX_FAC_NUM){
		if(factorial == 0)
			++factorial;
		
		for(; number > 0; --number)
			factorial *= number;
	}
   return(factorial);
}

int main(){
	
	int user_input;
	int factorial_1;
	int factorial_2;
	
	printf("\nPrograma apskaiciuoja ivesto skaiciaus faktoriala. Jei jo apskaiciuoti negalima - grazina 0. Tai daro su viena funkcija, kurioje naudojama rekursija ir su kita funkcija, kurioje nera naudojama rekursija.\n");
	
	printf("\nPrasome ivesti skaiciu: ");
	scanf("%d", &user_input);
	
	factorial_1 = getFactorial(user_input);
	factorial_2 = getFactorialOther(user_input);
	
	printf("\n\nSu rekursija: %d", factorial_1);
	printf("\nBe rekursijos: %d", factorial_2);
	
	
	printf("\n\nPrograma baigesi.");
	
	return 0;
}