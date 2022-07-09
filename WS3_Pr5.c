#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int fibo(int n){
	int f = 1, t1 = 1, t2 = 1;
	for(int i = 3; i<=n; i++){
		f = t1 + t2;
		t1 = t2;
		t2 = f;
	}
	return f;
}


int main(int argc, char *argv[]) {
	int n;
    do{
    	printf("Enter n: ");
    	scanf("%d", &n);
    	if(n<1){
    		printf("n<1, Please enter again!!!\n");
		} 
    	
	} while(n<1);
	printf("Value at the n th position in Fibonacci sequence = %d", fibo(n));


	return 0;
}
