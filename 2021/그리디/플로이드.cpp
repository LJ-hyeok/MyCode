#include<iostream>
#include<algorithm>
using namespace std;

int dp[101][101];
const int INF = 987654321;

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int N,M;
	cin >> N >> M;
	for(int i=1;i<=N;i++)
		for(int j=1;j<=N;j++)
			dp[i][j]=INF;
	for(int i=0;i<M;i++){
		int a,b,c;
		cin >> a >> b >> c;
		dp[a][b] = min(dp[a][b],c);
	}
	for(int k=1;k<=N;k++){
		for(int i=1;i<=N;i++){
			if(k==i)	continue;
			for(int j=1;j<=N;j++){
				if(j==i || j==k)	continue;
				dp[i][j] = min(dp[i][j], dp[i][k]+dp[k][j]);
			}
		}
	}
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			if(dp[i][j]==INF)
				cout << "0 ";
			else
				cout << dp[i][j] << " ";
		}
		cout << "\n";
	}
}
