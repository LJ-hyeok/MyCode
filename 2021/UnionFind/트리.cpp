#include<iostream>
#include<utility>
#include<stack>
#include<algorithm>
using namespace std;
int N,Q;
int d[200005];
int p[200005];
int r[200005];
typedef pair<int,int> pil;
stack<pil> s;
stack<int> a;

int find(int u){
	if(p[u]==u)	return u;
	return p[u] = find(p[u]);
}

void Union(int u,int v){
	u = find(u);
	v = find(v);
	if(u==v)	return;
	if(r[u]>r[v])	swap(u,v);
	p[u]=v;
	if(r[u]==r[v]) ++r[v];
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> N >> Q;
	for(int i=1;i<=N;i++)	p[i] = i;
	d[1]=1;
	for(int i=2;i<N+1;i++)	cin >> d[i];
	
	for(int i=0;i<(N-1)+Q;i++){
		int x,a,b=0;
		cin >> x;
		if(!x)	cin >> a;
		if(x)	cin >> a >> b;
		s.push((pil){a,b});
	}
	
	while(!s.empty()){
		pil cur = s.top();
		s.pop();
		if(cur.second==0)
			Union(cur.first,d[cur.first]);
		else{
			if(find(cur.first)==find(cur.second))
				a.push(1);
			else
				a.push(0);
		}
	}
	while(!a.empty()){
		if(a.top()==1)	cout << "YES\n";
		else	cout << "NO\n";
		a.pop();
	}
	
	return 0;
}
