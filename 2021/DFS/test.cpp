#include<iostream>
using namespace std;
int arr[5]={0,1,2,3,4};
int vis[5];
void dfs(int idx, int cnt){
	cout << arr[idx] << " ";		
	vis[idx] = 1;
	if(idx>=4){
		return;
	}
	if(cnt>4){
		cout << "\n";
		return;
	}
	for(int i=0;i<5;i++){
		if(vis[i]==1){
			dfs(i,cnt+1);
			vis[i]=0;
		}
	}
	return;
}
int main(){
	for(int i=0;i<5;i++)
		dfs(i,0);
	return 0;
}
