#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) 
{
	int C,K;
	int a,b,o,t;
	scanf("%d",&K);
	scanf("%d",&C);
	int O[C+1];
	t=K+1/2;
	for(int i=0;i<C;i++){
		scanf("%a %b",&a,&b);
		if(a==b)
			o=1;
		if(a>b){
			if(a-b<=t)
				o=1;
			else
				o=0;
		}
		if(b>a){
			if(b-a<=t)
				o=1;
			else
				o=0;
		}
		O[i]=o;
	}
	for(int i=0;i<C;i++)
		printf("%d\n",O[i]);
	return 0;
}
