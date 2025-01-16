#include <iostream>
using namespace std;
int main() {
  int b = 0;
  int n;
  int m;
  cin >> n >> m;
  int A[7];
  for (int i = 0; i < 7; i++) {
    cin >> A[i];
  }
  int B[5];
  for (int i = 1; i >= 0; i--)
    for (int j = 1; j >= 0; j--)
      for (int k = 1; k >= 0; k--)
        for (int l = 1; l >= 0; l--) {
          if (i + j + k + l == m) {
            B[1] = i;
            B[2] = j;
            B[3] = k;
            B[4] = l;
            int AA;
            int BB;
            int CC;
            int DD;
            AA = (B[A[0]] && !B[A[1]]);
            BB = (!B[2]);
            CC = ((B[A[2]] && B[A[3]]) || (!B[A[2]] && !B[A[3]]));
            DD = ((B[A[4]] && B[A[5]]) || (B[A[4]] && B[A[6]]) ||
                  (B[A[5]] && B[A[6]]));
            if (AA + BB + CC + DD == n) {
              b = 1;
              for (int z = 1; z <= 4; z++) {
                if (B[z] == 1)
                  cout << z;
              }
              cout << endl;
            }
          }
        }
  if (b == 0) {
    cout << -1 << endl;
  }
  return 0;
}