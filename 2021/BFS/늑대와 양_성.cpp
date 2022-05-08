#include <iostream>
#include <string>
using namespace std;
typedef struct {
   int y;
   int x;
}Dir;

Dir moveDir[4] = { {1,0}, {-1,0}, {0,1}, {0,-1} };
string map[500];

bool BFS(int r, int c) {
   for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
         if (map[i][j] == 'S') {
            for (int l = 0; l < 4; l++) {
               int chkY = i + moveDir[l].y;
               int chkX = j + moveDir[l].x;
               if (!(0 <= chkY and chkY <= r and 0 <= chkX and chkX <= c))
                  continue;
               if (map[chkY][chkX] == 'W')
                  return false;
               else if(map[chkY][chkX] == '.')
                  map[chkY][chkX] = 'D';
            }
         }
      }
   }
   return true;
}

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   int c, r;

   cin >> r >> c;
   for (int i = 0; i < r; i++)
      cin >> map[i];

   if (!BFS(r, c))
      cout << 0;
   else {
      cout << 1 << "\n";
      for (int i = 0; i < r; i++) {
         cout << map[i] << "\n";
      }
   }

   return 0;
}
