#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;
vector<int> v[100003];
queue<int> q;
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for(int i=1;i<=n;i++){
		if(v[i].size() == 1)
			q.push(i);
	}
	int num =  (q.size()+1)/2;
	printf("%d\n",num);	
	
	return 0;
}
