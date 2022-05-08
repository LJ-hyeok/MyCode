#include<iostream>
#define INF 987654321
using namespace std;

int score[101];
int arr[101][101];

int main(){
	int n,m,r;
	cin >> n >> m >> r;
	for(int i=1;i<=n;i++)	cin >> score[i];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			arr[i][j] = INF;
	for(int i=0;i<r;i++){
		int a,b,l;
		cin >> a >> b >> l;
		arr[a][b] = min(arr[a][b],l);
		arr[b][a] = min(arr[b][a],l);
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j)	continue;
			for(int k=1;k<=n;k++){
				if(k==i || k==j)	continue;
				if(arr[j][k] > arr[j][i] + arr[i][k])
					arr[j][k] = arr[j][i] + arr[i][k];
			}
		}
	}
	
	int ans = 0;
	for(int i=1;i<=n;i++){
		int tmp = score[i];
		for(int j=1;j<=n;j++){
			if(arr[i][j]==INF)	continue;
			if(arr[i][j] <= m)	tmp += score[j];
			}
		ans = ans<tmp?tmp:ans;
	}
	
	cout << ans;

}
