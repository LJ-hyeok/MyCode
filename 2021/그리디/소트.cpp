#include<iostream>
#include<algorithm>
using namespace std;

int N,S;
int arr[50];

void sort(){
	int a=1,b=1;
	for(int i=N;i>0;i--){
		if(arr[i-1]<arr[i]){
			a = i-1;
			b = i;
		} 
	}
	if(a==b)	return;
	swap(arr[a],arr[b]);
}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);
	cin >> N;
	for(int i=0;i<N;i++)
		cin >> arr[i];
	cin >> S;
	for(int i=0;i<S;i++)
		sort();
	for(int i=0;i<N;i++)
		cout << arr[i] << " ";
	return 0;
}
