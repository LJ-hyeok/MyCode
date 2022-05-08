#include <cstdio>
#include <algorithm>
#include <set>
using namespace std;
int n, m, q, x, y, z, par[100010], lca[100010], paint[100010];
int getlca(int x, int y, int k) {
    if (x == y)return x;
    int cnt = 0;
    while (x&&cnt < 1000) {
        lca[x] = k;
        x = par[x];
        cnt++;
    }
    cnt = 0;
    while (y&&cnt < 1000) {
        if (lca[y] == k)
            return y;
        y = par[y];
        cnt++;
    }
    return 0;
}
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        scanf("%d%d%d", &q, &x, &y);
        if (q == 1) {
            scanf("%d", &z);
            int anc = getlca(x, y, i);
            while (x != anc) {
                paint[x] = z;
                x = par[x];
            }
            while (y != anc) {
                paint[y] = z;
                y = par[y];
    	    }
        }
        else if (q == 2)
            par[x] = y;
        else {
            set<int> st;
            int anc = getlca(x, y, i);
            while (x != anc) {
                st.insert(paint[x]);
                x = par[x];
            }
            while (y != anc) {
                st.insert(paint[y]);
                y = par[y];
            }
            printf("%d\n", st.size());
        }
    }
    return 0;
}
