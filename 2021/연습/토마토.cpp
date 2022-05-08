#include<stdio.h>
#include<queue>
using namespace std;
int arr[1001][1001];
int N,M;
int cnt = 2;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
struct pt{
	int x,y;
};
queue<pt> q;
bool safe(int x,int y){
	return x>0 && y>0 && x<=N && y<=M;
}
void bfs(int x,int y){
	for(int i=0;i<4;i++){
		int tx = x + dx[i];
		int ty = y + dy[i];
		if(safe(tx,ty) && arr[tx][ty] == 0){
			q.push((pt){tx,ty});
			arr[tx][ty] = cnt;
		}
	}
	cnt++;
}
int main(){
	scanf("%d%d",&M,&N);
	for(int i=1;i<=N;i++){
		for(int j=1;j<=M;j++){
			scanf("%d",&arr[i][j]);
			if(arr[i][j]==1)
				q.push((pt){i,j});
		}
	}
	
	while(!q.empty()){
		pt cur = q.front();
		q.pop();
		bfs(cur.x,cur.y);
	}
	
	for(int i=1;i<=N;i++){
		for(int j=1;j<=M;j++)
			printf("%3d",arr[i][j]);
		printf("\n");
	}
	return 0;
}
