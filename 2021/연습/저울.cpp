#include<stdio.h>
#include<vector>
using namespace std;
vector<int> v[103];
int N,M;
int cnt;
void Fdfs(int x){
	for(int i=1;i<=N;i++){
		for(int j=0;j<v[i].size();j++){
			if(v[i][j] == x){
				cnt++;
				Fdfs(i);
			}
		}
	}
}
void Bdfs(int x){
	for(int i=0;i<v[x].size();i++){
		for(int j=1;j<=N;j++){
			if(v[x][i] == j){
				cnt++;
				Bdfs(j);
			}
		}
	}
}
int main(){
	scanf("%d%d",&N,&M);
	for(int i=0;i<M;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		v[a].push_back(b);
	}
	for(int i=1;i<=N;i++){
		cnt = 0;
		Fdfs(i);
		Bdfs(i);
		printf("%d\n",N-cnt-1);
	}
	return 0;
}

//v
//1 2
//2 3
//3 4
//4
//5 4
//6 5
//1234
//562

//1 2
//2 3
//3 4
//4
//5 6
//6 2
