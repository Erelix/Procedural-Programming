#include <stdio.h>

int main(){
	/*
	int number;
	int remnant;
	int digit;
	
	scanf("%d",&number);
	
	do{
		if(number%2==0){
			printf("Skaiciuje nera '1'.\t");
			printf("Skaicius\t( %d )\tlyginis, todėl daliname is 2\n",number);
			number/=2;
		
			}else(){
				printf("Skaiciuje nera '1'.\t");
				printf("Skaicius\t ( %d )\tnelyginis, todėl dauginame is 3 pridedame 1.\n");
				number= 3*number+1;
			}
	

	}
	
	
	
	
	}*/
	
	
	int number = 810;
	int b;
	int c = 0;
	int i = 0;

	while(i<1){
		
		for(b=number; b!=0; b = b/10){
			c = b%10;
				if(c==1){
					i++;
					

					
				}else{
					printf("c nepadidejo \n");
				}
				printf("%d\n%d\n%d\n%d\n",number,b,c,i);
				
		}if(i>0){
			printf("Skaiciuje yra skaitmuo 1");
			
			
		}else{
			printf("Skaiciuje nera '1'.\n");
			if(number%2==0){
				
				printf("Skaicius\t( %d )\tlyginis, todel daliname is 2\n",number);
				number = number/2;
		
			}else{
				
				printf("Skaicius\t ( %d )\tnelyginis, todel dauginame is 3 bei pridedame 1.\n",number);
				number= 3*number+1;
			}
		
			
			
		}
	}return 0;
	printf("Skaicius turi savyje 1, todel seka baigesi\n");
	
	printf("%d\n",number);
	
	
}