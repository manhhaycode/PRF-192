#include <stdio.h>
#include <stdlib.h>

int isFibonacci(int n){
	int f = 1, t1 = 1, t2 = 1;
	while(f<n){
		f = t1 + t2;
		t1 = t2;
		t2 = f;
	}
    if (n == f){
    	return 1;
	} else return 0;
		
	}
	

int main(int argc, char *argv[]) {
	int n;

		do{
		printf("Enter n >= 1: ");
		scanf("%d", &n);
		if(n<1){
			printf("You entered a number less than 1, please try again!!!\n");
		}
	}while (n<1);

	if (isFibonacci(n)){
		printf("%d is Fibo element!!!\n", n);
	} else printf("%d isn't Fibo element!!!\n", n);
	
	

	return 0;
}
