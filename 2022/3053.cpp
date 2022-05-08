#include<iostream>
#define PI 3.14159265359
using namespace std;
int main(){
	int r;
	cin >> r;
	double U = r*r*PI;
	double T = 2*r*r;
	
	cout << fixed;
	cout.precision(6);
	cout << U << "\n" << T;
}
