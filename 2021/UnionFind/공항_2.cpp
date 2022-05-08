#include<iostream>
using namespace std;
int G,P;
int p[100005];
bool c[100005];
int lo = 1;
void find(int x){
	if(!c[x]){
		lo = x;
		return;
	}
	find(x+1);
}
int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int cnt = 0;
	cin >> G >> P;
	for(int i=1;i<=P;i++) cin >> p[i];
	for(int i=1;i<=P;i++){
		int cur = p[i];
		if(!c[cur])
			c[cur] = true;
		else{
			find(lo);
			if(lo>=cur || G<lo)	break;
			c[lo] = true;
		}
		cnt++;
	}
	cout << cnt;
	return 0;
}
