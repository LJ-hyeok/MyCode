#include<stdio.h>
using namespace std;
struct pt{int num,way;};
struct node{int x,y;};
pt arr[5][5];
node chk[18];
int ans = 0;
int dx[8] = {-1,-1,0,1,1,1,0,-1};
int dy[8] = {0,-1,-1,-1,0,1,1,1};
bool safe(int x,int y){return x>=0 && y>=0 && x<4 && y<4;}

void move(int sx,int sy){
	for(int i=1;i<=16;i++){
		int x = chk[i].x, y = chk[i].y;
		int tx,ty;
		while(true){
			tx = x + dx[arr[x][y].way], ty = y + dy[arr[x][y].way];
			if(safe(tx,ty) && tx!=sx && ty!=sy){
				pt tmp;
				tmp = arr[tx][ty];
				arr[tx][ty] = arr[x][y];
				arr[x][y] = tmp;
				break;
			}
			arr[x][y].way = (arr[x][y].way + 1)%8;
		}
	}
	
}
void dfs(int x,int y,int sum){
	if(ans < sum)
		sum = ans;
	move(x,y);
	int way = arr[x][y].way;
	int tx,ty;
	while(true){
		tx = dx[way], ty = dy[way];
		if(safe(tx,ty))
			dfs(tx,ty,sum+arr[tx][ty].num);
		else
			return;
	}
	printf("1");
}
int main(){
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			int a,b;
			scanf("%d%d",&a,&b);
			arr[i][j].num = a, arr[i][j].way = b;
			chk[a].x = i, chk[a].y = j;
		}
	}
	dfs(0,0,arr[0][0].num);
	
	
	return 0;
}
