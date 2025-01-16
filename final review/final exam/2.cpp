#include <algorithm>
#include <cctype>
#include <cstring>
#include <iostream>
#include <string>

using namespace std;

int main() {
  int n;
  cin >> n;
  string WORD[n];
  string word[n];
  for(int i=0;i<n;i++){
    WORD[i].clear();



  }
  for (int i = 0; i < n; i++) {
    cin >> word[i];
    for (int j = 0; j < word[i].length(); j++) {
      if (word[i][j] >= 'A' && word[i][j] <= 'Z')
        WORD[i] +=char( word[i][j] + 'a' - 'A');
        else{
            WORD[i]+=word[i][j];


        }
    }
  }
  string AAA[16] = {"zero","one",    "two",    "three",    "four",     "five",
                    "six",    "seven",  "eight",    "nine",     "ten",
                    "eleven", "twelve", "thirteen", "fourteen", "fifteen"};
  int NUM1[9] = {101, 101, 101, 101, 101, 101, 101, 101, 101};
  int p = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < 16; j++)
      if ((WORD[i] < AAA[j]) + (WORD[i] > AAA[j]) == 0) {
        int MM=0;
        for(int k=0;k<WORD[i].length();k++){
           MM+=int(word[i][k]);


        }
        NUM1[p]=MM%100;
        p++;
        break;
      }
  
  for (int i = 1; i < 9; i++)
    for (int j = 0; j < 9 - i; j++) {
      int a;
      if (NUM1[j] > NUM1[j + 1]) {
        a = NUM1[j];
        NUM1[j] = NUM1[j + 1];
        NUM1[j + 1] = a;
      }
    }
  char FINAL[9][2];
 
  for (int i = 0; i < 9; i++) {
    if(NUM1[i]==101){
        FINAL[i][0]='*';


    
    break;
    }
    FINAL[i][0] = NUM1[i] / 10 + '0';
    FINAL[i][1] = NUM1[i] % 10 + '0';

    
    
  }
  string OUTPUT = "";
  int b = 0;
 int c=0;
  for (int i = 0; i < 9; i++)
    for (int j = 0; j < 2; j++) {
        if(FINAL[i][j]=='*')
        c=1;
      if (c==0&&(b == 1 || FINAL[i][j] != '0')) {
        OUTPUT.push_back(FINAL[i][j]);
        b = 1;
      }
    }
  if (OUTPUT.length() == 0)
    cout << 0 << endl;
  else
    cout << OUTPUT;
  return 0;
}