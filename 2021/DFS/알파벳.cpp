#include<stdio.h>
int R,C,max;
char A[25][25];
int chk[30];
// 
bool safe(int x,int y)
{
	if(x<0 || y<0 || x>R || y>C)
		return 0;
	else
		return 1;
}

void dfs(int x, int y, int idx, int cnt)
{
	
	
	for(int i=0;i<30;i++)
	{
		if(chk[i]==A[x][y])
			return;
	}
	chk[idx] = A[x][y];
	if(cnt>=max){
		max = cnt;
	}
	
		
	if(safe(x+1,y) == 1){
		chk[x][y] = 1
		dfs(x+1,y,idx+1,cnt+1);
	}
	if(safe(x,y-1) == 1)
		dfs(x,y-1,idx+1,cnt+1);
	if(safe(x-1,y) == 1)
		dfs(x-1,y,idx+1,cnt+1); 
	if(safe(x,y+1) == 1)
		dfs(x,y+1,idx+1,cnt+1);
	
}
int main()
{
	
	//
	scanf("%d %d",&R,&C);
	for(int i=0;i<R;i++)
			scanf("%s",A[i]);
			
	//
	dfs(0,0,0,0);
	printf("%d", max + 1);
	
	return 0;
}
