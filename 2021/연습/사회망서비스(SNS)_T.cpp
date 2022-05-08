/*
DP
현재가 얼리어답터이면 인접한곳은 얼리어답터가 아니다
현재가 얼리어답터가 아니면 인접한 곳은 얼리어답터이거나 얼리어답터가 아니다.

dp[i][j]  에서 i번째 노드가 j==0 일때는 얼리어답터가 아닐때, j==1 일때는 얼리어답터일때 값 저장.
*/
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string.h>
using namespace std;
vector<int> v[1000002];
int dp[1000002][2];
int dfs(int pre, int cur, bool chk){
  if(dp[cur][chk]!=-1) return dp[cur][chk];
  dp[cur][chk] = 0;
  for(int i=0;i<v[cur].size();i++){ //현재 위치에서 연결된 노드 전부 확인
    int nxt = v[cur][i]; //다음 노드
    if(nxt == pre) continue; //다음 위치가 이전 위치랑 동일하면 스킵
    if(chk) dp[cur][chk] += dfs(cur,nxt,0);
    else if(!chk) dp[cur][chk] += max(dfs(cur,nxt,1)+1,dfs(cur,nxt,0));
  }
  return dp[cur][chk];
}
int main(){
  int n;
  scanf("%d",&n);
  for(int i=0;i<n-1;i++){
    int a,b;
    scanf("%d%d",&a,&b);
    //양방향 그래프
    v[a].push_back(b);
    v[b].push_back(a);
  }
  memset(dp,-1,sizeof(dp)); //dp를 전부 -1 로 리셋 (아직 방문하지 않은 곳을 -1 로 한다)
  printf("%d",n - max(dfs(-1,1,0),dfs(-1,1,1)+1));
}
