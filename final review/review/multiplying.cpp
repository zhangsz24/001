#include<iostream>
#include<string>
#include<cstring>
#include<cctype>
#include<algorithm>
using namespace std;
int main(){
    int N;
    cin>>N;
    string A;
    string B;
    cin>>A>>B;
    int AA=0;
    int BB=0;
    for(int i=0;i<A.length();i++){
        int a;
        if(A[i]<'A'){
            a=A[i]-'0';


        }
        else{
            a=A[i]-'a'+10;



        }
        for(int j=0;j<A.length()-i-1;j++){
            a=a*N;


        }
        AA+=a;




    }

    for(int i=0;i<B.length();i++){
        int a;
        if(B[i]<'A'){
            a=B[i]-'0';


        }
        else{
            a=B[i]-'a'+10;



        }
        for(int j=0;j<B.length()-i-1;j++){
            a=a*N;


        }
        BB+=a;




    }
    int CC;
    CC=AA*BB;
    string C;
    C.clear();
    while(1){
        int a;
        a=CC%N;
        if(a<10){
            C+='0'+a;


        }
        else{
            C+='a'+a-10;


        }
        CC=CC/N;
        if(CC==0)
        break;




    }
    string str;
    reverse(C.begin(),C.end());
    cout<<C<<endl;







}