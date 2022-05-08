#include<iostream>
using namespace std;

int p[1000003];
int find(int x){
	if(p[x]==x)	return x;
	return p[x] = find(p[x]);
}

void Union(int a,int b){
	a = find(a);
	b = find(b);
	if(a==b)	return;
	p[a] = b;
	
}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n;i++)	p[i] = i;
	for(int i=0;i<m;i++){
		int t,a,b;
		cin >> t >> a >> b;
		if(t==1){
			if(find(a)==find(b))	cout << "YES\n";
			else	cout << "NO\n";
		}
		if(t==0){
			Union(a,b);
		}
	}
	return 0;
}
