#include <stdio.h>
#include <math.h>

int processX(int x){
	int primal = 1; 
  
    for (int i = 2; i <= x / 2; i++) { 
        if (x % i == 0) { 
            primal = 0; 
            break; 
        } 
    } 
  
    if (primal) { 
		isAbove20:
		while (x > 20) {
			minus7: 
			x -= 7;	
		}
		
		if (x >= 0)
			x = sqrt(x);
		
		if ((x % 2) == 0){
			goto minus7;
		} else {
			return (x*x + x - 4); 
		}
		
    } else { 
		int mul_3 = 1;
		int counter = 0;
		
		for (int i = 1; (i <= x) && (counter < 3); ++i) {
			if ((x % i) == 0) {
				mul_3 = mul_3*i;
				++counter;
			}
		}
		x = mul_3;
		goto isAbove20;     
	} 
}

int main(){
	int x = 8;
	printf("x = %d ", x);
	x = processX(x);
	printf("\nGautas skaicius ( %d )", x);

	return 0;
}
