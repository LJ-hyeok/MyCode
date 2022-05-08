#include<stdio.h>
int arr[11];
int main(){
	int N,K;
	scanf("%d%d",&N,&K);
	for(int i=1;i<=N;i++)
		scanf("%d",&arr[i]);
	
	int cnt = 0;
	for(int i=N;i>0;i--){
		if(K>=arr[i]){
			while(true){
				K-=arr[i];
				cnt++;
				if(K<arr[i]) break;
			}
		}
	}
	printf("%d",cnt);
	return 0;
}
