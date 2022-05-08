#include<iostream>
#include<algorithm>
using namespace std;

int n,m;
int arr[100003];

bool bs(int x){
	int lo, hi, mid;
	lo = 0;
	hi = n-1;
	while(lo<=hi){
		mid = (lo+hi)/2;
		if(arr[mid] == x)
			return true;
		else if(arr[mid] > x)
			hi = mid-1;
		else
			lo = mid+1;
	}
	return false;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for(int i=0;i<n;i++)
		cin >> arr[i];
	sort(arr,arr+n);
	cin >> m;
	for(int i=0;i<m;i++){
		int in;
		cin >> in;
		cout << bs(in) << "\n";
	}
}
