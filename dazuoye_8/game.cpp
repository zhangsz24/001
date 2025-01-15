
#include "page.h"
#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <unistd.h>
#include "help.h"
#include <limits>



using namespace std;





struct instruction {
  string instruction_name; // ָ 指令名   
  string operand;          //  操作数（字符串型）     
  int OPERAND;             //  操作数（整型）     
};


void set(int row,int column){//（光标定位函数）
cout<<"\033["<<row<<";"<<column<<"H";

}

int compare(int A[], int B[]) {//（比较两个数组，相同返回1，不同返回0，用于判断success/fail）
  for (int i = 0; i < 100; i++) {
    if (A[i] != B[i])
      return 0;
  }
  return 1;
}





void pop_in(int A[], int a) {//用于outbox时将一个数压入输出队列
  for (int i = 99; i > 0; i--) {//输入/输出队列长度都为100
    A[i] = A[i - 1];
  }
  A[0] = a;
}





void pop_out(int A[]) {//用于inbox时从输入队列弹出来一个数
  for (int i = 0; i < 99; i++) {
    A[i] = A[i + 1];
  }
  A[99] = -500;//-500表示该位置没有数
}





//只对第一关进行注释，其他关同理

int stage1() {
  int choice;//用户的选择（两种输入模式或打开帮助界面）
  
  int IN[100] = {1, 2};//输入队列
  int OUT[100] = {-500, -500}; //输出队列
  for (int i = 2; i < 100; i++) {
    IN[i] = -500;
    OUT[i] = -500;
  }
  int goal[100] = {2, 1};//目标输出队列
  for (int i = 2; i < 100; i++) {
    goal[i] = -500;
  }

  int block = -500; //机器人手中的积木（此时无积木）
  int space_num=0;//空地数
  labelone:
 
  system("cls");
  print01(space_num,IN,OUT,IN,block);//选择输入模式或help界面
  cout<<"\033[11;71H";//光标定位
  cin>>choice;//输入选择
  if(cin.fail()||(choice!=0&&choice!=1&&choice!=2)){//非法输入
    cin.clear(); // 清除错误状态
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 忽略错误输入直到下一个换行符
    cout<<"\033[12;71H"<<"无效输入，请输入0或1或2"<<endl;
    cout<<"\033[13;71H";
    system("pause");
    goto labelone;//返回



  }
  else if (choice==0){//跳转到帮助界面
    system("cls");
    help();
    goto labelone;//返回
    



  }
  else if(choice==1){//输入模式一
  
  
int count=0;//记录执行的总指令数

  system("cls");
  print11(space_num,IN,OUT,IN,block);//输入模式1开始界面
  
  
  
  
  int NUM; //指令数 ָ    
  cin >> NUM;





  string input[NUM + 1];
  for (int i = 0; i <= NUM; i++) {
    getline(cin, input[i]);//读取NUM条指令
  }
  instruction order[NUM + 1];
  for (int i = 1; i <= NUM; i++) //将每条input中指令名和操作数分开，便于后续执行    ֿ 
  {
    order[i].instruction_name.clear();
    order[i].operand.clear();
    int n = 0;
    while (n < input[i].length() && (input[i][n] != ' ')) {
      order[i].instruction_name.push_back(input[i][n]);
      n++;
    }
    n++;
    while (n < input[i].length()) {
      order[i].operand.push_back(input[i][n]);
      n++;
    }
    order[i].OPERAND = 0;
    for (int j = 0; j < order[i].operand.length(); j++) {//将字符串操作数转为整型
      if (order[i].operand[j] < '0' || order[i].operand[j] > '9') {
        order[i].OPERAND = -1;//操作数位置若有非数字内容操作数会变为-1，后续会报错
        break;
      }
      int m = order[i].operand[j] - '0';
      for (int p = 0; p < order[i].operand.length() - j - 1; p++) {
        m = m * 10;
      }
      order[i].OPERAND += m;
    }
  }
  
  
  int step = 1;//当前正在执行第几步
system("cls");
print2(space_num,IN,OUT,IN,block,input,step,NUM,0);//游戏运行过程中的界面
sleep(1);
  while (step <= NUM) {//步数小于指令总数则进行循环
    


//之后逐条比对某条指令的指令名和可用指令的指令名
    if (order[step].instruction_name == "inbox" && input[step].length() == 5) {//判定为inbox指令
      for(int i=-1;i>=-19;i=i-2){//机器人移动到左边
      system("cls");
      print2(space_num,IN,OUT,IN,block,input,step,NUM,i);
      usleep(400000);
    



    }
    sleep(1);
      
      
      
      
      
      
      if (IN[0] == -500) {//输入队列已空 
        
        
        
        
        
        if (compare(goal, OUT) == 1) {//结束游戏，比对此时的输出队列和目标输出队列
          set(6+NUM,72);
          cout << "Success" << endl;
          set(7+NUM,72);
          cout<<"本次游戏完整执行的指令数为："<<count<<endl;
          set(8+NUM,72);
          system("pause");
          return 1;//成功
        } else {
          set(6+NUM,72);
          cout << "Fail" << endl;
          set(7+NUM,72);
          cout<<"本次游戏完整执行的指令数为："<<count<<endl;
          set(8+NUM,72);
          system("pause");
          return 0;//失败
        }
      


        
      }

      //若游戏未结束，执行inbox的内容
      block = IN[0];
      pop_out(IN);
      count++;//已执行的指令数加1
      system("cls");
      print2(space_num,IN,OUT,IN,block,input,step,NUM,-19);
      sleep(1);
      for(int i=-18;i<=0;i=i+2){//机器人走回去
        system("cls");
      print2(space_num,IN,OUT,IN,block,input,step,NUM,i);
      usleep(400000);



      }
      sleep(1);
    }

    else if (order[step].instruction_name == "outbox" &&//判定为outbox指令
             input[step].length() == 6) {
              for(int i=1;i<=19;i=i+2){//机器人走到右边
      system("cls");
      print2(space_num,IN,OUT,IN,block,input,step,NUM,i);
      usleep(400000);
    



    }
    sleep(1);






      if (block == -500) {//先判定报错情况
      set(6+NUM,72);
        cout << "Error on instruction " << step<<endl;
        set(7+NUM,72);
        system("pause");
        
        
        return 0;//失败
      }
     //执行outbox内容
      pop_in(OUT, block);
      block = -500;
      count++;
      system("cls");
print2(space_num,IN,OUT,IN,block,input,step,NUM,19);
sleep(1);

for(int i=18;i>=0;i=i-2){//机器人走回来
        system("cls");
      print2(space_num,IN,OUT,IN,block,input,step,NUM,i);
      usleep(400000);



      }
      sleep(1);


    } 
    
    
    else {//这条指令和所有可用指令都不匹配，报错
      set(6+NUM,72);
      cout << "Error on instruction " << step<<endl;
      set(7+NUM,72);
      system("pause");
      return 0;
    }
    step++;//进入下一步
    system("cls");
print2(space_num,IN,OUT,IN,block,input,step,NUM,0);
sleep(1);
  }

  if (compare(goal, OUT) == 1) {//循环结束游戏结束后判定
    set(6+NUM,72);
    cout << "Success" << endl;
    set(7+NUM,72);
          cout<<"本次游戏完整执行的指令数为："<<count<<endl;
    set(8+NUM,72);
    system("pause");
    return 1;
  } else {
    set(6+NUM,72);
    cout << "Fail" << endl;
    set(7+NUM,72);
          cout<<"本次游戏完整执行的指令数为："<<count<<endl;
    set(8+NUM,72);
    system("pause");
    return 0;
  }
  }
  else {//输入模式二
    system("cls");
  print001(space_num,IN,OUT,IN,block);//游戏模式2开始界面
  
  int count=0;
  
  
  int NUM=1; //将初始总指令数设为1（即将输入第一条） ָ    
  int step=1;





  string input[100];
  
  instruction order[100];
  
  set(25,1);
  getline(cin,input[NUM]);//这一条会采集到空行
  labelthree://指令执行到底要输入新指令时会跳转到这里



  getline(cin,input[NUM]);//读取输入
  system("cls");
  print2(space_num,IN,OUT,IN,block,input,step,NUM,0);
  if(input[NUM]=="end"){//若输入为“end”则结束开始比对
    if (compare(goal, OUT) == 1) {
    set(6+NUM,72);
    cout << "Success" << endl;
    set(7+NUM,72);
          cout<<"本次游戏完整执行的指令数为："<<count<<endl;
    set(8+NUM,72);
    system("pause");
    return 1;
  } else {
    set(6+NUM,72);
    cout << "Fail" << endl;
    set(7+NUM,72);
          cout<<"本次游戏完整执行的指令数为："<<count<<endl;
    set(8+NUM,72);
    system("pause");
    return 0;
  }



  }
    order[NUM].instruction_name.clear();//与之前同理处理刚输入的指令
    order[NUM].operand.clear();
    int n = 0;
    while (n < input[NUM].length() && (input[NUM][n] != ' ')) {
      order[NUM].instruction_name.push_back(input[NUM][n]);
      n++;
    }
    n++;
    while (n < input[NUM].length()) {
      order[NUM].operand.push_back(input[NUM][n]);
      n++;
    }
    order[NUM].OPERAND = 0;
    for (int j = 0; j < order[NUM].operand.length(); j++) {
      if (order[NUM].operand[j] < '0' || order[NUM].operand[j] > '9') {
        order[NUM].OPERAND = -1;
        break;
      }
      int m = order[NUM].operand[j] - '0';
      for (int p = 0; p < order[NUM].operand.length() - j - 1; p++) {
        m = m * 10;
      }
      order[NUM].OPERAND += m;
    }
  labeltwo://继续执行下一条指令但无需输入
  
  
  
system("cls");
print2(space_num,IN,OUT,IN,block,input,step,NUM,0);
sleep(1);
  
    

  
//执行指令
    if (order[step].instruction_name == "inbox" && input[step].length() == 5) {
      for(int i=-1;i>=-19;i=i-2){
      system("cls");
      print2(space_num,IN,OUT,IN,block,input,step,NUM,i);
      usleep(400000);
    



    }
    sleep(1);
      
      
      
      
      
      
      if (IN[0] == -500) { 
        
        
        
        
        
        if (compare(goal, OUT) == 1) {
          set(6+NUM,72);
          cout << "Success" << endl;
          set(7+NUM,72);
          cout<<"本次游戏完整执行的指令数为："<<count<<endl;
          set(8+NUM,72);
          system("pause");
          return 1;
        } else {
          set(6+NUM,72);
          cout << "Fail" << endl;
          set(7+NUM,72);
          cout<<"本次游戏完整执行的指令数为："<<count<<endl;
          set(8+NUM,72);
          system("pause");
          return 0;
        }
      


        
      }

      
      block = IN[0];
      pop_out(IN);
      count++;
      system("cls");
      print2(space_num,IN,OUT,IN,block,input,step,NUM,-19);
      sleep(1);
      for(int i=-18;i<=0;i=i+2){
        system("cls");
      print2(space_num,IN,OUT,IN,block,input,step,NUM,i);
      usleep(400000);



      }
      sleep(1);
    }

    else if (order[step].instruction_name == "outbox" &&
             input[step].length() == 6) {
              for(int i=1;i<=19;i=i+2){
      system("cls");
      print2(space_num,IN,OUT,IN,block,input,step,NUM,i);
      usleep(400000);
    



    }
    sleep(1);






      if (block == -500) {
      set(6+NUM,72);
        cout << "Error on instruction " << step<<endl;
        set(7+NUM,72);
        system("pause");
        
        
        return 0;
      }
     
      pop_in(OUT, block);
      block = -500;
      count++;
      system("cls");
print2(space_num,IN,OUT,IN,block,input,step,NUM,19);
sleep(1);

for(int i=18;i>=0;i=i-2){
        system("cls");
      print2(space_num,IN,OUT,IN,block,input,step,NUM,i);
      usleep(400000);



      }
      sleep(1);


    } 
    
    
    else {
      set(6+NUM,72);
      cout << "Error on instruction " << step<<endl;
      set(7+NUM,72);
      system("pause");
      return 0;
    }
   system("cls");
  
  if(step<NUM){//执行完一条指令但还没到底（在后续有jump/jumpifzero指令存在时会出现这种情况）
    
    step++;//进入下一步
    
    goto labeltwo;//继续执行下一条指令，但无需输入


  }
  else{//执行已到底，后续会引导输入新指令
  step++;
  print2(space_num,IN,OUT,IN,block,input,step,NUM,0);
  set(6+NUM,72);  
  cout<<"已执行完现有指令，请输入下一条指令或输入end以结束"<<endl;

  
  

    NUM++;//指令数加一
    set(25,1);//定位
  goto labelthree;
  }
  
  


  }
  return 0;
}





int stage2() {
  int choice;
  string AAA;
  int IN[100] = {3, 9,5,1,-2,-2,9,-9};
  int OUT[100] = {-500, -500,-500,-500,-500,-500,-500,-500}; // -500  ʾ  λ  Ϊ  
  for (int i = 8; i < 100; i++) {
    IN[i] = -500;
    OUT[i] = -500;
  }
  int goal[100] = {-18,18,0,0,-4,4,6,-6};






  for (int i = 8; i < 100; i++) {
    goal[i] = -500;
  }

  int block = -500; //   ǰ  ľ
  int space_num=3;
  int SPACE[3]={-500,-500,-500};
  labelone:
  system("cls");
  print02(space_num,IN,OUT,SPACE,block);
  set(13,71);
  cin>>choice;
  if(cin.fail()||(choice!=0&&choice!=1&&choice!=2)){
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    set(14,71);
    cout<<"无效输入，请输入0或1或2"<<endl;
    set(15,71);
    system("pause");
    goto labelone;


  }
  else if(choice==0){
    system("cls");
    help();
    goto labelone;
  }
  else if(choice==1){
    int jump_num=0;
    int count=0;
  system("cls");
  print12(space_num,IN,OUT,SPACE,block);
  int NUM; // ָ    
  cin >> NUM;
  string input[NUM + 1];
  for (int i = 0; i <= NUM; i++) {
    getline(cin, input[i]);
  }
  instruction order[NUM + 1];
  for (int i = 1; i <= NUM; i++) //   ָ     Ͳ      ֿ 
  {
    order[i].instruction_name.clear();
    order[i].operand.clear();
    int n = 0;
    while (n < input[i].length() && (input[i][n] != ' ')) {
      order[i].instruction_name.push_back(input[i][n]);
      n++;
    }
    n++;
    while (n < input[i].length()) {
      order[i].operand.push_back(input[i][n]);
      n++;
    }
    order[i].OPERAND = 0;
    for (int j = 0; j < order[i].operand.length(); j++) {
      if (order[i].operand[j] < '0' || order[i].operand[j] > '9') {
        order[i].OPERAND = -1;
        break;
      }
      int m = order[i].operand[j] - '0';
      for (int p = 0; p < order[i].operand.length() - j - 1; p++) {
        m = m * 10;
      }
      order[i].OPERAND += m;
    }
  }
  
  
  int step = 1;
  system("cls");
print2(space_num,IN,OUT,SPACE,block,input,step,NUM,0);
sleep(1);
  while (step <= NUM) {
    if(jump_num>=200){break;}
    if (order[step].instruction_name == "inbox" && input[step].length() == 5) {
      for(int i=-1;i>=-19;i=i-2){
      system("cls");
      print2(space_num,IN,OUT,SPACE,block,input,step,NUM,i);
      usleep(400000);
    



    }
    sleep(1);
      
      
      if (IN[0] == -500) { //    봫 ʹ   û з   
        if (compare(goal, OUT) == 1) {
          set(6+NUM,72);
          cout << "Success" << endl;
          set(7+NUM,72);
          cout<<"本次游戏完整执行的指令数为："<<count<<endl;
          set(8+NUM,72);
          system("pause");
          return 1;
        } else {
          set(6+NUM,72);
          cout << "Fail" << endl;
          set(7+NUM,72);
          cout<<"本次游戏完整执行的指令数为："<<count<<endl;
          set(8+NUM,72);
          system("pause");
          return 0;
        }
        
        
      }

      
      block = IN[0];
      pop_out(IN);
      count++;

      system("cls");
      print2(space_num,IN,OUT,SPACE,block,input,step,NUM,-19);
      sleep(1);
      for(int i=-18;i<=0;i=i+2){
        system("cls");
      print2(space_num,IN,OUT,SPACE,block,input,step,NUM,i);
      usleep(400000);



      }
      sleep(1);
    }

    else if (order[step].instruction_name == "outbox" &&
             input[step].length() == 6) {
              for(int i=1;i<=19;i=i+2){
      system("cls");
      print2(space_num,IN,OUT,SPACE,block,input,step,NUM,i);
      usleep(400000);
    



    }
    sleep(1);




      if (block == -500) { // û е ǰ  ľ
      set(6+NUM,72);
        cout << "Error on instruction " << step<<endl;
        set(7+NUM,72);
        system("pause");
        return 0;
      }
      
      pop_in(OUT, block);
      block = -500;
      count++;

      system("cls");
print2(space_num,IN,OUT,SPACE,block,input,step,NUM,19);
sleep(1);

for(int i=18;i>=0;i=i-2){
        system("cls");
      print2(space_num,IN,OUT,SPACE,block,input,step,NUM,i);
      usleep(400000);



      }
      sleep(1);
    } 

    else if(order[step].instruction_name == "jump"){
      if(order[step].OPERAND<1||order[step].OPERAND>NUM)
      {set(6+NUM,72);
        cout<< "Error on instruction " << step<<endl;
      set(7+NUM,72);
      system("pause");
      return 0;}
      step=order[step].OPERAND;
      count++;
      jump_num++;
      system("cls");
      print2(space_num,IN,OUT,SPACE,block,input,step,NUM,0);
      sleep(1);
      continue;





    }

    else if(order[step].instruction_name=="jumpifzero"){
    if(order[step].OPERAND<1||order[step].OPERAND>NUM||block==-500)
      {set(6+NUM,72);
        cout<< "Error on instruction " << step<<endl;
      set(7+NUM,72);
      system("pause");
      
      return 0;}  
    count++;
    if(block==0){
      step=order[step].OPERAND;
      jump_num++;
      system("cls");
      print2(space_num,IN,OUT,SPACE,block,input,step,NUM,0);
      sleep(1);
      continue;



    }





    }


    else if(order[step].instruction_name=="add"){
      if(block==-500||order[step].OPERAND<0||order[step].OPERAND>=space_num||SPACE[order[step].OPERAND]==-500)
      {set(6+NUM,72);
        cout<< "Error on instruction " << step<<endl;
        set(7+NUM,72);
        system("pause");
      
      
      return 0;}
      block=block+SPACE[order[step].OPERAND];
      count++;
      system("cls");
      print2(space_num,IN,OUT,SPACE,block,input,step,NUM,0);
      sleep(2);



    }


    else if(order[step].instruction_name=="sub"){
      if(block==-500||order[step].OPERAND<0||order[step].OPERAND>=space_num||SPACE[order[step].OPERAND]==-500)
      {set(6+NUM,72);
        cout<< "Error on instruction " << step<<endl;
      set(7+NUM,72);
      system("pause");
      return 0;}
      block=block-SPACE[order[step].OPERAND];
      count++;
      system("cls");
      print2(space_num,IN,OUT,SPACE,block,input,step,NUM,0);
      sleep(2);


    }


    else if(order[step].instruction_name=="copyto"){
      if(block==-500||order[step].OPERAND<0||order[step].OPERAND>=space_num)
      {set(6+NUM,72);
        cout<< "Error on instruction " << step<<endl;
      set(7+NUM,72);
      system("pause");
      return 0;}
      SPACE[order[step].OPERAND]=block;
      count++;
      system("cls");
      print2(space_num,IN,OUT,SPACE,block,input,step,NUM,0);
      sleep(2);



    }

    else if(order[step].instruction_name=="copyfrom"){
      if(order[step].OPERAND<0||order[step].OPERAND>=space_num||SPACE[order[step].OPERAND]==-500)
      {set(6+NUM,72);
        cout<< "Error on instruction " << step<<endl;
      set(7+NUM,72);
      system("pause");
      return 0;}
      block=SPACE[order[step].OPERAND];
      count++;
      system("cls");
      print2(space_num,IN,OUT,SPACE,block,input,step,NUM,0);
      sleep(2);



    }

    
    else {set(6+NUM,72);
      cout << "Error on instruction " << step<<endl;
      set(7+NUM,72);
      system("pause");
      return 0;
    }
    step++;
    system("cls");
print2(space_num,IN,OUT,SPACE,block,input,step,NUM,0);
sleep(1);
  }

  if (compare(goal, OUT) == 1) {
    set(6+NUM,72);
    cout << "Success" << endl;
    set(7+NUM,72);
          cout<<"本次游戏完整执行的指令数为："<<count<<endl;
    set(8+NUM,72);
    system("pause");
    return 1;
  } else {
    set(6+NUM,72);
    cout << "Fail" << endl;
    set(7+NUM,72);
          cout<<"本次游戏完整执行的指令数为："<<count<<endl;
    set(8+NUM,72);
    system("pause");
    return 0;
  }
  

  }
  else{
    system("cls");
  print002(space_num,IN,OUT,SPACE,block);
  int count=0;
  int jump_num=0;
  
  
  int NUM=1; // ָ    
  int step=1;





  string input[100];
  
  instruction order[100];
  
  set(25,1);
  getline(cin,input[NUM]);
  labelthree:



  getline(cin,input[NUM]);
  system("cls");
  print2(space_num,IN,OUT,SPACE,block,input,step,NUM,0);
  if(input[NUM]=="end"){
    
    if (compare(goal, OUT) == 1) {
    set(6+NUM,72);
    cout << "Success" << endl;
    set(7+NUM,72);
          cout<<"本次游戏完整执行的指令数为："<<count<<endl;
    set(8+NUM,72);
    system("pause");
    return 1;
  } else {
    set(6+NUM,72);
    cout << "Fail" << endl;
    set(7+NUM,72);
          cout<<"本次游戏完整执行的指令数为："<<count<<endl;
    set(8+NUM,72);
    system("pause");
    return 0;
  }



  }
    order[NUM].instruction_name.clear();
    order[NUM].operand.clear();
    int n = 0;
    while (n < input[NUM].length() && (input[NUM][n] != ' ')) {
      order[NUM].instruction_name.push_back(input[NUM][n]);
      n++;
    }
    n++;
    while (n < input[NUM].length()) {
      order[NUM].operand.push_back(input[NUM][n]);
      n++;
    }
    order[NUM].OPERAND = 0;
    for (int j = 0; j < order[NUM].operand.length(); j++) {
      if (order[NUM].operand[j] < '0' || order[NUM].operand[j] > '9') {
        order[NUM].OPERAND = -1;
        break;
      }
      int m = order[NUM].operand[j] - '0';
      for (int p = 0; p < order[NUM].operand.length() - j - 1; p++) {
        m = m * 10;
      }
      order[NUM].OPERAND += m;
    }
  labeltwo:

  
system("cls");
print2(space_num,IN,OUT,SPACE,block,input,step,NUM,0);
sleep(1);

if(jump_num>200){
  if (compare(goal, OUT) == 1) {
    set(6+NUM,72);
    cout << "Success" << endl;
    set(7+NUM,72);
          cout<<"本次游戏完整执行的指令数为："<<count<<endl;
    set(8+NUM,72);
    system("pause");
    return 1;
  } else {
    set(6+NUM,72);
    cout << "Fail" << endl;
    set(7+NUM,72);
          cout<<"本次游戏完整执行的指令数为："<<count<<endl;
    set(8+NUM,72);
    system("pause");
    return 0;
  }



}
  

  
    

  

    if (order[step].instruction_name == "inbox" && input[step].length() == 5) {
      for(int i=-1;i>=-19;i=i-2){
      system("cls");
      print2(space_num,IN,OUT,SPACE,block,input,step,NUM,i);
      usleep(400000);
    



    }
    sleep(1);
      
      
      
      
      
      
      if (IN[0] == -500) { //    봫 ʹ   û з   
        
        
        
        
        
        if (compare(goal, OUT) == 1) {
          set(6+NUM,72);
          cout << "Success" << endl;
          set(7+NUM,72);
          cout<<"本次游戏完整执行的指令数为："<<count<<endl;
          set(8+NUM,72);
          system("pause");
          return 1;
        } else {
          set(6+NUM,72);
          cout << "Fail" << endl;
          set(7+NUM,72);
          cout<<"本次游戏完整执行的指令数为："<<count<<endl;
          set(8+NUM,72);
          system("pause");
          return 0;
        }
      


        
      }

      
      block = IN[0];
      pop_out(IN);
      count++;
      system("cls");
      print2(space_num,IN,OUT,SPACE,block,input,step,NUM,-19);
      sleep(1);
      for(int i=-18;i<=0;i=i+2){
        system("cls");
      print2(space_num,IN,OUT,SPACE,block,input,step,NUM,i);
      usleep(400000);



      }
      sleep(1);
    }

    else if (order[step].instruction_name == "outbox" &&
             input[step].length() == 6) {
              for(int i=1;i<=19;i=i+2){
      system("cls");
      print2(space_num,IN,OUT,SPACE,block,input,step,NUM,i);
      usleep(400000);
    



    }
    sleep(1);






      if (block == -500) { // û е ǰ  ľ
      set(6+NUM,72);
        cout << "Error on instruction " << step<<endl;
        set(7+NUM,72);
        system("pause");
        
        
        return 0;
      }
     
      pop_in(OUT, block);
      block = -500;
      count++;
      system("cls");
print2(space_num,IN,OUT,SPACE,block,input,step,NUM,19);
sleep(1);

for(int i=18;i>=0;i=i-2){
        system("cls");
      print2(space_num,IN,OUT,SPACE,block,input,step,NUM,i);
      usleep(400000);



      }
      sleep(1);


    } 
    else if(order[step].instruction_name == "jump"){
      if(order[step].OPERAND<1||order[step].OPERAND>NUM)
      {set(6+NUM,72);
        cout<< "Error on instruction " << step<<endl;
      set(7+NUM,72);
      system("pause");
      return 0;}
      step=order[step].OPERAND;
      count++;
      jump_num++;
      goto labeltwo;





    }

    else if(order[step].instruction_name=="jumpifzero"){
    if(order[step].OPERAND<1||order[step].OPERAND>NUM||block==-500)
      {set(6+NUM,72);
        cout<< "Error on instruction " << step<<endl;
      set(7+NUM,72);
      system("pause");
      
      return 0;}  
    count++;
    if(block==0){
      step=order[step].OPERAND;
      jump_num++;
      goto labeltwo;
      



    }





    }


    else if(order[step].instruction_name=="add"){
      if(block==-500||order[step].OPERAND<0||order[step].OPERAND>=space_num||SPACE[order[step].OPERAND]==-500)
      {set(6+NUM,72);
        cout<< "Error on instruction " << step<<endl;
        set(7+NUM,72);
        system("pause");
      
      
      return 0;}
      block=block+SPACE[order[step].OPERAND];
      count++;
      system("cls");
      print2(space_num,IN,OUT,SPACE,block,input,step,NUM,0);
      sleep(2);



    }


    else if(order[step].instruction_name=="sub"){
      if(block==-500||order[step].OPERAND<0||order[step].OPERAND>=space_num||SPACE[order[step].OPERAND]==-500)
      {set(6+NUM,72);
        cout<< "Error on instruction " << step<<endl;
      set(7+NUM,72);
      system("pause");
      return 0;}
      block=block-SPACE[order[step].OPERAND];
      count++;
      system("cls");
      print2(space_num,IN,OUT,SPACE,block,input,step,NUM,0);
      sleep(2);


    }


    else if(order[step].instruction_name=="copyto"){
      if(block==-500||order[step].OPERAND<0||order[step].OPERAND>=space_num)
      {set(6+NUM,72);
        cout<< "Error on instruction " << step<<endl;
      set(7+NUM,72);
      system("pause");
      return 0;}
      SPACE[order[step].OPERAND]=block;
      count++;
      system("cls");
      print2(space_num,IN,OUT,SPACE,block,input,step,NUM,0);
      sleep(2);



    }

    else if(order[step].instruction_name=="copyfrom"){
      if(order[step].OPERAND<0||order[step].OPERAND>=space_num||SPACE[order[step].OPERAND]==-500)
      {set(6+NUM,72);
        cout<< "Error on instruction " << step<<endl;
      set(7+NUM,72);
      system("pause");
      return 0;}
      block=SPACE[order[step].OPERAND];
      count++;
      system("cls");
      print2(space_num,IN,OUT,SPACE,block,input,step,NUM,0);
      sleep(2);



    }
    
    else {
      set(6+NUM,72);
      cout << "Error on instruction " << step<<endl;
      set(7+NUM,72);
      system("pause");
      return 0;
    }
   system("cls");
  
  if(step<NUM){
    
    step++;
    
    goto labeltwo;


  }
  else{
  step++;
  print2(space_num,IN,OUT,SPACE,block,input,step,NUM,0);
  set(6+NUM,72);  
  cout<<"已执行完现有指令，请输入下一条指令或输入end以结束"<<endl;

  
  

    NUM++;
    set(25,1);
  goto labelthree;
  }
  





  }

return 0;
}



/*int stage3() {
  
  string AAA;
  int IN[100] = {6,2,7,7,-9,3,-3,-3};
  int OUT[100] = {-500, -500,-500,-500,-500,-500,-500,-500}; // -500  ʾ  λ  Ϊ  
  for (int i = 8; i < 100; i++) {
    IN[i] = -500;
    OUT[i] = -500;
  }
  int goal[100] = {-3,7};






  for (int i = 2; i < 100; i++) {
    goal[i] = -500;
  }

  int block = -500; //   ǰ  ľ
  int space_num=3;
  int SPACE[4]={-500,-500,-500,-500};
  system("cls");
  print13(space_num,IN,OUT,SPACE,block);
  
  
  
  
  
  int NUM; // ָ    
  cin >> NUM;
  string input[NUM + 1];
  for (int i = 0; i <= NUM; i++) {
    getline(cin, input[i]);
  }
  instruction order[NUM + 1];
  for (int i = 1; i <= NUM; i++) //   ָ     Ͳ      ֿ 
  {
    order[i].instruction_name.clear();
    order[i].operand.clear();
    int n = 0;
    while (n < input[i].length() && (input[i][n] != ' ')) {
      order[i].instruction_name.push_back(input[i][n]);
      n++;
    }
    n++;
    while (n < input[i].length()) {
      order[i].operand.push_back(input[i][n]);
      n++;
    }
    order[i].OPERAND = 0;
    for (int j = 0; j < order[i].operand.length(); j++) {
      if (order[i].operand[j] < '0' || order[i].operand[j] > '9') {
        order[i].OPERAND = -1;
        break;
      }
      int m = order[i].operand[j] - '0';
      for (int p = 0; p < order[i].operand.length() - j - 1; p++) {
        m = m * 10;
      }
      order[i].OPERAND += m;
    }
  }
  
  
  int step = 1;
  system("cls");
print2(space_num,IN,OUT,SPACE,block,input,step,NUM,0);
sleep(1);
  while (step <= NUM) {
    if (order[step].instruction_name == "inbox" && input[step].length() == 5) {
      for(int i=-1;i>=-19;i=i-2){
      system("cls");
      print2(space_num,IN,OUT,SPACE,block,input,step,NUM,i);
      usleep(400000);
    



    }
    sleep(1);
      
      
      
      
      if (IN[0] == -500) { //    봫 ʹ   û з   
        if (compare(goal, OUT) == 1) {
          cout << "Success" << endl;
          return 1;
        } else {
          cout << "Fail" << endl;
          return 0;
        }
        
      }

     
      block = IN[0];
      pop_out(IN);

      system("cls");
      print2(space_num,IN,OUT,SPACE,block,input,step,NUM,-19);
      sleep(1);
      for(int i=-18;i<=0;i=i+2){
        system("cls");
      print2(space_num,IN,OUT,SPACE,block,input,step,NUM,i);
      usleep(400000);



      }
      sleep(1);
    }

    else if (order[step].instruction_name == "outbox" &&
             input[step].length() == 6) {
              for(int i=1;i<=19;i=i+2){
      system("cls");
      print2(space_num,IN,OUT,SPACE,block,input,step,NUM,i);
      usleep(400000);
    



    }
    sleep(1);




      if (block == -500) { // û е ǰ  ľ
        cout << "Error on instruction " << step<<endl;
        
        return 0;
      }
      
      pop_in(OUT, block);
      block = -500;
      system("cls");
print2(space_num,IN,OUT,SPACE,block,input,step,NUM,19);
sleep(1);

for(int i=18;i>=0;i=i-2){
        system("cls");
      print2(space_num,IN,OUT,SPACE,block,input,step,NUM,i);
      usleep(400000);



      }
      sleep(1);
    } 

    else if(order[step].instruction_name == "jump"){
      if(order[step].OPERAND<1||order[step].OPERAND>NUM)
      {cout<< "Error on instruction " << step<<endl;
      
      return 0;}
      step=order[step].OPERAND;
      system("cls");
      print2(space_num,IN,OUT,SPACE,block,input,step,NUM,0);
      sleep(1);
      continue;





    }

    else if(order[step].instruction_name=="jumpifzero"){
    if(order[step].OPERAND<1||order[step].OPERAND>NUM||block==-500)
      {cout<< "Error on instruction " << step<<endl;
      
      return 0;}  
    
    if(block==0){
      step=order[step].OPERAND;
      system("cls");
      print2(space_num,IN,OUT,SPACE,block,input,step,NUM,0);
      sleep(1);
      continue;



    }





    }


    else if(order[step].instruction_name=="add"){
      if(block==-500||order[step].OPERAND<0||order[step].OPERAND>=space_num||SPACE[order[step].OPERAND]==-500)
      {cout<< "Error on instruction " << step<<endl;
      
      return 0;}
      block=block+SPACE[order[step].OPERAND];
      system("cls");
      print2(space_num,IN,OUT,SPACE,block,input,step,NUM,0);
      sleep(1);



    }


    else if(order[step].instruction_name=="sub"){
      if(block==-500||order[step].OPERAND<0||order[step].OPERAND>=space_num||SPACE[order[step].OPERAND]==-500)
      {cout<< "Error on instruction " << step<<endl;
      
      return 0;}
      block=block-SPACE[order[step].OPERAND];
      system("cls");
      print2(space_num,IN,OUT,SPACE,block,input,step,NUM,0);
      sleep(1);


    }


    else if(order[step].instruction_name=="copyto"){
      if(block==-500||order[step].OPERAND<0||order[step].OPERAND>=space_num)
      {cout<< "Error on instruction " << step<<endl;
      
      return 0;}
      SPACE[order[step].OPERAND]=block;
      system("cls");
      print2(space_num,IN,OUT,SPACE,block,input,step,NUM,0);
      sleep(1);



    }

    else if(order[step].instruction_name=="copyfrom"){
      if(order[step].OPERAND<0||order[step].OPERAND>=space_num||SPACE[order[step].OPERAND]==-500)
      {cout<< "Error on instruction " << step<<endl;
      
      return 0;}
      block=SPACE[order[step].OPERAND];
      system("cls");
      print2(space_num,IN,OUT,SPACE,block,input,step,NUM,0);
      sleep(1);



    }

    
    else {
      cout << "Error on instruction " << step<<endl;
      return 0;
    }
    step++;
    system("cls");
print2(space_num,IN,OUT,SPACE,block,input,step,NUM,0);
sleep(1);
  }

  if (compare(goal, OUT) == 1) {
    cout << "Success" << endl;
    return 1;
  } else {
    cout << "Fail" << endl;
    return 0;

  }
  




}*/


int stage3() {
  int choice;
  string AAA;
  int IN[100] = {6,2,7,7,-9,3,-3,-3};
  int OUT[100] = {-500, -500,-500,-500,-500,-500,-500,-500}; // -500  ʾ  λ  Ϊ  
  for (int i = 8; i < 100; i++) {
    IN[i] = -500;
    OUT[i] = -500;
  }
  int goal[100] = {-3,7};






  for (int i = 2; i < 100; i++) {
    goal[i] = -500;
  }

  int block = -500; //   ǰ  ľ
  int space_num=3;
  int SPACE[3]={-500,-500,-500};
  labelone:
  system("cls");
  print03(space_num,IN,OUT,SPACE,block);
  set(13,71);
  cin>>choice;
  if(cin.fail()||(choice!=0&&choice!=1&&choice!=2)){
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    set(14,71);
    cout<<"无效输入，请输入0或1或2"<<endl;
    set(15,71);
    system("pause");
    goto labelone;


  }
  else if(choice==0){
    system("cls");
    help();
    goto labelone;
  }
  else if(choice==1){
    int count=0;
    int jump_num=0;
  system("cls");
  print13(space_num,IN,OUT,SPACE,block);
  int NUM; // ָ    
  cin >> NUM;
  string input[NUM + 1];
  for (int i = 0; i <= NUM; i++) {
    getline(cin, input[i]);
  }
  instruction order[NUM + 1];
  for (int i = 1; i <= NUM; i++) //   ָ     Ͳ      ֿ 
  {
    order[i].instruction_name.clear();
    order[i].operand.clear();
    int n = 0;
    while (n < input[i].length() && (input[i][n] != ' ')) {
      order[i].instruction_name.push_back(input[i][n]);
      n++;
    }
    n++;
    while (n < input[i].length()) {
      order[i].operand.push_back(input[i][n]);
      n++;
    }
    order[i].OPERAND = 0;
    for (int j = 0; j < order[i].operand.length(); j++) {
      if (order[i].operand[j] < '0' || order[i].operand[j] > '9') {
        order[i].OPERAND = -1;
        break;
      }
      int m = order[i].operand[j] - '0';
      for (int p = 0; p < order[i].operand.length() - j - 1; p++) {
        m = m * 10;
      }
      order[i].OPERAND += m;
    }
  }
  
  
  int step = 1;
  system("cls");
print2(space_num,IN,OUT,SPACE,block,input,step,NUM,0);
sleep(1);
  while (step <= NUM) {
    if(jump_num>200){break;}
    if (order[step].instruction_name == "inbox" && input[step].length() == 5) {
      for(int i=-1;i>=-19;i=i-2){
      system("cls");
      print2(space_num,IN,OUT,SPACE,block,input,step,NUM,i);
      usleep(400000);
    



    }
    sleep(1);
      
      
      if (IN[0] == -500) { //    봫 ʹ   û з   
        if (compare(goal, OUT) == 1) {
          set(6+NUM,72);
          cout << "Success" << endl;
          set(7+NUM,72);
          cout<<"本次游戏完整执行的指令数为："<<count<<endl;
          set(8+NUM,72);
          system("pause");
          return 1;
        } else {
          set(6+NUM,72);
          cout << "Fail" << endl;
          set(7+NUM,72);
          cout<<"本次游戏完整执行的指令数为："<<count<<endl;
          set(8+NUM,72);
          system("pause");
          return 0;
        }
        
        
      }

      
      block = IN[0];
      pop_out(IN);
      count++;

      system("cls");
      print2(space_num,IN,OUT,SPACE,block,input,step,NUM,-19);
      sleep(1);
      for(int i=-18;i<=0;i=i+2){
        system("cls");
      print2(space_num,IN,OUT,SPACE,block,input,step,NUM,i);
      usleep(400000);



      }
      sleep(1);
    }

    else if (order[step].instruction_name == "outbox" &&
             input[step].length() == 6) {
              for(int i=1;i<=19;i=i+2){
      system("cls");
      print2(space_num,IN,OUT,SPACE,block,input,step,NUM,i);
      usleep(400000);
    



    }
    sleep(1);




      if (block == -500) { // û е ǰ  ľ
      set(6+NUM,72);
        cout << "Error on instruction " << step<<endl;
        set(7+NUM,72);
        system("pause");
        return 0;
      }
      
      pop_in(OUT, block);
      block = -500;
      count++;

      system("cls");
print2(space_num,IN,OUT,SPACE,block,input,step,NUM,19);
sleep(1);

for(int i=18;i>=0;i=i-2){
        system("cls");
      print2(space_num,IN,OUT,SPACE,block,input,step,NUM,i);
      usleep(400000);



      }
      sleep(1);
    } 

    else if(order[step].instruction_name == "jump"){
      if(order[step].OPERAND<1||order[step].OPERAND>NUM)
      {set(6+NUM,72);
        cout<< "Error on instruction " << step<<endl;
      set(7+NUM,72);
      system("pause");
      return 0;}
      step=order[step].OPERAND;
      count++;
      jump_num++;
      system("cls");
      print2(space_num,IN,OUT,SPACE,block,input,step,NUM,0);
      sleep(1);
      continue;





    }

    else if(order[step].instruction_name=="jumpifzero"){
    if(order[step].OPERAND<1||order[step].OPERAND>NUM||block==-500)
      {set(6+NUM,72);
        cout<< "Error on instruction " << step<<endl;
      set(7+NUM,72);
      system("pause");
      
      return 0;}  
    count++;
    if(block==0){
      step=order[step].OPERAND;
      jump_num++;
      system("cls");
      print2(space_num,IN,OUT,SPACE,block,input,step,NUM,0);
      sleep(1);
      continue;



    }





    }


    else if(order[step].instruction_name=="add"){
      if(block==-500||order[step].OPERAND<0||order[step].OPERAND>=space_num||SPACE[order[step].OPERAND]==-500)
      {set(6+NUM,72);
        cout<< "Error on instruction " << step<<endl;
        set(7+NUM,72);
        system("pause");
      
      
      return 0;}
      block=block+SPACE[order[step].OPERAND];
      count++;
      system("cls");
      print2(space_num,IN,OUT,SPACE,block,input,step,NUM,0);
      sleep(2);



    }


    else if(order[step].instruction_name=="sub"){
      if(block==-500||order[step].OPERAND<0||order[step].OPERAND>=space_num||SPACE[order[step].OPERAND]==-500)
      {set(6+NUM,72);
        cout<< "Error on instruction " << step<<endl;
      set(7+NUM,72);
      system("pause");
      return 0;}
      block=block-SPACE[order[step].OPERAND];
      count++;
      system("cls");
      print2(space_num,IN,OUT,SPACE,block,input,step,NUM,0);
      sleep(2);


    }


    else if(order[step].instruction_name=="copyto"){
      if(block==-500||order[step].OPERAND<0||order[step].OPERAND>=space_num)
      {set(6+NUM,72);
        cout<< "Error on instruction " << step<<endl;
      set(7+NUM,72);
      system("pause");
      return 0;}
      SPACE[order[step].OPERAND]=block;
      count++;
      system("cls");
      print2(space_num,IN,OUT,SPACE,block,input,step,NUM,0);
      sleep(2);



    }

    else if(order[step].instruction_name=="copyfrom"){
      if(order[step].OPERAND<0||order[step].OPERAND>=space_num||SPACE[order[step].OPERAND]==-500)
      {set(6+NUM,72);
        cout<< "Error on instruction " << step<<endl;
      set(7+NUM,72);
      system("pause");
      return 0;}
      block=SPACE[order[step].OPERAND];
      count++;
      system("cls");
      print2(space_num,IN,OUT,SPACE,block,input,step,NUM,0);
      sleep(2);



    }

    
    else {set(6+NUM,72);
      cout << "Error on instruction " << step<<endl;
      set(7+NUM,72);
      system("pause");
      return 0;
    }
    step++;
    system("cls");
print2(space_num,IN,OUT,SPACE,block,input,step,NUM,0);
sleep(1);
  }

  if (compare(goal, OUT) == 1) {
    set(6+NUM,72);
    cout << "Success" << endl;
    set(7+NUM,72);
          cout<<"本次游戏完整执行的指令数为："<<count<<endl;
    set(8+NUM,72);
    system("pause");
    return 1;
  } else {
    set(6+NUM,72);
    cout << "Fail" << endl;
    set(7+NUM,72);
          cout<<"本次游戏完整执行的指令数为："<<count<<endl;
    set(8+NUM,72);
    system("pause");
    return 0;
  }
  

  }
  else{
    int count=0;
    int jump_num=0;
    system("cls");
  print003(space_num,IN,OUT,SPACE,block);
  
  
  
  
  int NUM=1; // ָ    
  int step=1;





  string input[100];
  
  instruction order[100];
  
  set(25,1);
  getline(cin,input[NUM]);
  labelthree:



  getline(cin,input[NUM]);
  system("cls");
  print2(space_num,IN,OUT,SPACE,block,input,step,NUM,0);
  if(input[NUM]=="end"){
    if (compare(goal, OUT) == 1) {
    set(6+NUM,72);
    cout << "Success" << endl;
    set(7+NUM,72);
          cout<<"本次游戏完整执行的指令数为："<<count<<endl;
    set(8+NUM,72);
    system("pause");
    return 1;
  } else {
    set(6+NUM,72);
    cout << "Fail" << endl;
    set(7+NUM,72);
          cout<<"本次游戏完整执行的指令数为："<<count<<endl;
    set(8+NUM,72);
    system("pause");
    return 0;
  }



  }
    order[NUM].instruction_name.clear();
    order[NUM].operand.clear();
    int n = 0;
    while (n < input[NUM].length() && (input[NUM][n] != ' ')) {
      order[NUM].instruction_name.push_back(input[NUM][n]);
      n++;
    }
    n++;
    while (n < input[NUM].length()) {
      order[NUM].operand.push_back(input[NUM][n]);
      n++;
    }
    order[NUM].OPERAND = 0;
    for (int j = 0; j < order[NUM].operand.length(); j++) {
      if (order[NUM].operand[j] < '0' || order[NUM].operand[j] > '9') {
        order[NUM].OPERAND = -1;
        break;
      }
      int m = order[NUM].operand[j] - '0';
      for (int p = 0; p < order[NUM].operand.length() - j - 1; p++) {
        m = m * 10;
      }
      order[NUM].OPERAND += m;
    }
  labeltwo:
  if(jump_num>200){
    if (compare(goal, OUT) == 1) {
    set(6+NUM,72);
    cout << "Success" << endl;
    set(7+NUM,72);
          cout<<"本次游戏完整执行的指令数为："<<count<<endl;
    set(8+NUM,72);
    system("pause");
    return 1;
  } else {
    set(6+NUM,72);
    cout << "Fail" << endl;
    set(7+NUM,72);
          cout<<"本次游戏完整执行的指令数为："<<count<<endl;
    set(8+NUM,72);
    system("pause");
    return 0;
  }



  }
  
  
system("cls");
print2(space_num,IN,OUT,SPACE,block,input,step,NUM,0);
sleep(1);
  
    

  

    if (order[step].instruction_name == "inbox" && input[step].length() == 5) {
      for(int i=-1;i>=-19;i=i-2){
      system("cls");
      print2(space_num,IN,OUT,SPACE,block,input,step,NUM,i);
      usleep(400000);
    



    }
    sleep(1);
      
      
      
      
      
      
      if (IN[0] == -500) { //    봫 ʹ   û з   
        
        
        
        
        
        if (compare(goal, OUT) == 1) {
          set(6+NUM,72);
          cout << "Success" << endl;
          set(7+NUM,72);
          cout<<"本次游戏完整执行的指令数为："<<count<<endl;
          set(8+NUM,72);
          system("pause");
          return 1;
        } else {
          set(6+NUM,72);
          cout << "Fail" << endl;
          set(7+NUM,72);
          cout<<"本次游戏完整执行的指令数为："<<count<<endl;
          set(8+NUM,72);
          system("pause");
          return 0;
        }
      


        
      }

      
      block = IN[0];
      pop_out(IN);
      count++;
      system("cls");
      print2(space_num,IN,OUT,SPACE,block,input,step,NUM,-19);
      sleep(1);
      for(int i=-18;i<=0;i=i+2){
        system("cls");
      print2(space_num,IN,OUT,SPACE,block,input,step,NUM,i);
      usleep(400000);



      }
      sleep(1);
    }

    else if (order[step].instruction_name == "outbox" &&
             input[step].length() == 6) {
              for(int i=1;i<=19;i=i+2){
      system("cls");
      print2(space_num,IN,OUT,SPACE,block,input,step,NUM,i);
      usleep(400000);
    



    }
    sleep(1);






      if (block == -500) { // û е ǰ  ľ
      set(6+NUM,72);
        cout << "Error on instruction " << step<<endl;
        set(7+NUM,72);
        system("pause");
        
        
        return 0;
      }
     
      pop_in(OUT, block);
      block = -500;
      count++;
      system("cls");
print2(space_num,IN,OUT,SPACE,block,input,step,NUM,19);
sleep(1);

for(int i=18;i>=0;i=i-2){
        system("cls");
      print2(space_num,IN,OUT,SPACE,block,input,step,NUM,i);
      usleep(400000);



      }
      sleep(1);


    } 
    else if(order[step].instruction_name == "jump"){
      if(order[step].OPERAND<1||order[step].OPERAND>NUM)
      {set(6+NUM,72);
        cout<< "Error on instruction " << step<<endl;
      set(7+NUM,72);
      system("pause");
      return 0;}
      count++;
      jump_num++;
      step=order[step].OPERAND;
      goto labeltwo;





    }

    else if(order[step].instruction_name=="jumpifzero"){
    if(order[step].OPERAND<1||order[step].OPERAND>NUM||block==-500)
      {set(6+NUM,72);
        cout<< "Error on instruction " << step<<endl;
      set(7+NUM,72);
      system("pause");
      
      return 0;}  
    count++;
    if(block==0){
      step=order[step].OPERAND;
      jump_num++;
      goto labeltwo;
      



    }





    }


    else if(order[step].instruction_name=="add"){
      if(block==-500||order[step].OPERAND<0||order[step].OPERAND>=space_num||SPACE[order[step].OPERAND]==-500)
      {set(6+NUM,72);
        cout<< "Error on instruction " << step<<endl;
        set(7+NUM,72);
        system("pause");
      
      
      return 0;}
      block=block+SPACE[order[step].OPERAND];
      count++;
      system("cls");
      print2(space_num,IN,OUT,SPACE,block,input,step,NUM,0);
      sleep(2);



    }


    else if(order[step].instruction_name=="sub"){
      if(block==-500||order[step].OPERAND<0||order[step].OPERAND>=space_num||SPACE[order[step].OPERAND]==-500)
      {set(6+NUM,72);
        cout<< "Error on instruction " << step<<endl;
      set(7+NUM,72);
      system("pause");
      return 0;}
      block=block-SPACE[order[step].OPERAND];
      count++;
      system("cls");
      print2(space_num,IN,OUT,SPACE,block,input,step,NUM,0);
      sleep(2);


    }


    else if(order[step].instruction_name=="copyto"){
      if(block==-500||order[step].OPERAND<0||order[step].OPERAND>=space_num)
      {set(6+NUM,72);
        cout<< "Error on instruction " << step<<endl;
      set(7+NUM,72);
      system("pause");
      return 0;}
      SPACE[order[step].OPERAND]=block;
      count++;
      system("cls");
      print2(space_num,IN,OUT,SPACE,block,input,step,NUM,0);
      sleep(2);



    }

    else if(order[step].instruction_name=="copyfrom"){
      if(order[step].OPERAND<0||order[step].OPERAND>=space_num||SPACE[order[step].OPERAND]==-500)
      {set(6+NUM,72);
        cout<< "Error on instruction " << step<<endl;
      set(7+NUM,72);
      system("pause");
      return 0;}
      block=SPACE[order[step].OPERAND];
      count++;
      system("cls");
      print2(space_num,IN,OUT,SPACE,block,input,step,NUM,0);
      sleep(2);



    }
    
    else {
      set(6+NUM,72);
      cout << "Error on instruction " << step<<endl;
      set(7+NUM,72);
      system("pause");
      return 0;
    }
   system("cls");
  
  if(step<NUM){
    
    step++;
    
    goto labeltwo;


  }
  else{
  step++;
  print2(space_num,IN,OUT,SPACE,block,input,step,NUM,0);
  set(6+NUM,72);  
  cout<<"已执行完现有指令，请输入下一条指令或输入end以结束"<<endl;

  
  

    NUM++;
    set(25,1);
  goto labelthree;
  }
  





  }

return 0;
}

int stage4() {
  int choice;
  string AAA;
  int IN[100] = {3, 7,0,1,-2,-9,4,-5};
  int OUT[100] = {-500, -500,-500,-500,-500,-500,-500,-500}; // -500  ʾ  λ  Ϊ  
  for (int i = 8; i < 100; i++) {
    IN[i] = -500;
    OUT[i] = -500;
  }
  int goal[100] = {-50,40,-90,-20,10,0,70,30};






  for (int i = 8; i < 100; i++) {
    goal[i] = -500;
  }

  int block = -500; //   ǰ  ľ
  int space_num=3;
  int SPACE[3]={-500,-500,-500};
  labelone:
  system("cls");
  print04(space_num,IN,OUT,SPACE,block);
  set(13,71);
  cin>>choice;
  if(cin.fail()||(choice!=0&&choice!=1&&choice!=2)){
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    set(14,71);
    cout<<"无效输入，请输入0或1或2"<<endl;
    set(15,71);
    system("pause");
    goto labelone;


  }
  else if(choice==0){
    
    system("cls");
    help();
    goto labelone;
  }
  else if(choice==1){
    int count=0;
    int jump_num=1;
  system("cls");
  print14(space_num,IN,OUT,SPACE,block);
  int NUM; // ָ    
  cin >> NUM;
  string input[NUM + 1];
  for (int i = 0; i <= NUM; i++) {
    getline(cin, input[i]);
  }
  instruction order[NUM + 1];
  for (int i = 1; i <= NUM; i++) //   ָ     Ͳ      ֿ 
  {
    order[i].instruction_name.clear();
    order[i].operand.clear();
    int n = 0;
    while (n < input[i].length() && (input[i][n] != ' ')) {
      order[i].instruction_name.push_back(input[i][n]);
      n++;
    }
    n++;
    while (n < input[i].length()) {
      order[i].operand.push_back(input[i][n]);
      n++;
    }
    order[i].OPERAND = 0;
    for (int j = 0; j < order[i].operand.length(); j++) {
      if (order[i].operand[j] < '0' || order[i].operand[j] > '9') {
        order[i].OPERAND = -1;
        break;
      }
      int m = order[i].operand[j] - '0';
      for (int p = 0; p < order[i].operand.length() - j - 1; p++) {
        m = m * 10;
      }
      order[i].OPERAND += m;
    }
  }
  
  
  int step = 1;
  system("cls");
print2(space_num,IN,OUT,SPACE,block,input,step,NUM,0);
sleep(1);
  while (step <= NUM) {
    if (order[step].instruction_name == "inbox" && input[step].length() == 5) {
      for(int i=-1;i>=-19;i=i-2){
      system("cls");
      print2(space_num,IN,OUT,SPACE,block,input,step,NUM,i);
      usleep(400000);
    



    }
    sleep(1);
      
      
      if (IN[0] == -500) { //    봫 ʹ   û з   
        if (compare(goal, OUT) == 1) {
          set(6+NUM,72);
          cout << "Success" << endl;
          set(7+NUM,72);
          cout<<"本次游戏完整执行的指令数为："<<count<<endl;
          set(8+NUM,72);
          system("pause");
          return 1;
        } else {
          set(6+NUM,72);
          cout << "Fail" << endl;
          set(7+NUM,72);
          cout<<"本次游戏完整执行的指令数为："<<count<<endl;
          set(8+NUM,72);
          system("pause");
          return 0;
        }
        
        
      }

      
      block = IN[0];
      pop_out(IN);
      count++;

      system("cls");
      print2(space_num,IN,OUT,SPACE,block,input,step,NUM,-19);
      sleep(1);
      for(int i=-18;i<=0;i=i+2){
        system("cls");
      print2(space_num,IN,OUT,SPACE,block,input,step,NUM,i);
      usleep(400000);



      }
      sleep(1);
    }

    else if (order[step].instruction_name == "outbox" &&
             input[step].length() == 6) {
              for(int i=1;i<=19;i=i+2){
      system("cls");
      print2(space_num,IN,OUT,SPACE,block,input,step,NUM,i);
      usleep(400000);
    



    }
    sleep(1);




      if (block == -500) { // û е ǰ  ľ
      set(6+NUM,72);
        cout << "Error on instruction " << step<<endl;
        set(7+NUM,72);
        system("pause");
        return 0;
      }
      
      pop_in(OUT, block);
      block = -500;
      count++;

      system("cls");
print2(space_num,IN,OUT,SPACE,block,input,step,NUM,19);
sleep(1);

for(int i=18;i>=0;i=i-2){
        system("cls");
      print2(space_num,IN,OUT,SPACE,block,input,step,NUM,i);
      usleep(400000);



      }
      sleep(1);
    } 

    else if(order[step].instruction_name == "jump"){
      if(order[step].OPERAND<1||order[step].OPERAND>NUM)
      {set(6+NUM,72);
        cout<< "Error on instruction " << step<<endl;
      set(7+NUM,72);
      system("pause");
      return 0;}
      step=order[step].OPERAND;
      count++;
      jump_num++;
      system("cls");
      print2(space_num,IN,OUT,SPACE,block,input,step,NUM,0);
      sleep(1);
      continue;





    }

    else if(order[step].instruction_name=="jumpifzero"){
    if(order[step].OPERAND<1||order[step].OPERAND>NUM||block==-500)
      {set(6+NUM,72);
        cout<< "Error on instruction " << step<<endl;
      set(7+NUM,72);
      system("pause");
      
      return 0;}  
      count++;
    
    if(block==0){
      step=order[step].OPERAND;
      jump_num++;
      system("cls");
      print2(space_num,IN,OUT,SPACE,block,input,step,NUM,0);
      sleep(1);
      continue;



    }





    }


    else if(order[step].instruction_name=="add"){
      if(block==-500||order[step].OPERAND<0||order[step].OPERAND>=space_num||SPACE[order[step].OPERAND]==-500)
      {set(6+NUM,72);
        cout<< "Error on instruction " << step<<endl;
        set(7+NUM,72);
        system("pause");
      
      
      return 0;}
      block=block+SPACE[order[step].OPERAND];
      count++;
      system("cls");
      print2(space_num,IN,OUT,SPACE,block,input,step,NUM,0);
      sleep(2);



    }


    else if(order[step].instruction_name=="sub"){
      if(block==-500||order[step].OPERAND<0||order[step].OPERAND>=space_num||SPACE[order[step].OPERAND]==-500)
      {set(6+NUM,72);
        cout<< "Error on instruction " << step<<endl;
      set(7+NUM,72);
      system("pause");
      return 0;}
      block=block-SPACE[order[step].OPERAND];
      count++;
      system("cls");
      print2(space_num,IN,OUT,SPACE,block,input,step,NUM,0);
      sleep(2);


    }


    else if(order[step].instruction_name=="copyto"){
      if(block==-500||order[step].OPERAND<0||order[step].OPERAND>=space_num)
      {set(6+NUM,72);
        cout<< "Error on instruction " << step<<endl;
      set(7+NUM,72);
      system("pause");
      return 0;}
      SPACE[order[step].OPERAND]=block;
      count++;
      system("cls");
      print2(space_num,IN,OUT,SPACE,block,input,step,NUM,0);
      sleep(2);



    }

    else if(order[step].instruction_name=="copyfrom"){
      if(order[step].OPERAND<0||order[step].OPERAND>=space_num||SPACE[order[step].OPERAND]==-500)
      {set(6+NUM,72);
        cout<< "Error on instruction " << step<<endl;
      set(7+NUM,72);
      system("pause");
      return 0;}
      block=SPACE[order[step].OPERAND];
      count++;
      system("cls");
      print2(space_num,IN,OUT,SPACE,block,input,step,NUM,0);
      sleep(2);



    }

    
    else {set(6+NUM,72);
      cout << "Error on instruction " << step<<endl;
      set(7+NUM,72);
      system("pause");
      return 0;
    }
    step++;
    system("cls");
print2(space_num,IN,OUT,SPACE,block,input,step,NUM,0);
sleep(1);
  }

  if (compare(goal, OUT) == 1) {
    set(6+NUM,72);
    cout << "Success" << endl;
    set(7+NUM,72);
          cout<<"本次游戏完整执行的指令数为："<<count<<endl;
    set(8+NUM,72);
    system("pause");
    return 1;
  } else {
    set(6+NUM,72);
    cout << "Fail" << endl;
    set(7+NUM,72);
          cout<<"本次游戏完整执行的指令数为："<<count<<endl;
    set(8+NUM,72);
    system("pause");
    return 0;
  }
  

  }
  else{
    int count=0;
    int jump_num=0;
    system("cls");
  print004(space_num,IN,OUT,SPACE,block);
  
  
  
  
  int NUM=1; // ָ    
  int step=1;





  string input[100];
  
  instruction order[100];
  
  set(25,1);
  getline(cin,input[NUM]);
  labelthree:



  getline(cin,input[NUM]);
  system("cls");
  print2(space_num,IN,OUT,SPACE,block,input,step,NUM,0);
  if(input[NUM]=="end"){
    if (compare(goal, OUT) == 1) {
    set(6+NUM,72);
    cout << "Success" << endl;
    set(7+NUM,72);
          cout<<"本次游戏完整执行的指令数为："<<count<<endl;
    set(8+NUM,72);
    system("pause");
    return 1;
  } else {
    set(6+NUM,72);
    cout << "Fail" << endl;
    set(7+NUM,72);
          cout<<"本次游戏完整执行的指令数为："<<count<<endl;
    set(8+NUM,72);
    system("pause");
    return 0;
  }



  }
    order[NUM].instruction_name.clear();
    order[NUM].operand.clear();
    int n = 0;
    while (n < input[NUM].length() && (input[NUM][n] != ' ')) {
      order[NUM].instruction_name.push_back(input[NUM][n]);
      n++;
    }
    n++;
    while (n < input[NUM].length()) {
      order[NUM].operand.push_back(input[NUM][n]);
      n++;
    }
    order[NUM].OPERAND = 0;
    for (int j = 0; j < order[NUM].operand.length(); j++) {
      if (order[NUM].operand[j] < '0' || order[NUM].operand[j] > '9') {
        order[NUM].OPERAND = -1;
        break;
      }
      int m = order[NUM].operand[j] - '0';
      for (int p = 0; p < order[NUM].operand.length() - j - 1; p++) {
        m = m * 10;
      }
      order[NUM].OPERAND += m;
    }
  labeltwo:
  if(jump_num>200){
    if (compare(goal, OUT) == 1) {
    set(6+NUM,72);
    cout << "Success" << endl;
    set(7+NUM,72);
          cout<<"本次游戏完整执行的指令数为："<<count<<endl;
    set(8+NUM,72);
    system("pause");
    return 1;
  } else {
    set(6+NUM,72);
    cout << "Fail" << endl;
    set(7+NUM,72);
          cout<<"本次游戏完整执行的指令数为："<<count<<endl;
    set(8+NUM,72);
    system("pause");
    return 0;
  }


  }
  
  
system("cls");
print2(space_num,IN,OUT,SPACE,block,input,step,NUM,0);
sleep(1);
  
    

  

    if (order[step].instruction_name == "inbox" && input[step].length() == 5) {
      for(int i=-1;i>=-19;i=i-2){
      system("cls");
      print2(space_num,IN,OUT,SPACE,block,input,step,NUM,i);
      usleep(400000);
    



    }
    sleep(1);
      
      
      
      
      
      
      if (IN[0] == -500) { //    봫 ʹ   û з   
        
        
        
        
        
        if (compare(goal, OUT) == 1) {
          set(6+NUM,72);
          cout << "Success" << endl;
          set(7+NUM,72);
          cout<<"本次游戏完整执行的指令数为："<<count<<endl;
          set(8+NUM,72);
          system("pause");
          return 1;
        } else {
          set(6+NUM,72);
          cout << "Fail" << endl;
          set(7+NUM,72);
          cout<<"本次游戏完整执行的指令数为："<<count<<endl;
          set(8+NUM,72);
          system("pause");
          return 0;
        }
      


        
      }

      
      block = IN[0];
      pop_out(IN);
      count++;
      system("cls");
      print2(space_num,IN,OUT,SPACE,block,input,step,NUM,-19);
      sleep(1);
      for(int i=-18;i<=0;i=i+2){
        system("cls");
      print2(space_num,IN,OUT,SPACE,block,input,step,NUM,i);
      usleep(400000);



      }
      sleep(1);
    }

    else if (order[step].instruction_name == "outbox" &&
             input[step].length() == 6) {
              for(int i=1;i<=19;i=i+2){
      system("cls");
      print2(space_num,IN,OUT,SPACE,block,input,step,NUM,i);
      usleep(400000);
    



    }
    sleep(1);






      if (block == -500) { // û е ǰ  ľ
      set(6+NUM,72);
        cout << "Error on instruction " << step<<endl;
        set(7+NUM,72);
        system("pause");
        
        
        return 0;
      }
     
      pop_in(OUT, block);
      block = -500;
      count++;
      system("cls");
print2(space_num,IN,OUT,SPACE,block,input,step,NUM,19);
sleep(1);

for(int i=18;i>=0;i=i-2){
        system("cls");
      print2(space_num,IN,OUT,SPACE,block,input,step,NUM,i);
      usleep(400000);



      }
      sleep(1);


    } 
    else if(order[step].instruction_name == "jump"){
      if(order[step].OPERAND<1||order[step].OPERAND>NUM)
      {set(6+NUM,72);
        cout<< "Error on instruction " << step<<endl;
      set(7+NUM,72);
      system("pause");
      return 0;}
      step=order[step].OPERAND;
      count++;
      jump_num++;
      goto labeltwo;





    }

    else if(order[step].instruction_name=="jumpifzero"){
    if(order[step].OPERAND<1||order[step].OPERAND>NUM||block==-500)
      {set(6+NUM,72);
        cout<< "Error on instruction " << step<<endl;
      set(7+NUM,72);
      system("pause");
      
      return 0;}  
      count++;
    
    if(block==0){
      step=order[step].OPERAND;
      jump_num++;
      goto labeltwo;
      



    }





    }


    else if(order[step].instruction_name=="add"){
      if(block==-500||order[step].OPERAND<0||order[step].OPERAND>=space_num||SPACE[order[step].OPERAND]==-500)
      {set(6+NUM,72);
        cout<< "Error on instruction " << step<<endl;
        set(7+NUM,72);
        system("pause");
      
      
      return 0;}
      block=block+SPACE[order[step].OPERAND];
      count++;
      system("cls");
      print2(space_num,IN,OUT,SPACE,block,input,step,NUM,0);
      sleep(2);



    }


    else if(order[step].instruction_name=="sub"){
      if(block==-500||order[step].OPERAND<0||order[step].OPERAND>=space_num||SPACE[order[step].OPERAND]==-500)
      {set(6+NUM,72);
        cout<< "Error on instruction " << step<<endl;
      set(7+NUM,72);
      system("pause");
      return 0;}
      block=block-SPACE[order[step].OPERAND];
      count++;
      system("cls");
      print2(space_num,IN,OUT,SPACE,block,input,step,NUM,0);
      sleep(2);


    }


    else if(order[step].instruction_name=="copyto"){
      if(block==-500||order[step].OPERAND<0||order[step].OPERAND>=space_num)
      {set(6+NUM,72);
        cout<< "Error on instruction " << step<<endl;
      set(7+NUM,72);
      system("pause");
      return 0;}
      SPACE[order[step].OPERAND]=block;
      count++;
      system("cls");
      print2(space_num,IN,OUT,SPACE,block,input,step,NUM,0);
      sleep(2);



    }

    else if(order[step].instruction_name=="copyfrom"){
      if(order[step].OPERAND<0||order[step].OPERAND>=space_num||SPACE[order[step].OPERAND]==-500)
      {set(6+NUM,72);
        cout<< "Error on instruction " << step<<endl;
      set(7+NUM,72);
      system("pause");
      return 0;}
      block=SPACE[order[step].OPERAND];
      count++;
      system("cls");
      print2(space_num,IN,OUT,SPACE,block,input,step,NUM,0);
      sleep(2);



    }
    
    else {
      set(6+NUM,72);
      cout << "Error on instruction " << step<<endl;
      set(7+NUM,72);
      system("pause");
      return 0;
    }
   system("cls");
  
  if(step<NUM){
    
    step++;
    
    goto labeltwo;


  }
  else{
  step++;
  print2(space_num,IN,OUT,SPACE,block,input,step,NUM,0);
  set(6+NUM,72);  
  cout<<"已执行完现有指令，请输入下一条指令或输入end以结束"<<endl;

  
  

    NUM++;
    set(25,1);
  goto labelthree;
  }
  





  }

return 0;
}
