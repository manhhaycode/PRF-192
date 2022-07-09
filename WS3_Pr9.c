#include <stdio.h>
#include <stdlib.h>
int gcd(int a, int b){
	while(a!=b){
		if (a>b){
			a = a-b;
		} else {
			b = b-a;
		}
	}
	return b;
}

int lcm(int a, int b){
	return a*b/gcd(a,b);
}

int main(int argc, char *argv[]) {
	int a, b;
	do{
		
		printf("Enter number a > 0 : ");
		scanf("%d", &a);
		printf("Enter number b > 0 : ");
		scanf("%d", &b);
		if (a<=0||b<=0){
			printf("You entered number <= 0, please try again!!!\n");
		} 
	} while(a<=0||b<=0);
    
    printf("GCD of %d and %d is: %d\n", a, b, gcd(a,b));
    printf("LCM of %d and %d is: %d\n", a, b, lcm(a,b));


}
