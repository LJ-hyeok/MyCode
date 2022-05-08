#include<stdio.h>
/*
int arr[1005];
int cnt = 0;
void print(){
	printf("\n");
	for(int i=0;i<n;i++)
		printf("%d ",arr[i]);
}
void dfs(int idx)
{
	if(idx > n)
		return;
	if(arr[n-1] !=  0){
		cnt++;
//		print();
	}
	
	arr[idx] = 1;
	dfs(idx+1);
	arr[idx] = 0;
	
	arr[idx]=2, arr[idx+1]=2;
	dfs(idx+2);
	arr[idx]=0, arr[idx+1] =0;
}*/

long long dp[1005];
int n;
int main()
{
	scanf("%d",&n);
//	dfs(0);
//	printf("%d\n",cnt%10007);
	dp[1] = 1;
	dp[2] = 2;
	for(int i=3;i<=n;i++)
		dp[i] = (dp[i-1] + dp[i-2])%10007;
	printf("%lld",(dp[n])%10007);
	return 0;
}
