#include<iostream>
#include<map>
using namespace std;
int main(){
	
	map<string, int> Map;
	Map["abc"] = 3;
	Map["abc"] = 2;
	Map["ghi"] = 3;
	Map["jkl"] = 4;
	
	
	cout << Map.count("abc");
	
	return 0;
}   
