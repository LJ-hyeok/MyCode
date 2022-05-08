#include<stdio.h>
#include<queue>
char A[55][55];
int arr[55][55];
using namespace std;
int n,m; 
bool safe(int x, int y){return x>=0 && y>=0 && x<n && y<m;}
struct pt{
	int x;
	int y;
};
int dx[]={1,0};
int dy[]={0,1};
int main()
{
	
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;++i){
		scanf("%s",A[i]);	
		for(int j=0;j<m;j++)
		{
			if(A[i][j]=='W')
				arr[i][j] = 1;// W -> 1
			else
				arr[i][j] = 0;// B -> 0
		}
	} 
	queue<pt> Q;
	
	Q.push({0,0}); 
	while(!Q.empty()){
		pt cur = Q.front();
		Q.pop();
		for(int i=0;i<2;i++){
			int tx = dx[i]+cur.x;
			int ty = dy[i]+cur.y;
			if(safe(tx,ty) && arr[tx][ty] == 0){
				
				Q.push({tx,ty});
			}
		}
	}
	return 0;
}
