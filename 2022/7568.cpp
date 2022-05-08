#include<iostream>
using namespace std;

int m[51];
int h[51];
int ans[51];

int main(){
	int N;
	cin >> N;
	for(int i=0;i<N;i++)
		cin >> m[i] >> h[i];
	
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(i==j)	continue;
			if(m[i]<m[j] && h[i]<h[j])
				ans[i]++;
		}
	}
	for(int i=0;i<N;i++)
		cout << ans[i]+1 << " ";
}
