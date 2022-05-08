#include<iostream>
using namespace std;

int arrx[1001];
int arry[1001];

int main(){
	int x1,x2,x3;
	int y1,y2,y3;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
	arrx[x1]++, arrx[x2]++, arrx[x3]++;
	arry[y1]++, arry[y2]++, arry[y3]++;
	
	int x4, y4;
	for(int i=1;i<=1000;i++){
		if(arrx[i] == 1)	x4 = i;
		if(arry[i] == 1)	y4 = i;
	}
	cout << x4 << " " << y4;
}
