#include<stdio.h>
#include<vector>
#include<string.h>
#include<queue>
using namespace std;
struct pt{ int x,c; };
vector<pt> v[100003];
int arr[100003];
bool chk[100003];
int s,e;
int ans=0;
bool bfs(int mid){
	queue<pt> q;
	for(int i=0;i<v[s].size();i++){
		q.push((pt){v[s][i].x,v[s][i].c});
		chk[v[s][i].x] = 1;
	}
	
	bool flag = false;
	while(!q.empty()){
		pt cur = q.front();
		q.pop();
		if(cur.x==e && cur.c >= mid){
			flag = true;
			break;
		}
		for(int i=0;i<v[cur.x].size();i++){
			if(!chk[v[cur.x][i].x] && v[cur.x][i].c >= mid){
				q.push((pt){v[cur.x][i].x,v[cur.x][i].c});
				chk[v[cur.x][i].x] = 1;
			}
		}
	}
	return flag;
	
	
}
int BS(){
	int h = 1000000000, l = 1;
	int ans=0;
	while(h>=l){
		int mid = (h+l)/2;
//		printf("%d\t%d\t%d\n",h,mid,l);
		memset(chk,0,sizeof(chk));
		if(bfs(mid)){
			ans = max(ans,mid);
			l = mid+1;
		}
		else
			h = mid-1;
	}
	return ans;
}
int main(){
	int N,M;
	scanf("%d%d",&N,&M);
	for(int i=0;i<M;i++){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		v[a].push_back((pt){b,c});
		v[b].push_back((pt){a,c});
	}
	scanf("%d%d",&s,&e);
	printf("%d",BS());
	return 0;
}
