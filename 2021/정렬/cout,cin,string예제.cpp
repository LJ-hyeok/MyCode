#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int main(){
	string A[10];
	for(int i=0;i<3;i++)
		cin >> A[i];
	sort(A,A+3);
	for(int i=0;i<3;i++)
		cout << A[i] << endl;
	return 0;
}
