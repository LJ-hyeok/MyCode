#include<iostream>
#include<algorithm>
using namespace std;
int N,H;
int arr[500001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> H;
	int a,b;
	for(int i=0;i<N/2;i++){
		cin >> a;
		cin >> b;
		arr[a]--;
		arr[H-b]++;
	}
	
 	int cnt = N/2;
 	for(int i=1;i<=H;i++){
		cnt += arr[i];
		cout << cnt <<" ";
		arr[i] = cnt;
	}
	
	int res,resN=0;
	for(int i=1;i<H;i++)
		res = min(arr[i],arr[i+1]);
	for(int i=1;i<=H;i++)
		if(arr[i] == res)
			resN++;
	cout << res << " " << resN;
	return 0;
}
