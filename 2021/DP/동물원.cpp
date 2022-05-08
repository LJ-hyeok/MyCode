#include<stdio.h>
int N;
int dp[100001][3]; //0 - x, 1-left,2-right
const int mod = 9901;
int main()
{
	scanf("%d",&N);
	dp[1][1]=dp[1][0]=dp[1][2] = 1;
	for(int i=2;i<=N;i++){
		dp[i][0] = (dp[i-1][0]+dp[i-1][1]+dp[i-1][2])%mod;
		dp[i][1] = (dp[i-1][0]+dp[i-1][2])%mod;
		dp[i][2] = (dp[i-1][0]+dp[i-1][1])%mod;
	}
	printf("%d",(dp[N][0]+dp[N][1]+dp[N][2])%mod);
	return 0;
}
