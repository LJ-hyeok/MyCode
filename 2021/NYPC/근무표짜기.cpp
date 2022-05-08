#include<iostream>
#include<queue>
#include<stack>
#include<vector>
using namespace std;


int p[100];
int t[100];
priority_queue<pair<int,int>> pq; // first: time, second: idx
stack<pair<int,int>> mystack;
vector<int> ans;

int main(){
	int N,K;
	cin >> N >> K;
	
	int mx = 0;
	for(int i=0;i<N;i++){
		cin >> p[i];
		mx+=p[i];
	}
	
	for(int i=0;i<N;i++)	pq.push({p[i],i});
	for(int i=0;i<K;i++)	cin >> t[i];
	
	int cnt = 0;
	int tmp = 0;
	bool flag = true;
	for(int i=0;i<K;i++){
		if(flag){
			for(int j=0;j<t[i];j++){
				if(tmp==mx){
					flag = false;
					break;
				}
				int time = pq.top().first;
				int idx = pq.top().second;
				pq.pop();
				ans.push_back(idx+1);
				mystack.push({time-1,idx});
				tmp++;
			}
			while(!mystack.empty()){
				pq.push({mystack.top().first,mystack.top().second});
				mystack.pop();
			}
		}
		cout << ans.size() << " ";
		for(int i=0;i<ans.size();i++)	cout << ans[i] << " ";
		cout << "\n";
		ans.clear();
	}
	return 0;
}
