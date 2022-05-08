#include<iostream>
#include<algorithm>
using namespace std; 
int N;
int A[51];
int B[51];
int P[51];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for(int i=0;i<N;i++){
		cin >> A[i];
		B[i] = A[i];
	}
	sort(B,B+N);
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(A[i]==B[j]){
				B[j] = 0;
				P[i] = j;
				break;
			}
		}
				
	}
	for(int i=0;i<N;i++)
		cout << P[i] << " ";
		
	return 0;
}
