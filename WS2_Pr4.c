#include<stdio.h>

int main(){
	int x,y;
	do{
		printf("Enter x: ");
		scanf("%d", &x);
		int t = x;
		printf("Enter y: ");
		scanf("%d", &y);
		if(x==0 || y==0){
			break;
		}
		x = y;
		y = t;
		printf("x = %d", x);
		printf(" y = %d\n", y);
	} while(x!=0 && y!=0);
	return 0;
}
