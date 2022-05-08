#include<stdio.h>
int max(int a, int b){return a>b ? a:b;}
int k;
int bud[10005];
int s,e;
int re;
int main(){
    scanf("%d",&k);
    int m = 0;
    for(int i=0;i<k;i++) {
        scanf("%d",&bud[i]);
        m = max(m,bud[i]);
    }
    scanf("%d",&re);
    s = 0;
    e = m;
    int mid;
    int test;
    int ans =0;
    while(s<=e){
        mid=(s+e)/2;
        test = 0;
        for(int i=0;i<k;i++) test+=(bud[i]<mid) ? bud[i]:mid;
        printf("%d\t%d\t%d\t%d\n",s,mid,e,test);
        if(test<=re){
            s=mid+1;
            if(ans<mid) ans = mid;
        }
        else e = mid-1;
    }
    printf("%d",ans);
    return 0;
}
