#include<iostream>
using namespace std;
int main(){
    int n;
    int k;
    cin>>n>>k;
    int activity[n+1];
    for(int i=1;i<n+1;i++){
        cin>>activity[i];



    }
    int plan[n-k+2];
    for(int i=1;i<n-k+2;i++){
        plan[i]=0;



    }
    for(int i=1;i<n-k+2;i++)
    for(int j=0;j<k;j++){
        plan[i]+=activity[i+j];




    }
    int SUM=plan[1]+plan[k+1]+1;
    int sum1=plan[1]+1;
    int sum2;
    int a;
    int b;
    for(int i=1;i<n-2*k+2;i++){
        int A=plan[i];
        if(A>=sum1)
        continue;
        sum1=A;
        for(int j=i+k;j<n-k+2;j++){
            sum2=plan[j];
            if((sum1+sum2)<SUM){
                SUM=sum1+sum2;
                a=i;
                b=j;


            }



        }
       





    }
    cout<<a;
    cout<<' ';
    cout<<b;



        



    

return 0;




}