#include<iostream>
using namespace std;

const int mx = 10000;
int arr[mx+1]; 

void solve(int x){
	int l,r;
	for(int i=2;i<=x/2;i++){
		if(arr[i] && arr[x-i]){
			l = i;
			r = x-i;
		}
	}
	cout << l << " " << r << "\n";
}

int main(){
	//init
	for(int i=2;i<=mx;i++)	arr[i] = 1;
	for(int i=2;i<=mx;i++)
		for(int j=i+i;j<=mx;j+=i)
			arr[j] = 0;		

	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		int a;
		cin >> a;
		solve(a);
	}
}
