#include<stdio.h>
#include<queue>
using namespace std;
int M,N,H;
struct pt{ int x,y,z; }; 
queue<pt> q;
int arr[105][105][105];
int dx[]={1,-1,0,0,0,0};
int dy[]={0,0,1,-1,0,0};
int dz[]={0,0,0,0,1,-1};
int ans;
bool safe(int x,int y,int z){
	return x>=0 && y>=0 && z>=0 && x<N && y<M && z<H;
}
void bfs(int x,int y,int z){
	for(int i=0;i<6;i++){
		int tx = dx[i] + x;
		int ty = dy[i] + y;
		int tz = dz[i] + z;
		if(safe(tx,ty,tz) && arr[tx][ty][tz]==0){
			arr[tx][ty][tz] = arr[x][y][z] + 1;
			ans = arr[tx][ty][tz];
			q.push((pt){tx,ty,tz});
		}
	}
	
}
int main(){
	scanf("%d%d%d",&M,&N,&H);
	for(int k=0;k<H;k++)	for(int i=0;i<N;i++)	for(int j=0;j<M;j++)
		scanf("%d",&arr[i][j][k]);
	for(int k=0;k<H;k++)	for(int i=0;i<N;i++)	for(int j=0;j<M;j++)
		if(arr[i][j][k]==1)
			q.push((pt){i,j,k});
	while(!q.empty()){ 
		pt cur = q.front();
		bfs(cur.x,cur.y,cur.z);
		q.pop();
	}
	
//	print();
	bool flag = true;
	for(int k=0;k<H;k++)	for(int i=0;i<N;i++)	for(int j=0;j<M;j++)
		if(arr[i][j][k]==0)
			flag = false;
	if(flag){
		if(ans!=0)
			printf("%d",ans-1);
		else
			printf("0");
	}
	if(!flag)
		printf("-1");
	return 0;
}
