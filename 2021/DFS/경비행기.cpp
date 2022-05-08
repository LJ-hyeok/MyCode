#include<stdio.h>
#include<queue>
#include<math.h>
#include<string.h>
using namespace std;
struct pt{int x,y;};

int n,k;
pt arr[1003];
int d[1003][1003];
int chk[1005];
int L(pt cur,pt tmp)
{return (int)sqrt((cur.x-tmp.x)*(cur.x-tmp.x)+(cur.y-tmp.y)*(cur.y-tmp.y));}

bool bfs(int mid)
{
	queue<int> Q;
	memset(chk,-1,sizeof(chk));
	Q.push(0);
	chk[0]=0;
	while(!Q.empty())
	{
		int cur = Q.front();
		Q.pop();
		if(chk[cur]>k+1) return 0;
		if(cur == n+1) return true;	
		for(int i=0;i<=n+1;i++){
			if(d[cur][i] < mid*10 && chk[i] == -1){
				chk[i] = chk[cur]+1;
				Q.push(i);
			}
		}
		
	}
	return 0;
}

int BS()
{
	int h=14142,l=0;
	while(l<h)
	{
		int mid = (l+h-1)/2;
		if(bfs(mid))
			h = mid;
		else
			l = mid + 1;
	}
	return h;
}
int main()
{
	scanf("%d%d",&n,&k);
	int a,b;
	arr[0].x = 0, arr[0].y = 0;
	arr[n+1].x = 10000, arr[n+1].y = 10000;

	for(int i=1;i<=n;i++)
		scanf("%d %d",&arr[i].x,&arr[i].y);

	for(int i=0;i<n+1;i++)
		for(int j=0;j<=n+1;j++)
			d[i][j] = L(arr[i],arr[j]);
	
	printf("%d",BS());
	
	
	return 0;
}


//arr에 거리값을 미리 저장, 구조체 사용하여 입력 
//BS 연료통 크기
//bool bfs  연료통으로 갈수 있는지  
