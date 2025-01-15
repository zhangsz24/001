#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
/////////////////各个print只注释print2（游戏运行时的界面），其他同理
using namespace std;
//各函数作用见头文件
struct str{
    string a;



};

void COM(int step,int line,string input[],int NUM){
if(line<=NUM){//连续NUM（指令数）行输出已有指令，并随游戏进行（step变化）改变箭头位置
    cout<<" ";
    if(step==line){cout<<"->";}
    else{cout<<"  ";}
    cout<<line<<" ";
    
    cout<<input[line]<<endl;
    




}
else if(line==NUM+1){//在NUM行指令下方输出"END"进行提示
    cout<<" ";
    if(step==line){cout<<"->";}
    else{cout<<"  ";}
    cout<<line<<" ";
    
    cout<<"END"<<endl;


}
else{//再下方不输出
    cout<<endl;


}

}




str change(int b){
    str output;
    string A;
    A=to_string(b);
    if(A.length()==1){//控制输出长度为3
    output.a=" ";
    output.a+=A;
    output.a+=" ";
    
    
    }
    else if(A.length()==2){
        output.a=A+" ";



    }
    else if(A.length()==3){
        output.a=A;


    }
    else{//若长度大于等于4则输出000
        output.a="000";


    }
    if(b==-500){//无内容则输出“X”
        output.a=" X ";


    }
    return output;



}
void print11(int space_num,int IN[],int OUT[],int SPACE[],int block){//游戏开始界面(stage1)

cout<<endl<<endl;
/////////////////////////////////////////////////////line 1
cout<<"     "<<"+---+";//5
for(int i=0;i<20;i++){cout<<' ';}
cout<<"+---+";
for(int i=0;i<20;i++){cout<<' ';}
cout<<"+---+";
cout<<"         "<<"|"<<" "<<"关卡信息:"<<"可用空地数:"<<space_num<<endl;//9



/////////////////////////////////////////////////////line 2
cout<<" IN  "<<"|"<<change(IN[0]).a<<"|";//5
for(int i=0;i<20;i++){cout<<' ';}
cout<<"|"<<change(block).a<<"|";
for(int i=0;i<20;i++){cout<<' ';}
cout<<"|"<<change(OUT[0]).a<<"|";
cout<<"  OUT    "<<"|"<<" "<<"         "<<"可用指令集:"<<"inbox,outbox"<<endl;//9

/////////////////////////////////////////////////////line 3
cout<<"     "<<"+---+";//5
for(int i=0;i<20;i++){cout<<' ';}
cout<<"+---+";
for(int i=0;i<20;i++){cout<<' ';}
cout<<"+---+";
cout<<"         "<<"|"<<endl;//9

/////////////////////////////////////////////////////line 4
cout<<"     "<<"+---+";//5
for(int i=0;i<20;i++){cout<<' ';}
cout<<"@   @";
for(int i=0;i<20;i++){cout<<' ';}
cout<<"+---+";
cout<<"         "<<"|"<<" "<<"关卡任务:"<<"让机器人取出输入序列上的每个积木放入输出序"<<endl;//9



/////////////////////////////////////////////////////line 5
cout<<"     "<<"|"<<change(IN[1]).a<<"|";//5
for(int i=0;i<20;i++){cout<<' ';}
cout<<"-----";
for(int i=0;i<20;i++){cout<<' ';}
cout<<"|"<<change(OUT[1]).a<<"|";
cout<<"         "<<"|"<<" "<<"         "<<"列中"<<endl;//9

/////////////////////////////////////////////////////line 6
cout<<"     "<<"+---+";//5
for(int i=0;i<20;i++){cout<<' ';}
cout<<"|@ @|";
for(int i=0;i<20;i++){cout<<' ';}
cout<<"+---+";
cout<<"         "<<"|"<<endl;//9

/////////////////////////////////////////////////////line 7
cout<<"     "<<"+---+";//5
for(int i=0;i<20;i++){cout<<' ';}
cout<<"  +  ";
for(int i=0;i<20;i++){cout<<' ';}
cout<<"+---+";
cout<<"         "<<"|"<<" "<<"请输入指令数(第一行)和指令(从第二行起每行一条)"<<endl;//9



/////////////////////////////////////////////////////line 8
cout<<"     "<<"|"<<change(IN[2]).a<<"|";//5
for(int i=0;i<20;i++){cout<<' ';}
cout<<"/   "<<char(92);
for(int i=0;i<20;i++){cout<<' ';}
cout<<"|"<<change(OUT[2]).a<<"|";
cout<<"         "<<"|"<<endl;//9

/////////////////////////////////////////////////////line 9
cout<<"     "<<"+---+";//5
for(int i=0;i<20;i++){cout<<' ';}
cout<<" | | ";
for(int i=0;i<20;i++){cout<<' ';}
cout<<"+---+";
cout<<"         "<<"|"<<endl;//9

/////////////////////////////////////////////////////line 10
cout<<"     "<<"+---+";//5
for(int i=0;i<20;i++){cout<<' ';}
cout<<"     ";
for(int i=0;i<20;i++){cout<<' ';}
cout<<"+---+";
cout<<"         "<<"|"<<endl;//9



/////////////////////////////////////////////////////line 11
cout<<"     "<<"|"<<change(IN[3]).a<<"|";//5
for(int i=0;i<14;i++){cout<<' ';}
for(int i=0;i<space_num;i++){cout<<"+---+ ";}
for(int i=0;i<26+5-6*space_num;i++){cout<<' ';}
cout<<"|"<<change(OUT[3]).a<<"|";
cout<<"         "<<"|"<<endl;//9

/////////////////////////////////////////////////////line 12
cout<<"     "<<"+---+";//5
for(int i=0;i<14;i++){cout<<' ';}
for(int i=0;i<space_num;i++){cout<<"|"<<change(SPACE[i]).a<<"| ";}
for(int i=0;i<26+5-6*space_num;i++){cout<<' ';}
cout<<"+---+";
cout<<"         "<<"|"<<endl;//9

/////////////////////////////////////////////////////line 13
cout<<"     "<<"+---+";//5
for(int i=0;i<14;i++){cout<<' ';}
for(int i=0;i<space_num;i++){cout<<"+---+ ";}
for(int i=0;i<26+5-6*space_num;i++){cout<<' ';}
cout<<"+---+";
cout<<"         "<<"|"<<endl;//9



/////////////////////////////////////////////////////line 14
cout<<"     "<<"|"<<change(IN[4]).a<<"|";//5
for(int i=0;i<14;i++){cout<<' ';}
for(int i=0;i<space_num;i++){cout<<"  "<<i<<"   ";}
for(int i=0;i<26+5-6*space_num;i++){cout<<' ';}
cout<<"|"<<change(OUT[4]).a<<"|";
cout<<"         "<<"|"<<endl;//9

/////////////////////////////////////////////////////line 15
cout<<"     "<<"+---+";//5
for(int i=0;i<45;i++){cout<<' ';}
cout<<"+---+";
cout<<"         "<<"|"<<endl;//9

}

void print12(int space_num,int IN[],int OUT[],int SPACE[],int block){//游戏开始界面(stage1)

cout<<endl<<endl;
/////////////////////////////////////////////////////line 1
cout<<"     "<<"+---+";//5
for(int i=0;i<20;i++){cout<<' ';}
cout<<"+---+";
for(int i=0;i<20;i++){cout<<' ';}
cout<<"+---+";
cout<<"         "<<"|"<<" "<<"关卡信息："<<"可用空地数:"<<space_num<<endl;//9



/////////////////////////////////////////////////////line 2
cout<<" IN  "<<"|"<<change(IN[0]).a<<"|";//5
for(int i=0;i<20;i++){cout<<' ';}
cout<<"|"<<change(block).a<<"|";
for(int i=0;i<20;i++){cout<<' ';}
cout<<"|"<<change(OUT[0]).a<<"|";
cout<<"  OUT    "<<"|"<<" "<<"          "<<"可用指令集："<<"inbox,outbox,jump,jumpifzero"<<endl;//9

/////////////////////////////////////////////////////line 3
cout<<"     "<<"+---+";//5
for(int i=0;i<20;i++){cout<<' ';}
cout<<"+---+";
for(int i=0;i<20;i++){cout<<' ';}
cout<<"+---+";
cout<<"         "<<"|"<<" "<<"                      "<<"add,sub,copyto,copyfrom"<<endl;//9

/////////////////////////////////////////////////////line 4
cout<<"     "<<"+---+";//5
for(int i=0;i<20;i++){cout<<' ';}
cout<<"@   @";
for(int i=0;i<20;i++){cout<<' ';}
cout<<"+---+";
cout<<"         "<<"|"<<" "<<"关卡任务："<<"对于输入序列中的每两个东西，先把第 1 个减"<<endl;//9



/////////////////////////////////////////////////////line 5
cout<<"     "<<"|"<<change(IN[1]).a<<"|";//5
for(int i=0;i<20;i++){cout<<' ';}
cout<<"-----";
for(int i=0;i<20;i++){cout<<' ';}
cout<<"|"<<change(OUT[1]).a<<"|";
cout<<"         "<<"|"<<" "<<"          "<<"去第 2 个，并把结果放在输出序列中，然后把"<<endl;//9


/////////////////////////////////////////////////////line 6
cout<<"     "<<"+---+";//5
for(int i=0;i<20;i++){cout<<' ';}
cout<<"|@ @|";
for(int i=0;i<20;i++){cout<<' ';}
cout<<"+---+";
cout<<"         "<<"|"<<" "<<"          "<<"第 2 个减去第 1 个，再把结果放在输出序列中，重复。"<<endl;//9

/////////////////////////////////////////////////////line 7
cout<<"     "<<"+---+";//5
for(int i=0;i<20;i++){cout<<' ';}
cout<<"  +  ";
for(int i=0;i<20;i++){cout<<' ';}
cout<<"+---+";
cout<<"         "<<"|"<<endl;//9



/////////////////////////////////////////////////////line 8
cout<<"     "<<"|"<<change(IN[2]).a<<"|";//5
for(int i=0;i<20;i++){cout<<' ';}
cout<<"/   "<<char(92);
for(int i=0;i<20;i++){cout<<' ';}
cout<<"|"<<change(OUT[2]).a<<"|";
cout<<"         "<<"|"<<" "<<"请输入指令数(第一行)和指令(从第二行起每行一条)"<<endl;//9

/////////////////////////////////////////////////////line 9
cout<<"     "<<"+---+";//5
for(int i=0;i<20;i++){cout<<' ';}
cout<<" | | ";
for(int i=0;i<20;i++){cout<<' ';}
cout<<"+---+";
cout<<"         "<<"|"<<endl;//9

/////////////////////////////////////////////////////line 10
cout<<"     "<<"+---+";//5
for(int i=0;i<20;i++){cout<<' ';}
cout<<"     ";
for(int i=0;i<20;i++){cout<<' ';}
cout<<"+---+";
cout<<"         "<<"|"<<endl;//9



/////////////////////////////////////////////////////line 11
cout<<"     "<<"|"<<change(IN[3]).a<<"|";//5
for(int i=0;i<14;i++){cout<<' ';}
for(int i=0;i<space_num;i++){cout<<"+---+ ";}
for(int i=0;i<26+5-6*space_num;i++){cout<<' ';}
cout<<"|"<<change(OUT[3]).a<<"|";
cout<<"         "<<"|"<<endl;//9

/////////////////////////////////////////////////////line 12
cout<<"     "<<"+---+";//5
for(int i=0;i<14;i++){cout<<' ';}
for(int i=0;i<space_num;i++){cout<<"|"<<change(SPACE[i]).a<<"| ";}
for(int i=0;i<26+5-6*space_num;i++){cout<<' ';}
cout<<"+---+";
cout<<"         "<<"|"<<endl;//9

/////////////////////////////////////////////////////line 13
cout<<"     "<<"+---+";//5
for(int i=0;i<14;i++){cout<<' ';}
for(int i=0;i<space_num;i++){cout<<"+---+ ";}
for(int i=0;i<26+5-6*space_num;i++){cout<<' ';}
cout<<"+---+";
cout<<"         "<<"|"<<endl;//9



/////////////////////////////////////////////////////line 14
cout<<"     "<<"|"<<change(IN[4]).a<<"|";//5
for(int i=0;i<14;i++){cout<<' ';}
for(int i=0;i<space_num;i++){cout<<"  "<<i<<"   ";}
for(int i=0;i<26+5-6*space_num;i++){cout<<' ';}
cout<<"|"<<change(OUT[4]).a<<"|";
cout<<"         "<<"|"<<endl;//9

/////////////////////////////////////////////////////line 15
cout<<"     "<<"+---+";//5
for(int i=0;i<45;i++){cout<<' ';}
cout<<"+---+";
cout<<"         "<<"|"<<endl;//9

}

void print13(int space_num,int IN[],int OUT[],int SPACE[],int block){//游戏开始界面(stage1)

cout<<endl<<endl;
/////////////////////////////////////////////////////line 1
cout<<"     "<<"+---+";//5
for(int i=0;i<20;i++){cout<<' ';}
cout<<"+---+";
for(int i=0;i<20;i++){cout<<' ';}
cout<<"+---+";
cout<<"         "<<"|"<<" "<<"关卡信息："<<"可用空地数:"<<space_num<<endl;//9



/////////////////////////////////////////////////////line 2
cout<<" IN  "<<"|"<<change(IN[0]).a<<"|";//5
for(int i=0;i<20;i++){cout<<' ';}
cout<<"|"<<change(block).a<<"|";
for(int i=0;i<20;i++){cout<<' ';}
cout<<"|"<<change(OUT[0]).a<<"|";
cout<<"  OUT    "<<"|"<<" "<<"          "<<"可用指令集："<<"inbox,outbox,jump,jumpifzero"<<endl;//9

/////////////////////////////////////////////////////line 3
cout<<"     "<<"+---+";//5
for(int i=0;i<20;i++){cout<<' ';}
cout<<"+---+";
for(int i=0;i<20;i++){cout<<' ';}
cout<<"+---+";
cout<<"         "<<"|"<<" "<<"                      "<<"add,sub,copyto,copyfrom"<<endl;//9

/////////////////////////////////////////////////////line 4
cout<<"     "<<"+---+";//5
for(int i=0;i<20;i++){cout<<' ';}
cout<<"@   @";
for(int i=0;i<20;i++){cout<<' ';}
cout<<"+---+";
cout<<"         "<<"|"<<" "<<"关卡任务："<<"从输入序列中依次取 2 个数字，如果相等则将"<<endl;//9



/////////////////////////////////////////////////////line 5
cout<<"     "<<"|"<<change(IN[1]).a<<"|";//5
for(int i=0;i<20;i++){cout<<' ';}
cout<<"-----";
for(int i=0;i<20;i++){cout<<' ';}
cout<<"|"<<change(OUT[1]).a<<"|";
cout<<"         "<<"|"<<" "<<"          "<<"其中一个输出，否则扔掉。重复这个过程直到"<<endl;//9


/////////////////////////////////////////////////////line 6
cout<<"     "<<"+---+";//5
for(int i=0;i<20;i++){cout<<' ';}
cout<<"|@ @|";
for(int i=0;i<20;i++){cout<<' ';}
cout<<"+---+";
cout<<"         "<<"|"<<" "<<"          "<<"输入传送带为空。"<<endl;//9

/////////////////////////////////////////////////////line 7
cout<<"     "<<"+---+";//5
for(int i=0;i<20;i++){cout<<' ';}
cout<<"  +  ";
for(int i=0;i<20;i++){cout<<' ';}
cout<<"+---+";
cout<<"         "<<"|"<<endl;//9



/////////////////////////////////////////////////////line 8
cout<<"     "<<"|"<<change(IN[2]).a<<"|";//5
for(int i=0;i<20;i++){cout<<' ';}
cout<<"/   "<<char(92);
for(int i=0;i<20;i++){cout<<' ';}
cout<<"|"<<change(OUT[2]).a<<"|";
cout<<"         "<<"|"<<" "<<"请输入指令数(第一行)和指令(从第二行起每行一条)"<<endl;//9

/////////////////////////////////////////////////////line 9
cout<<"     "<<"+---+";//5
for(int i=0;i<20;i++){cout<<' ';}
cout<<" | | ";
for(int i=0;i<20;i++){cout<<' ';}
cout<<"+---+";
cout<<"         "<<"|"<<endl;//9

/////////////////////////////////////////////////////line 10
cout<<"     "<<"+---+";//5
for(int i=0;i<20;i++){cout<<' ';}
cout<<"     ";
for(int i=0;i<20;i++){cout<<' ';}
cout<<"+---+";
cout<<"         "<<"|"<<endl;//9



/////////////////////////////////////////////////////line 11
cout<<"     "<<"|"<<change(IN[3]).a<<"|";//5
for(int i=0;i<14;i++){cout<<' ';}
for(int i=0;i<space_num;i++){cout<<"+---+ ";}
for(int i=0;i<26+5-6*space_num;i++){cout<<' ';}
cout<<"|"<<change(OUT[3]).a<<"|";
cout<<"         "<<"|"<<endl;//9

/////////////////////////////////////////////////////line 12
cout<<"     "<<"+---+";//5
for(int i=0;i<14;i++){cout<<' ';}
for(int i=0;i<space_num;i++){cout<<"|"<<change(SPACE[i]).a<<"| ";}
for(int i=0;i<26+5-6*space_num;i++){cout<<' ';}
cout<<"+---+";
cout<<"         "<<"|"<<endl;//9

/////////////////////////////////////////////////////line 13
cout<<"     "<<"+---+";//5
for(int i=0;i<14;i++){cout<<' ';}
for(int i=0;i<space_num;i++){cout<<"+---+ ";}
for(int i=0;i<26+5-6*space_num;i++){cout<<' ';}
cout<<"+---+";
cout<<"         "<<"|"<<endl;//9



/////////////////////////////////////////////////////line 14
cout<<"     "<<"|"<<change(IN[4]).a<<"|";//5
for(int i=0;i<14;i++){cout<<' ';}
for(int i=0;i<space_num;i++){cout<<"  "<<i<<"   ";}
for(int i=0;i<26+5-6*space_num;i++){cout<<' ';}
cout<<"|"<<change(OUT[4]).a<<"|";
cout<<"         "<<"|"<<endl;//9

/////////////////////////////////////////////////////line 15
cout<<"     "<<"+---+";//5
for(int i=0;i<45;i++){cout<<' ';}
cout<<"+---+";
cout<<"         "<<"|"<<endl;//9

}

void print2(int space_num,int IN[],int OUT[],int SPACE[],int block,string input[],int step,int NUM,int move){//游戏进行界面
int line=0;
cout<<endl<<endl;
/////////////////////////////////////////////////////line 1
cout<<"     "<<"+---+";//5
for(int i=0;i<20+move;i++){cout<<' ';}//用变量move控制机器人的移动
cout<<"+---+";
for(int i=0;i<20-move;i++){cout<<' ';}
cout<<"+---+";
cout<<"         "<<"|"<<" ===== CODE ====="<<endl;//9

line++;//从下一行开始作为使用COM函数输出指令的第一行

/////////////////////////////////////////////////////line 2
cout<<" IN  "<<"|"<<change(IN[0]).a<<"|";//“change(IN[0]).a为转化后长度为三的字符串”
for(int i=0;i<20+move;i++){cout<<' ';}
cout<<"|"<<change(block).a<<"|";
for(int i=0;i<20-move;i++){cout<<' ';}
cout<<"|"<<change(OUT[0]).a<<"|";
cout<<"  OUT    "<<"|";//9
COM(step,line,input,NUM);//输出指令或“END”
line++;

/////////////////////////////////////////////////////line 3
cout<<"     "<<"+---+";//5
for(int i=0;i<20+move;i++){cout<<' ';}
cout<<"+---+";
for(int i=0;i<20-move;i++){cout<<' ';}
cout<<"+---+";
cout<<"         "<<"|";//9
COM(step,line,input,NUM);
line++;
/////////////////////////////////////////////////////line 4
cout<<"     "<<"+---+";//5
for(int i=0;i<20+move;i++){cout<<' ';}
cout<<"@   @";
for(int i=0;i<20-move;i++){cout<<' ';}
cout<<"+---+";
cout<<"         "<<"|";//9
COM(step,line,input,NUM);
line++;

/////////////////////////////////////////////////////line 5
cout<<"     "<<"|"<<change(IN[1]).a<<"|";//5
for(int i=0;i<20+move;i++){cout<<' ';}
cout<<"-----";
for(int i=0;i<20-move;i++){cout<<' ';}
cout<<"|"<<change(OUT[1]).a<<"|";
cout<<"         "<<"|";//9
COM(step,line,input,NUM);
line++;
/////////////////////////////////////////////////////line 6
cout<<"     "<<"+---+";//5
for(int i=0;i<20+move;i++){cout<<' ';}
cout<<"|@ @|";
for(int i=0;i<20-move;i++){cout<<' ';}
cout<<"+---+";
cout<<"         "<<"|";//9
COM(step,line,input,NUM);
line++;
/////////////////////////////////////////////////////line 7
cout<<"     "<<"+---+";//5
for(int i=0;i<20+move;i++){cout<<' ';}
cout<<"  +  ";
for(int i=0;i<20-move;i++){cout<<' ';}
cout<<"+---+";
cout<<"         "<<"|";//9
COM(step,line,input,NUM);
line++;

/////////////////////////////////////////////////////line 8
cout<<"     "<<"|"<<change(IN[2]).a<<"|";//5
for(int i=0;i<20+move;i++){cout<<' ';}
cout<<"/   "<<char(92);
for(int i=0;i<20-move;i++){cout<<' ';}
cout<<"|"<<change(OUT[2]).a<<"|";
cout<<"         "<<"|";//9
COM(step,line,input,NUM);
line++;
/////////////////////////////////////////////////////line 9
cout<<"     "<<"+---+";//5
for(int i=0;i<20+move;i++){cout<<' ';}
cout<<" | | ";
for(int i=0;i<20-move;i++){cout<<' ';}
cout<<"+---+";
cout<<"         "<<"|";//9
COM(step,line,input,NUM);
line++;
/////////////////////////////////////////////////////line 10
cout<<"     "<<"+---+";//5
for(int i=0;i<20;i++){cout<<' ';}
cout<<"     ";
for(int i=0;i<20;i++){cout<<' ';}
cout<<"+---+";
cout<<"         "<<"|";//9

COM(step,line,input,NUM);
line++;
/////////////////////////////////////////////////////line 11
cout<<"     "<<"|"<<change(IN[3]).a<<"|";//5
for(int i=0;i<14;i++){cout<<' ';}
for(int i=0;i<space_num;i++){cout<<"+---+ ";}//依据空地数space_num打印相应数量的空地
for(int i=0;i<26+5-6*space_num;i++){cout<<' ';}
cout<<"|"<<change(OUT[3]).a<<"|";
cout<<"         "<<"|";//9
COM(step,line,input,NUM);
line++;
/////////////////////////////////////////////////////line 12
cout<<"     "<<"+---+";//5
for(int i=0;i<14;i++){cout<<' ';}
for(int i=0;i<space_num;i++){cout<<"|"<<change(SPACE[i]).a<<"| ";}
for(int i=0;i<26+5-6*space_num;i++){cout<<' ';}
cout<<"+---+";
cout<<"         "<<"|";//9
COM(step,line,input,NUM);
line++;
/////////////////////////////////////////////////////line 13
cout<<"     "<<"+---+";//5
for(int i=0;i<14;i++){cout<<' ';}
for(int i=0;i<space_num;i++){cout<<"+---+ ";}
for(int i=0;i<26+5-6*space_num;i++){cout<<' ';}
cout<<"+---+";
cout<<"         "<<"|";//9
COM(step,line,input,NUM);
line++;

/////////////////////////////////////////////////////line 14
cout<<"     "<<"|"<<change(IN[4]).a<<"|";//5
for(int i=0;i<14;i++){cout<<' ';}
for(int i=0;i<space_num;i++){cout<<"  "<<i<<"   ";}
for(int i=0;i<26+5-6*space_num;i++){cout<<' ';}
cout<<"|"<<change(OUT[4]).a<<"|";
cout<<"         "<<"|";//9
COM(step,line,input,NUM);
line++;
/////////////////////////////////////////////////////line 15
cout<<"     "<<"+---+";//5
for(int i=0;i<45;i++){cout<<' ';}
cout<<"+---+";
cout<<"         "<<"|";//9
COM(step,line,input,NUM);
line++;
for(int i=0;i<5;i++){
for(int j=0;j<69;j++){cout<<" ";}//最后再多打印几行防止指令数过多
cout<<"|";
COM(step,line,input,NUM);
line++;
}

}


void print01(int space_num,int IN[],int OUT[],int SPACE[],int block){

cout<<endl<<endl;
/////////////////////////////////////////////////////line 1
cout<<"     "<<"+---+";//5
for(int i=0;i<20;i++){cout<<' ';}
cout<<"+---+";
for(int i=0;i<20;i++){cout<<' ';}
cout<<"+---+";
cout<<"         "<<"|"<<" "<<"关卡信息:"<<"可用空地数:"<<space_num<<endl;//9



/////////////////////////////////////////////////////line 2
cout<<" IN  "<<"|"<<change(IN[0]).a<<"|";//5
for(int i=0;i<20;i++){cout<<' ';}
cout<<"|"<<change(block).a<<"|";
for(int i=0;i<20;i++){cout<<' ';}
cout<<"|"<<change(OUT[0]).a<<"|";
cout<<"  OUT    "<<"|"<<" "<<"         "<<"可用指令集:"<<"inbox,outbox"<<endl;//9

/////////////////////////////////////////////////////line 3
cout<<"     "<<"+---+";//5
for(int i=0;i<20;i++){cout<<' ';}
cout<<"+---+";
for(int i=0;i<20;i++){cout<<' ';}
cout<<"+---+";
cout<<"         "<<"|"<<endl;//9

/////////////////////////////////////////////////////line 4
cout<<"     "<<"+---+";//5
for(int i=0;i<20;i++){cout<<' ';}
cout<<"@   @";
for(int i=0;i<20;i++){cout<<' ';}
cout<<"+---+";
cout<<"         "<<"|"<<" "<<"关卡任务:"<<"让机器人取出输入序列上的每个积木放入输出序"<<endl;//9



/////////////////////////////////////////////////////line 5
cout<<"     "<<"|"<<change(IN[1]).a<<"|";//5
for(int i=0;i<20;i++){cout<<' ';}
cout<<"-----";
for(int i=0;i<20;i++){cout<<' ';}
cout<<"|"<<change(OUT[1]).a<<"|";
cout<<"         "<<"|"<<" "<<"         "<<"列中"<<endl;//9

/////////////////////////////////////////////////////line 6
cout<<"     "<<"+---+";//5
for(int i=0;i<20;i++){cout<<' ';}
cout<<"|@ @|";
for(int i=0;i<20;i++){cout<<' ';}
cout<<"+---+";
cout<<"         "<<"|"<<" "<<"若对可用指令有疑问请输入“0”跳转到帮助界面"<<endl;//9

/////////////////////////////////////////////////////line 7
cout<<"     "<<"+---+";//5
for(int i=0;i<20;i++){cout<<' ';}
cout<<"  +  ";
for(int i=0;i<20;i++){cout<<' ';}
cout<<"+---+";
cout<<"         "<<"|"<<" "<<"若无疑问请选择输入模式:1:一次性输入所有指令"<<endl;//9



/////////////////////////////////////////////////////line 8
cout<<"     "<<"|"<<change(IN[2]).a<<"|";//5
for(int i=0;i<20;i++){cout<<' ';}
cout<<"/   "<<char(92);
for(int i=0;i<20;i++){cout<<' ';}
cout<<"|"<<change(OUT[2]).a<<"|";
cout<<"         "<<"|"<<" "<<"                                 "<<"2:依次输入指令"<<endl;

/////////////////////////////////////////////////////line 9
cout<<"     "<<"+---+";//5
for(int i=0;i<20;i++){cout<<' ';}
cout<<" | | ";
for(int i=0;i<20;i++){cout<<' ';}
cout<<"+---+";
cout<<"         "<<"|"<<endl;//9

/////////////////////////////////////////////////////line 10
cout<<"     "<<"+---+";//5
for(int i=0;i<20;i++){cout<<' ';}
cout<<"     ";
for(int i=0;i<20;i++){cout<<' ';}
cout<<"+---+";
cout<<"         "<<"|"<<endl;//9



/////////////////////////////////////////////////////line 11
cout<<"     "<<"|"<<change(IN[3]).a<<"|";//5
for(int i=0;i<14;i++){cout<<' ';}
for(int i=0;i<space_num;i++){cout<<"+---+ ";}
for(int i=0;i<26+5-6*space_num;i++){cout<<' ';}
cout<<"|"<<change(OUT[3]).a<<"|";
cout<<"         "<<"|"<<endl;//9

/////////////////////////////////////////////////////line 12
cout<<"     "<<"+---+";//5
for(int i=0;i<14;i++){cout<<' ';}
for(int i=0;i<space_num;i++){cout<<"|"<<change(SPACE[i]).a<<"| ";}
for(int i=0;i<26+5-6*space_num;i++){cout<<' ';}
cout<<"+---+";
cout<<"         "<<"|"<<endl;//9

/////////////////////////////////////////////////////line 13
cout<<"     "<<"+---+";//5
for(int i=0;i<14;i++){cout<<' ';}
for(int i=0;i<space_num;i++){cout<<"+---+ ";}
for(int i=0;i<26+5-6*space_num;i++){cout<<' ';}
cout<<"+---+";
cout<<"         "<<"|"<<endl;//9



/////////////////////////////////////////////////////line 14
cout<<"     "<<"|"<<change(IN[4]).a<<"|";//5
for(int i=0;i<14;i++){cout<<' ';}
for(int i=0;i<space_num;i++){cout<<"  "<<i<<"   ";}
for(int i=0;i<26+5-6*space_num;i++){cout<<' ';}
cout<<"|"<<change(OUT[4]).a<<"|";
cout<<"         "<<"|"<<endl;//9

/////////////////////////////////////////////////////line 15
cout<<"     "<<"+---+";//5
for(int i=0;i<45;i++){cout<<' ';}
cout<<"+---+";
cout<<"         "<<"|"<<endl;//9

}

void print02(int space_num,int IN[],int OUT[],int SPACE[],int block){//游戏开始界面(stage1)

cout<<endl<<endl;
/////////////////////////////////////////////////////line 1
cout<<"     "<<"+---+";//5
for(int i=0;i<20;i++){cout<<' ';}
cout<<"+---+";
for(int i=0;i<20;i++){cout<<' ';}
cout<<"+---+";
cout<<"         "<<"|"<<" "<<"关卡信息："<<"可用空地数:"<<space_num<<endl;//9



/////////////////////////////////////////////////////line 2
cout<<" IN  "<<"|"<<change(IN[0]).a<<"|";//5
for(int i=0;i<20;i++){cout<<' ';}
cout<<"|"<<change(block).a<<"|";
for(int i=0;i<20;i++){cout<<' ';}
cout<<"|"<<change(OUT[0]).a<<"|";
cout<<"  OUT    "<<"|"<<" "<<"          "<<"可用指令集："<<"inbox,outbox,jump,jumpifzero"<<endl;//9

/////////////////////////////////////////////////////line 3
cout<<"     "<<"+---+";//5
for(int i=0;i<20;i++){cout<<' ';}
cout<<"+---+";
for(int i=0;i<20;i++){cout<<' ';}
cout<<"+---+";
cout<<"         "<<"|"<<" "<<"                      "<<"add,sub,copyto,copyfrom"<<endl;//9

/////////////////////////////////////////////////////line 4
cout<<"     "<<"+---+";//5
for(int i=0;i<20;i++){cout<<' ';}
cout<<"@   @";
for(int i=0;i<20;i++){cout<<' ';}
cout<<"+---+";
cout<<"         "<<"|"<<" "<<"关卡任务："<<"对于输入序列中的每两个东西，先把第 1 个减"<<endl;//9



/////////////////////////////////////////////////////line 5
cout<<"     "<<"|"<<change(IN[1]).a<<"|";//5
for(int i=0;i<20;i++){cout<<' ';}
cout<<"-----";
for(int i=0;i<20;i++){cout<<' ';}
cout<<"|"<<change(OUT[1]).a<<"|";
cout<<"         "<<"|"<<" "<<"          "<<"去第 2 个，并把结果放在输出序列中，然后把"<<endl;//9


/////////////////////////////////////////////////////line 6
cout<<"     "<<"+---+";//5
for(int i=0;i<20;i++){cout<<' ';}
cout<<"|@ @|";
for(int i=0;i<20;i++){cout<<' ';}
cout<<"+---+";
cout<<"         "<<"|"<<" "<<"          "<<"第 2 个减去第 1 个，再把结果放在输出序列中，重复。"<<endl;//9

/////////////////////////////////////////////////////line 7
cout<<"     "<<"+---+";//5
for(int i=0;i<20;i++){cout<<' ';}
cout<<"  +  ";
for(int i=0;i<20;i++){cout<<' ';}
cout<<"+---+";
cout<<"         "<<"|"<<" "<<"若对可用指令有疑问请输入“0”跳转到帮助界面"<<endl;//9



/////////////////////////////////////////////////////line 8
cout<<"     "<<"|"<<change(IN[2]).a<<"|";//5
for(int i=0;i<20;i++){cout<<' ';}
cout<<"/   "<<char(92);
for(int i=0;i<20;i++){cout<<' ';}
cout<<"|"<<change(OUT[2]).a<<"|";
cout<<"         "<<"|"<<" "<<"若无疑问请选择输入模式:1:一次性输入所有指令"<<endl;//9

/////////////////////////////////////////////////////line 9
cout<<"     "<<"+---+";//5
for(int i=0;i<20;i++){cout<<' ';}
cout<<" | | ";
for(int i=0;i<20;i++){cout<<' ';}
cout<<"+---+";
cout<<"         "<<"|"<<" "<<"                                 "<<"2:依次输入指令"<<endl;

/////////////////////////////////////////////////////line 10
cout<<"     "<<"+---+";//5
for(int i=0;i<20;i++){cout<<' ';}
cout<<"     ";
for(int i=0;i<20;i++){cout<<' ';}
cout<<"+---+";
cout<<"         "<<"|"<<endl;//9



/////////////////////////////////////////////////////line 11
cout<<"     "<<"|"<<change(IN[3]).a<<"|";//5
for(int i=0;i<14;i++){cout<<' ';}
for(int i=0;i<space_num;i++){cout<<"+---+ ";}
for(int i=0;i<26+5-6*space_num;i++){cout<<' ';}
cout<<"|"<<change(OUT[3]).a<<"|";
cout<<"         "<<"|"<<endl;//9

/////////////////////////////////////////////////////line 12
cout<<"     "<<"+---+";//5
for(int i=0;i<14;i++){cout<<' ';}
for(int i=0;i<space_num;i++){cout<<"|"<<change(SPACE[i]).a<<"| ";}
for(int i=0;i<26+5-6*space_num;i++){cout<<' ';}
cout<<"+---+";
cout<<"         "<<"|"<<endl;//9

/////////////////////////////////////////////////////line 13
cout<<"     "<<"+---+";//5
for(int i=0;i<14;i++){cout<<' ';}
for(int i=0;i<space_num;i++){cout<<"+---+ ";}
for(int i=0;i<26+5-6*space_num;i++){cout<<' ';}
cout<<"+---+";
cout<<"         "<<"|"<<endl;//9



/////////////////////////////////////////////////////line 14
cout<<"     "<<"|"<<change(IN[4]).a<<"|";//5
for(int i=0;i<14;i++){cout<<' ';}
for(int i=0;i<space_num;i++){cout<<"  "<<i<<"   ";}
for(int i=0;i<26+5-6*space_num;i++){cout<<' ';}
cout<<"|"<<change(OUT[4]).a<<"|";
cout<<"         "<<"|"<<endl;//9

/////////////////////////////////////////////////////line 15
cout<<"     "<<"+---+";//5
for(int i=0;i<45;i++){cout<<' ';}
cout<<"+---+";
cout<<"         "<<"|"<<endl;//9

}




void print03(int space_num,int IN[],int OUT[],int SPACE[],int block){//游戏开始界面(stage1)

cout<<endl<<endl;
/////////////////////////////////////////////////////line 1
cout<<"     "<<"+---+";//5
for(int i=0;i<20;i++){cout<<' ';}
cout<<"+---+";
for(int i=0;i<20;i++){cout<<' ';}
cout<<"+---+";
cout<<"         "<<"|"<<" "<<"关卡信息："<<"可用空地数:"<<space_num<<endl;//9



/////////////////////////////////////////////////////line 2
cout<<" IN  "<<"|"<<change(IN[0]).a<<"|";//5
for(int i=0;i<20;i++){cout<<' ';}
cout<<"|"<<change(block).a<<"|";
for(int i=0;i<20;i++){cout<<' ';}
cout<<"|"<<change(OUT[0]).a<<"|";
cout<<"  OUT    "<<"|"<<" "<<"          "<<"可用指令集："<<"inbox,outbox,jump,jumpifzero"<<endl;//9

/////////////////////////////////////////////////////line 3
cout<<"     "<<"+---+";//5
for(int i=0;i<20;i++){cout<<' ';}
cout<<"+---+";
for(int i=0;i<20;i++){cout<<' ';}
cout<<"+---+";
cout<<"         "<<"|"<<" "<<"                      "<<"add,sub,copyto,copyfrom"<<endl;//9

/////////////////////////////////////////////////////line 4
cout<<"     "<<"+---+";//5
for(int i=0;i<20;i++){cout<<' ';}
cout<<"@   @";
for(int i=0;i<20;i++){cout<<' ';}
cout<<"+---+";
cout<<"         "<<"|"<<" "<<"关卡任务："<<"从输入序列中依次取 2 个数字，如果相等则将"<<endl;//9



/////////////////////////////////////////////////////line 5
cout<<"     "<<"|"<<change(IN[1]).a<<"|";//5
for(int i=0;i<20;i++){cout<<' ';}
cout<<"-----";
for(int i=0;i<20;i++){cout<<' ';}
cout<<"|"<<change(OUT[1]).a<<"|";
cout<<"         "<<"|"<<" "<<"          "<<"其中一个输出，否则扔掉。重复这个过程直到"<<endl;//9


/////////////////////////////////////////////////////line 6
cout<<"     "<<"+---+";//5
for(int i=0;i<20;i++){cout<<' ';}
cout<<"|@ @|";
for(int i=0;i<20;i++){cout<<' ';}
cout<<"+---+";
cout<<"         "<<"|"<<" "<<"          "<<"输入传送带为空。"<<endl;//9

/////////////////////////////////////////////////////line 7
cout<<"     "<<"+---+";//5
for(int i=0;i<20;i++){cout<<' ';}
cout<<"  +  ";
for(int i=0;i<20;i++){cout<<' ';}
cout<<"+---+";
cout<<"         "<<"|"<<" "<<"若对可用指令有疑问请输入“0”跳转到帮助界面"<<endl;//9



/////////////////////////////////////////////////////line 8
cout<<"     "<<"|"<<change(IN[2]).a<<"|";//5
for(int i=0;i<20;i++){cout<<' ';}
cout<<"/   "<<char(92);
for(int i=0;i<20;i++){cout<<' ';}
cout<<"|"<<change(OUT[2]).a<<"|";
cout<<"         "<<"|"<<" "<<"若无疑问请选择输入模式:1:一次性输入所有指令"<<endl;//9

/////////////////////////////////////////////////////line 9
cout<<"     "<<"+---+";//5
for(int i=0;i<20;i++){cout<<' ';}
cout<<" | | ";
for(int i=0;i<20;i++){cout<<' ';}
cout<<"+---+";
cout<<"         "<<"|"<<" "<<"                                 "<<"2:依次输入指令"<<endl;

/////////////////////////////////////////////////////line 10
cout<<"     "<<"+---+";//5
for(int i=0;i<20;i++){cout<<' ';}
cout<<"     ";
for(int i=0;i<20;i++){cout<<' ';}
cout<<"+---+";
cout<<"         "<<"|"<<endl;//9



/////////////////////////////////////////////////////line 11
cout<<"     "<<"|"<<change(IN[3]).a<<"|";//5
for(int i=0;i<14;i++){cout<<' ';}
for(int i=0;i<space_num;i++){cout<<"+---+ ";}
for(int i=0;i<26+5-6*space_num;i++){cout<<' ';}
cout<<"|"<<change(OUT[3]).a<<"|";
cout<<"         "<<"|"<<endl;//9

/////////////////////////////////////////////////////line 12
cout<<"     "<<"+---+";//5
for(int i=0;i<14;i++){cout<<' ';}
for(int i=0;i<space_num;i++){cout<<"|"<<change(SPACE[i]).a<<"| ";}
for(int i=0;i<26+5-6*space_num;i++){cout<<' ';}
cout<<"+---+";
cout<<"         "<<"|"<<endl;//9

/////////////////////////////////////////////////////line 13
cout<<"     "<<"+---+";//5
for(int i=0;i<14;i++){cout<<' ';}
for(int i=0;i<space_num;i++){cout<<"+---+ ";}
for(int i=0;i<26+5-6*space_num;i++){cout<<' ';}
cout<<"+---+";
cout<<"         "<<"|"<<endl;//9



/////////////////////////////////////////////////////line 14
cout<<"     "<<"|"<<change(IN[4]).a<<"|";//5
for(int i=0;i<14;i++){cout<<' ';}
for(int i=0;i<space_num;i++){cout<<"  "<<i<<"   ";}
for(int i=0;i<26+5-6*space_num;i++){cout<<' ';}
cout<<"|"<<change(OUT[4]).a<<"|";
cout<<"         "<<"|"<<endl;//9

/////////////////////////////////////////////////////line 15
cout<<"     "<<"+---+";//5
for(int i=0;i<45;i++){cout<<' ';}
cout<<"+---+";
cout<<"         "<<"|"<<endl;//9

}

void print001(int space_num,int IN[],int OUT[],int SPACE[],int block){

cout<<endl<<endl;
/////////////////////////////////////////////////////line 1
cout<<"     "<<"+---+";//5
for(int i=0;i<20;i++){cout<<' ';}
cout<<"+---+";
for(int i=0;i<20;i++){cout<<' ';}
cout<<"+---+";
cout<<"         "<<"|"<<" "<<"关卡信息:"<<"可用空地数:"<<space_num<<endl;//9



/////////////////////////////////////////////////////line 2
cout<<" IN  "<<"|"<<change(IN[0]).a<<"|";//5
for(int i=0;i<20;i++){cout<<' ';}
cout<<"|"<<change(block).a<<"|";
for(int i=0;i<20;i++){cout<<' ';}
cout<<"|"<<change(OUT[0]).a<<"|";
cout<<"  OUT    "<<"|"<<" "<<"         "<<"可用指令集:"<<"inbox,outbox"<<endl;//9

/////////////////////////////////////////////////////line 3
cout<<"     "<<"+---+";//5
for(int i=0;i<20;i++){cout<<' ';}
cout<<"+---+";
for(int i=0;i<20;i++){cout<<' ';}
cout<<"+---+";
cout<<"         "<<"|"<<endl;//9

/////////////////////////////////////////////////////line 4
cout<<"     "<<"+---+";//5
for(int i=0;i<20;i++){cout<<' ';}
cout<<"@   @";
for(int i=0;i<20;i++){cout<<' ';}
cout<<"+---+";
cout<<"         "<<"|"<<" "<<"关卡任务:"<<"让机器人取出输入序列上的每个积木放入输出序"<<endl;//9



/////////////////////////////////////////////////////line 5
cout<<"     "<<"|"<<change(IN[1]).a<<"|";//5
for(int i=0;i<20;i++){cout<<' ';}
cout<<"-----";
for(int i=0;i<20;i++){cout<<' ';}
cout<<"|"<<change(OUT[1]).a<<"|";
cout<<"         "<<"|"<<" "<<"         "<<"列中"<<endl;//9

/////////////////////////////////////////////////////line 6
cout<<"     "<<"+---+";//5
for(int i=0;i<20;i++){cout<<' ';}
cout<<"|@ @|";
for(int i=0;i<20;i++){cout<<' ';}
cout<<"+---+";
cout<<"         "<<"|"<<endl;//9

/////////////////////////////////////////////////////line 7
cout<<"     "<<"+---+";//5
for(int i=0;i<20;i++){cout<<' ';}
cout<<"  +  ";
for(int i=0;i<20;i++){cout<<' ';}
cout<<"+---+";
cout<<"         "<<"|"<<" "<<"请输入一条指令"<<endl;//9



/////////////////////////////////////////////////////line 8
cout<<"     "<<"|"<<change(IN[2]).a<<"|";//5
for(int i=0;i<20;i++){cout<<' ';}
cout<<"/   "<<char(92);
for(int i=0;i<20;i++){cout<<' ';}
cout<<"|"<<change(OUT[2]).a<<"|";
cout<<"         "<<"|"<<endl;//9

/////////////////////////////////////////////////////line 9
cout<<"     "<<"+---+";//5
for(int i=0;i<20;i++){cout<<' ';}
cout<<" | | ";
for(int i=0;i<20;i++){cout<<' ';}
cout<<"+---+";
cout<<"         "<<"|"<<endl;//9

/////////////////////////////////////////////////////line 10
cout<<"     "<<"+---+";//5
for(int i=0;i<20;i++){cout<<' ';}
cout<<"     ";
for(int i=0;i<20;i++){cout<<' ';}
cout<<"+---+";
cout<<"         "<<"|"<<endl;//9



/////////////////////////////////////////////////////line 11
cout<<"     "<<"|"<<change(IN[3]).a<<"|";//5
for(int i=0;i<14;i++){cout<<' ';}
for(int i=0;i<space_num;i++){cout<<"+---+ ";}
for(int i=0;i<26+5-6*space_num;i++){cout<<' ';}
cout<<"|"<<change(OUT[3]).a<<"|";
cout<<"         "<<"|"<<endl;//9

/////////////////////////////////////////////////////line 12
cout<<"     "<<"+---+";//5
for(int i=0;i<14;i++){cout<<' ';}
for(int i=0;i<space_num;i++){cout<<"|"<<change(SPACE[i]).a<<"| ";}
for(int i=0;i<26+5-6*space_num;i++){cout<<' ';}
cout<<"+---+";
cout<<"         "<<"|"<<endl;//9

/////////////////////////////////////////////////////line 13
cout<<"     "<<"+---+";//5
for(int i=0;i<14;i++){cout<<' ';}
for(int i=0;i<space_num;i++){cout<<"+---+ ";}
for(int i=0;i<26+5-6*space_num;i++){cout<<' ';}
cout<<"+---+";
cout<<"         "<<"|"<<endl;//9



/////////////////////////////////////////////////////line 14
cout<<"     "<<"|"<<change(IN[4]).a<<"|";//5
for(int i=0;i<14;i++){cout<<' ';}
for(int i=0;i<space_num;i++){cout<<"  "<<i<<"   ";}
for(int i=0;i<26+5-6*space_num;i++){cout<<' ';}
cout<<"|"<<change(OUT[4]).a<<"|";
cout<<"         "<<"|"<<endl;//9

/////////////////////////////////////////////////////line 15
cout<<"     "<<"+---+";//5
for(int i=0;i<45;i++){cout<<' ';}
cout<<"+---+";
cout<<"         "<<"|"<<endl;//9

}

void print002(int space_num,int IN[],int OUT[],int SPACE[],int block){

cout<<endl<<endl;
/////////////////////////////////////////////////////line 1
cout<<"     "<<"+---+";//5
for(int i=0;i<20;i++){cout<<' ';}
cout<<"+---+";
for(int i=0;i<20;i++){cout<<' ';}
cout<<"+---+";
cout<<"         "<<"|"<<" "<<"关卡信息："<<"可用空地数:"<<space_num<<endl;//9



/////////////////////////////////////////////////////line 2
cout<<" IN  "<<"|"<<change(IN[0]).a<<"|";//5
for(int i=0;i<20;i++){cout<<' ';}
cout<<"|"<<change(block).a<<"|";
for(int i=0;i<20;i++){cout<<' ';}
cout<<"|"<<change(OUT[0]).a<<"|";
cout<<"  OUT    "<<"|"<<" "<<"          "<<"可用指令集："<<"inbox,outbox,jump,jumpifzero"<<endl;//9

/////////////////////////////////////////////////////line 3
cout<<"     "<<"+---+";//5
for(int i=0;i<20;i++){cout<<' ';}
cout<<"+---+";
for(int i=0;i<20;i++){cout<<' ';}
cout<<"+---+";
cout<<"         "<<"|"<<" "<<"                      "<<"add,sub,copyto,copyfrom"<<endl;//9

/////////////////////////////////////////////////////line 4
cout<<"     "<<"+---+";//5
for(int i=0;i<20;i++){cout<<' ';}
cout<<"@   @";
for(int i=0;i<20;i++){cout<<' ';}
cout<<"+---+";
cout<<"         "<<"|"<<" "<<"关卡任务："<<"对于输入序列中的每两个东西，先把第 1 个减"<<endl;//9



/////////////////////////////////////////////////////line 5
cout<<"     "<<"|"<<change(IN[1]).a<<"|";//5
for(int i=0;i<20;i++){cout<<' ';}
cout<<"-----";
for(int i=0;i<20;i++){cout<<' ';}
cout<<"|"<<change(OUT[1]).a<<"|";
cout<<"         "<<"|"<<" "<<"          "<<"去第 2 个，并把结果放在输出序列中，然后把"<<endl;//9


/////////////////////////////////////////////////////line 6
cout<<"     "<<"+---+";//5
for(int i=0;i<20;i++){cout<<' ';}
cout<<"|@ @|";
for(int i=0;i<20;i++){cout<<' ';}
cout<<"+---+";
cout<<"         "<<"|"<<" "<<"          "<<"第 2 个减去第 1 个，再把结果放在输出序列中，重复。"<<endl;//9

/////////////////////////////////////////////////////line 7
cout<<"     "<<"+---+";//5
for(int i=0;i<20;i++){cout<<' ';}
cout<<"  +  ";
for(int i=0;i<20;i++){cout<<' ';}
cout<<"+---+";
cout<<"         "<<"|"<<endl;//9



/////////////////////////////////////////////////////line 8
cout<<"     "<<"|"<<change(IN[2]).a<<"|";//5
for(int i=0;i<20;i++){cout<<' ';}
cout<<"/   "<<char(92);
for(int i=0;i<20;i++){cout<<' ';}
cout<<"|"<<change(OUT[2]).a<<"|";
cout<<"         "<<"|"<<" "<<"请输入一条指令"<<endl;//9

/////////////////////////////////////////////////////line 9
cout<<"     "<<"+---+";//5
for(int i=0;i<20;i++){cout<<' ';}
cout<<" | | ";
for(int i=0;i<20;i++){cout<<' ';}
cout<<"+---+";
cout<<"         "<<"|"<<endl;//9

/////////////////////////////////////////////////////line 10
cout<<"     "<<"+---+";//5
for(int i=0;i<20;i++){cout<<' ';}
cout<<"     ";
for(int i=0;i<20;i++){cout<<' ';}
cout<<"+---+";
cout<<"         "<<"|"<<endl;//9



/////////////////////////////////////////////////////line 11
cout<<"     "<<"|"<<change(IN[3]).a<<"|";//5
for(int i=0;i<14;i++){cout<<' ';}
for(int i=0;i<space_num;i++){cout<<"+---+ ";}
for(int i=0;i<26+5-6*space_num;i++){cout<<' ';}
cout<<"|"<<change(OUT[3]).a<<"|";
cout<<"         "<<"|"<<endl;//9

/////////////////////////////////////////////////////line 12
cout<<"     "<<"+---+";//5
for(int i=0;i<14;i++){cout<<' ';}
for(int i=0;i<space_num;i++){cout<<"|"<<change(SPACE[i]).a<<"| ";}
for(int i=0;i<26+5-6*space_num;i++){cout<<' ';}
cout<<"+---+";
cout<<"         "<<"|"<<endl;//9

/////////////////////////////////////////////////////line 13
cout<<"     "<<"+---+";//5
for(int i=0;i<14;i++){cout<<' ';}
for(int i=0;i<space_num;i++){cout<<"+---+ ";}
for(int i=0;i<26+5-6*space_num;i++){cout<<' ';}
cout<<"+---+";
cout<<"         "<<"|"<<endl;//9



/////////////////////////////////////////////////////line 14
cout<<"     "<<"|"<<change(IN[4]).a<<"|";//5
for(int i=0;i<14;i++){cout<<' ';}
for(int i=0;i<space_num;i++){cout<<"  "<<i<<"   ";}
for(int i=0;i<26+5-6*space_num;i++){cout<<' ';}
cout<<"|"<<change(OUT[4]).a<<"|";
cout<<"         "<<"|"<<endl;//9

/////////////////////////////////////////////////////line 15
cout<<"     "<<"+---+";//5
for(int i=0;i<45;i++){cout<<' ';}
cout<<"+---+";
cout<<"         "<<"|"<<endl;//9

}

void print003(int space_num,int IN[],int OUT[],int SPACE[],int block){

cout<<endl<<endl;
/////////////////////////////////////////////////////line 1
cout<<"     "<<"+---+";//5
for(int i=0;i<20;i++){cout<<' ';}
cout<<"+---+";
for(int i=0;i<20;i++){cout<<' ';}
cout<<"+---+";
cout<<"         "<<"|"<<" "<<"关卡信息："<<"可用空地数:"<<space_num<<endl;//9



/////////////////////////////////////////////////////line 2
cout<<" IN  "<<"|"<<change(IN[0]).a<<"|";//5
for(int i=0;i<20;i++){cout<<' ';}
cout<<"|"<<change(block).a<<"|";
for(int i=0;i<20;i++){cout<<' ';}
cout<<"|"<<change(OUT[0]).a<<"|";
cout<<"  OUT    "<<"|"<<" "<<"          "<<"可用指令集："<<"inbox,outbox,jump,jumpifzero"<<endl;//9

/////////////////////////////////////////////////////line 3
cout<<"     "<<"+---+";//5
for(int i=0;i<20;i++){cout<<' ';}
cout<<"+---+";
for(int i=0;i<20;i++){cout<<' ';}
cout<<"+---+";
cout<<"         "<<"|"<<" "<<"                      "<<"add,sub,copyto,copyfrom"<<endl;//9

/////////////////////////////////////////////////////line 4
cout<<"     "<<"+---+";//5
for(int i=0;i<20;i++){cout<<' ';}
cout<<"@   @";
for(int i=0;i<20;i++){cout<<' ';}
cout<<"+---+";
cout<<"         "<<"|"<<" "<<"关卡任务："<<"从输入序列中依次取 2 个数字，如果相等则将"<<endl;//9



/////////////////////////////////////////////////////line 5
cout<<"     "<<"|"<<change(IN[1]).a<<"|";//5
for(int i=0;i<20;i++){cout<<' ';}
cout<<"-----";
for(int i=0;i<20;i++){cout<<' ';}
cout<<"|"<<change(OUT[1]).a<<"|";
cout<<"         "<<"|"<<" "<<"          "<<"其中一个输出，否则扔掉。重复这个过程直到"<<endl;//9


/////////////////////////////////////////////////////line 6
cout<<"     "<<"+---+";//5
for(int i=0;i<20;i++){cout<<' ';}
cout<<"|@ @|";
for(int i=0;i<20;i++){cout<<' ';}
cout<<"+---+";
cout<<"         "<<"|"<<" "<<"          "<<"输入传送带为空。"<<endl;//9

/////////////////////////////////////////////////////line 7
cout<<"     "<<"+---+";//5
for(int i=0;i<20;i++){cout<<' ';}
cout<<"  +  ";
for(int i=0;i<20;i++){cout<<' ';}
cout<<"+---+";
cout<<"         "<<"|"<<endl;//9



/////////////////////////////////////////////////////line 8
cout<<"     "<<"|"<<change(IN[2]).a<<"|";//5
for(int i=0;i<20;i++){cout<<' ';}
cout<<"/   "<<char(92);
for(int i=0;i<20;i++){cout<<' ';}
cout<<"|"<<change(OUT[2]).a<<"|";
cout<<"         "<<"|"<<" "<<"请输入一条指令"<<endl;//9

/////////////////////////////////////////////////////line 9
cout<<"     "<<"+---+";//5
for(int i=0;i<20;i++){cout<<' ';}
cout<<" | | ";
for(int i=0;i<20;i++){cout<<' ';}
cout<<"+---+";
cout<<"         "<<"|"<<endl;//9

/////////////////////////////////////////////////////line 10
cout<<"     "<<"+---+";//5
for(int i=0;i<20;i++){cout<<' ';}
cout<<"     ";
for(int i=0;i<20;i++){cout<<' ';}
cout<<"+---+";
cout<<"         "<<"|"<<endl;//9



/////////////////////////////////////////////////////line 11
cout<<"     "<<"|"<<change(IN[3]).a<<"|";//5
for(int i=0;i<14;i++){cout<<' ';}
for(int i=0;i<space_num;i++){cout<<"+---+ ";}
for(int i=0;i<26+5-6*space_num;i++){cout<<' ';}
cout<<"|"<<change(OUT[3]).a<<"|";
cout<<"         "<<"|"<<endl;//9

/////////////////////////////////////////////////////line 12
cout<<"     "<<"+---+";//5
for(int i=0;i<14;i++){cout<<' ';}
for(int i=0;i<space_num;i++){cout<<"|"<<change(SPACE[i]).a<<"| ";}
for(int i=0;i<26+5-6*space_num;i++){cout<<' ';}
cout<<"+---+";
cout<<"         "<<"|"<<endl;//9

/////////////////////////////////////////////////////line 13
cout<<"     "<<"+---+";//5
for(int i=0;i<14;i++){cout<<' ';}
for(int i=0;i<space_num;i++){cout<<"+---+ ";}
for(int i=0;i<26+5-6*space_num;i++){cout<<' ';}
cout<<"+---+";
cout<<"         "<<"|"<<endl;//9



/////////////////////////////////////////////////////line 14
cout<<"     "<<"|"<<change(IN[4]).a<<"|";//5
for(int i=0;i<14;i++){cout<<' ';}
for(int i=0;i<space_num;i++){cout<<"  "<<i<<"   ";}
for(int i=0;i<26+5-6*space_num;i++){cout<<' ';}
cout<<"|"<<change(OUT[4]).a<<"|";
cout<<"         "<<"|"<<endl;//9

/////////////////////////////////////////////////////line 15
cout<<"     "<<"+---+";//5
for(int i=0;i<45;i++){cout<<' ';}
cout<<"+---+";
cout<<"         "<<"|"<<endl;//9

}

void print004(int space_num,int IN[],int OUT[],int SPACE[],int block){//游戏开始界面(stage1)

cout<<endl<<endl;
/////////////////////////////////////////////////////line 1
cout<<"     "<<"+---+";//5
for(int i=0;i<20;i++){cout<<' ';}
cout<<"+---+";
for(int i=0;i<20;i++){cout<<' ';}
cout<<"+---+";
cout<<"         "<<"|"<<" "<<"关卡信息:"<<"可用空地数:"<<space_num<<endl;//9



/////////////////////////////////////////////////////line 2
cout<<" IN  "<<"|"<<change(IN[0]).a<<"|";//5
for(int i=0;i<20;i++){cout<<' ';}
cout<<"|"<<change(block).a<<"|";
for(int i=0;i<20;i++){cout<<' ';}
cout<<"|"<<change(OUT[0]).a<<"|";
cout<<"  OUT    "<<"|"<<" "<<"         "<<"可用指令集:"<<"inbox,outbox,jump,jumpifzero"<<endl;//9

/////////////////////////////////////////////////////line 3
cout<<"     "<<"+---+";//5
for(int i=0;i<20;i++){cout<<' ';}
cout<<"+---+";
for(int i=0;i<20;i++){cout<<' ';}
cout<<"+---+";
cout<<"         "<<"|"<<" "<<"                      "<<"add,sub,copyto,copyfrom"<<endl;

/////////////////////////////////////////////////////line 4
cout<<"     "<<"+---+";//5
for(int i=0;i<20;i++){cout<<' ';}
cout<<"@   @";
for(int i=0;i<20;i++){cout<<' ';}
cout<<"+---+";
cout<<"         "<<"|"<<" "<<"关卡任务:"<<"让机器人取出输入序列上的每个积木乘十后放入"<<endl;//9



/////////////////////////////////////////////////////line 5
cout<<"     "<<"|"<<change(IN[1]).a<<"|";//5
for(int i=0;i<20;i++){cout<<' ';}
cout<<"-----";
for(int i=0;i<20;i++){cout<<' ';}
cout<<"|"<<change(OUT[1]).a<<"|";
cout<<"         "<<"|"<<" "<<"         "<<"输出序列中"<<endl;//9

/////////////////////////////////////////////////////line 6
cout<<"     "<<"+---+";//5
for(int i=0;i<20;i++){cout<<' ';}
cout<<"|@ @|";
for(int i=0;i<20;i++){cout<<' ';}
cout<<"+---+";
cout<<"         "<<"|"<<endl;//9

/////////////////////////////////////////////////////line 7
cout<<"     "<<"+---+";//5
for(int i=0;i<20;i++){cout<<' ';}
cout<<"  +  ";
for(int i=0;i<20;i++){cout<<' ';}
cout<<"+---+";
cout<<"         "<<"|"<<" "<<"请输入一条指令"<<endl;//9



/////////////////////////////////////////////////////line 8
cout<<"     "<<"|"<<change(IN[2]).a<<"|";//5
for(int i=0;i<20;i++){cout<<' ';}
cout<<"/   "<<char(92);
for(int i=0;i<20;i++){cout<<' ';}
cout<<"|"<<change(OUT[2]).a<<"|";
cout<<"         "<<"|"<<endl;//9

/////////////////////////////////////////////////////line 9
cout<<"     "<<"+---+";//5
for(int i=0;i<20;i++){cout<<' ';}
cout<<" | | ";
for(int i=0;i<20;i++){cout<<' ';}
cout<<"+---+";
cout<<"         "<<"|"<<endl;//9

/////////////////////////////////////////////////////line 10
cout<<"     "<<"+---+";//5
for(int i=0;i<20;i++){cout<<' ';}
cout<<"     ";
for(int i=0;i<20;i++){cout<<' ';}
cout<<"+---+";
cout<<"         "<<"|"<<endl;//9



/////////////////////////////////////////////////////line 11
cout<<"     "<<"|"<<change(IN[3]).a<<"|";//5
for(int i=0;i<14;i++){cout<<' ';}
for(int i=0;i<space_num;i++){cout<<"+---+ ";}
for(int i=0;i<26+5-6*space_num;i++){cout<<' ';}
cout<<"|"<<change(OUT[3]).a<<"|";
cout<<"         "<<"|"<<endl;//9

/////////////////////////////////////////////////////line 12
cout<<"     "<<"+---+";//5
for(int i=0;i<14;i++){cout<<' ';}
for(int i=0;i<space_num;i++){cout<<"|"<<change(SPACE[i]).a<<"| ";}
for(int i=0;i<26+5-6*space_num;i++){cout<<' ';}
cout<<"+---+";
cout<<"         "<<"|"<<endl;//9

/////////////////////////////////////////////////////line 13
cout<<"     "<<"+---+";//5
for(int i=0;i<14;i++){cout<<' ';}
for(int i=0;i<space_num;i++){cout<<"+---+ ";}
for(int i=0;i<26+5-6*space_num;i++){cout<<' ';}
cout<<"+---+";
cout<<"         "<<"|"<<endl;//9



/////////////////////////////////////////////////////line 14
cout<<"     "<<"|"<<change(IN[4]).a<<"|";//5
for(int i=0;i<14;i++){cout<<' ';}
for(int i=0;i<space_num;i++){cout<<"  "<<i<<"   ";}
for(int i=0;i<26+5-6*space_num;i++){cout<<' ';}
cout<<"|"<<change(OUT[4]).a<<"|";
cout<<"         "<<"|"<<endl;//9

/////////////////////////////////////////////////////line 15
cout<<"     "<<"+---+";//5
for(int i=0;i<45;i++){cout<<' ';}
cout<<"+---+";
cout<<"         "<<"|"<<endl;//9

}


void print04(int space_num,int IN[],int OUT[],int SPACE[],int block){

cout<<endl<<endl;
/////////////////////////////////////////////////////line 1
cout<<"     "<<"+---+";//5
for(int i=0;i<20;i++){cout<<' ';}
cout<<"+---+";
for(int i=0;i<20;i++){cout<<' ';}
cout<<"+---+";
cout<<"         "<<"|"<<" "<<"关卡信息:"<<"可用空地数:"<<space_num<<endl;//9



/////////////////////////////////////////////////////line 2
cout<<" IN  "<<"|"<<change(IN[0]).a<<"|";//5
for(int i=0;i<20;i++){cout<<' ';}
cout<<"|"<<change(block).a<<"|";
for(int i=0;i<20;i++){cout<<' ';}
cout<<"|"<<change(OUT[0]).a<<"|";
cout<<"  OUT    "<<"|"<<" "<<"         "<<"可用指令集:"<<"inbox,outbox,jump,jumpifzero"<<endl;//9

/////////////////////////////////////////////////////line 3
cout<<"     "<<"+---+";//5
for(int i=0;i<20;i++){cout<<' ';}
cout<<"+---+";
for(int i=0;i<20;i++){cout<<' ';}
cout<<"+---+";
cout<<"         "<<"|"<<" "<<"                      "<<"add,sub,copyto,copyfrom"<<endl;//9

/////////////////////////////////////////////////////line 4
cout<<"     "<<"+---+";//5
for(int i=0;i<20;i++){cout<<' ';}
cout<<"@   @";
for(int i=0;i<20;i++){cout<<' ';}
cout<<"+---+";
cout<<"         "<<"|"<<" "<<"关卡任务:"<<"让机器人取出输入序列上的每个积木乘十后放入"<<endl;//9



/////////////////////////////////////////////////////line 5
cout<<"     "<<"|"<<change(IN[1]).a<<"|";//5
for(int i=0;i<20;i++){cout<<' ';}
cout<<"-----";
for(int i=0;i<20;i++){cout<<' ';}
cout<<"|"<<change(OUT[1]).a<<"|";
cout<<"         "<<"|"<<" "<<"         "<<"输出序列中"<<endl;//9

/////////////////////////////////////////////////////line 6
cout<<"     "<<"+---+";//5
for(int i=0;i<20;i++){cout<<' ';}
cout<<"|@ @|";
for(int i=0;i<20;i++){cout<<' ';}
cout<<"+---+";
cout<<"         "<<"|"<<" "<<"若对可用指令有疑问请输入“0”跳转到帮助界面"<<endl;//9

/////////////////////////////////////////////////////line 7
cout<<"     "<<"+---+";//5
for(int i=0;i<20;i++){cout<<' ';}
cout<<"  +  ";
for(int i=0;i<20;i++){cout<<' ';}
cout<<"+---+";
cout<<"         "<<"|"<<" "<<"若无疑问请选择输入模式:1:一次性输入所有指令"<<endl;//9



/////////////////////////////////////////////////////line 8
cout<<"     "<<"|"<<change(IN[2]).a<<"|";//5
for(int i=0;i<20;i++){cout<<' ';}
cout<<"/   "<<char(92);
for(int i=0;i<20;i++){cout<<' ';}
cout<<"|"<<change(OUT[2]).a<<"|";
cout<<"         "<<"|"<<" "<<"                                 "<<"2:依次输入指令"<<endl;

/////////////////////////////////////////////////////line 9
cout<<"     "<<"+---+";//5
for(int i=0;i<20;i++){cout<<' ';}
cout<<" | | ";
for(int i=0;i<20;i++){cout<<' ';}
cout<<"+---+";
cout<<"         "<<"|"<<endl;//9

/////////////////////////////////////////////////////line 10
cout<<"     "<<"+---+";//5
for(int i=0;i<20;i++){cout<<' ';}
cout<<"     ";
for(int i=0;i<20;i++){cout<<' ';}
cout<<"+---+";
cout<<"         "<<"|"<<endl;//9



/////////////////////////////////////////////////////line 11
cout<<"     "<<"|"<<change(IN[3]).a<<"|";//5
for(int i=0;i<14;i++){cout<<' ';}
for(int i=0;i<space_num;i++){cout<<"+---+ ";}
for(int i=0;i<26+5-6*space_num;i++){cout<<' ';}
cout<<"|"<<change(OUT[3]).a<<"|";
cout<<"         "<<"|"<<endl;//9

/////////////////////////////////////////////////////line 12
cout<<"     "<<"+---+";//5
for(int i=0;i<14;i++){cout<<' ';}
for(int i=0;i<space_num;i++){cout<<"|"<<change(SPACE[i]).a<<"| ";}
for(int i=0;i<26+5-6*space_num;i++){cout<<' ';}
cout<<"+---+";
cout<<"         "<<"|"<<endl;//9

/////////////////////////////////////////////////////line 13
cout<<"     "<<"+---+";//5
for(int i=0;i<14;i++){cout<<' ';}
for(int i=0;i<space_num;i++){cout<<"+---+ ";}
for(int i=0;i<26+5-6*space_num;i++){cout<<' ';}
cout<<"+---+";
cout<<"         "<<"|"<<endl;//9



/////////////////////////////////////////////////////line 14
cout<<"     "<<"|"<<change(IN[4]).a<<"|";//5
for(int i=0;i<14;i++){cout<<' ';}
for(int i=0;i<space_num;i++){cout<<"  "<<i<<"   ";}
for(int i=0;i<26+5-6*space_num;i++){cout<<' ';}
cout<<"|"<<change(OUT[4]).a<<"|";
cout<<"         "<<"|"<<endl;//9

/////////////////////////////////////////////////////line 15
cout<<"     "<<"+---+";//5
for(int i=0;i<45;i++){cout<<' ';}
cout<<"+---+";
cout<<"         "<<"|"<<endl;//9

}

void print14(int space_num,int IN[],int OUT[],int SPACE[],int block){//游戏开始界面(stage1)

cout<<endl<<endl;
/////////////////////////////////////////////////////line 1
cout<<"     "<<"+---+";//5
for(int i=0;i<20;i++){cout<<' ';}
cout<<"+---+";
for(int i=0;i<20;i++){cout<<' ';}
cout<<"+---+";
cout<<"         "<<"|"<<" "<<"关卡信息:"<<"可用空地数:"<<space_num<<endl;//9



/////////////////////////////////////////////////////line 2
cout<<" IN  "<<"|"<<change(IN[0]).a<<"|";//5
for(int i=0;i<20;i++){cout<<' ';}
cout<<"|"<<change(block).a<<"|";
for(int i=0;i<20;i++){cout<<' ';}
cout<<"|"<<change(OUT[0]).a<<"|";
cout<<"  OUT    "<<"|"<<" "<<"         "<<"可用指令集:"<<"inbox,outbox,jump,jumpifzero"<<endl;//9

/////////////////////////////////////////////////////line 3
cout<<"     "<<"+---+";//5
for(int i=0;i<20;i++){cout<<' ';}
cout<<"+---+";
for(int i=0;i<20;i++){cout<<' ';}
cout<<"+---+";
cout<<"         "<<"|"<<" "<<"                      "<<"add,sub,copyto,copyfrom"<<endl;//9

/////////////////////////////////////////////////////line 4
cout<<"     "<<"+---+";//5
for(int i=0;i<20;i++){cout<<' ';}
cout<<"@   @";
for(int i=0;i<20;i++){cout<<' ';}
cout<<"+---+";
cout<<"         "<<"|"<<" "<<"关卡任务:"<<"让机器人取出输入序列上的每个积木乘十后放入"<<endl;//9



/////////////////////////////////////////////////////line 5
cout<<"     "<<"|"<<change(IN[1]).a<<"|";//5
for(int i=0;i<20;i++){cout<<' ';}
cout<<"-----";
for(int i=0;i<20;i++){cout<<' ';}
cout<<"|"<<change(OUT[1]).a<<"|";
cout<<"         "<<"|"<<" "<<"         "<<"输出序列中"<<endl;//9

/////////////////////////////////////////////////////line 6
cout<<"     "<<"+---+";//5
for(int i=0;i<20;i++){cout<<' ';}
cout<<"|@ @|";
for(int i=0;i<20;i++){cout<<' ';}
cout<<"+---+";
cout<<"         "<<"|"<<endl;//9

/////////////////////////////////////////////////////line 7
cout<<"     "<<"+---+";//5
for(int i=0;i<20;i++){cout<<' ';}
cout<<"  +  ";
for(int i=0;i<20;i++){cout<<' ';}
cout<<"+---+";
cout<<"         "<<"|"<<" "<<"请输入指令数(第一行)和指令(从第二行起每行一条)"<<endl;//9



/////////////////////////////////////////////////////line 8
cout<<"     "<<"|"<<change(IN[2]).a<<"|";//5
for(int i=0;i<20;i++){cout<<' ';}
cout<<"/   "<<char(92);
for(int i=0;i<20;i++){cout<<' ';}
cout<<"|"<<change(OUT[2]).a<<"|";
cout<<"         "<<"|"<<endl;//9

/////////////////////////////////////////////////////line 9
cout<<"     "<<"+---+";//5
for(int i=0;i<20;i++){cout<<' ';}
cout<<" | | ";
for(int i=0;i<20;i++){cout<<' ';}
cout<<"+---+";
cout<<"         "<<"|"<<endl;//9

/////////////////////////////////////////////////////line 10
cout<<"     "<<"+---+";//5
for(int i=0;i<20;i++){cout<<' ';}
cout<<"     ";
for(int i=0;i<20;i++){cout<<' ';}
cout<<"+---+";
cout<<"         "<<"|"<<endl;//9



/////////////////////////////////////////////////////line 11
cout<<"     "<<"|"<<change(IN[3]).a<<"|";//5
for(int i=0;i<14;i++){cout<<' ';}
for(int i=0;i<space_num;i++){cout<<"+---+ ";}
for(int i=0;i<26+5-6*space_num;i++){cout<<' ';}
cout<<"|"<<change(OUT[3]).a<<"|";
cout<<"         "<<"|"<<endl;//9

/////////////////////////////////////////////////////line 12
cout<<"     "<<"+---+";//5
for(int i=0;i<14;i++){cout<<' ';}
for(int i=0;i<space_num;i++){cout<<"|"<<change(SPACE[i]).a<<"| ";}
for(int i=0;i<26+5-6*space_num;i++){cout<<' ';}
cout<<"+---+";
cout<<"         "<<"|"<<endl;//9

/////////////////////////////////////////////////////line 13
cout<<"     "<<"+---+";//5
for(int i=0;i<14;i++){cout<<' ';}
for(int i=0;i<space_num;i++){cout<<"+---+ ";}
for(int i=0;i<26+5-6*space_num;i++){cout<<' ';}
cout<<"+---+";
cout<<"         "<<"|"<<endl;//9



/////////////////////////////////////////////////////line 14
cout<<"     "<<"|"<<change(IN[4]).a<<"|";//5
for(int i=0;i<14;i++){cout<<' ';}
for(int i=0;i<space_num;i++){cout<<"  "<<i<<"   ";}
for(int i=0;i<26+5-6*space_num;i++){cout<<' ';}
cout<<"|"<<change(OUT[4]).a<<"|";
cout<<"         "<<"|"<<endl;//9

/////////////////////////////////////////////////////line 15
cout<<"     "<<"+---+";//5
for(int i=0;i<45;i++){cout<<' ';}
cout<<"+---+";
cout<<"         "<<"|"<<endl;//9

}