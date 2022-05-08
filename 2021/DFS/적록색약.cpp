#include<stdio.h>
int N;
char A[105][105];
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
int arr[105][105];
int cnt=1;
char pre;


bool safe(int x,int y)
{
	return x>=0 && y>=0 && x<N && y<N;
}
void dfs(int x,int y)
{
	
	for(int i=0;i<4;i++){
		int tx = x + dx[i];
		int ty = y + dy[i];
		if(safe(tx,ty) && pre == A[tx][ty] && arr[tx][ty] != cnt)
		{
			arr[tx][ty] = cnt;
			dfs(tx,ty);
		}
	}
}
int main()
{
	//입 력 
	scanf("%d",&N);
	for(int i=0;i<N;i++)
		scanf("%s",&A[i]);
		
	//ans1 = 정상 (적록색약x)
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(arr[i][j] == 0)
			{
				pre = A[i][j];
				arr[i][j] = cnt;
				dfs(i,j);
				cnt++;
//				for(int k=0;k<N;k++){
//					for(int l=0;l<N;l++)
//						printf("%d\t",arr[k][l]);
//					printf("\n");
//				}
//				printf("\n\n");
			}
		}
	}
	int ans1 = cnt-1;
	
	//arr 초기화, cnt 초기화, R => G 변경 
	cnt = 1;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			arr[i][j] = 0;
			if(A[i][j] == 'R')
				A[i][j] = 'G';
		}
	}
	
//	printf("=================================");
	//ans2 = 적록색약 
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(arr[i][j] == 0)
			{
				pre = A[i][j];
				arr[i][j] = cnt;
				dfs(i,j);
				cnt++;
//				for(int k=0;k<N;k++){
//					for(int l=0;l<N;l++)
//						printf("%d\t",arr[k][l]);
//					printf("\n");
//				}
//				printf("\n\n");
				
			}
		}
	}
	int ans2 = cnt-1;
	
	
	
	//출력 
	
	printf("%d %d",ans1,ans2);
	return 0;
}
