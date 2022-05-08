#include<iostream>
using namespace std;
int dx[]={1,0,1};
int dy[]={0,1,1};
int N,M;
int arr[1003][1003];
int dp[1003][1003];
bool safe(int x,int y){
	return x>=0 && y>=0 && x<N && y<M;
}
int main(){
	cin >> N >> M;
	for(int i=0;i<N;i++)
		for(int j=0;j<M;j++)
			cin >> arr[i][j];
	dp[0][0] = arr[0][0];
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			for(int k=0;k<3;k++){
				int tx = i + dx[k];
				int ty = j + dy[k];
				if(safe(tx,ty) && dp[i][j]+arr[tx][ty] > dp[tx][ty])
					dp[tx][ty] = dp[i][j]+arr[tx][ty];
			}
		}
	}
//	for(int i=0;i<N;i++){
//		cout << "\n";
//		for(int j=0;j<M;j++)
//			cout << dp[i][j] << " ";
//	}
	cout << dp[N-1][M-1];
	
	return 0;
}
