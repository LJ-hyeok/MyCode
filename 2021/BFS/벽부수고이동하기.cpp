#include<stdio.h>
#include<queue>
using namespace std;
int N,M;
int arr[1001][1001];
int vis[1001][1001][2];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
void print(){
	printf("\n===============================================\n");
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++)
			printf("%3d",arr[i][j]);
		printf("\n");
	}
}
struct pt{
	int x,y,d;
};
queue<pt> Q;
bool safe(int x,int y){return x>=0 && y>=0 && x<N && y<M;}
void bfs(){
	Q.push((pt){0,0});
	while(!Q.empty()){
		pt cur = Q.front();
		for(int i=0;i<4;i++){
			int tx = cur.x + dx[i];
			int ty = cur.y + dy[i];
			if(safe(tx,ty) && arr[tx][ty] == 0 ){
				arr[tx][ty] = arr[cur.x][cur.y] + 1;
				Q.push((pt){tx,ty});
			}
		}
		Q.pop();
	}
	
}

int main()
{
	scanf("%d%d",&N,&M);
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			scanf("%1d",&arr[i][j]);
			vis[i][j][0] = arr[i][j];
		}
	}
	
	//Ã¹¹ø¤Š 
	int ans = N*M,tmp=0;
	vis[0][0][0] = 2;
	bfs();
	
	return 0;
}
