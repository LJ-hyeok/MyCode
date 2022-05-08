#include<stdio.h>
#include<string.h>
int N;
int ans = 0;
int L[2001];
int R[2001];
int dp[2001][2001];
inline int max(int a, int b){return a>b?a:b;}
void print(int left,int right,int sum)
{
	printf("\n");
	for(int i=0;i<N;i++){
		if(left<=i)
			printf("%d ",L[i]);
		else
			printf("  ");
		if(right<=i)
			printf("%d\n",R[i]);
		else
			printf("\n");
	}
	printf("==============%d\n",sum);
}

int dfs(int left,int right)
{
	if(left>=N || right>=N) return 0;
	if(dp[left][right] != -1) return dp[left][right];
	dp[left][right] = 0;
	if(L[left]>R[right]){
		dp[left][right]+=R[right]+dfs(left,right+1);
	}
	else{
		dp[left][right]+=max(dfs(left+1,right),dfs(left+1,right+1));
	}
	return dp[left][right];
}	
int main(){
	scanf("%d",&N);
	for(int i=0;i<N;i++)
		scanf("%d",&L[i]);
	for(int i=0;i<N;i++)
		scanf("%d",&R[i]);
	memset(dp,-1,sizeof(dp));
	
	
	printf("%d",dfs(0,0));
	return 0;
}
