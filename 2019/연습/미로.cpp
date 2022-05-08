#include<stdio.h>
#include<queue>
using namespace std;
struct pt{
	int x;
	int y;
};
int h,w;
bool safe(int x, int y){return x>=0 && y>=0 && x<h && y<w;}
char map[30][30];
int arr[30][30];
int sx,sy;
int gx,gy;
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
int main(){
	scanf("%d%d",&h,&w);
	for(int i=0;i<h;i++){
		scanf("%s",map[i]);
		for(int j=0;j<w;j++){
			if(map[i][j] == '#') arr[i][j]=-1;
			else if(map[i][j] == '.') arr[i][j]=0;
			else if(map[i][j] == 'G') {
				sx=i,sy=j;
				arr[i][j]=0;	
			}
			else if(map[i][j] == 'S') {
				gx=i,gy=j;
				arr[i][j]=0;
			}
		}
	}
	queue<pt> Q;
	Q.push({sx,sy});
	while(!Q.empty()){
		pt cur = Q.front();
		Q.pop();
		for(int i=0;i<4;i++){
			int tx = dx[i]+cur.x;
			int ty = dy[i]+cur.y;
			if(safe(tx,ty) && arr[tx][ty] == 0){
				arr[tx][ty] = arr[cur.x][cur.y]+1;
				Q.push({tx,ty});
			}
		}
	}
	printf("%d",arr[gx][gy]);
	return 0;
}



/*
5 5
#S###
#...#
#.#.#
#....
###G#
*/

//-1  0 -1 -1 -1
//-1  0  0  0 -1
//-1  0 -1  0 -1
//-1  0  0  0  0
//-1 -1 -1  0 -1
