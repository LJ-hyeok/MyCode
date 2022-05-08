#include <iostream>
using namespace std;
int dp[31];
int main() {
	int N;
	cin >> N;
	dp[0] = 1;
	dp[2] = 3;
	for(int i = 4; i <= N; i++){
		dp[i] = dp[i - 2] * 3;
		for(int j = 4; j <= i; j+=2)
			dp[i] += dp[i - j] *2;
	}
	cout << dp[N];
	return 0;
}
