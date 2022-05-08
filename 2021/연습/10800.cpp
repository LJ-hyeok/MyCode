#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct pt{int num,col,sz;};
vector<pt> v;
int ans[200001];
int dp[200001];

bool cmp(pt a,pt b){
	return a.sz<b.sz;
}

int main(){
	int N;
	cin >> N;
	for(int i=0;i<N;i++){
		int a,b;
		cin >> a >> b;
		v.push_back({i+1,a,b});
	}
	sort(v.begin(),v.end(),cmp);
//	for(int i=0;i<v.size();i++)
//		cout << v[i].num << " " << v[i].col << " " << v[i].sz << "\n";
	int sum = 0, cnt = 1, pri = 0;
	for(int i=0;i<v.size();i++){
		
		ans[v[i].num] = sum - dp[v[i].col];
		if(pri==v[i].sz){
			cnt++;
		}
		else{
			sum += pri*cnt + v[i].sz;
			dp[v[i].col] += pri*cnt + v[i].sz;
			cnt = 1;
		}
		pri = v[i].sz;
		
	}
	for(int i=1;i<=N;i++)
		cout << ans[i] << "\n";
	return 0;
}

