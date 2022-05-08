#include<iostream>
using namespace std;

int N, way;
int arr[21][21];
int chk[21][21];
int cnt;
int ans = 0;

void initialization(){
	for(int i=1;i<=N;i++)
		for(int j=1;j<=N;j++)
			chk[i][j] = arr[i][j];
}

void D(){
}

void dfs_1(){
}

void dfs_2(){
}

void dfs_3(){
}

void dfs_4(){
}

void first_cut(int x,int y){
	for(int i=1;i<=N;i++){
		if(arr[x][i]==2)	return;
		chk[x][i] = -1;
	}
	dfs_1();
	dfs_3();
}
void second_cut(int x,int y){
	for(int i=1;i<=N;i++){
		if(arr[i][y]==2)	return;
		chk[i][y] = -1;
	}
	dfs_2();
	dfs_4();
}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin >> N;
	int c1 = 0;
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			cin >> arr[i][j];
			if(arr[i][j]==1)	c1++;
		}
	}

	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			if(arr[i][j]==1){
				cnt = c1;
				initialization();
				first_cut(i,j);//가로
				
				cnt = c1;
				initialization();
				second_cut(i,j);//세로 
			}
		}
	}
	cout << ans;
			
}
