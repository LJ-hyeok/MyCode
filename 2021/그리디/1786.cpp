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
        while (j > 0 && a[i] != b[j])        //���� j��ŭ ã�Ҵµ� �̹��� ���ϴ� ���ڰ� �ٸ� ���
            j = pi[j - 1];        //���ڿ� B�� failure function ���� ���� �񱳸� ���ݴϴ�.
        if (a[i] == b[j]){            //���ϴ� ���ڰ� ���� ���
            if (j == b.length() - 1){    //���ڿ� B�� ���� Ž���Ͽ��� ������ �信 ��ġ�� �־��ݴϴ�.
                res.push_back(i - b.length() + 2);
                j = pi[j];    //���� Ž���� ���Ͽ� �̹����� failure function ���� ���� �񱳸� ���ݴϴ�.
            }
            else
                j++;    //���ڿ� B�� ���� �ܾ �����ݴϴ�.
        }
    }
}
void getpi(){
    pi.resize(b.length());
    int j = 0;
    for (int i = 1; i < b.length(); i++){
        while (j > 0 && b[i] != b[j])
            j = pi[j - 1];        //����ġ�� �Ͼ ���
        if (b[i] == b[j])
            pi[i] = ++j;        //prefix�� ���� ����ġ��ŭ pi�� �����ݴϴ�.
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
