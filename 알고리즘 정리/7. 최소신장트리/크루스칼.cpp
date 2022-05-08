#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct pt{int f,t,w;};
vector<pt> v;
int p[1001];

bool cmp(pt a,pt b){	return a.w<b.w;}

int find(int u){
	if(p[u]==u)	return u;
	return p[u] = find(p[u]);
}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int N,M;
	cin >> N >> M;
	for(int i=1;i<=N;i++)	p[i]=i;
	for(int i=0;i<M;i++){
		int a,b,c;
		cin >> a >> b >> c;
		v.push_back((pt){a,b,c});
	}
	
	int sum = 0;
	sort(v.begin(),v.end(),cmp);
	for(int i=0;i<v.size();i++){
		int a = find(v[i].f);
		int b = find(v[i].t);
		if(a==b)	continue;
		p[a]=b;
		sum+=v[i].w;
	}
	
	cout << sum;
}
