#include<iostream>
#include<queue> 
using namespace std;
priority_queue<int,vector<int>, greater<int> >pq;//minheap
int chk[32001];
int main(){
	int N,M;
	cin >> N >> M;
	for(int i=0;i<M;i++){
		int a,b;
		cin >> a >> b;
		chk[b] = a;
		if(!chk[a])
			chk[a] = 1;
		pq.push(b);
	}
	int tmp;	
	for(int i=1;i<=N;i++){
		if(pq.size()>0)
			tmp = pq.top();
		if(tmp == i){
			cout << chk[i] << " " << i << " ";
			pq.pop();
		}
		if(chk[i]==0&&tmp!= i)
			cout << i << " ";
	}
	return 0;
}
