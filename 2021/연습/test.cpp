#include<iostream>
#include<vector>
using namespace std;
int main(){
	vector<int> v;
	vector<int> a;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.resize(3);
	v=a;
	for(int i=0;i<v.size();i++){
		cout << v[i];
	}
}
