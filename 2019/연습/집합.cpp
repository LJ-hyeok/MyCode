#include <iostream>

int main(int argc, char** argv) 
{
	
	int m=0,n=0;
	int A[30];
	int B[30];
	int A+B[60];
	int A-B[60];
	
	printf("Data of set A = ");
	while(1){
		scanf("%d",&A[m]);
		if(A[m]==-1) break;
		m++;
	}
	printf("Data of set B = ");
	while(1){
		scanf("%d",&B[n]);
		if(B[n]==-1) break;
		n++;
	}
	
	printf("set A = ");
	for(int i=0;i<m;i++){
		if(i==0){
			printf("{");
			printf("%d,",A[i]);
		}
		if(i==m-1){
			printf("%d",A[i]);
			printf("}");
		}		
		else
			printf("%d,",A[i]);
	}
	
	printf("\nset B = ");
	for(int i=0;i<n;i++){
		if(i==0){
			printf("{");
			printf("%d,",B[i]);
		}
		if(i==n-1){
			printf("%d",B[i]);
			printf("}");
		}		
		else
			printf("%d,",B[i]);
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(A[i]==B[j]){
				 
			}
		}	
	}
	
	return 0;
}
