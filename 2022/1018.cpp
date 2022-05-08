#include<iostream>
using namespace std;

int arr[51][51];
int n,m;

int fn(bool col, int x, int y){
	int cnt = 0;
	bool tmp;
	for(int i=x;i<x+8;i++){
		col = !col;
		for(int j=y;j<y+8;j++){
			if(j%2==0)	tmp = col;
			else		tmp = !col;
			if(arr[i][j] != tmp)
				cnt++;
		}
	}
	return cnt;
}

int main(){
	cin >> n >> m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			char a;
			cin >> a;
			if(a=='W')
				arr[i][j] = 1;
			if(a=='B')
				arr[i][j] = 0;
		}
	}
	
	int ans = 64+1;
	for(int i=0;i<=n-8;i++){
		for(int j=0;j<=m-8;j++){
			int x = fn(1,i,j);
			int y = fn(0,i,j);
			ans = ans>x ? x : ans;
			ans = ans>y ? y : ans;
		}
	}
	
	cout << ans;
}
