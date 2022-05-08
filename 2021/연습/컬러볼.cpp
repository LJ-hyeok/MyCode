#include<stdio.h> 
#include<vector>
using namespace std;

const int mxN=200000;
const int mxS=2000;
vector<int> v[mxN+2];
int chk[mxN+2][mxS+2];
int dp[mxS+2];
struct pt{
	int color,size;
};
pt ans[mxN+2];
int main(){
	int N;
	scanf("%d",&N);
	
	for(int i=1;i<=N;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		v[a].push_back(b);
		ans[i].color = a;
		ans[i].size = b;
	}

	for(int i=1;i<=N;i++){
		for(int j=0;j<v[i].size();j++){
			dp[v[i][j]]=v[i][j];
		}
	}
			
	for(int i=1;i<=mxS;i++)
		dp[i] += dp[i-1];

	for(int i=1;i<=N;i++){
		for(int j=0;j<v[i].size();j++){
			int sum =0;
			for(int k=0;k<v[i].size();k++){
				if(v[i][j] > v[i][k])
					sum += v[i][k];
			}
			int tmp = dp[v[i][j]];
			dp[v[i][j]] -= sum + v[i][j];
			chk[i][v[i][j]] = dp[v[i][j]];
			dp[v[i][j]] = tmp;
		}
	}
	
	for(int i=1;i<=N;i++)
		printf("%d\n",chk[ans[i].color][ans[i].size]);
		
	return 0;
}
