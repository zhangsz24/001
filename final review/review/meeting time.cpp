#include<iostream>
#include<string>
#include<cctype>
#include<algorithm>
using namespace std;











int main(){
    string begin_1;
    string end_1;
    string begin_2;
    string end_2;

    int begin1[2];
    int begin2[2];
    int end1[2];
    int end2[2];
    cin>>begin_1;
    cin>>end_1;
    cin>>begin_2;
    cin>>end_2;
    
    begin1[0]=(begin_1[0]-'0')*10+(begin_1[1]-'0');
    begin1[1]=(begin_1[3]-'0')*10+(begin_1[4]-'0');
    begin2[0]=(begin_2[0]-'0')*10+(begin_2[1]-'0');
    begin2[1]=(begin_2[3]-'0')*10+(begin_2[4]-'0');
    end1[0]=(end_1[0]-'0')*10+(end_1[1]-'0');
    end1[1]=(end_1[3]-'0')*10+(end_1[4]-'0');
    end2[0]=(end_2[0]-'0')*10+(end_2[1]-'0');
    end2[1]=(end_2[3]-'0')*10+(end_2[4]-'0');
    if(begin1[0]<begin2[0]||(begin1[0]==begin2[0]&&begin1[1]<=begin2[1])){
        if(end1[0]<begin2[0]||(end1[0]==begin2[0]&&end1[1]<=begin2[1])){
        cout<<-1;


    }
    else{
        int time1;
        int time2;
        time1=(end1[0]-begin2[0])*60+(end1[1]-begin2[1]);
        time2=(end2[0]-begin2[0])*60+(end2[1]-begin2[1]);
        cout<<min(time1,time2);
        

    }


    }
    else{
        if(end2[0]<begin1[0]||(end2[0]==begin1[0]&&end2[1]<=begin1[1])){
        cout<<-1;


    }
    else{
        int time1;
        int time2;
        time1=(end2[0]-begin1[0])*60+(end2[1]-begin1[1]);
        time2=(end1[0]-begin1[0])*60+(end1[1]-begin1[1]);
        cout<<min(time1,time2);
        

    }


    }
    return 0;
    

    





}