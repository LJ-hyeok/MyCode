#include<iostream>
#include<algorithm>
using namespace std;

struct info{
	int num;
	int value;
};
info arr[1000003];
int ans[1000003];

bool cmp(info a, info b){
	if(a.value==b.value)
		return a.num<b.num;
	return a.value<b.value;
}

int main(){
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> arr[i].value;
		arr[i].num = i;
	}

	sort(arr,arr+n,cmp);

	for(int i=0;i<n;i++)
		ans[arr[i].num] = i;
		
	int x = 0;
	for(int i=0;i<n;i++){
		int tmp = arr[i].value;
		while(true){
			ans[arr[i].num]-=x;
			if(tmp!=arr[i+1].value)
				break;
			i++,x++;
		}
	}
	
	for(int i=0;i<n;i++)
		cout << ans[i] << " ";
}
