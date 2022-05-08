#include<stdio.h>
#include<queue>
using namespace std;
int N,M;
int arr[101][101];
int dx[]={0,0,1,-1};
int dy[]={-1,1,0,0};
bool safe(int x,int y){
	return x>=0 && y>=0 && x<N && y<M;
}
struct pt
{
	int x,y;	
};
int print() {
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++)
			printf("%2d ",arr[i][j]);
		printf("\n");
	}
}
void bfs()
{
	queue<pt> Q;
	Q.push((pt){0,0});
	while(!Q.empty())
	{
		pt cur = Q.front();
		Q.pop();
		for(int i=0;i<4;i++){
			int tx = cur.x + dx[i];
			int ty = cur.y + dy[i];
			if(safe(tx,ty) && arr[tx][ty]==1)
			{
				Q.push((pt){tx,ty});
				arr[tx][ty] = arr[cur.x][cur.y] + 1;
			}
		}
	}
}
int main()
{
	scanf("%d%d",&N,&M);
	for(int i=0;i<N;i++)
		for(int j=0;j<M;j++)
			scanf("%1d",&arr[i][j]);
			
	bfs();
	
	printf("%d",arr[N-1][M-1]);
	printf("\n");
	print();
	return 0;
}
