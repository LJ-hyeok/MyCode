#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
map<string, int> name;
int p[100003];
int r[100003];
int find(int u){
	if(u==p[u])
		return u;
	return p[u]=find(p[u]);
}
void Union(int u, int v){
	u = find(u);
	v = find(v);
	if(r[u]>r[v])
		swap(u,v);
	p[u]=v;
	if(r[u]==r[v])
		r[v]++;
}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);
	int T;
	cin >> T;
	
	while(T--){
		name.clear();
		int F;
		cin >> F;
		for(int i=0;i<F;i++){
			
			string str1,str2;
			cin >> str1 >> str2;
			int cnt = 1;
			if(!name.count(str1)){	
				name[str1]=cnt,cnt++;
				p[cnt]=cnt;
			}
			if(!name.count(str2)){	
				name[str2]=cnt,cnt++;
				p[cnt]=cnt;
			}
			
			Union(name[str1],name[str2]);
			
			int ans=0;
			for(int i=1;i<=cnt;i++)
				if(find(name[str1])==find(p[i]))
					ans++;
			cout << ans << "\n";
			
		}
		
		
	}

	return 0;
}

//1
//3
//Fred Barney
//Betty Wilma
//Barney Betty
