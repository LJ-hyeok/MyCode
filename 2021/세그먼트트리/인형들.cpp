#include<iostream>
#include<math.h>
const double INF = 9e15;
using namespace std;

double arr[501];

int main(){
	int N,K;
	scanf("%d%d",&N,&K);
	for(int i=0;i<N;i++)	scanf("%lf",&arr[i]);
	
	double sum, m, p, ans=INF;
	
	
	
	for(int l=K;l<=N;l++){
		for(int i=0;i<N-l+1;i++){
			//평균
			sum = 0;
			for(int j=i;j<i+l;j++)	sum += arr[j];
			m = sum/(double)l;
			//분산  
			sum = 0;
			for(int j=i;j<i+l;j++)	sum += (arr[j]-m) * (arr[j]-m);
			p = sum/(double)l;
			//최소 
			ans = ans>sqrt(p) ? sqrt(p):ans;
		}
		
	}
	printf("%.6lf",ans);
}
