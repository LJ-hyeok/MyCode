#include<bits/stdc++.h>
using namespace std;
const int mx = 6561;

int arr[mx+1][mx+1];
int dx[8] = {0, 0, 0, 1, 1, 2, 2, 2};
int dy[8] = {0, 1, 2, 0, 2, 0, 1, 2};
int n;

bool safe(int x,int y){
	return x>0 && y>0 && x<=n && y<=n;
}

void recur(int k, int x, int y){
	if(k==0)	return;
	
	int tx = x + k;
	int ty = y + k;
	for(int i=tx;i<tx+k;i++)
		for(int j=ty;j<ty+k;j++)
			arr[i][j] = 0;

	for(int i=0;i<8;i++){
		int nx = x + dx[i] * k;
		int ny = y + dy[i] * k;
		if(safe(nx,ny))
			recur(k/3, nx, ny);
	}
}

void solve(int k){
	for(int i=1;i<=k;i++)
		for(int j=1;j<=k;j++)
			arr[i][j] = 1;
	recur(k/3,1,1);
}

int main(){
	cin >> n;
	solve(n);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(arr[i][j])
				cout << "*";
			else
				cout << " ";
		}
		cout << "\n";
	}
}
