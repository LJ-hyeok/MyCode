#include<iostream>
#include<queue>
using namespace std;
priority_queue<long long int,vector<long long int>, greater<long long int> >pq;
int main(){
	int n,m;
	cin >> n >> m;
	
	long long int tmp;
	for(int i=0;i<n;i++){
		cin >> tmp;
		pq.push(tmp);
	}
	for(int i=0;i<m;i++){
		long long int a,b;
		a = pq.top();
		pq.pop();
		b = pq.top();
		pq.pop();
		pq.push(a+b), pq.push(a+b);
	}	
	long long int sum = 0;
	while(!pq.empty()){
		sum+=pq.top();
		pq.pop();
	}
	cout << sum;
	return 0;
}
