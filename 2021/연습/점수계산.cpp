#include<stdio.h>
int main(){
	int N;
	scanf("%d",&N);
	int cnt = 0;
	int sum = 0;
	for(int i=0;i<N;i++){
		int a;
		scanf("%d",&a);
		if(a)  	cnt++;
		if(!a)  cnt = 0;
		sum += cnt;
	}
	printf("%d",sum);
	return 0;
}
