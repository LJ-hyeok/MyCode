#include<iostream>
#include<queue>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	queue<int> q,ans;
	int N, K;
	cin >> N >> K;
	for(int i=1;i<=N;i++)	q.push(i);
	for(int i=0;i<N;i++){
		for(int j=0;j<K-1;j++){
			q.push(q.front());
			q.pop();
		}
		ans.push(q.front());
		q.pop();
	}
	cout << "<";
	for(int i=0;i<N-1;i++){
		cout << ans.front() << ", ";
		ans.pop();
	}
	cout << ans.front() << ">";
}
