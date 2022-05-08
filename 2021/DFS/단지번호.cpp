#include<stdio.h>
#include<algorithm>
int N;
int arr[30][30];
bool safe(int x, int y){
	return x>=0 && y>=0 && x<N && y<N;
}
void fn(int x, int y, int cnt)
{
	arr[x][y] = cnt;
	if(safe(x+1,y) && arr[x+1][y] == 1)
		fn(x+1,y,cnt);

	if(safe(x-1,y) && arr[x-1][y] == 1)
		fn(x-1,y,cnt);

	if(safe(x,y+1) && arr[x][y+1] == 1)
		fn(x,y+1,cnt);

	if(safe(x,y-1) && arr[x][y-1] == 1)
		fn(x,y-1,cnt);
}

int main(){

	//===
	scanf("%d",&N);
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			scanf("%1d",&arr[i][j]);

	//====
	int cnt = 2;
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			if(arr[i][j] == 1){
				fn(i,j,cnt);
				cnt++;
			}
	//===
	/*
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++)
			printf("%d ",arr[i][j]);
		printf("\n");
	}
	*/
	//====
	int arr2[1000];
	int tmp;
	for(int k=0;k<(cnt-2);k++){
		tmp = 0;
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				if(arr[i][j] == k+2)
					tmp++;
			}
		}
		arr2[k] = tmp;
//		printf("%d:%d\n",k,arr2[k]);
	}
	std::sort(arr2,arr2+cnt-2);


	//===
	printf("%d\n",cnt-2);
	for(int i=0;i<cnt-2;i++) printf("%d\n",arr2[i]);

	return 0;
}
