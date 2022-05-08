#include<stdio.h>
#include<algorithm>

int n;
int dp[1000];
int arr[1000];

int dfs(int x){
	if(dp[x])
		return dp[x];
	int hi=0;
	for(int i=0;i<x;i++)
		if(arr[i]<arr[x])
			hi = std::max(hi,dfs(i));
	return dp[x]=std::max(dp[x],hi)+arr[x];
}

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++)	scanf("%d",&arr[i]);
	int ans = 0;
	for(int i=0;i<n;i++)
		ans = std::max(ans,dfs(i));
	printf("%d",ans);
	return 0;
}
