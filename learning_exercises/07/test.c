#include<stdio.h>
#include<time.h>

void myFunction()
{
    time_t t;
    t = time(NULL);
    struct tm tm = *localtime(&t);
	printf("Siandienos date: ");
    printf("%d-%d-%d", tm.tm_year+1900, tm.tm_mon+1, tm.tm_mday);
}

int main(){
	
	myFunction();
	return 0;
}
