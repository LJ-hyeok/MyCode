#include<iostream>
#include<queue>
#define mx 100000
using namespace std;

int arr[100003];

bool safe(int x){
	return x>=0 && x<=mx;
}

void bfs(int s){
	for(int i=0;i<=mx;i++)	arr[i]=mx;
	arr[s]=0;
	queue<int> q;
	q.push(s);
	while(!q.empty()){
		int cur = q.front();
		q.pop();
		if(safe(cur+1) && arr[cur+1]>arr[cur]+1){
			arr[cur+1]=arr[cur]+1;
			q.push(cur+1);
		}
		if(safe(cur-1) && arr[cur-1]>arr[cur]+1){
			arr[cur-1]=arr[cur]+1;
			q.push(cur-1); 
		}
		if(cur==0)	continue;
		int tmp=cur*2;
		while(tmp<=mx){
			if(safe(tmp) && arr[tmp]>arr[cur]){
				arr[tmp]=arr[cur];
				q.push(tmp);
			}
			tmp*=2;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,k;
	cin >> n >> k;
	bfs(n);
	cout << arr[k];
}
