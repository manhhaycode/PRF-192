#include<stdio.h>

int factorial(int n){
	int S = 1;
	for(int i = 2; i<=n; i++){
		S = S*i;
	}
	return S;
}




int main(){
	int n;
	do{
	printf("Enter n >= 0: ");
	scanf("%d", &n);
	if(n<0){
		printf("n < 0, please enter n again!!!\n");
	}
		} while(n<0);	
    printf("Factorial %d! = %d",n, factorial(n));
	
}
