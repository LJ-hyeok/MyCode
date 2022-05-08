#include <iostream>
#include <memory.h>
#include <string.h>
int rom[]={1000,500,100,50,10,5,1};
char romA[]={"MDCLXVI"};
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int Roman(char A[100]){
	int sum =0;
	int a =0;
	a=strlen(A);
	for(int i=0;i<a;i++){
		if(A[i]=='M')
			sum+=1000;
		if(A[i]=='D')
			sum+=500;	
		if(A[i]=='C')
			sum+=100;
		if(A[i]=='L')
			sum+=50;
		if(A[i]=='X')
			sum+=10;
		if(A[i]=='V')
			sum+=5;
		if(A[i]=='I')
			sum+=1;
	}
	return sum;
}

void fromroman(int a){
	char out[100];
	for(int i=0;i<7;i++){
		if(a>=rom[i]){
			for(int j=0;j<a/rom[i];j++) printf("%c",romA[i]);
			a%=rom[i];
		}
	}
}

int main(int argc, char** argv) {
	char A[2][100];
	int B[2];
	int b=0;
	char o;
	char C[100];
	int k;
	
	for(int i=0;i<2;i++){
		printf("Enter the number: ");
		scanf("%s",A[i]);
		B[i]=Roman(A[i]);
		printf("The number %s is %d\n",A[i],B[i]);
	}
	
	
	printf("Enter the desired arithmetic operation: ");
	fflush(stdin);
	scanf("%c",&o);
	
	if(o=='+')
		b = B[0] + B[1];
	if(o=='-')
		b = B[0] - B[1];
	if(o=='*')
		b = B[0] * B[1];
	if(o=='/')
		b = B[0] / B[1];
	
	printf("%s %c %s = ",A[0],o,A[1]);
	printf("(%d) ",b);
	fromroman(b);
	return 0;
}
