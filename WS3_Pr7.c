#include <stdio.h>
#include <stdlib.h>

int sumDigits(int n){
	int S = 0, remainder;
	
	do{
			remainder = n%10;
			n = n/10;
			S += remainder;
	} while(n>0);
	
	return S;
}

int main(int argc, char *argv[]) {
	int n, S;
	
	do{
		printf("Enter n >= 0: ");
		scanf("%d", &n);
		if (n<0){
			printf("You entered n < 0, please try again!!!\n");
		}
	} while(n<0);
	
	S = sumDigits(n);
	printf("Sum digits of %d is: %d", n, S);
	
	return 0;
}
