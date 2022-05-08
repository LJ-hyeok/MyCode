#include<stdio.h>
#include<queue>
using namespace std;
int N;
int arr[101][101];
int chk[101][101];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int num = 1;
int ans = 10000000;
void print()
{
	printf("\n==========================\n");
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++)
			printf("%3d ",arr[i][j]);
		printf("\n");
	}
}
bool safe(int x,int y){
	return x>=0 && y>=0 && x<N && y<N;
}
struct pt{
	int x,y;	
}a;

queue<pt> Q;

void dfs(int x, int y)
{
	for(int i=0;i<4;i++){
		int tx = x + dx[i];
		int ty = y + dy[i];
		if(safe(tx,ty) && chk[tx][ty] == 1 && chk[tx][ty] != num){
			chk[tx][ty] = num;
			dfs(tx,ty);
		}
		
	}
}
void bfs()
{
	bool flag = false;
	while(!Q.empty())
	{
		pt cur = Q.front();
		for(int i=0;i<4;i++){
			int tx = cur.x + dx[i];
			int ty = cur.y + dy[i];
			if(arr[tx][ty] == 1 && chk[a.x][a.y] != chk[tx][ty]){
				flag = true;
				if(ans > arr[cur.x][cur.y])
					ans = arr[cur.x][cur.y];
			}
			if(flag)
				break;
			if(safe(tx,ty) && arr[tx][ty] == 0)
			{
				Q.push((pt){tx,ty});
				arr[tx][ty] = arr[cur.x][cur.y] + 1;
			}
				
		}
		Q.pop();
	}
}
int main()
{
	// 
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			scanf("%d",&arr[i][j]);
			chk[i][j] = arr[i][j];
		}
	}
	//
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(chk[i][j] == 1){
				num++;
				chk[i][j] = num;
				dfs(i,j);
			}
		}
	}
	//
	
	for(int i=0;i<num-1;i++){
		
		for(int j=0;j<N;j++){
			for(int k=0;k<N;k++){
				if(chk[j][k] == i+2){
					Q.push((pt){j,k});
					a.x = j;
					a.y = k;
				}
			}
		}
		
		
		bfs();
//		print();
		//
		for(int j=0;j<N;j++)
			for(int k=0;k<N;k++)
				if(chk[j][k] == 0)
					arr[j][k] = 0;
	}
	
	//
	printf("%d",ans-1);
	
	return 0;
}
