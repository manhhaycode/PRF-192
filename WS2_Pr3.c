#include<stdio.h>
int main(){
	int n, s=0;
	do{
		printf("Enter number:");
		scanf("%d",&n);
		if(n!=0){
			s = s+n;
		}
	} while(n!=0);
	printf("Sum: %d",s);
	return 0;
}
