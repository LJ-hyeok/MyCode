#include<iostream>
using namespace std;

bool D(int x){
	bool flag = 1;
	if(x==1)	flag = 0;
	for(int i=2;i<x;i++)
		if(x%i==0)
			flag = 0;
	return flag;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int n, m, sum = 0, mn;
	bool flag = true, chk = false;
	cin >> n >> m;
	
	for(int i=n;i<=m;i++){
		if(D(i)){
			chk = true;
			sum+=i;
			if(flag){
				mn = i;
				flag = false;
			}
		}
	}
	chk ? cout << sum << "\n" << mn : cout << "-1";
}
