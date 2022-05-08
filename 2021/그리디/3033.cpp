#include <stdio.h>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
char arr[200005];
int len;
vector<int> v[65538];
int f(int m) {
    int t = 0;
    if (m >= len) return 0;
    long long int hash = 0;
    long long int x = 1;
    for (int i = 0; i<m; i++) {
        hash = (hash * 2 + arr[i]) % 65537;
        if (i<m - 1) {
            x *= 2;
            x %= 65537;
        }
    }
    v[hash].push_back(0);
    bool ch = false;
    bool full = false;
    for (int i = m + 1; i<len; i++) {
        hash = (2*(hash - arr[i - m - 1] * x) + arr[i-1]) % 65537;
        while (hash<0) hash += 65537;
        if (!v[hash].empty()) {
            for (int j : v[hash]) {
                full = true;
                for (int k = 0; k<m; k++) {
                    if (arr[i - m + k] != arr[j + k]) {
                        full = false;
                        break;
                    }
                }
                if (full == true) {
                    ch = true;
                    break;
                }
            }
        }
        if (ch) break;
        else v[hash].push_back(i - m);
    }
    for (int i = 0; i<65538; i++) v[i].clear();
    return ch ? 1 : 0;
}
int main() {
    scanf("%d", &len);
    scanf("%s", arr);
    int s = 0, e = 200005, mid;
    while (s + 1<e) {
        mid = (s + e) / 2;
        int t = f(mid);
        if (t == 1) {
            s = mid;
        }
        else e = mid;
    }
    printf("%d", s);
    return 0;
}
