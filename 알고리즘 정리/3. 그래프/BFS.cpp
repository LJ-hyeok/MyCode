//BOJ_2667
#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int arr[26][26];
int ans[25*25/2+2];
int n, cnt=1;

bool safe(int x, int y){return x>0 && y>0 && x<=n && y<=n;}

void bfs(int x,int y){ 
	queue<pair<int,int>> q;
	q.push({x,y});
	cnt++;
	arr[x][y]=cnt;
	ans[cnt]++;
	while(!q.empty()){
		int x = q.front().first, y = q.front().second;
		q.pop();
		for(int i=0;i<4;i++){
			int tx = x + dx[i];
			int ty = y + dy[i];
			if(safe(tx,ty) && arr[tx][ty]==1){
				if(arr[tx][ty]!=cnt)	ans[cnt]++;
				arr[tx][ty] = cnt;
				q.push({tx,ty});
			}
		}
	}
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			scanf("%1d",&arr[i][j]);
	
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(arr[i][j]==1)
				bfs(i,j);

	printf("%d\n",cnt-1);
	sort(ans+2,ans+1+cnt);
	for(int i=2;i<=cnt;i++)
		printf("%d\n",ans[i]);
}
