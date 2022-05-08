#include<stdio.h> 
#include<queue>
using namespace std;
char map[505][505];
int R,C;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
struct pt{
	int x,y;	
};
queue<pt> Q;
void bfs(){
	Q.push((pt){});
	
	while(!Q.empty()){
		pt cur = Q.front();
		Q.pop();
		for(int i=0;i<4;i++){
			int tx = cur.x + dx[i];
			int ty = cur.y + dy[i];
			if()
				Q.push();
		}
	}
	
}
//¹Ì¿Ï  
int main(){
	scanf("%d%d",&R,&C);
	for(int i=0;i<R;i++)
		scanf("%s",&map[i]);
		
	
	return 0;
}
