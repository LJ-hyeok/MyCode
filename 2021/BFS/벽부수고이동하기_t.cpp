#include<cstdio>
#include<queue>
using namespace std;
const int MAX = 1000;
struct pt{int x,y,b;};
int n,m;
int arr[MAX][MAX];
int dp[MAX][MAX][2];
int dx[]={1,-1,0,0},dy[]={0,0,1,-1};
inline bool safe(int x, int y){return x>=0 && y>=0 && x<n && y<m;}
int bfs(){
  queue<pt> Q;
  Q.push((pt){0,0,1});
  dp[0][0][1] = 1;
  while(!Q.empty()){
    int x = Q.front().x;
    int y = Q.front().y;
    int b = Q.front().b;
    Q.pop();
    if(x == n-1 && y == m-1) return dp[x][y][b];
    for(int i=0;i<4;i++){
      int tx = x+dx[i];
      int ty = y+dy[i];
      if(safe(tx,ty)){
        if(arr[tx][ty] == 1 && b){
          dp[tx][ty][b-1] = dp[x][y][b]+1;
          Q.push((pt){tx,ty,b-1});
        }
        else if(arr[tx][ty] == 0 && dp[tx][ty][b] == 0){
          dp[tx][ty][b] = dp[x][y][b]+1;
          Q.push((pt){tx,ty,b});
        }
      }
    }
  }
  return -1;
}
int main(){
  scanf("%d%d",&n,&m);
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++)
      scanf("%1d",&arr[i][j]);
  }
  printf("%d\n",bfs());
  return 0;
}
