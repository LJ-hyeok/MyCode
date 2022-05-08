#include<iostream>
using namespace std;
int main(){
	int M,F,N;
	cin >> M >> F >> N;
	int ans = 1;
	if(M-F>=N)	cout << ans;
	else
	{
		N-=M-F;
		ans += N/M + 1;
		cout << ans;
	}
	
	return 0;
}
