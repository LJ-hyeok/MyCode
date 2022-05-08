#include<stdio.h>
#define mod 10007
int dp[1001][10];
int main(){
  int n,sum = 0;
  scanf("%d",&n);
  for(int i=0;i<=9;i++) dp[1][i]=1;
  for(int i=2;i<=n;i++)
    for(int j=0;j<=9;j++)
      for(int k=j;k<=9;k++){
        dp[i][k]+=dp[i-1][j];
        dp[i][k]%=mod;
      }
  for(int i=0;i<=9;i++) sum+=dp[n][i];
//  for(int i=0;i<=9;i++)	printf("%d ",dp[n][i]);
  printf("%d\n",sum%mod);
  return 0;
}

