#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<ctime>
using namespace std;
struct pt{
	int x,y;
};
int arr[100];
pt arr2[100];
bool cmp(int a, int b){
	return a>b; //내림차순  
}
bool cmp2(pt a, pt b){
	return a.x==b.x ? a.y<b.y : a.x<b.x;
}
int main(){
	srand(time(NULL)); //randomseed 
	for(int i=0;i<100;i++){
		arr[i] = rand()%100+1;
		printf("%d ",arr[i]);
	}
	printf("\n\n");
	sort(arr,arr+100,cmp);
	for(int i=0;i<100;i++){
		arr2[i] = {rand()%100,rand()%100};
		printf("(%d,%d) ",arr2[i].x,arr2[i].y);
	}
	printf("\n\n");
	//============================================================
	sort(arr2,arr2+100,cmp2);
	
	for(int i=0;i<100;i++){
		printf("%d ",arr[i]);
	}
	printf("\n\n");
	for(int i=0;i<100;i++){
		printf("(%d,%d) ",arr2[i].x,arr2[i].y);
	}
	printf("\n\n");
	return 0;
}
