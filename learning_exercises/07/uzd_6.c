#include <stdio.h>

int showMenu(char *menuTitle, char *menuOptions[], int menuSize, char *inputMsg){
	int user_input;
	
	printf("\n%s\n\n", menuTitle);
	
	for (int i = 0; i < menuSize; ++i){
		int a = i+1;
		printf("%d. %s\n",a, menuOptions[i]);		
	}
		
	printf("\n%s", inputMsg);
	scanf("%d", &user_input);
	
	if(user_input > 0 && user_input <= menuSize){
		--user_input;
		return(user_input);
	}else
		showMenu(menuTitle, menuOptions, menuSize, inputMsg);
}

int main(){
	int size = 4;
	char * menu[4] = {"Cepelinai", "Balandeliai", "Guliasas", "Varskeciai"};
	
	char menu_name[] = "Dienos pietus";
	char msg[] = "Prasome ivesti pasirinkto patiekalo numeri: ";
	
	int result = showMenu(menu_name, menu, size, msg);
	
	printf("\nPasirinktas patiekalas:\n");
	printf("%d. %s", result+1, menu[result]);
	
	printf("\n\nPrograma baigesi.");
	
	return 0;
}