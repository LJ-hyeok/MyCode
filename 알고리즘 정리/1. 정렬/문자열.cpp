//BOJ_1427
#include<iostream>
#include<algorithm>
using namespace std;

bool cmp(char a, char b){
	return a>b;
}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); 
	string s;
	cin >> s;
	sort(s.begin(),s.end(),cmp);
	cout << s;
}
