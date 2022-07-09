#include<stdio.h>
#include<math.h>
#include <stdlib.h>
int prime(int n){
	
     int m = sqrt(n);
     if (n<2) return 0;
     for(int i = 2; i<=m; i++){
     	if(n%i==0){
     		return 0;
		 }
	 }
	 return 1;
}


void Pr1(){
	int n = 1;
	do {
		printf("Nhap 1 so lon hon bang 2: ");
		scanf("%d", &n);
		if (n<2){
	    	printf("So nho hon 2 vui long nhap lai!!!\n");
		} 
	}while(n<2);
	
	if(prime(n)==1){
		printf("So %d la so nguyen to!!!\n", n);
	} else {
		printf("So %d khong phai so nguyen to!!!\n", n);
	}
	
}
