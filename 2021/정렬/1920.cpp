//BOJ_1920
#include<iostream>
#include<algorithm>
using namespace std;
int arr[100001];

int BS(int left, int right, int x){
	while(left<=right){
		int mid = (left+right)/2;
		if(arr[mid]==x)	return 1;
		if(arr[mid]>x)
			right = mid-1;
		if(arr[mid]<x)
			left = mid+1;
	}
	return 0;
}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int N,M;
	cin >> N;
	for(int i=1;i<=N;i++)
		cin >> arr[i];
	sort(arr+1,arr+1+N);
	cin >> M;
	for(int i=0;i<M;i++){
		int a;
		cin >> a;
		cout << BS(1,N,a) << "\n";
	}
}
