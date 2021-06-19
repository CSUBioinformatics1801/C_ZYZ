//!encoding: ASCII
//IDE: Clion 2019.2.1
//Architecture: Windows 10 SDK version 1903
//File Name: 710张彦哲第12题.c
//Author: Sean Peldom Zhang
//Create Time: 2019/09/18 18:26
#include <stdio.h>
int main(){
    puts("This is a program that solve a problem called 'Monkey's peach'.");
    int peach=1;
    for (int i = 1; i <=10 ; i++) {
        printf_s("The number of peach at %2dth day is %-4d.\n",11-i,peach);
        peach=2*(peach+1);
    }
    return 0;
}
/*
 * 题目：猴子吃桃问题。第一题摘下若干桃子，吃掉1半加1个，第2天早上将剩下的吃掉1半加1个；
 * 后每天如此反复，第10天时仅有1个桃子，求第1天有多少个桃子？
 */