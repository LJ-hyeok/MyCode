#include<stdio.h>

unsigned long long int dp[501][501];
int main(){
	for(int i=1;i<=100;i++){
		for(int j=0;j<=i;j++){
			if(j==0 || j==i)	dp[i][j]=1;
			else	dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
		}
	}
	int n,m;
	scanf("%d%d",&n,&m);
	printf("%lld",dp[n][m]);
	return 0;
}
