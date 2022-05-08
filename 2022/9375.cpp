#include<iostream>
#include<string>
#include<map>
using namespace std;

map<string,int> m;
int arr[30];

void init(){
	m.clear();
	for(int i=0;i<30;i++)
		arr[i] = 0;
}

int solve(int m){
	int sum=1;
	for(int i=0;i<m;i++)
		sum*=arr[i]+1;
	return sum-1;
}

int main(){
	int T;
	cin >> T;
	while(T--){
		init();
		int n;
		cin >> n;
		int idx=0;
		for(int i=0;i<n;i++){
			string a,b;
			cin >> a >> b;
			
			if(m.count(b))
				arr[m[b]]++;
			else{
				m[b]=idx;
				arr[idx]++;
				idx++;	
			}
		}
		cout << solve(idx) << "\n";
	}
}
