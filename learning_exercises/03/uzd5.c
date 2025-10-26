#include <stdio.h>
#include <math.h>

int main(){
	
	double x, y, z;
	double result_a;
	double result_b;
	
	scanf("%lf %lf %lf", &x, &y, &z);
	printf("%s", y < 0 ? "saknis is neigiamo skaiciaus negalima\n" : "\n");
		result_a = x + 4*y + pow(z,3);
		result_b = (x + sqrt(y)) * (pow(z,4) - fabs(z) + 46.3);
	
	printf("a) Ats.: %f\n", result_a);
	printf("b) Ats.: %f", result_b);
	
   return 0;
	
}