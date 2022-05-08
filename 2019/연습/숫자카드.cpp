#include<iostream>

int main(void){
	int N,M;
	int n[1000],m[1000];
	int a,chk;
	
	scanf("%d",&N);
	for(int i=0;i<N;i++)
		scanf("%d",&n[i]);
	scanf("%d",&M);
	for(int i=0;i<M;i++)
		scanf("%d",&m[i]);
	
	for(int i=0;i<M;i++){
		a=m[i];
		chk=0;
		for(int j=0;j<N;j++){
			if(a==n[j])
				chk=1;
		}
		if(chk==0)
			printf("0 ");
		else
			printf("1 ");
	}
	
}
