#include <stdio.h>

int isInRange(int number, int low, int high){
	int true_or_false = 0;
	if(low <= high && number <= high && number >= low){
		true_or_false = 1;
	}
	return(true_or_false);
}

int main(){
	
	int low_num;
	int high_num;
	int user_number;
	int result;
	
	printf("\nPrograma patikrina, ar duotas skaicius \"number\" papuola i nustatyta intervala [ low ; high ] ir atitinkamai atspausdina \"True\" ar \"False\"\n");
	printf("\nPrasome ivesti intervalo pirma rezi\nlow: ");
	scanf("%d", &low_num);
	
	printf("\nPrasome ivesti intervalo antra rezi\nhigh: ");
	scanf("%d", &high_num);
	
	printf("\nPrasome ivesti skaiciu, kuris bus patikrintas ar priklauso ivestam intervalui\nnumber: ");
	scanf("%d", &user_number);
	
	result = isInRange(user_number, low_num, high_num);
		
	
	if(result == 1)
		printf("\nTrue");
	else
		printf("\nFalse");
		
	printf("\n\nPrograma baigesi.");	
	
	return 0;
}