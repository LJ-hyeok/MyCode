//BOJ_1786
#include<iostream>
#include<string>
#include<vector>
using namespace std;

vector<int> pi;
vector<int> ans;
string s,p;

void KMP(){
	int j=0;
	for(int i=0;i<s.length();i++){
		while(j>0 && s[i]!=p[j])
			j = pi[j-1];
		if(s[i]==p[j]){
			if(j==p.length()-1){
				ans.push_back(i-p.length()+2);
				j = pi[j];
			}
			else
				++j;
		}
	}
}

void getpi(){
	pi.resize(p.length());
	int j=0;
	for(int i=1;i<p.length();i++){//////////1บฮลอ 
		while(j>0 && p[i]!=p[j])
			j=pi[j-1];
		if(p[i]==p[j])
			pi[i] = ++j;
	}
}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	getline(cin,s);
	getline(cin,p);
	getpi();
	KMP();
	cout << ans.size() << "\n";
	for(int i=0;i<ans.size();i++)
		cout << ans[i] << "\n";
}
