#include<stdio.h>
int arr[1001];
int main(){
	int N,L;
	scanf("%d%d",&N,&L);
	for(int i=0;i<N;i++){
		int a;
		scanf("%d",&a);
		arr[a]=true;
	}
	
	int cnt = 0;
	for(int i=1;i<=1000;i++){
		if(arr[i]==1){
			for(int j=i;j<=i+L-1;j++)	arr[j]=0;
			cnt++;
		}
	}
	printf("%d",cnt);
	return 0;
}
