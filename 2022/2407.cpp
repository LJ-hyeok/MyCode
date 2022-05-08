#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

string dp[103][103];

string sum(string a,string b){
	string ret;
	int e = a.length()>b.length() ? a.length() : b.length();
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());
	int tmp=0;
	for(int i=0;i<=e;i++){
		if(a.length()>=i+1)		tmp += a[i]-'0';
		if(b.length()>=i+1)		tmp += b[i]-'0';
		
		if(tmp>9){
			tmp -= 10;
			ret.push_back(tmp+'0');
			tmp = 1;
		}
		else {
			ret.push_back(tmp+'0');
			tmp = 0;
		}
	}
	if(ret[ret.length()-1]=='0')	ret.pop_back();
	reverse(ret.begin(),ret.end());
	return ret;
}

void solve(int n,int k){
	dp[0][0]="1";
	for(int i=1;i<=n;i++){
		for(int j=0;j<=i;j++){
			if(j==0 || j==i){
				dp[i][j]="1";
				continue;
			}
			dp[i][j] = sum(dp[i-1][j-1], dp[i-1][j]);
		}
	}
	cout << dp[n][k];
}

int main(){
	int n,k;
	cin >> n >> k;
	solve(n,k);
}
