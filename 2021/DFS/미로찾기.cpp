#include<stdio.h>
int h,w;
char way[105][105];
bool chk[105][105];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int ans=10000;
bool safe(int x,int y){
	return (x>=0 && y>=0 && x<h && y<w);
}

void dfs(int x, int y,int cnt)
{
	if(way[x][y] == 'G'){
		if(ans > cnt)
			ans = cnt;
		return;
	}
	
	for(int i=0;i<4;i++){
		int tx = x + dx[i];
		int ty = y + dy[i];
		if(way[tx][ty] != '#' && safe(tx,ty) && !chk[tx][ty]){
			chk[tx][ty] = 1;
			dfs(tx, ty,cnt+1);
			chk[tx][ty] = 0;
		}
	}
}
int main(){
	scanf("%d %d",&h,&w);
	for(int i=0;i<h;i++)
		scanf("%s",&way[i]);
		
	//S G 
	
	int sx,sy;
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			if(way[i][j] == 'S'){
				sx = i;
				sy = j;
			}
		}
	}
	
	//
	dfs(sx,sy,0);
	//
	
	if(ans > 10000)
		printf("-1");
	else
		printf("%d",ans);
	return 0;
}
