#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

struct pt{int x,y,v;};
struct cmp{bool operator()(const pt &a,const pt &b){return a.v<b.v;}};
priority_queue<pt,vector<pt>,cmp> pq;
int N;
int arr[501][501];
int dp[501][501];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

bool safe(int x,int y){return x>=0 && y>=0 && x<N && y<N;}

int main(){
	cin >> N; 
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cin >> arr[i][j];
			pq.push((pt){i,j,arr[i][j]});
		}
	}
	int ans=0;
	while(!pq.empty()){
		pt cur = pq.top();
		pq.pop();
		for(int i=0;i<4;i++){
			int tx = cur.x + dx[i];
			int ty = cur.y + dy[i];
			if(safe(tx,ty)&&arr[tx][ty]>arr[cur.x][cur.y])
				dp[cur.x][cur.y] = max(dp[cur.x][cur.y], dp[tx][ty]+1 );;
		}
		ans=max(ans,dp[cur.x][cur.y]);
	}
	cout << ans+1;
	return 0;
}
