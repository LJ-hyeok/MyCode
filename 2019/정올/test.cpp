#include<stdio.h>
#include<queue>
struct pt
{
	int x;
	int y;
};
int h,w;
bool safe(int x,int y){
	return x<=0 && y<=0 && x<h && y<w;
}
using namespace std;
char input[50][50];
int map[50][50];
int sx,sy;
int ex,ey;
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
int main()
{
	scanf("%d %d",&h,&w);
	for(int i=0;i<h;++i)
	{
		scanf("%s",input[i]);
		for(int j=0;j<w;++j)
		{
			if(input[i][j]=='#')
				map[i][j] = -1;
			if(input[i][j]=='S')
			{
				sx = i;
				sy = j;
				map[i][j] = 0;
			}
			if(input[i][j]=='E')
				map[i][j] = 0;
			if(input[i][j]=='.')
				map[i][j] = 0;
		}
	}//문자입력 -> 숫자  
	queue<pt> Q;
	Q.push({sx,sy});
	while(!Q.empty())
	{
		pt cur = Q.front();
		Q.pop();
		for(int i=0;i<4;i++)
		{
			int tx = cur.x;
			int ty = cur.y;
			if(safe(tx,ty) && map[tx][ty] == 0)
			{
				map[tx][ty] = 1;
				Q.push({tx+dx[i],ty+dy[i]}); 
			}
		}
	}
	
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
