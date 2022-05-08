#include<iostream>
#define INF 987654321
using namespace std;

int arr[21][21];
int edge[21][21];

int main(){
	int N;
	cin >> N;
	for(int i=1;i<=N;i++)
		for(int j=1;j<=N;j++)
			cin >> arr[i][j];
	for(int i=1;i<=N;i++)
		for(int j=1;j<=N;j++)
			edge[i][j] = arr[i][j];
			
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			if(i==j)	continue;
			for(int k=1;k<=N;k++){
				if(i==k || j==k)	continue;
				if(arr[j][k] >= arr[j][i] + arr[i][k]){
					edge[j][k] = 0;
				}
			}
		}
	}
	
	bool flag = true;
	int ans = 0;
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			if(i<j)				ans += edge[i][j];
			if(edge[i][j]==0)	edge[i][j] = INF;
		}
	}
	
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			if(i==j)	continue;
			for(int k=1;k<=N;k++){
				if(i==k || j==k)	continue;
				if(edge[j][k] > edge[j][i] + edge[i][k])
					edge[j][k] = edge[j][i] + edge[i][k];
			}
		}
	}
	
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			if(edge[i][j]==INF)	edge[i][j] = 0;
			if(arr[i][j]!=edge[i][j])	flag = false;
		}
	}
	flag ? cout<<ans : cout<<"-1";
}
