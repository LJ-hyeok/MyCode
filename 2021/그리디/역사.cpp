#include<iostream>
#include<algorithm>
using namespace std;

int dp[401][401];
const int INF = 987654321;
int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int n,k;
	cin >> n >> k;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			dp[i][j]=INF;
	for(int i=0;i<k;i++){
		int a,b;
		cin >> a >> b;
		dp[a][b] = 1;
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			if(k==i)	continue;
			for(int j=1;j<=n;j++){
				if(j==i || j==k)	continue;
				dp[i][j] = min(dp[i][j], dp[i][k]+dp[k][j]);
			}
		}
	}
	int s;
	cin >> s;
	for(int i=0;i<s;i++){
		int a,b;
		cin >> a >> b;
		int x = dp[a][b];
		int y = dp[b][a];
		if(x==INF && y==INF)
			cout << "0\n";
		else if(y==INF)
			cout << "-1\n";
		else if(x==INF)
			cout << "1\n";
	}
}
