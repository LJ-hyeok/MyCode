#include<stdio.h>
int arr[100003];
int chk[100003];
int main(){
	int N,M;
	scanf("%d%d",&N,&M);
	for(int i=0;i<M;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		arr[a]++;
		arr[b]--;
	}
	for(int i=1;i<=N;i++){
		arr[i]+=i;
		chk[arr[i]]++;
	}
	
	bool flag = true;
	for(int i=1;i<=N;i++)
		if(chk[i]!=1)
			flag = false;
	if(flag){
		for(int i=1;i<=N;i++)
			printf("%d ",arr[i]);
		}
	if(!flag)
		printf("-1");
	return 0;
}
