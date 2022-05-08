#include<iostream>
#include<vector>
#include<string>
using namespace std;
string net[100000]

int find(string u){
	if(u==net(u))
		return u;
	return net[u]=find(net[u]);
}

void Union(string u, string v){
	u = find(u);
	v = find(v);
	
}

int main(){
	int T;
	cin >> T;
	while(T--){
		int F;
		cin >> F;
		for(int i=0;i<F;i++){
			string a,b;
			cin >> a >> b;
			Union(a,b);
		}
	}
	return 0;
}
