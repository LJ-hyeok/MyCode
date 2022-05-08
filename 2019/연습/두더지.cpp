#include<stdio.h>
int n;
int map[35][35];
int dx[]={1,-1,0,0},dy[]={0,0,1,-1};

bool safe(int x, int y){
	return x>=0 && y>=0 && x<n && y<n;
}
void check(int x, int y,int c){
	map[x][y]=c;
	for(int i=0;i<4;i++){
		int tx = x+dx[i];
		int ty = y+dy[i];
		if(safe(tx,ty) && map[tx][ty]==1) check(tx,ty,c);
	}
}
int main(){
	scanf("%d",&n);
	int cnt = 1;
	for(int i=0;i<n;i++) for(int j=0;j<n;j++) scanf("%d",&map[i][j]);
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if(map[i][j]==1) check(i,j,++cnt);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++) printf("%d ",map[i][j]);
		printf("\n");
	}
	
	printf("%d",cnt-1);

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			
		}
	}
	return 0;
}
/*
7
0 1 1 0 1 0 0
0 1 1 0 1 0 1
1 1 1 0 1 0 1
0 0 0 0 1 1 1
0 1 0 0 0 0 0
0 1 1 1 1 1 0
0 1 1 1 0 0 0
*/
