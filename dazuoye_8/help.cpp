#include <iostream>

// ...<< std::setw()
void help (){
std::cout << "\033[1;32m帮助\033[0m\n" << std::endl << "注：带操作数的指令，格式为指令与操作数（即X）用空格分开，如add 0。操作数（X）均为整数。" << std::endl;

std::cout << std::endl << "\033[1;31m指令名及其解释：\033[0m\n" << std::endl;

std::cout << std::endl << "\033[1;33mInbox\033[0m" << " :" << std::endl;
std::cout << "机器人拿起输入传送带的第一个积木（即成为当前积木）原有当前积木被舍弃。当输入传送带上" << std::endl << "没有积木时，游戏结束。" << std::endl;

std::cout << std::endl << "\033[1;33mOutbox\033[0m" << " :" << std::endl;
std::cout << "将当前积木摆在输出传送带上。（机器人不再拥有当前积木）" << std::endl;

std::cout << std::endl << "\033[1;33madd X\033[0m" << " :" << std::endl;
std::cout << "将当前机器人手中积木的数字加上X 号空地上的积木。X 号空地上的积木保持不变,机器人手中积" << std::endl << "木的数字替换成加完的结果。" << std::endl;

std::cout << std::endl << "\033[1;33msub X\033[0m" << " :" << std::endl;
std::cout << "将当前积木的数字减去 X 号空地上的积木。X 号空地上的积木保持不变，机器人手中积木的数字" << std::endl << "替换成减完的结果。" << std::endl;

std::cout << std::endl << "\033[1;33mcopyto X\033[0m" << " :" << std::endl;
std::cout << "复制当前积木到 X 号空地。若 X 空地上有积木则舍弃原有积木。" << std::endl;

std::cout << std::endl << "\033[1;33mcopyfrom X\033[0m" << " :" << std::endl;
std::cout << "复制 X 号空地上的积木到当前积木,即把机器人手中积木的数字替换成 X 号空地上的积木数字。" << std::endl << "若存在当前积木则舍弃原有当前积木。" << std::endl;

std::cout << std::endl << "\033[1;33mjump X\033[0m" << " :" << std::endl;
std::cout << "改变机器人的程序，将后续执行的指令改为从第 X 条指令开始执行。(这里的第 X 条是指机器人" << std::endl << "程序中的第 X 条。比如假设第一条被执行过 10 次，它依旧是第一条指令)" << std::endl;

std::cout << std::endl << "\033[1;33mjumpifzero X\033[0m" << " :" << std::endl;
std::cout << "如果当前积木为0，则改变机器人的机器人程序，将后续执行的指令改为从第 X 条指令开始执行。" << std::endl << "如果当前积木不为 0，则不做任何操作。\n" << std::endl;


system("pause");
return;
}

/*
copyfrom X  ：
复制 X 号空地上的积木到当前积木,即把机器人手中积木的数字替换成 X 号空地上的积木的数字。若存在当前积木则舍弃原有当前积木。

jump X  ：
改变机器人的机器人程序，将后续执行的指令改为从第 X 条指令开始执行。(这里的第 X 条是指机器人程序中的第 X 条。比如假设第一条被执行过 10 次，它依旧是第一条指令)

jumpifzero X  ：
如果当前积木为 0，则改变机器人的机器人程序，将后续执行的指令改为从第 X 条指令开始执行。如果当前积木不为 0，则不做任何操作。
*/