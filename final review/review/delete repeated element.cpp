#include<iostream>
#include<vector>
using namespace std;
int main(){
    int N;
    cin>>N;
    vector<int>list;
    int b;
    for(int i=0;i<N;i++){
        int c;
        cin>>c;
        if(i==0){
            b=c;
            list.push_back(c);



        }
        else{
            if(c!=b){
                b=c;
            list.push_back(c);



            }




        }




    }
    cout<<list.size()<<endl;
    return 0;







}