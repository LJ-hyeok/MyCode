#include<iostream>
#include<set>
using namespace std;
int main(){
	set<int> A,B,tmp;
	int n,m;
	cin >> n >> m;
	for(int i=0;i<n;i++){
		int a;
		cin >> a;
		A.insert(a);
	}
	for(int i=0;i<m;i++){
		int b;
		cin >> b;
		B.insert(b);
	}
	
	tmp=B;
	for(auto i:A)
		if(B.count(i))
			B.erase(i);
	for(auto i:tmp)
		if(A.count(i))
			A.erase(i);
	
	cout << A.size()+B.size();
	
}
