#include<stdio.h>
#include<queue>
using namespace std;
struct pt{
  int x,y;
};
int arr[101][101];
char str[105][105];
int dx[]={1,-1,0,0},dy[]={0,0,1,-1};
int h,w;
int sx,sy,gx,gy;
inline bool safe(int x, int y){return x>=0 && y>=0 && x<h && y<w;}
void print(){
  printf("\n-------------------------\n");
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      printf("%3d ",arr[i][j]);
    }
    printf("\n");
  }
  printf("\n-------------------------\n");
}
// void dfs(int x, int y, int cnt){
//   arr[x][y] = cnt;
//   print();
//   for(int i=0;i<4;i++){
//     int tx = x+dx[i];
//     int ty = y+dy[i];
//     if(safe(tx,ty) && (arr[tx][ty] == 0 || arr[tx][ty] > cnt+1)){
//       dfs(tx,ty,cnt+1);
//     }
//   }
// }

void bfs(){
  queue<pt> Q;
  Q.push((pt){sx,sy});
  arr[sx][sy] = 0;
  while(!Q.empty()){
    print();
    pt cur = Q.front();
    Q.pop();
    for(int i=0;i<4;i++){
      int tx = cur.x+dx[i];
      int ty = cur.y+dy[i];
      if(safe(tx,ty) && arr[tx][ty] == 0){
        arr[tx][ty] = arr[cur.x][cur.y]+1;
        Q.push((pt){tx,ty});
      }
    }
  }
}
int main(){
  scanf("%d%d",&h,&w);
  for(int i=0;i<h;i++){
    scanf("%s",str[i]);
    for(int j=0;j<w;j++){
      if(str[i][j] == '.'){
        arr[i][j] = 0;
      }else if(str[i][j] == '#'){
        arr[i][j] = -1;
      }else if(str[i][j] == 'S'){
        arr[i][j] = 0;
        sx = i, sy = j;
      }else if(str[i][j] == 'G'){
        arr[i][j] = 0;
        gx = i, gy = j;
      }
    }
  }
  // print();
  bfs();
  // print();
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
    
    
  
  


