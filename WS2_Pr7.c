#include<stdio.h>


 int main(){
	char c1, c2;
	int d;
    printf("Enter character 1: ");
	scanf("%c", &c1);
	getchar();
	printf("Enter character 2: ");
	scanf("%c", &c2);
	getchar();
	
	if(c1>c2){
		int t = c1;
		c1 = c2;
		c2 = t;
	}
	d= c2-c1;
	printf("Range: %d\n\n", d);
	for(int e = c1; e<=c2; e++){
		printf("%c : %d, %o, %X\n", e, e, e, e);
	}
} 
