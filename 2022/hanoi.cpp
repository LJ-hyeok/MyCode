#include<stdio.h>

int cnt = 0;

void hanoi(int n, int from, int by, int to){
	if(n==1){
		printf("%d->%d\n",from,to);
		cnt++;
	}
	else{
		hanoi(n-1, from, to, by);
		printf("%d->%d\n",from,to);
		cnt++;
		hanoi(n-1, by, from, to);
	}
}

int main(){
	int n;
	scanf("%d",&n);
	hanoi(n,1,2,3);
	printf("%d",cnt);
}
