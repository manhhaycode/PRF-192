#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
double num1, num2;
char  op;
double result;
 printf("Enter expression: ");
 scanf("%lf%c%lf", &num1, &op, &num2);
 switch(op)
 {    case '+' : result = num1 + num2;
                 printf("Result = %3lf",result);
                 break;
      case '-' : result = num1 - num2;
                 printf("Result = %3lf",result);
                 break;
      case '*' : result = num1 * num2;
                 printf("Result = %3lf",result);
                 break;
      case '/' : if ( num2==0){
                 printf("Devide by 0");
             	 } else{
                    result = num1 / num2;
                    printf("Result = %3lf",result);
                 }
	  default: break;	              
}
	return 0;
}
