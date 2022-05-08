#include<iostream>
#include<queue>
#include<string.h>
using namespace std;
int N,M;
int arr[1003][1003];
int dp[1003][1003];
int dx[]={1,0};
int dy[]={0,1};
struct pt{int x,y;};
queue<pt> q;
bool safe(int x,int y){return x>=0 && y>=0 && x<N && y<M;}
void bfs(){
	q.push((pt){0,0});
	while(!q.empty()){
		pt cur = q.front();
		q.pop();
		for(int i=0;i<2;i++){
			int tx = cur.x + dx[i];
			int ty = cur.y + dy[i];
			if(safe(tx,ty) && dp[cur.x][cur.y]+arr[tx][ty] > dp[tx][ty]){
				dp[tx][ty] = dp[cur.x][cur.y]+arr[tx][ty];
				q.push((pt){tx,ty});
			}
		}
	}
}

int main(){
	cin >> N >> M;
	for(int i=0;i<N;i++)
		for(int j=0;j<M;j++)
			cin >> arr[i][j];
	memset(dp,-1,sizeof(dp));
	dp[0][0] = arr[0][0];
	bfs();
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++)
			cout << dp[i][j] << ' ';
		cout << "\n";
	}
//	cout << dp[N-1][M-1];	
	return 0;
}
