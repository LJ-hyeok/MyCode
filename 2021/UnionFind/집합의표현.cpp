#include<iostream>
#include<algorithm>
using namespace std;
int p[1000005];
int r[1000005];
int n,m;
int find(int u){
	if(u == p[u])	return u;
	return p[u]=find(p[u]);
}
void Union(int u, int v){
	u = find(u);
	v = find(v);
	if(u==v)  return;
	if(r[u]>r[v]) swap(u,v);
	p[u]=v;
	if(r[u]==r[v])	++r[v];
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0); 
	cin >> n >> m;
	for(int i=0;i<=n;i++)	p[i] = i;
	for(int i=0;i<m;i++){
		bool a;
		int b,c;
		cin >> a >> b >> c;
		if(!a){
			Union(b,c);
			for(int i=0;i<=n;i++)
				cout << p[i] << " ";
			cout << "\n"; 
			continue;
		}
		if(p[b]==p[c])	cout << "YES\n";
		else	cout << "NO\n";
	}
	return 0;
}
