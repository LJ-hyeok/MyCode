#include<iostream>
#include<string>
#include<vector>
using namespace std;

int n,m;
string s,p;
vector<int> pi;
int ans = 0;

void KMP(){
	int j = 0;
	for(int i=0;i<s.size();i++){
		while(j>0 && s[i]!=p[j])
			j = pi[j-1];
		if(s[i]==p[j]){
			if(j==p.length()-1){
				ans++;
				j = pi[j];
			}
			else
				++j;
		}
	}
}

void getpi(){
	pi.resize(p.length());
	int j = 0;
	for(int i=1;i<p.size();i++){
		while(j>0 && p[i]!=p[j])
			j = pi[j-1];
		if(p[i]==p[j])
			pi[i] = ++j;
	}
}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin >> n >> m >> s;
	for(int i=0;i<n;i++){p.push_back('I');p.push_back('O');}p.push_back('I');
	getpi();
	KMP();
	cout << ans;
}
