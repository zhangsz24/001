#include<iostream>
#include<cmath>
#include<algorithm>
#include<iomanip>
using namespace std;
int main(){
    int m,p,q;
    cin>>m>>p>>q;
double up[p];
    double down[q];

    for(int i=0;i<p;i++){
        cin>>up[i];


    }
    for(int i=0;i<q;i++){
        cin>>down[i];


    }
    
    double A=m+1;
    int z=0;
    for(int i=0;i<p;i++){
        double B=m+1;
        for(int j=z;j<q;j++){
            int C=abs(up[i]-down[j]);
            if(C>B)
            break;
            else{
                B=C;
                z=j;



            }
            A=min(B,A);

           
            






        }
        





    }
    double AAA;
    AAA=sqrt(A*A+1);
    cout<<fixed<<setprecision(2)<<AAA<<endl;
    return 0;





}