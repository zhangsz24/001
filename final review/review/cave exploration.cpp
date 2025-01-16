#include<iostream>
using namespace std;
int b=0;
int AAA=0;
int **map;
struct spot{
    int row;
    int column;


};

int compare(int row,int column,spot A[],int num){
    for(int i=0;i<num;i++){
        if(row==A[i].row&&column==A[i].column)
        return 1;



    }
    return 0;






}
void move(int row,int column,int danger,int n,int m,int protection,spot A[],spot B[],int danger_num,int protection_num){
    if(row>=n||column>=m)
    return;
    if(compare(row,column,A,danger_num)==1){
        if(protection==0)
        return;
        else
        protection--;



    }
    danger+=map[row][column];
    if(row==n-1&&column==m-1){
        if(b==0){
            b=1;
            AAA=danger;


        }
        else{
            if(danger<AAA){
                AAA=danger;


            }



        }



    }
    if(compare(row,column,B,protection_num==1))
    protection++;
    move(row+1,column,danger,n,m,protection,A,B,danger_num,protection_num);
    move(row,column+1,danger,n,m,protection,A,B,danger_num,protection_num);
    return;
    




}
int main(){
    int n;
    int m;
    cin>>n>>m;
    map=new int*[n];
    for(int i=0;i<n;i++){
        map[i]=new int[m];


    }
    for(int i=0;i<n;i++)
    for(int j=0;j<m;j++){
        cin>>map[i][j];



    }
    int trap_num;
    int protection_num;
    cin>>trap_num;
    
    spot trap[trap_num];
    if(trap_num!=0){
    for(int i=0;i<trap_num;i++){
        cin>>trap[i].row;
        cin>>trap[i].column;
        trap[i].row--;
        trap[i].column--;



    }}
    
    cin>>protection_num;
    
    spot protection[protection_num];
    if(protection_num!=0){
    for(int i=0;i<trap_num;i++){
        cin>>protection[i].row;
        cin>>protection[i].column;
        protection[i].row--;
        protection[i].column--;



    }}
    move(0,0,0,n,m,0,trap,protection,trap_num,protection_num);
    if(b==0)
    cout<<"failed";
    else
    cout<<AAA;




    for (int i=0; i<n; i++) delete[] map[i];    
    delete[] map;
    return 0;
    
    

    





}