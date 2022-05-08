#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
string a,b;
vector<int> pi;
vector<int> res;
void kmp(){
    int j = 0;
    for (int i = 0; i < a.length(); i++){
        while (j > 0 && a[i] != b[j])        //현재 j만큼 찾았는데 이번에 비교하는 문자가 다른 경우
            j = pi[j - 1];        //문자열 B를 failure function 이후 부터 비교를 해줍니다.
        if (a[i] == b[j]){            //비교하는 문자가 같은 경우
            if (j == b.length() - 1){    //문자열 B를 전부 탐색하였기 때문에 답에 위치를 넣어줍니다.
                res.push_back(i - b.length() + 2);
                j = pi[j];    //다음 탐색을 위하여 이번에도 failure function 이후 부터 비교를 해줍니다.
            }
            else
                j++;    //문자열 B의 다음 단어를 비교해줍니다.
        }
    }
}
void getpi(){
    pi.resize(b.length());
    int j = 0;
    for (int i = 1; i < b.length(); i++){
        while (j > 0 && b[i] != b[j])
            j = pi[j - 1];        //불일치가 일어날 경우
        if (b[i] == b[j])
            pi[i] = ++j;        //prefix가 같은 가중치만큼 pi를 정해줍니다.
    }
}
int main(){ios_base::sync_with_stdio(0);cin.tie(0);
  getline(cin,a);
  getline(cin,b);
  
  getpi();
  kmp();
  cout << res.size() << "\n";
  for(int i=0;i<res.size();i++)
    cout << res[i] << "\n";
  return 0;
}
