#include<iostream>
using namespace std;
int G,P;
int p[100003];
int find(int u){
	if(u==p[u])
		return u;
	return p[u] = find(p[u]);
}
void Union(int u, int v){
	p[u] = v;
}
int main(){
	cin >> G >> P;
	for(int i=1;i<=G;i++)	p[i]=i;
	int cnt = 0;
	for(int i=0;i<P;i++){
		int cur;
		cin >> cur;
		if(find(cur)==0)	break;
		int f = find(cur);
		Union(f,f-1);
		cnt++;
	}
	cout << cnt;
	return 0;
}
