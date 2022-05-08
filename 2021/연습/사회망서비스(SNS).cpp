#include<stdio.h>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
vector<int> v[1000002];
dp[1000002];
//얼리어답터 옆은 얼리어답터면 안됨
//얼리어답터가 아니라면 옆이 얼리어답터여도 되고 아니여도 됨 
void dfs(int pre, int cur, bool chk){
	if(dp[cur][chk]!=-1)
		return dp[cur][chk];
	dp[cur][chk] = 0;
	for(int i=0;i<sizeof(v[cur]);i++){
		int next = v[cur][i];
		if(next == cur)
			continue;
		
	}
	dp[cur][chk];
}
int main(){
	int N;
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	memset(dp,-1,sizeof(dp));
	printf("%d", min(dfs(-1,1,0), dfs(-1,1,1));
	return 0;
}
