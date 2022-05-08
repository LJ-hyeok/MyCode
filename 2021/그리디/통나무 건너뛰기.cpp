#include<iostream>
#include<algorithm>
using namespace std;
int T,N;
int arr[10001];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> T;
	while(T--)
	{
		cin >> N;
		for(int i=0;i<N;i++) cin >> arr[i];
		sort(arr,arr+N);
		int a,b;
		int tmp=0;
		for(int i=0;i<N;i++){
			if(i+2<N)
				tmp = max(tmp,arr[i+2]-arr[i]);
		}
		cout << tmp << "\n";
	}
	 
	return 0;
}
