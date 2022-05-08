#include<iostream>
#include<queue>
#include<string.h>
using namespace std;

int chk[10];

int MaxInQ(){
	for(int i=9;i>=1;i--){
		if(chk[i]){
			chk[i]--;
			return i;
		}
	}
}

int main(){
	int T;
	cin >> T;
	while(T--){
		queue<pair<int,int>> q;
		memset(chk,0,sizeof(chk));
		int cnt = 1;	
		int n,m;
		cin >> n >> m;
		for(int i=0;i<n;i++){
			int a;
			cin >> a;
			chk[a]++;
			q.push({a,i});
		}
		int mx = MaxInQ();
		while(!q.empty()){
			if(q.front().first==mx){
				if(q.front().second==m)
					break;
				else{
					cnt++;
					mx = MaxInQ();
					q.pop();
				}
			}
			else{
				q.push(q.front());
				q.pop();
			}
		}
		cout << cnt << "\n";
	}
}
