#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;
int main(){
    int M,N,D;
    cin>>M>>N>>D;
   double e=2.7182818;
    
    double z=sqrt(D);
    double Q[M][D];
    double K[N][D];
    double V[N][D];
    double S[M][N];
    double W[M][N];
    double C[M][D];
    for(int i=0;i<M;i++)
    for(int j=0;j<D;j++){
        cin>>Q[i][j];
        


 

    }

    for(int i=0;i<N;i++)
    for(int j=0;j<D;j++){
        cin>>K[i][j];
        


 

    }

    for(int i=0;i<N;i++)
    for(int j=0;j<D;j++){
        cin>>V[i][j];
        


 

    }







    for(int i=0;i<M;i++)
    for(int j=0;j<N;j++){
        S[i][j]=0;
        for(int k=0;k<D;k++){
            S[i][j]+=Q[i][k]*K[j][k];






        }
        S[i][j]=S[i][j]/z;


 

    }
    for(int i=0;i<M;i++)
    for(int j=0;j<N;j++){
        double sigma=0;
        for(int k=0;k<N;k++){
            sigma+=pow(e,S[i][k]);



        }
        W[i][j]=pow(e,S[i][j])/sigma;






    }
    for(int i=0;i<M;i++)
    for(int j=0;j<D;j++){
        C[i][j]=0;
        for(int k=0;k<N;k++){
            C[i][j]+=   W[i][k]*V[k][j];






        }
        


 

    }

    for(int i=0;i<M;i++){
    for(int j=0;j<D;j++){
        cout<<fixed<<setprecision(1)<<C[i][j]<<' ';
    
        


 

    }
    cout<<endl;

    }




}