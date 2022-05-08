#include<iostream>
using namespace std;
int N,M;
int arr[1001][1001];
int chk = 2;
int chkar[1001];
void print(){
	cout <<"\n=======================\n";
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++)
			cout << arr[i][j] << " ";
		cout << "\n";
	}
}
void dfs(int x,int y){
	arr[x][y] = chk;
	for(int i=1;i<=N;i++){
		if(arr[y][i] == 1)
			dfs(y,i);
	}
	return;
}

int main(){
	int a,b;
	cin >> N >> M;
	for(int i=1;i<=M;i++){
		cin >> a >> b;
		arr[a][b] = 1;
		arr[b][a] = 1;
		chkar[a]= 1, chkar[b]=1;
	}
	
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			if(arr[i][j] == 1){
				dfs(i,j);
				chk++;
			}
		}
	}
//	print();
	for(int i=1;i<=N;i++)
		if(chkar[i]==0)
			chk++;
	cout << chk-2;
}
