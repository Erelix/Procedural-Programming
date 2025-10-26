#include <stdio.h>

int the_num = 123456;

int getPositiveNumber(char *msg){
	int user_input;
	printf("\n%s %d:\n", msg, the_num);
	
	scanf("%d", &user_input);
		if(the_num != user_input)
			getPositiveNumber(msg);
		else
			return(user_input);
}

int main(){
	
	int result;
	
	printf("\nPrograma praso vartotojo ivesti %d, tol kol jis sio skaiciaus neiveda. Kai iveda, tada atspausdina ta skaiciu, kuri reikejo ivesti\n\n", the_num);
	
	char msg[] = "Prasome ivesti skaiciu";
	result = getPositiveNumber(msg);
	
	printf("\n%d", result);
	
	printf("\n\nPrograma baigesi.");
	
	return 0;
}