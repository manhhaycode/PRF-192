#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void printFibo(int n){
	int f = 1, t1 = 1, t2 = 1;
	for(int i = 1; i<=n; i++){
		if(i<=2){
		printf("1 ");   	
		} else{

		f = t1 + t2;
		printf("%d ",f);
		t1 = t2;
		t2 = f;
		}
	}

}


void Pr1() {
	int n;
    do{
    	printf("Enter n: ");
    	scanf("%d", &n);
    	if(n<1){
    		printf("n<1, Please enter again!!!\n");
		} 
    	
	} while(n<1);
	printf("The first %d Fibonacci numbers: ", n);
	printFibo(n);
    printf("\n");
}
