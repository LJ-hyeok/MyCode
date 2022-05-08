#include<iostream>
#include<queue>
using namespace std;

struct pt{int x,y;};

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int arr[51][51];

bool safe(int x,int y,int n,int m){return x>=0 && y>=0 && x<n && y<m;}

void bfs(int x, int y, int n, int m){
	queue<pt> q;
	q.push((pt){x,y});
	arr[x][y] = 2;
	while(!q.empty()){
		pt cur = q.front();
		q.pop();
		for(int i=0;i<4;i++){
			int tx = dx[i] + cur.x;
			int ty = dy[i] + cur.y;
			if(safe(tx,ty,n,m) && arr[tx][ty] == 1){
				arr[tx][ty] = 2;
				q.push((pt){tx,ty});
			}
		}
	}
	return;
}

int main(){
	int T;
	cin >> T;
	while(T--){
		//memset
		int n,m,k;
		cin >> n >> m >> k;
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				arr[i][j] = 0;
		
		//input
		for(int i=0;i<k;i++){
			int a,b;
			cin >> a >> b;
			arr[a][b] = 1;
		}
		
		//bfs
		int ans = 0;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(arr[i][j] == 1){
					bfs(i,j,n,m);
					ans++;
				}
			}
		}
		
		//output
		cout << ans << "\n";
		
		
	}
}
