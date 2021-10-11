#include <stdio.h>  
#include <stdlib.h>

//#include这行代码是一条C预处理器指令
//#include <stdio.h>的作用相当于把stdio.h文件中的所有内容都输入该行所在的位置

//C程序一定从main()函数开始执行
//int是main()函数的返回类型。这表明main()函数返回的值是整数,返回给操作系统
//所有的C函数都使用花括号标记函数体的开始和结束。这是规定，不能省略。只有花括号{}能起这种作用

int main()
{
    printf("hello word!\n");
    system("pause"); //阻塞程序运行，按下任意键继续
    //system("mspaint");	//打开画图
    //system("calc");		//打开计算器
    return 0;
}
