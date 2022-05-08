#include<iostream>
#include<algorithm>
#include<set>
using namespace std;
int N,K;
int p[100003];
int d[100003];
int col[100003];
set<int> s;
void paint(int u,int v,int c){
	if(d[u]>d[v])	swap(u,v);
	while(d[u]!=d[v]){
		col[v]=c;
		v=p[v];
	}
	while(u!=v){
		col[u]=c;
		col[v]=c;
		u=p[u];
		v=p[v];
	}
}
int count(int u, int v){
	if(d[u]>d[v])	swap(u,v);
	while(d[u]!=d[v]){
		s.insert(col[v]);
		v=p[v];
	}
	while(u!=v){
		s.insert(col[u]);
		s.insert(col[v]);
		u=p[u];
		v=p[v];
	}
	return s.size();
}
int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);
	cin >> N >> K;
	
	for(int i=1;i<=N;i++)	d[i]=1;
	
	for(int i=0;i<K;i++){
		int r,a,b,c;
		cin >> r;
		if(r==1)
		{
			cin >> a >> b >> c;
			paint(a,b,c);
		}
		if(r==2)
		{
			cin >> a >> b;
//			move(a,b);
			p[a]=b;
			d[a]=d[b]+1;
		}
		if(r==3)
		{
			cin >> a >> b;
			s.clear();
			cout << count(a,b) << '\n';
		}
	}
	return 0;
}
