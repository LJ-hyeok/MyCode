#include<iostream>
#include<algorithm>
using namespace std;

int gcd(int x,int y){
	if(x<y)	swap(x,y);
	while(y!=0){
		int r = x%y;
		x = y;
		y = r;
	}
	return x;
}

void solve(int x,int y){
	int gcd_xy = gcd(x,y);
	cout << x/gcd_xy << "/" << y/gcd_xy << "\n";
}

int main(){
	int n, A, B;
	cin >> n;
	cin >> A;
	for(int i=0;i<n-1;i++){
		cin >> B;
		solve(A,B);
	}
}
