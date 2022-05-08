#include<stdio.h>
#include<deque>
using namespace std;
deque<int> Q;

int N,M;
int arr[55];
int ans=10000000;
int cnt1,cnt2;
bool flag = true;

int way1(int idx)
{
	cnt1 = 0;
	while(Q.front() != arr[idx])
	{
		int cur = Q.front();
		Q.pop_front();
		Q.push_back(cur);
		cnt1++;
	}
	if(flag){
		for(int i=0;i<cnt1;i++){
			int cur = Q.back();
			Q.pop_back();
			Q.push_front(cur);
		}
	}
	return cnt1;
}
int way2(int idx)
{
	cnt2 = 0;
	while(Q.front() != arr[idx])
	{
		int cur = Q.back();
		Q.pop_back();
		Q.push_front(cur);
		cnt2++;
	}
	if(flag){
		for(int i=0;i<cnt2;i++){
			int cur = Q.front();
			Q.pop_front();
			Q.push_back(cur);
		}
	}
	return cnt2;
}


int main()
{
	scanf("%d%d",&N,&M);
	for(int i=0;i<M;i++)
		scanf("%d",&arr[i]);
	for(int i=1;i<=N;i++)
		Q.push_back(i);

	int tmp = 0;
	for(int i=0;i<M;i++){
		if(way1(i) > way2(i)){
			flag = false;
			tmp += way2(i);
		}
		else{
			flag = false;
			tmp += way1(i);
		}
		flag = true;
		Q.pop_front();
		
	}
	printf("%d",tmp);
	return 0;
}


