#include <iostream>
using namespace std;
int main() {
  int n;
  cin >> n;
  string A;
  string INPUT[n];
  int AA[n][n];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      AA[i][j] = 0;
    }

    for(int i=0;i<n;i++){
        cin>>INPUT[i];




    }
  

  for (int i = 0; i < n; i++)
    for (int j = 0; j < n - 6; j++) {
      string word;
      word.clear();
      for (int k = 0; k < 7; k++) {
        word += INPUT[i][j + k];
      }
      if (word == "program") {
        for (int k = 0; k < 7; k++) {
          AA[i][j + k] = 1;
        }
      }
    }

  for (int i = 0; i < n; i++)
    for (int j = n - 1; j > 5; j--) {
      string word;
      word.clear();
      for (int k = 0; k < 7; k++) {
        word += INPUT[i][j - k];
      }
      if (word == "program") {
        for (int k = 0; k < 7; k++) {
          AA[i][j - k] = 1;
        }
      }
    }

  for (int i = 0; i < n; i++)
    for (int j = 0; j < n - 6; j++) {
      string word;
      word.clear();
      for (int k = 0; k < 7; k++) {
        word += INPUT[j + k][i];
      }
      if (word == "program") {
        for (int k = 0; k < 7; k++) {
          AA[j + k][i] = 1;
        }
      }
    }

  for (int i = 0; i < n; i++)
    for (int j = n - 1; j > 5; j--) {
      string word;
      word.clear();
      for (int k = 0; k < 7; k++) {
        word += INPUT[j - k][i];
      }
      if (word == "program") {
        for (int k = 0; k < 7; k++) {
          AA[j - k][i] = 1;
        }
      }
    }

  for (int i = 0; i < n - 6; i++)
    for (int j = 0; j < n - 6; j++) {
      string word;
      word.clear();
      for (int k = 0; k < 7; k++) {
        word += INPUT[i + k][j + k];
      }
      if (word == "program" || word == "margorp") {
        for (int k = 0; k < 7; k++) {
          AA[i + k][j + k] = 1;
        }
      }
    }

  for (int i = 0; i < n - 6; i++)
    for (int j = n - 1; j > 5; j--) {
      string word;
      word.clear();
      for (int k = 0; k < 7; k++) {
        word += INPUT[i + k][j - k];
      }
      if (word == "program" || word == "margorp") {
        for (int k = 0; k < 7; k++) {
          AA[i + k][j - k] = 1;
        }
      }
    }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      if (AA[i][j] == 0) {
        INPUT[i][j] = '*';
      }
    }
  for (int i = 0; i < n; i++) {
    cout << INPUT[i] << endl;
  }

  return 0;
}