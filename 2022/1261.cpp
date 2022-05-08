#include<cstdio>
#include<queue>
#define INF 987654321
using namespace std;

int dx[]={0,0,-1,1};
int dy[]={1,-1,0,0};
int arr[101][101];
int dist[101][101];
int N,M;

bool safe(int x, int y){
	return x>=0 && y>=0 && x<N && y<M;
}

int dijkstra(){
	queue<pair<int,int>> q;
	q.push({0,0});
	dist[0][0] = 0; 
	while(!q.empty()){
		int curx = q.front().first;
		int cury = q.front().second;
		q.pop();
		for(int i=0;i<4;i++){
			int tx = dx[i] + curx;
			int ty = dy[i] + cury;
			if(!safe(tx,ty))	continue;
			if(dist[tx][ty] > dist[curx][cury] + arr[tx][ty]){
				dist[tx][ty] = dist[curx][cury] + arr[tx][ty];
				q.push({tx,ty});
			}
		}
	}
	return dist[N-1][M-1];
}

int main(){
	//init
	scanf("%d%d",&M,&N);
	for(int i=0;i<N;i++)
		for(int j=0;j<M;j++)
			scanf("%1d",&arr[i][j]);
	for(int i=0;i<=N;i++)
		for(int j=0;j<=M;j++)
			dist[i][j] = INF;

	printf("%d",dijkstra());
	return 0;
}
