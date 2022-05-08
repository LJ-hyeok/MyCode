#include<stdio.h>
int main(){
	int N,M;
	scanf("%d%d",&N,&M);
	int lo,hi;
	if(N<M)	lo=N, hi=M;
	else	lo=M, hi=N;
	for(int i=hi;i>0;i--){
		if(hi%i==0 && lo%i==0){
			printf("%d\n",i);
			break;
		}
	}
	for(int i=hi;i<=hi*lo;i++){
		if(i%hi==0 && i%lo==0){
			printf("%d",i);
			break;
		}
	}
	return 0;
}
