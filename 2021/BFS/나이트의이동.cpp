#include<stdio.h>
#include<queue>
using namespace std;
int l;
int arr[305][305];
int dx[]={2,1,-1,-2,2,1,-1,-2};
int dy[]={1,2,2,1,-1,-2,-2,-1};
int sx,sy;
int ex,ey;
void print()
{
	printf("\n=======================================\n");
	for(int i=0;i<l;i++){
		for(int j=0;j<l;j++)
			printf("%3d ",arr[i][j]);
		printf("\n");
	}
}
struct pt{
	int x,y;
};
bool safe(int x,int y){
	return x>=0 && y>=0 && x<l && y<l;
}
queue<pt> Q;
void bfs()
{
	bool flag = false;
	while(!Q.empty())
	{
		pt cur = Q.front();
		for(int i=0;i<8;i++){
			int tx = cur.x + dx[i];
			int ty = cur.y + dy[i];
			if(flag)
				break;
			if(tx == ex && ty == ey)
				flag = true;
			
			if(safe(tx,ty) && arr[tx][ty]==0 ){
				Q.push((pt){tx,ty});
				arr[tx][ty] = arr[cur.x][cur.y]+1;
//				print();
			}
		}
		if(flag)
			break;
		Q.pop();
	}
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t!=0)
	{
		scanf("%d",&l);
		scanf("%d%d",&sx,&sy);
		scanf("%d%d",&ex,&ey);
		while(!Q.empty())
			Q.pop();
		for(int i=0;i<l;i++)
			for(int j=0;j<l;j++)
				arr[i][j] =  0;
		//
		if(sx == ex && sy == ey)
			printf("0\n");
		else{
			Q.push((pt){sx,sy});
			arr[sx][sy] = 1;
			bfs();
			printf("%d\n",arr[ex][ey] - 1);
		}

		//
		
		
		//
		t--;
	}
	return 0;
}
