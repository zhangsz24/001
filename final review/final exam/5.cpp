#include<iostream>
using namespace std;
int INPUT[1001][1001];
int MEMORY[1001][1001];

void space_jump(int step,int N,int M,int i,int j){
    if(i>N||j>M)
    return;
    if(MEMORY[i][j]!=-1&&MEMORY[i][j]<= step)
    return;
    else{
        MEMORY[i][j]=step;
        if(INPUT[i][j]==3)
        return;
        if(i==N-1&&j==M-1)
        return;
        if(INPUT[i][j]==1){
            space_jump(step+1,N,M,2*i,j);
            space_jump(step+1,N,M,i,2*j);



        }
        else if(INPUT[i][j]==2){
            space_jump(step+1,N,M,2*i,j);
            space_jump(step+1,N,M,i,2*j);
            space_jump(step+1,N,M,i+1,j);
            space_jump(step+1,N,M,i,j+1);


        }
        return;




    }
    return;




}
int main(){
    int N;
    int M;
 cin>>N>>M;
   
    for(int i=0;i<1001;i++)
    for(int j=0;j<1001;j++){
        MEMORY[i][j]=-1;
        INPUT[i][j]=-1;




    }
 for(int i=1;i<=N;i++)
    for(int j=1;j<=M;j++){
        cin>>INPUT[i][j];




    }



    space_jump(0,N,M,1,1);
    if(MEMORY[N][M]==-1){
        cout<<-1;


    }
    else{
        cout<<MEMORY[N][M];


    }

   return 0;

    

    







}