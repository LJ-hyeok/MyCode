#include<stdio.h>
int R,C,ans;
char A[25][25];
int chk[30];
int dx[]={1,-1,0,0},dy[]={0,0,1,-1};
// 
int max(int a, int b){return a>b?a:b;}
bool safe(int x,int y){
	return x>=0 && y>=0 && x<R && y<C;
}

void dfs(int x, int y, int cnt)
{
	ans = max(ans,cnt);
	for(int i=0;i<4;i++){
		int tx = x+dx[i];
		int ty = y+dy[i];
		if(safe(tx,ty) && chk[A[tx][ty]-'A'] == 0){
			chk[A[tx][ty]-'A']=1;
			dfs(tx,ty,cnt+1);
			chk[A[tx][ty]-'A']=0;
		}
	}
	
}
int main()
{
	
	//
	scanf("%d %d",&R,&C);
	for(int i=0;i<R;i++)
			scanf("%s",A[i]);
			
	//
	chk[A[0][0]-'A'] = 1;
	dfs(0,0,1);
	printf("%d", ans);
	
	return 0;
}
