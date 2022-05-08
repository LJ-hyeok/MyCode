#include<stdio.h>
int main(){
	int N,M;
	scanf("%d%d",&N,&M);
	int sum = 0, lo = 10001;
	for(int i=1;i<=100;i++){
		if(N<=i*i && i*i<=M){
			sum+=i*i;
			if(i*i<lo)
				lo = i*i;
		}
	}
	if(sum)
		printf("%d\n%d",sum,lo);
	if(!sum)
		printf("-1");
}
