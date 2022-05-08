#include<stdio.h>
int n;
int arr[301];
int dp[301];
void dfs(int idx,int chk)
{
	
	
	
	dfs(idx+1,chk);
	dfs(idx+2,chk);
}	
int main()
{	
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);
	
	dfs(0,0);
	

//


	return 0;
}
