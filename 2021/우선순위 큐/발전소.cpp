#include<iostream>
#include<algorithm> 
#include<queue>
using namespace std;
int arr[16][16];
int chk[16];
int main(){
	int N,P;
	int sum=0, cnt=0;
	string s;
	queue<int> q;
	priority_queue<int,vector<int>,greater<int> > pq;
	
	cin >> N;
	for(int i=1;i<=N;i++)
		for(int j=1;j<=N;j++)
			cin >> arr[i][j];
	cin >> s;
	for(int i=0;i<s.length();i++){
		if(s[i]=='N')
			q.push(i+1);
		else
			chk[i+1]=1;
	}
	cin >> P;
	
	int nd = P-(N-q.size()); //NÀÇ°³¼ö  		
	while(!q.empty()){
		int cur = q.front();
		q.pop();
		int lo = 51;
		bool flag=false;
		for(int i=1;i<=N;i++){
			if(!chk[i]&&arr[i][cur]==0)	continue;
			lo = min(lo,arr[i][cur]);
			flag = true;
		}
		if(flag){
			cnt++;
			pq.push(lo);
		}
	}
	if(cnt<nd || P==nd)
		cout << "-1";
	else{
		for(int i=0;i<nd;i++){
			sum+=pq.top();
			pq.pop();
		}
		cout << sum;
	}
	
	return 0;
}


//2
//0 1
//1 0
//NN
//2
