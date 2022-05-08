#include<iostream>
using namespace std;
int arr[1001][1001];
int main(){
	int N,M;
	while(true){
		cin >> N >> M;
		if(N==0&&M==0)
			break;
		for(int i=0;i<N;i++)
			for(int j=0;j<M;j++)
				cin >> arr[i][j];
	}
	
	return 0;
}
