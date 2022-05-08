#include<stdio.h>
#include<vector>
using namespace std;

int cost[101];
vector<int> arr[101];
int dp[101];
int chk[101];
int cnt = 1;

int solve(int x){
	if(dp[x]==cnt)	return cnt;
	if(chk[x]==1)	return 0;
	chk[x]=1;
	for(int i=0;i<v[x].size();i++)
		dp[x] = solve(v[x][i]);
}
int main(){
	int N;
	scanf("%d",&N);
	for(int i=1;i<=N;i++)
		scanf("%d",&cost[i]);
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			int a;
			scanf("%1d",&a);
			if(a)	arr[i].push_back(j);
		}
	}
	for(int i=1;i<=N;i++)
		
	for(int i=1;i<=N;i++){
		if(dp[i]==0){
			dp[i]=++cnt;
			solve(i);
		}
	}

}
