#include<iostream>
using namespace std;

int fn(int n, int cnt){
	return n/cnt*(cnt+1);
}

int lcm(int x, int y){
	int cx=1, cy=1;
	while(true){
		if(x==y)	return x;
		
		if(x < y){
			x = fn(x, cx);
			cx++;
		}
		else if(x > y){
			y = fn(y, cy);
			cy++;
		}
	}
}

int main(){
	int t;
	cin >> t;
	while(t--){
		int a,b;
		cin >> a >> b;
		cout << lcm(a,b) << "\n";
	}
}
