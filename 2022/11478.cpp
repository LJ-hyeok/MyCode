#include<iostream>
#include<set>
using namespace std;
set<string> s;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string S;
	cin >> S;
	for(int i=0;i<S.length();i++){
		for(int j=1;j<=S.length()-i;j++){
			s.insert(S.substr(i,j));
		}
	}
	cout << s.size();
}
