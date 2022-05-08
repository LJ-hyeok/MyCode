#include<iostream>
using namespace std;

int arr[2200][2200];
int ans[3];

bool chk(int x,int y,int s){
	int cmp = arr[x][y];
	for(int i=x;i<x+s;i++)
		for(int j=y;j<y+s;j++)
			if(cmp!=arr[i][j])
				return false;
	return true;
}

void fn(int x,int y,int s){
	if(chk(x,y,s)){
		ans[arr[x][y]+1]++;
		return;
	}
	int n = 0, m = 0, t = s/3;
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			fn(x+n,y+m,t);
			m+=t;
		}
		m = 0;
		n+=t;
	}
}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int N;
	cin >> N;
	for(int i=1;i<=N;i++)
		for(int j=1;j<=N;j++)
			cin >> arr[i][j];
	fn(1,1,N);
	for(int i=0;i<3;i++)
		cout << ans[i] << "\n";
}
