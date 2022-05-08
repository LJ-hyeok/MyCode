#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct pt{
	int f,t,c;
};
vector<pt> v;
int p[10001];

bool cmp(pt a, pt b){
	return a.c < b.c;
}

int find(int x){
	if(x==p[x])	return x;
	return p[x] = find(p[x]);
}

int main(){
	int V,E;
	cin >> V >> E;
	for(int i=0;i<E;i++){
		int a,b,c;
		cin >> a >> b >> c;
		v.push_back({a,b,c});
	}
	
	for(int i=1;i<=V;i++)	p[i] = i;
	sort(v.begin(),v.end(),cmp);
	
	int ans = 0;
	for(int i=0;i<v.size();i++){
		int x = find(v[i].f);
		int y = find(v[i].t);
		if(x==y)	continue;
		p[x] = y;
		ans+=v[i].c;
	}
	cout << ans;
}
