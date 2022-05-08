#include<stdio.h>
int N, M, K;
int res = 0;
int arr[303][303];
int dp[303][2];
//dp어케하지 
bool max(int a,int b){
	return a>b?true:false;
}
void dfs(int idx,int cnt,int sum)
{
	if(idx>N)
		return;
	if(cnt > M)
		return;
	if(max(sum,res) && idx==N)
		res = sum;

	for(int i=idx+1;i<=N;i++)
		if(arr[idx][i] != 0)
			dfs(i,cnt+1,sum+arr[idx][i]);
}
int main()
{
	scanf("%d%d%d",&N,&M,&K);
	for(int i=1;i<=K;i++){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		if(max(c, arr[a][b]))
			arr[a][b] = c;
	}
	
//	dfs(1,1,0);

	for(int i=2;i<=N;i++){
		for(int j=1;j<=i;j++){
			int tmp = dp[j][0] + arr[j][i];
			if(max(tmp,dp[i][0]) && dp[i][1]+1<M){
				dp[i][0] = tmp;
				dp[i][1]++;
			}
		}
	}
//	for(int i=1;i<=N;i++)
		printf("%d ",dp[N][0]);
//	printf("%d",res);
	return 0;
}

