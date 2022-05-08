#include<stdio.h>
int n,m;
int org_map[10][10];
int tmp_map[10][10];
int tmp2_map[10][10];
int dx[]={1,-1,0,0},dy[]={0,0,1,-1};
int ans = 0;
int vir_cnt;
struct point{
 int x;
 int y;
}vir[100];

inline int max(int a, int b){return a>b?a:b;}
inline bool safe(int x, int y){return x>=0 && y>=0 && x<n && y<m;}
void copy_map(){
 for(int i=0;i<n;i++) for(int j=0;j<m;j++) tmp_map[i][j]=org_map[i][j];
}

void spread(int x, int y){
 for(int i=0;i<4;i++){
   int tx = x+dx[i];
   int ty = y+dy[i];
   if(safe(tx,ty) && tmp_map[tx][ty]==0){
     tmp_map[tx][ty]=2;
     spread(tx,ty);
   }
 }
}
void get_ans(){
 int cnt = 0;
 for(int i=0;i<n;i++) for(int j=0;j<m;j++) if(tmp_map[i][j]==0) cnt++;
 ans = max(ans,cnt);
}
void get_wall(int cnt){
 if(cnt == 3) {
   for(int i=0;i<n;i++) for(int j=0;j<m;j++) tmp2_map[i][j]=tmp_map[i][j];
   for(int i=0;i<vir_cnt;i++)
       spread(vir[i].x,vir[i].y);
   get_ans();
   for(int i=0;i<n;i++) for(int j=0;j<m;j++) tmp_map[i][j]=tmp2_map[i][j];
   return;
 }
 for(int i=0;i<n;i++){
   for(int j=0;j<m;j++){
     if(tmp_map[i][j]==0){
       tmp_map[i][j]=1;
       get_wall(cnt+1);
       tmp_map[i][j]=0;
     }
   }
 }
}
int main(){
 scanf("%d%d",&n,&m);
 for(int i=0;i<n;i++)
   for(int j=0;j<m;j++)
     scanf("%d",&org_map[i][j]);
 for(int i=0;i<n;i++) for(int j=0;j<m;j++)
   if(org_map[i][j]==2) {
     vir[vir_cnt].x=i;
     vir[vir_cnt++].y=j;
   }
 for(int i=0;i<n;i++) for(int j=0;j<m;j++)
   if(org_map[i][j]==0){
     copy_map();
     tmp_map[i][j]=1;
     get_wall(1);
     tmp_map[i][j]=0;
   }

 printf("%d",ans);
 return 0;
}
