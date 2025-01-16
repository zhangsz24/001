#include <iostream>
using namespace std;
int p=0;
int i_1;
  int i_2;
  int i_3;
  int i_4;
  int j_1;
  int j_2;
  int j_3;
  int j_4;
void AAA(int a, int b,int c,int d){
  int A=(b==i_1)+(c==j_1);
  int B=(c==i_2)+(d==j_2);
  int C=(d==i_3)+(a==j_3);
  int D=(a==i_4)+(b==j_4);
  if(A==1&&B==1&&C==1&&D==1){
    p=1;
    cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
  }
  


}
int main() {
  
  cin >> i_1 >> i_2 >> i_3 >> i_4 >> j_1 >> j_2 >> j_3 >> j_4;
  AAA(1,2,3,4);
  AAA(1,2,4,3);
  AAA(1,3,2,4);
  AAA(1,3,4,2);
  AAA(1,4,2,3);
  AAA(1,4,3,2);
  AAA(2,1,3,4);
  AAA(2,1,4,3);
  AAA(2,3,1,4);
  AAA(2,3,4,1);
  AAA(2,4,1,3);
  AAA(2,4,3,1);
  AAA(3,1,2,4);
  AAA(3,1,4,2);
  AAA(3,2,1,4);
  AAA(3,2,4,1);
  AAA(3,4,1,2);
  AAA(3,4,2,1);
  AAA(4,1,2,3);
  AAA(4,1,3,2);
  AAA(4,2,1,3);
  AAA(4,2,3,1);
  AAA(4,3,1,2);
  AAA(4,3,2,1);
  

  

  

  
  
  
  if(p==0){
    cout<<-1;
  }
 
}

