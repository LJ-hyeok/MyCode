#include<iostream>
#include<algorithm>
using namespace std;
int N,M,K;
int arr[303][303];
int dp[303][303];
int main(){
	cin >> N >> M >> K;
	for(int i=0;i<K;i++){
		int a,b,c;
		cin >> a >> b >> c;
		arr[a][b] = max(arr[a][b],c);
	}
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			for(int k=1;k<=N;k++){
				dp[i][k]+
			}
		}
	}
	return 0;
}
