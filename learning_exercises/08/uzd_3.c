#include <stdio.h>

void swap(int *x, int *y){
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

int main(){
	int x, y;
	printf("Programa ivestus 2 sveikuosius kintamuosius sukeicia vietomis.\n");
	
	printf("\nx: ");
	scanf("%d", &x);
	
	printf("\ny: ");
	scanf("%d", &y);
	
	swap(&x, &y);
	
	printf("\n%d %d", x, y);
	
	printf("\n\nPrograma baigesi.");
	
	return 0;
}