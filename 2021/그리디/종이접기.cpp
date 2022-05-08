#include<iostream>
#include<string>
using namespace std;

bool fn(string s){
	if(s.size()<=2)	return true;
	for(int i=0;i<s.size()/2;i++)
		if(s[i]==s[s.size()-i-1])
			return false;
	return fn(s.substr(0,s.size()/2));
}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		fn(s)?cout << "YES\n" : cout << "NO\n";
	}
}
