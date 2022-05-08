#include<iostream>
#include<vector>
using namespace std;
using namespace std;
int main(){
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	
	v.erase(1,2);
	return 0;
}
