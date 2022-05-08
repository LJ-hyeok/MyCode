#include<iostream>
#include<string.h>
using namespace std;
int N;
bool G[101][101];
bool ans[101][101];
int chk;
void print(){
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++)
			cout << ans[i][j] <<" ";
		cout << "\n";
	}
}
void dfs(int x){
	for(int i=1;i<=N;i++){
		if(G[x][i]&&!ans[chk][i]){
			ans[chk][i]=1;
			dfs(i);
		}
	}
}

int main(){
	ios_base::sync_with_stdio;
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N;
	for(int i=1;i<=N;i++)
		for(int j=1;j<=N;j++) 
			cin >> G[i][j];
	
	for(int i=1;i<=N;i++){
		chk = i;
		dfs(i);
	}
	print();
	return 0;
}
