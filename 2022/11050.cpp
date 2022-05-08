#include<iostream>
#define mod 10007
using namespace std;

int dp[1003][1003];

void solve(int n,int k){
	dp[0][0] = 1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=i;j++){
			if(j==0 || j==i){
				dp[i][j] = 1;
				continue;
			}
			dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
		}
	}
	cout << dp[n][k];
}

int main(){
	int n,k;
	cin >> n >> k;
	solve(n,k);
}
