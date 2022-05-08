#include<iostream>
using namespace std;

int arr[1000001];

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int N, M;
	cin >> N >> M;
	for(int i=2;i<=1000000;i++)	arr[i] = 1;
	
	for(int i=2;i<=1000000;i++){
		for(int j=i+i;j<=1000000;j+=i)
			arr[j] = 0;
	}
	for(int i=N;i<=M;i++)
		if(arr[i])
			cout << i << "\n";
}
