#include<iostream>
#include<algorithm>
using namespace std;
int n,m;
int p[101];
int r[101]; //자식 노드가 총 몇개인지 //깊이를 줄이는 역할 
int find(int u){
  if(u == p[u]) return u;
  return find(p[u]);
}
void Union(int u, int v){
  u = find(u);
  v = find(v);
  if(u==v) return;
  if(r[u]>r[v]) swap(u,v);
  p[u] = v;
  if(r[u] == r[v]) ++r[v];
}
void print(){
	for(int i=1;i<=n;i++)
		cout << p[i] << " ";
	cout << "\n\n";
}
int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin >> n >> m;
  for(int i=1;i<=n;i++) p[i] = i;
  for(int i=0;i<m;i++){
    int a,b;
    cin >> a >> b;
    Union(a,b);
//    print();
  }
  int cnt = 0;
  for(int i=2;i<=n;i++)
    if(find(1) == find(i)) cnt++;
  cout << cnt;
  return 0;
}
