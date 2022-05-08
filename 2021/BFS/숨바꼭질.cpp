#include<stdio.h>
#include<queue>
using namespace std; 
int N,K;
int arr[100002];
bool safe(int a){
	return a>=0 && a<=100000;
}
queue<int> Q;
void bfs()
{
	arr[N] = 1;
	Q.push(N);
	while(!Q.empty())
	{
		int cur = Q.front();
		if(safe(cur+1) && arr[cur+1] == 0){
			Q.push(cur+1);
			arr[cur+1] = arr[cur] + 1;
		}
		if(safe(cur-1) && arr[cur-1] == 0){
			Q.push(cur-1);
			arr[cur-1] = arr[cur] + 1;
		}
		if(safe(2*cur) && arr[2*cur] == 0){
			Q.push(2*cur);
			arr[2*cur] = arr[cur] + 1;
		}
		if(arr[K]!=0)
			break;
		Q.pop();
	}
}
int main()
{
	scanf("%d%d",&N,&K);
	bfs();
	printf("%d",arr[K]-1);
	
	return 0;
}
