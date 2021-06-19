//!encoding: utf-8
//IDE: Clion 2019.2.1
//Architecture: Windows 10 SDK version 1903
//File Name: 710张彦哲第5题.c
//Author: Sean Peldom Zhang
//Create Time: 2019/09/15 14:15
#include <stdio.h>
#include <math.h>
int main()
{
    unsigned int in_num,n=0;
    puts("Please input an integer between 1 and 999,this program will output its square root:");
    tryagain:
    fflush(stdin);//防止出错的输入影响下一轮
    scanf_s("%d",&in_num,1);//这里可能会出错：程序读入的是整型，应该先读入为字符型，然后判断是否为整型
    if(in_num<1000 && in_num>0){
        printf_s("%-7.2lf",pow(in_num,0.5));
        return 0;}
    else if(n<100)//防止无穷循环
        {
        puts("The integer you input must between 1 and 999.Please try again:");
        n++;
        goto tryagain;
        }
    return 0;
}
