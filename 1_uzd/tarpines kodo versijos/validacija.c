#include <stdio.h>
int main()
{
	int i = 0;
    char str[20];
    printf("Skaicius:");
	scanf("%s",&str);
	
	if(str[0] == 45){
		++i;
		printf("skaicius neigiamas\n");
	}
	
    for (; str[i] != '\0'; ++i) { 
        if (str[i]>=48 && str[i]<=57) {
			printf("%c = %d\n", str[i], str[i]);

        }else{
			printf("%c = %d NETINKA\n", str[i], str[i]);
		}
		
    }
    return 0;
}