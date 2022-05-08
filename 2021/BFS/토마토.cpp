#include<stdio.h>
#include<queue>
int N,M;
int arr[1001][1001];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int ans =0;
int cnt = 0;
bool safe(int x,int y){return x>=0 && y>=0 && x<N && y<M;}
struct pt{int x,y;};

using namespace std;
queue<pt> Q;
void print(){
	printf("\n=======================================\n");
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++)
			printf("%3d ",arr[i][j]);
		printf("\n");
	}
	
	printf("=======================================");
}
void bfs()
{
	while(!Q.empty())
	{
		pt cur = Q.front();
		for(int k=0;k<4;k++){
			int tx = cur.x + dx[k];
			int ty = cur.y + dy[k];
			if(safe(tx,ty) && arr[tx][ty] == 0 && arr[tx][ty]!=arr[cur.x][cur.y])
			{	
				Q.push((pt){tx,ty});
				arr[tx][ty] = arr[cur.x][cur.y]+1;
				ans = arr[tx][ty]-1;
//				print();
//				printf("\n%d,%d\n\n\n",cur.x,cur.y);
			}
		}	
					
			
		Q.pop();
	}
}

int main()
{
	scanf("%d%d",&M,&N);
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			scanf("%d",&arr[i][j]);
			if(arr[i][j] == 1)
				Q.push((pt){i,j});
		}
	}

	bfs();
	//
	bool flag = true;
	for(int i=0;i<N;i++)
		for(int j=0;j<M;j++)
			if(arr[i][j] == 0)
				flag = false;
	//
	if(flag)
		printf("%d",ans);
	else
		printf("-1");
	return 0;
}
