#include <stdio.h>

int main(){
	
	int user_input;
	
	scanf("%d", &user_input);
	printf("Skaicius yra %s", user_input == 0 ? "nei lyginis, nei nelyginis" : ((user_input%2) == 0 ?  "lyginis" : "nelyginis"));
	
  return 0;
}