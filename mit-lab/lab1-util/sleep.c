#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

#define STDIN_FILENO  0
#define STDOUT_FILENO 1
#define STDDER_FILENO 2


/*
C语言 main 函数的参数介绍
argc : main函数参数个数，当参数为void的时，argc=1，默认参数为可执行文件名
argv : 指针数组，分别指向个参数字符串首地址，其中argv[0]指向默认参数
默认情况下，argc 值为 1，表示 argv[0] 当前工程可执行文件的文件名；后面的参数从 arg[1] 开始都按顺序存放在字符数组中，argc 数至少是 1 个；

*/

int main(int argc, char* argv[])
{
    // 参数判断
    if (argc != 2)
    {
        fprintf(STDDER_FILENO, "usage: sleep <number>\n");
        exit(1);
    }
  
    // 转型
    int number = atoi(argv[1]);
    
    //系统调用sleep
    sleep(number);
    exit(0);
}
