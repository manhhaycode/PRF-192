#include <stdio.h>
#include <stdlib.h>
void Pr1();
void Pr2();
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
		int chooseoption;
	
	do{		
	printf("1 - Fibonacci sequence\n");
	printf("2 - Check a date\n");
	printf("3 - Quit\n");
	printf("Select an operation: ");
   	scanf("%d", &chooseoption);
	
		switch(chooseoption){
			case 1: Pr1();
			        break;
			        
			case 2: Pr2();
			        break;
			        
			case 3:	break;
							        
			default: break;
		}
		
	} while (chooseoption>=1&&chooseoption<3);
	
	return 0;
}
