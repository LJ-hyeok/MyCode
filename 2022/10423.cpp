#include<iostream>
#include<vector>
#include<queue>
#include<string.h>
#include<algorithm>
using namespace std;

struct pt{
	int f,t,c;
};
vector<pt> v;
vector<pt> Lessv;
int p[1001];
int chk[1001];
int arr[1001][1001];
int power[1001];
int N,M,K;

bool cmp(pt a, pt b){	return a.c < b.c;}
bool cmp2(pt a, pt b){	return a.c > b.c;}

int find(int u){
	if(u==p[u])	return u;
	return p[u] = find(p[u]);
}

bool bfs(int s){
	memset(chk,0,sizeof(chk));
	queue<int> q;
	q.push(s);
	chk[s] = 1;
	bool flag = false;
	while(!q.empty()){
		int cur = q.front();
		q.pop();
		if(power[cur])	flag = true;
		for(int i=1;i<=N;i++){
			if(arr[cur][i] && !chk[i]){
				q.push(i);
				chk[i] = 1;
			}
		}
	}
	return flag;
}

int main(){
	//init
	cin >> N >> M >> K;
	for(int i=0;i<K;i++){
		int a;
		cin >> a;
		power[a] = 1;
	}
	for(int i=0;i<M;i++){
		int a,b,c;
		cin >> a >> b >> c;
		v.push_back((pt){a,b,c});
	}
	for(int i=1;i<=N;i++)	p[i] = i;
	
	sort(v.begin(),v.end(),cmp);
	int ans = 0;
	for(int i=0;i<v.size();i++){
		int x = find(v[i].f);
		int y = find(v[i].t);
		if(x==y)	continue;
		arr[v[i].f][v[i].t] = 1, arr[v[i].t][v[i].f] = 1;
		p[x] = y;
		ans += v[i].c;
		Lessv.push_back(v[i]);
	}
	
	sort(Lessv.begin(),Lessv.end(),cmp2);
	int cnt = 0;
	for(int i=0;i<Lessv.size();i++){
		if(cnt==K-1)	break;
		int cx = Lessv[i].f, cy = Lessv[i].t;
		arr[cx][cy] = 0, arr[cy][cx] = 0;
		
		if(bfs(cx) && bfs(cy)){
			ans-=Lessv[i].c;
			cnt++;
		}
		else
			arr[cx][cy] = 1, arr[cy][cx] = 1;
	}
	cout << ans;
}
