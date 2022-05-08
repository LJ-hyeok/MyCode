#include<iostream>
#include<algorithm>
using namespace std;
int T[1003];
int P[1003];
int dp[1003];
int main(){
	int N;
	cin >> N;
	int ans = 0;
	for(int i=1;i<=N;i++)	cin >> T[i] >> P[i];
	for(int i=1;i<=N;i++){
		if(i + T[i] > N+1)	continue;
		dp[i+T[i]] = max(dp[i+T[i]], dp[i] + P[i]);
		for(int j=i+T[i];j<=N+1;j++)
			dp[j] = max(dp[j],dp[i+T[i]]);
	}
	for(int i=1;i<=N+1;i++)
		ans = max(ans,dp[i]);
	cout << ans;
	return 0;
}
