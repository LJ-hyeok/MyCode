#include<iostream>
#include<algorithm>
using namespace std;
int L,K,C;
int arr[10001];
int main()
{	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> L >> K >> C;
	for(int i=0;i<K;++i)
		cin >> arr[i];
	sort(arr,arr+K);
	K--;
	int frontS=0,backS=L;
	int i = 0;
	while(C--){
		if(backS-arr[K-i]<arr[i]-frontS){
			backS=arr[K-i];
			cout << backS << "\n";
		}
		else{
			frontS=arr[i];
			cout << frontS << "\n";
		}
		i++;
	}
	cout << backS-frontS;
	
	return 0;
}
