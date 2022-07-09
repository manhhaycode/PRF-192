#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void quadraticEquation(float a, float b, float c){
	int x, x1, x2, delta;
	delta = pow(b,2) - 4*a*c;
	if(a==0){
		
		if(b==0 && c==0){
			printf("Day la phuong trinh bac nhat, phuong trinh co vo so nghiem\n");	
		}
		
		if(b==0 && c!=0){
			printf("Day la phuong trinh bac nhat, phuong trinh vo nghiem\n");
		}
		
		if(b!=0){
			printf("Day la phuong trinh bac nhat, phuong trinh co nghiem x = %f\n", (c/b == 0 )? 0: -c/b);
		}		
		
	} else {
		
		if(delta < 0){
			printf("Phuong trinh vo nghiem\n");
		}
		
		if(delta == 0){
			printf("Phuong trinh co nghiem kep x1 = x2 = %f\n", (b/(2*a) == 0)? 0: -b/(2*a));
		}
		
		if(a!=0 && delta > 0){
			printf("Phuong trinh co 2 nghiem phan biet x1 = %f, x2 = %f\n", (-b+sqrt(delta))/2*a, (-b-sqrt(delta))/2*a);
		}

	}
}

void bankDeposit(){
  int n;
  double d, amount, r;
  do{
		printf("Enter deposit: ");
		scanf("%lf", &d);
		fflush(stdin);
		printf("Enter yearly rate: ");
		scanf("%lf", &r);
		fflush(stdin);
		printf("Enter number of year: ");
		scanf("%d", &n);
		fflush(stdin);
	} while(d<=0 || r<=0 || r>=0.1 || n<=0);
	amount = d*(pow(1+r,n));
	printf("Amount at the  %dth year: %.4lf\n", n, amount);
}  



int main(){
	int choose;
	float a, b, c;	
	do{
		printf("Enter choose: ");
		scanf("%d",&choose);
		fflush(stdin);
		switch(choose){
			case 1: printf(" -  ax^2 + bx + c  -\n");
			        printf("Enter a b c: ");
			        scanf("%f %f %f", &a, &b, &c);
			        fflush(stdin);
			        quadraticEquation(a, b, c);
					break;
				
			case 2: bankDeposit();
					break;
				
			default: break;
		}
	}while(choose!=3);
}
