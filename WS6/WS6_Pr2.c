#include<stdio.h>
#include<stdlib.h>
void addValue(float *a, int *n){
	printf("Enter value: ");
	scanf("%f", &a[(*n)++]);
	fflush(stdin);
	printf("Value has been added!!!\n\n");
}

int searchValue(float *a, int *search, int *n, float value){
	int count = 0;
	for(int i = 0; i<*n; i++){
		if(a[i] == value){
			search[count++] = i;
		}
	}
	return count;
}
void printArray(float *a, int *n){
	for(int i = 0; i<*n; i++){
		printf("a[%d]: %.4f\n", i, a[i]);
	}
	printf("\n");
}

void printByRange(float *a, int *n, int maxVal, int minVal){
	float range[100];
	int j=0, count=0;
	for(int i = 0;i<*n; i++){
		if(a[i]>= minVal && a[i]<=maxVal){
			count=0;	
			for(int c=0; c<j; c++){
				if(a[i]== range[c]){
					count++;
				}
			}		
			if(count == 0){
				range[j++] = a[i];
			}    
		}
	}
	printf("The values in array which are between minVal and maxVal: \n");
	for(int i = 0; i<j; i++){
		printf("%.4f\n", range[i]);
	}
	printf("\n");
}


float* sortArray(float *a, int *n){
	static float sort[100];
	for(int i = 0; i<*n; i++){
		sort[i] = a[i];
	}
	for(int i=0; i<*n-1; i++){
		for(int j = *n-1; j>i; j--){
			if(sort[j]<sort[j-1]){
				int t = sort[j];
				sort[j] = sort[j-1];
				sort[j-1] = t;
			}
		}
	}
	return sort;
}
int main(){
	int n = 0, choose, search[100], countS;
	float a[100], value, *sort, maxVal, minVal;
	do{
		printf("1- Add a value\n");
		printf("2- Search a value\n");
		printf("3- Print out the array \n");
		printf("4- Print out the array in a range\n");
		printf("5- Print out the array in ascending order\n");	
		printf("Other - Quit\n\n");
		printf("Enter choose: ");
		scanf("%d",&choose);
		fflush(stdin);
		switch(choose){
			case 1: addValue(a,&n);
					break;
				
			case 2: printf("Enter value need find: ");
					scanf("%f", &value);
					fflush(stdin);
					countS = searchValue(a, search, &n, value);
			        if(countS==0){
			        	printf("Value does not exist in array!!!\n\n");
					} else{
						printf("The value %.4f is found at position:", value);
						for(int i = 0; i<countS; i++){
				        	printf(" %d", search[i]);
				    	}
				    	printf("\n\n");
					}	
					break;
			
			case 3: printArray(a,&n);
					break;
			
			case 4: printf("Enter max value: ");
					scanf("%f", &maxVal);
					fflush(stdin);
					printf("Enter min value: ");
					scanf("%f", &minVal);
					fflush(stdin);
					if(maxVal<minVal){
						int t = minVal;
						minVal = maxVal;
						maxVal = t;
					}
					printByRange(a, &n, maxVal, minVal);
					break;
			
			case 5: sort = 	sortArray(a,&n);
					printf("Sort value ascending: \n");
					printArray(sort,&n);
					
			default: break;
		}
	}while(choose>0 && choose<6); 
	return 0;
}

/*
Test case
1
1
1
1
1
1
1
3
1
5
1
7
1
2
1
1
1
9
1
35
1
23
1
92
1
76
1
54
1
23
1
88
1 
77
1
2
1
3
1
2
1
1
1
7
1
99
1
1
1
2
1
3
*/

