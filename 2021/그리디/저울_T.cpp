#include <iostream>
#include <algorithm>
using namespace std;
int main(void){
    int n;
    int num[1000];
    cin >> n;
    for (int i = 0; i < n; i++) 
		cin >> num[i];
    sort(num, num + n);
    int result = 1;
    if (num[0] == 1) {
        int acc = num[0];
        for (int i = 1; i < n && acc >= num[i] - 1; i++) {
			acc += num[i];
			printf("%d\n",acc);
		}
        result = acc + 1;
        
    }
    cout << result;
    return 0;
}
