#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,t;
	cin >> t;
	while(t--){
		string arr[10001];
		bool flag = false;
		cin >> n;
		for(int i=0;i<n;i++)
			cin >> arr[i];
			
		sort(arr,arr+n);
		bool stat = false;
		for(int i=0;i<n-1;i++){
			int cur = arr[i].length();
			int next = arr[i+1].length();
			if(cur>next) continue;
			if(arr[i] == arr[i+1].substr(0,cur)){
				stat = true;
				break;
			}
		}
		cout << (!stat ? "YES":"NO") << "\n";
	}
	return 0;
}
