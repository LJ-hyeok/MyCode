#include<iostream>
using namespace std;

int arr[100001];
int chk[100001];

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int N,M;
	cin >> N >> M;
	for(int i=0;i<M;i++){
		int a,b;
		cin >> a >> b;
		arr[a]++;
		arr[b]--;
	}
	for(int i=1;i<=N;i++){
		arr[i] += i;
		if(chk[arr[i]]){
			cout << "-1";
			return 0; 
		}
		chk[arr[i]] = 1;
	}
	for(int i=1;i<=N;i++)
		cout << arr[i] << " ";
}
