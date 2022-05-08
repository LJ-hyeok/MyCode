#include<stdio.h>
int N,M;
int main()
{
	scanf("%d%d",&N,&M);
	
	if(N==1)
		printf("1");
	if(N==2){
		if(M<7)
			printf("%d",(M+1)/2);
		if(M>=7)
			printf("4");
		}
	if(N>=3){
		if(M<=4)
			printf("%d",M);
		if(4<M&&M<7)
			printf("4");
		if(M>=7)
			printf("%d",M-2);
	}
			
		
	return 0;
}
