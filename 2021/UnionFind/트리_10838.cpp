#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
int p[100005];
int c[100005];
bool chk[1000000003];
int N,K;
int color, tn;
int cnt;
void chk0(int u){
	chk[u] = 1;
	if(u==0)
		return;
	chk0(p[u]);
}
void chk1(int u){
	if(chk[u]){
		tn = u;
		return;
	}
	chk1(p[u]);
}
void paint(int u){
	c[u] = color;
	if(u==tn)
		return;
	paint(p[u]);
}
void count(int u){
	if(chk[c[u]]!=1){
		cnt++;
		chk[c[u]]=1;
	}
	if(u==tn)
		return;
	count(p[u]);
}
int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	cin >> N >> K;
	for(int i=1;i<=N;i++)
		p[i] = 0;
	for(int i=0;i<K;i++){
		int r,a,b,c;
		cin >> r;
		if(r==1){//paint
			cin >> a >> b >> c;
			color = c;
			chk0(a), chk1(b);
			paint(a),paint(b);
			memset(chk,0,sizeof(chk));
		}
		if(r==2){//move
			cin >> a >> b;
			p[a] = b;
		}
		if(r==3){//count
			cin >> a >> b;
			chk0(a),chk1(b);
			cnt = 0;
			count(a),count(b);
			memset(chk,0,sizeof(chk));
			cout << cnt << "\n";
		}
	}		
	return 0;
}
