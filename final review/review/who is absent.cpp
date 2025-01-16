#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int M;
    int N;
    cin>>N>>M;
    int student[N];
    for(int i=0;i<N;i++){
        student[i]=0;





    }
    for(int i=0;i<M;i++){
        int p;
        cin>>p;
        student[p-1]=1;




    }
    int c=0;
    for(int i=0;i<N;i++){
        if(student[i]==0){
            c=1;
            cout<<i+1<<' ';



        }




    }
    if(c==0){
        cout<<"ALL";


    }
    return 0;





}