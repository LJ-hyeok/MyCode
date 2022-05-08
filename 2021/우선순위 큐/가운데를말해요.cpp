#include<iostream>
#include<queue>
using namespace std;
priority_queue<int,vector<int>, greater<int> > minheap;
priority_queue<int,vector<int>, less<int> > maxheap;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	for(int i=0;i<N;i++){
		int in;
		cin >> in;
		if(maxheap.size()==minheap.size())
			maxheap.push(in);
		else
			minheap.push(in);
		if(minheap.size()>0&&maxheap.top()>minheap.top()){
			int tmp,tmp2;
			tmp = minheap.top(),tmp2 = maxheap.top();
			minheap.pop(),maxheap.pop();
			minheap.push(tmp2),maxheap.push(tmp);
		}
		cout << maxheap.top() << "\n";
	}
	return 0;
}
