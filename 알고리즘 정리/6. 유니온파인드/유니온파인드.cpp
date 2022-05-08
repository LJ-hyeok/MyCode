//BOJ_1717
#include<iostream>
#include<algorithm>
using namespace std;

int p[1000001];
int r[1000001];

int find(int u){
	if(p[u]==u)	return u;
	return p[u] = find(p[u]);
}

void Union(int u, int v){
	u = find(u);
	v = find(v);
	if(u==v)	return;
	if(r[u]>r[v])	swap(u,v);
	p[u]=v;
	if(r[u]==r[v])	++r[v];
}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int n,m;
	cin >> n >> m;
	for(int i=0;i<=n;i++)	p[i]=i;
	for(int i=0;i<m;i++){
		int a,b,c;
		cin >> a;
		if(a==1){
			cin >> b >> c;
			find(b)==find(c) ? cout << "YES\n" : cout << "NO\n";
		}
		if(a==0){
			cin >> b >> c;
			Union(b,c);
		}
	}
}
