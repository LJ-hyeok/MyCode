#include<iostream>
#include<string>
#include<set>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	set<string> s;
	string a;
	int N,M;
	cin >> N >> M;
	for(int i=0;i<N;i++){
		cin >> a;
		s.insert(a);
	}
	int ans=0;
	for(int i=0;i<M;i++){
		cin >> a;
		if(s.count(a))
			ans++;
	}
	cout << ans;
}
