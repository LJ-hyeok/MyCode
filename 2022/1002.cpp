#include<bits/stdc++.h>
using namespace std;



int main(){
	int T;
	cin >> T;
	
	while(T--){
		int x1, y1, r1;
		int x2, y2, r2;
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		
		int dist = pow(x1-x2, 2) + pow(y1-y2, 2);
		int D = pow(r1+r2, 2);
		
		int tmp1=r1, tmp2 =r2;
		if(tmp1<tmp2)	swap(tmp1, tmp2);
		
		// 동일
		if(x1==x2 && y1==y2 && r1 ==r2)
			cout << "-1\n";
			
		//원 안  
		else if(dist < pow(tmp1-tmp2, 2))
			cout << "0\n";
			
		//내접  
		else if(dist == pow(tmp1-tmp2, 2))
			cout << "1\n";
	 
		//원 밖 
		else if(dist > D)
			cout << "0\n";
		else if(dist == D)
			cout << "1\n";
		else if(dist < D)
			cout << "2\n";
	}
}
