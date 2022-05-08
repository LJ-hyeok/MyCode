#include<stdio.h>
int w,h;
int arr[55][55];
int cnt=1;
int dx[]={0,0,1,-1,1,1,-1,-1};
int dy[]={1,-1,0,0,1,-1,1,-1};
bool safe(int x,int y){
	return x>=0 && y>=0 && x<h && y<w;}
void dfs(int x,int y)
{
	for(int i=0;i<8;i++){
		int tx = x + dx[i];
		int ty = y + dy[i];
		if(safe(tx,ty) && arr[tx][ty] == 1 && arr[tx][ty] != cnt){
			arr[tx][ty] = cnt;
			dfs(tx,ty);
		}
	}
}
int main()
{
	while(true)
	{	
		//입력 
		scanf("%d %d",&w,&h);
		if(w == 0 && h == 0)
			break;
		for(int i=0;i<h;i++)
			for(int j=0;j<w;j++)
				scanf("%d",&arr[i][j]);
		//dfs
		for(int i=0;i<h;i++)
			for(int j=0;j<w;j++){
				if(arr[i][j] == 1){
					cnt++;
					arr[i][j] = cnt;
					dfs(i,j);
				}
		}
		printf("%d\n",cnt-1);//\n안해서 1시간동안 틀림 하하하 
		//초기화 
		cnt = 1;
		for(int i=0;i<h;i++)
			for(int j=0;j<w;j++)
				arr[i][j] = 0;
	}
	return 0;
}
