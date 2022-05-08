#include<bits/stdc++.h>
using namespace std;

stack<int> ans;

void BigNumSum(string a, string b){
	for(int i=0;i<a.length()/2;i++)
		swap(a[i], a[a.length()-i-1]);
	for(int i=0;i<b.length()/2;i++)
		swap(b[i], b[b.length()-i-1]);
	int last = a.length()>b.length() ? a.length() : b.length();
	int x,y,z = 0;
	
	for(int i=0;i<last;i++){
		if(a.length() > i )	x = a[i] - 48;
		if(b.length() > i )	y = b[i] - 48;
		int tmp = x+y+z;
		if(tmp>9){
			ans.push(tmp-10);
			z = 1;
		}
		else{
			ans.push(tmp);
			z = 0;
		}
		x = y = 0;
	}
	if(z==1)	ans.push(1);
	
}

int main(){
	int n;
	cin >> n;
	cout << pow(2,n)-1;
	hanoi(n,1,2,3);
	
}
