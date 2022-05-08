#include<stdio.h>
#include<queue>
using namespace std;
struct pt{
	int x,y;
};
queue<pt> Q;
int N,M;
int arr[10][10];
int chk[10][10];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int c;
int ans = 0;
bool safe(int x,int y) {return x>=0 && y>=0 && x<N && y<M;}
void print()
{
	printf("\n");
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++)
			printf("%d ",chk[i][j]);
		printf("\n");
	}
}
void count0(){ //0 개수 세고 chk 초기화 
	int tmp = 0;
	for(int i=0;i<N;i++)
		for(int j=0;j<M;j++)
			if(chk[i][j]  == 0)
				tmp++;
				
	for(int i=0;i<N;i++)
		for(int j=0;j<M;j++)
			chk[i][j] = arr[i][j];
			
	if(tmp > ans)
			ans = tmp;
}	
/*
void dfs2(int x,int y){ // 2퍼뜨리기 

	if(chk[x][y] != 2)
		return;		
	for(int i=0;i<4;i++){
		int tx = x + dx[i];
		int ty = y + dy[i];
		if(safe(tx,ty) && chk[tx][ty] == 0 && chk[tx][ty] != 2){
			chk[tx][ty] = 2;
			dfs2(tx,ty);
		}
	}
	
}*/
void bfs(int x,int y)
{
	Q.push((pt){x,y});
	while(!Q.empty())
	{
		pt cur = Q.front();
		for(int i=0;i<4;i++){
			int tx = cur.x + dx[i];
			int ty = cur.y + dy[i];
			if(safe(tx,ty) && chk[tx][ty] == 0){
				Q.push((pt){tx,ty});
				chk[tx][ty] = 2;
			}
		}
		Q.pop();
	}
}
void dfs(int cnt)//벽세우기 
{	
	if(cnt==3){
		for(int i=0;i<N;i++)
			for(int j=0;j<M;j++)
				arr[i][j] = chk[i][j];


		for(int i=0;i<N;i++)
			for(int j=0;j<M;j++)
				if(chk[i][j] == 2)
					bfs(i,j);
//					dfs(i,j);

//		print();
		count0();
		return;
	}
	
	for(int i=0;i<c;i++){
		int x = i/M;
		int y = i%M;
		if(chk[x][y] == 0){
			chk[x][y] = 1;
			dfs(cnt+1);
			chk[x][y] = 0;
		}
	}
	
}	
int main()
{
	scanf("%d%d",&N,&M);
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			scanf("%d",&arr[i][j]);
			chk[i][j] = arr[i][j];
		}
	}
	
	c = N*M;
	//벽세우기  
	dfs(0);
	printf("%d",ans);
	return 0;
} 	
