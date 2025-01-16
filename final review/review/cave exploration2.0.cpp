#include <iostream>
using namespace std;
struct spot {
  int danger;
  int protection;
};
struct plan {
  long long A[12][2];
  int num;
};
int main() {
  int n;
  int m;
  cin >> n;
  cin >> m;
  spot map[n][m];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      cin >> map[i][j].danger;
      map[i][j].protection = 0;
    }

  int trap_num;
  int protection_num;
  cin >> trap_num;
  for (int k = 0; k < trap_num; k++) {
    int i;
    int j;
    cin >> i >> j;
    map[i - 1][j - 1].protection = -1;
  }

  cin >> protection_num;
  for (int k = 0; k < protection_num; k++) {
    int i;
    int j;
    cin >> i >> j;
    map[i - 1][j - 1].protection = 1;
  }

  plan P[n][m];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      P[i][j].num = 0;
    }

  for (int i = 0; i < n; i++) {
    if (i == 0) {
      P[i][0].num = 1;
      P[i][0].A[1][0] = map[i][0].danger;
      P[i][0].A[1][1] = map[i][0].protection;

    } else {
      P[i][0].A[1][0] = map[i][0].danger + P[i - 1][0].A[1][0];
      P[i][0].A[1][1] = map[i][0].protection + P[i - 1][0].A[1][1];
      if (P[i][0].A[1][1] < 0)
        {break;}
      P[i][0].num = 1;
    }
  }

  for (int i = 1; i < m; i++) {

    P[0][i].A[1][0] = map[0][i].danger + P[0][i - 1].A[1][0];
    P[0][i].A[1][1] = map[0][i].protection + P[0][i - 1].A[1][1];
    if (P[0][i].A[1][1] < 0)
      break;
    P[0][i].num = 1;
  }

  for (int i = 1; i < n; i++)
    for (int j = 1; j < m; j++) {
      for (int k = 1; k <= P[i - 1][j].num; k++) {
        long long a;
        long long b;
        a = P[i - 1][j].A[k][0] + map[i][j].danger;
        b = P[i - 1][j].A[k][1] + map[i][j].protection;
        if(b<0)
        continue;
        if(b>10)
        {b=10;}
        int c=0;
        for(int z=1;z<=P[i][j].num;z++){
          if(P[i][j].A[z][1]==b){
            if(a<P[i][j].A[z][0]){
              P[i][j].A[z][0]=a;


            }
            c=-1;
            break;



          }



        }
        if(c==0){
          P[i][j].num++;
          P[i][j].A[P[i][j].num][0]=a;
          P[i][j].A[P[i][j].num][1]=b;


        }


      }

      for (int k = 1; k <= P[i][j - 1].num; k++) {
       long long a;
        long long b;
        a = P[i][j-1].A[k][0] + map[i][j].danger;
        b = P[i][j-1].A[k][1] + map[i][j].protection;
        if(b<0)
        continue;
        if(b>10)
        b=10;
        int c=0;
        for(int z=1;z<=P[i][j].num;z++){
          if(P[i][j].A[z][1]==b){
            if(a<P[i][j].A[z][0]){
              P[i][j].A[z][0]=a;


            }
            c=-1;
            break;



          }



        }
        if(c==0){
          P[i][j].num++;
          P[i][j].A[P[i][j].num][0]=a;
          P[i][j].A[P[i][j].num][1]=b;


        }


      }
    }

  if (P[n - 1][m - 1].num == 0)
    cout << "failed" << endl;
  else {
    long long step;
    for (int i = 1; i <= P[n - 1][m - 1].num; i++) {
      if (i == 1) {
        step = P[n - 1][m - 1].A[i][0];

      } else {
        if (P[n - 1][m - 1].A[i][0] < step)
          step = P[n - 1][m - 1].A[i][0];
      }
    }
    cout << step << endl;
  }
}