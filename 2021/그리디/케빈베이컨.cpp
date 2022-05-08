#include<iostream>
#include<algorithm>
using namespace std;

const int INF = 987654321;
int arr[101][101];

int main(){
	int N,M;
	cin >> N >> M;
	for(int i=1;i<=N;i++)
		for(int j=1;j<=N;j++)
			arr[i][j]=INF;

	for(int i=0;i<M;i++){
		int a,b;
		cin >> a >> b;
		arr[a][b]=1, arr[b][a]=1;
	}
	
	for(int k=1;k<=N;k++){
		for(int i=1;i<=N;i++){
			if(i==k)	continue;
			for(int j=1;j<=N;j++){
				if(j==i || j==k)	continue;
				arr[i][j] = min(arr[i][j], arr[i][k]+arr[k][j]);
			}
		}
	}
	int tmp = INF;
	int idx;
	for(int i=N;i>=1;i--){
		int sum = 0;
		for(int j=1;j<=N;j++){
			if(arr[i][j]==INF)	continue;
			sum+=arr[i][j];
		}
		if(tmp>=sum){
			tmp = sum;
			idx = i;
		}
	}
	cout << idx;
}
