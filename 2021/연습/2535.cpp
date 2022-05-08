#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct pt{int x,y,z;};
vector<pt> v;
int dp[101];

bool cmp(pt a,pt b){
	return a.z > b.z;
}

int main(){
	int N;
	cin >> N;
	for(int i=0;i<N;i++){
		int a,b,c;
		cin >> a >> b >> c;
		v.push_back((pt){a,b,c});
	}
	sort(v.begin(),v.end(),cmp);
	int cnt = 0;
	for(int i=0;i<v.size();i++){
		if(cnt>=3)	break;
		if(dp[v[i].x]>=2)	continue;
		cnt++;
		dp[v[i].x]++;
		cout << v[i].x << " " << v[i].y << "\n";
	}
}
