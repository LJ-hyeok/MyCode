#include<iostream>
#define INF 987654321
using namespace std;

int arr[401][401];

int main(){
	int V,E;
	cin >> V >> E;
	for(int i=1;i<=V;i++)
		for(int j=1;j<=V;j++)
			arr[i][j] = INF;
	
	for(int i=0;i<E;i++){
		int a,b,c;
		cin >> a >> b >> c;
		arr[a][b] = c;
	}
	
	for(int i=1;i<=V;i++){
		for(int j=1;j<=V;j++){
			for(int k=1;k<=V;k++){
				if(arr[i][k] > arr[i][j] + arr[j][k])
					arr[i][k] = arr[i][j] + arr[j][k];
			}
		}
	}
	
	int ans = INF;
	for(int i=1;i<=V;i++)	ans = ans>arr[i][i]?arr[i][i]:ans;
	ans==INF?cout << "-1":cout << ans;
}
