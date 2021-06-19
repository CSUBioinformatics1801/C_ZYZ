//!encoding: UTF-8
//IDE: Clion 2019.2.2
//Architecture: Windows 10 SDK version 1903
//File Name: 710张彦哲第10题.c
//Author: Sean Peldom Zhang
//Create Time: 2019/10/10 11:57
#include <stdio.h>
int isprime(unsigned int a){
    int judgingprime=0;
    for (unsigned int j = 2; j < a; j++)if (a % j == 0) judgingprime=1;
       //如果有因数，则不为素数,返回1
    return judgingprime;
}
int main(void) {
    int cycle=0;
    rejudge:
    cycle++;
    puts("This is a program that judging prime, please input a integer");
    unsigned int n;
    scanf_s("%d", &n);//保证整数
    if (n == 1 || n == 0)printf_s("%d is not prime.\n", n);
    else {
        printf_s("%d is ", n);
        if (isprime(n))printf_s("not ");
        printf_s("a prime. cycle: %d\n",cycle);
    }
    if(cycle<5)goto rejudge;
    return 0;
}

//        for (int i = 2; i < 200; ++i) {
//            if (isprime(i) == 0)printf_s("%d\n", i);
//        }
/*
 * 思路：统计所有单词长度，以空格为间隔，结构体，有单词起始位点和长度组成
 * 输入的可能成分：字母，空格，标点，换行符；空格或换行符作为起始点，标点符号为终止
 * 单词开始有3种情况：1.文章开始 2.句子末尾 3.单词末尾 4.换行
 * 为了方便，去除情况1，放入情况2中
 */

