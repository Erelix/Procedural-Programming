#include <stdio.h>

// Funkcija uzpildanti i desine
int myRightFill(int num, int filler, int current_column, int current_row, int till_column, int (*arr)[num]){
	for (int i = current_column; i < till_column; ++i){
		++filler;
		arr[i][current_row] = filler;
	}
   return(filler);
}

// Funkcija uzpildanti i apacia
int myDownFill(int num, int filler, int current_column, int current_row, int till_line, int (*arr)[num]){
	for (int i = current_row; i < till_line; ++i){
		++filler;
		arr[current_column][i] = filler;
	}
   return(filler);
}

// Funkcija uzpildanti i kaire
int myLeftFill(int num, int filler, int current_column, int current_row, int zero_column, int (*arr)[num]){
	for (int i = current_column; i >= zero_column; --i){
		++filler;
		arr[i][current_row] = filler;
	}
   return(filler);
}

// Funkcija uzpildanti i virsu
int myUpFill(int num, int filler, int current_column, int current_row, int zero_row, int (*arr)[num]){
	for (int i = current_row; i >= zero_row; --i){
		++filler;
		arr[current_column][i] = filler;
		
	}
   return(filler);
}

// 10
int main(){
	int a = 0;
	int user_input;
	int square_user_input;
	int num;
	int current_num = 0;
	
	//Prasomas inputas / validacija
	printf("\nPrograma papraso vartotojo sveiko skaiciaus. Ji gavusi, uzpildo matrica N*N sveikais skaiciais 1, 2, 3, ..., surasytais spirale.\n\n");
	
	while(a == 0){
		printf("\nPrasome ivesti sveika skaiciu: ");
		if((scanf("%d", &user_input) == 1) && (getchar() == '\n')){
			printf("Ivestis issaugota. Jusu skaicius ( %d )\n", user_input);
			a++;
		}else{
			printf("Netinkama ivestis. Prsome ivesti sveika skaiciu.\n");
		
			while(getchar() != '\n')
				;
		}
	}
	if(user_input <= 269 && user_input >= -269){
	
		square_user_input = user_input * user_input;
	
		// Jei neigiamas, tai pakeiciamas zenklas
		if(user_input < 0)
			num = -user_input;
		else
			num = user_input;
	
	
		int matrix[num][num];
		int till_c = num;
		int till_l = num;
		int column = 0;
		int row = 0;
		int zero_column = 0;
		int zero_row = 0;
	
		// Pildymo ciklas
		while(current_num < square_user_input){	
			if(current_num < square_user_input){
				current_num = myRightFill(num, current_num, column, row, till_c, matrix);
				 ++zero_row;
				  column = --till_c;
				   ++row;
			}
			if(current_num < square_user_input){
				current_num = myDownFill(num, current_num, column, row, till_l, matrix);
				 --column;
				  row = --till_l;
			}
			if(current_num < square_user_input){
				current_num = myLeftFill(num, current_num, column, row, zero_column, matrix);
				 column = zero_column;
				  ++zero_column;
				   row = till_l-1;
			}
			if(current_num < square_user_input){
				current_num = myUpFill(num, current_num, column, row, zero_row, matrix);
				 row = zero_row;
				  column = zero_column;
			}
		}
	
		// Matricos isvedimas
		printf("\n\nGauta matrica:\n");
		for (int i = 0; i < num; ++i){
			for (int j = 0; j <num; ++j)
				printf("%6d ", matrix[j][i]);
			printf("\n");
		}
	
	}else
		printf("\nMatrica nebetelpa i ekrana, todel bus neteisingai atspausdinta...");
	
	printf("\n\nPrograma baigesi.");
	
   return 0;
}	



