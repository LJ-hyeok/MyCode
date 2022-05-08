#include<iostream>
using namespace std;

const int mx = 123456*2 + 1;
int arr[mx]; 

int main(){
	//init
	for(int i=2;i<=mx;i++)	arr[i] = 1;
	for(int i=2;i<=mx;i++)
		for(int j=i+i;j<=mx;j+=i)
			arr[j] = 0;		

	while(1){
		int n, cnt = 0;
		cin >> n;
		if(n==0)	break;
		for(int i=n+1;i<=n+n;i++)
			if(arr[i])
				cnt++;
		cout << cnt << "\n";
	}
}
