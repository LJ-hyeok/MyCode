#include<iostream>
#include<vector>
#include<string.h>
using namespace std;
int t[1003];
vector<int> v[1003];
int dp[1003];
int N,K,D,W;
int ans;
void dfs(int a,int sum){
	if(dp[a] != 0 ) return;
	if(sum > dp[a])
		dp[a] = sum;
	for(int i=0;i<v[a].size();i++){
		if(dp[v[a][i]]<dp[a])
			dfs(v[a][i],sum+t[v[a][i]]);
	}
	if(sum > ans)
		ans = sum;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;
	while(T--){
		ans = 0;
		memset(v,0,sizeof(v));
		memset(t,0,sizeof(t));
		memset(dp,0,sizeof(dp));
		cin >> N >> K;
		for(int i=1;i<=N;i++)
			cin >> t[i];
		for(int i=0;i<K;i++){
			int a,b;
			cin >> a >> b;
			v[b].push_back(a);
		}
		cin >> W;
		dfs(W,t[W]);
		cout << ans << "\n";
//		cout << "\n";
//		for(int i=1;i<=N;i++)
//			cout << dp[i] << " ";
				
	}
	return 0;
}
