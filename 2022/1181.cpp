#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

string s[20003];

bool cmp(string a, string b){
	if(a.length()==b.length()){
		for(int i=0;i<a.length();i++)
			if(a[i]!=b[i])
				return a[i]<b[i];
	}
	return a.length()<b.length();
}

int main(){
	int n;
	cin >> n;

	for(int i=0;i<n;i++)
		cin >> s[i];
	
	sort(s,s+n,cmp);
	
	string tmp = s[0];
	cout << s[0] << "\n";
	
	for(int i=1;i<n;i++){
		if(tmp==s[i])	continue;
		cout << s[i] << "\n";
		tmp = s[i];
	}
}
