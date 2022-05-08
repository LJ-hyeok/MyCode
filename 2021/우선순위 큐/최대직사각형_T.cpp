#include<cstdio>
#include<algorithm>
using namespace std;
int n, m;
int main() {
    while (scanf("%d%d", &n, &m) && n) {
        int r = 0, h[1001] = { 0 }, stk[1001], top;
        for (int i = 1; i <= n; i++) {
            stk[top = 0] = 0;
            for (int j = 1, x; j <= m; j++) {
                scanf("%d", &x);
                h[j] = (h[j] + 1) * x;
                while (h[stk[top]] > h[j]) r = max(r, (j - stk[top - 1] - 1)*h[stk[top--]]);
                stk[++top] = j;
            }
            while (top) r = max(r, (m - stk[top - 1])*h[stk[top--]]);
        }
        printf("%d\n", r);
    }
    return 0;
}
