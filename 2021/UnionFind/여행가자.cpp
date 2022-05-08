#include<iostream>
#include<algorithm>
using namespace std;
int p[203];
int r[203];
int N,M;
int find(int u){
	if(u==p[u])
		return u;
	return find(p[u]);
}
void Union(int u,int v){
	u = find(p[u]);
	v = find(p[v]);
	if(r[u]>r[v])
		swap(u,v);
	p[u] = v;
	if(r[u] == r[v]) 
		r[v]++;
}
void print(){
	for(int i=1;i<=N;i++)
		cout << p[i] << " ";
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(NULL);
	cin >> N >> M;
	for(int i=1;i<=N;i++) p[i] = i;
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			int a;
			cin >> a;
			if(a)
				Union(i,j);
		}
	}
	int cm;
	cin >> cm;
	bool ans = true;
	for(int i=0;i<M-1;i++){
		int cur;
		cin >> cur;
		if(find(cm)!=find(cur))
			ans=false;
	}
//	print();
	if(ans)
		cout << "YES";
	else
		cout << "NO";
	
	return 0;
}
