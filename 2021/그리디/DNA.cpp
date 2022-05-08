#include<iostream>
using namespace std;

int arr[5][1001];
string s[1001];
int main(){
	int N,M;
	cin >> N >> M;
	for(int i=0;i<N;i++)
		cin >> s[i];
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			char a = s[i][j];
			if(a=='A')	arr[3][j]++;
			if(a=='C')	arr[2][j]++;
			if(a=='G')	arr[1][j]++;
			if(a=='T')	arr[0][j]++;
		}
	}
	string ans;
	for(int i=0;i<M;i++){
		int tmp=3;
		for(int j=0;j<4;j++)
			if(arr[j][i]>=arr[tmp][i])
				tmp = j;
		if(tmp==0)	ans.push_back('T');
		if(tmp==1)	ans.push_back('G');
		if(tmp==2)	ans.push_back('C');
		if(tmp==3)	ans.push_back('A');
	}
	cout << ans << '\n';
	int sum = 0;
	for(int i=0;i<N;i++)
		for(int j=0;j<M;j++)
			if(s[i][j]!=ans[j])
				sum++;
	cout << sum;
	return 0;
} 
