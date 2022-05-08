#include <cstdio>
bool fl, c[11];
char s[11], a[11];
int k;
void f(int idx, int n, int d) {
    bool flg = true;
    if(idx == k + 1) { 
		printf("%s\n", a); 
		fl = 1;
		return; 
	}
    for(int i = n; !fl && i != 9 - n + d; i += d) {
        if(c[i])
			continue;
        a[idx] = i + '0';
        c[i] = true;
        if(idx){
            if (s[idx - 1] == '>' && a[idx - 1] < a[idx]) 
				flg = false;
            else if (s[idx - 1] == '<' && a[idx - 1] > a[idx]) 
				flg = false;
        }
        if (flg)
			f(idx + 1, n, d);
        a[idx] = 0;
        c[i] = false;
        flg = true;
    }   
}
int main() {
    scanf("%d", &k);
    for (int i = 0 ; i < k; i++) scanf(" %c", s + i);
    f(0, 9, -1);
    fl = false;
    f(0, 0, 1);
}
