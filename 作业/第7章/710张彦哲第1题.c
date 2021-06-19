//!encoding: UTF-8
//IDE: Clion 2019.2.2
//Architecture: Windows 10 SDK version 1903
//File Name: 710张彦哲第1题.c
//Author: Sean Peldom Zhang
//Create Time: 2019/10/09 16:43
#include <stdio.h>
int max_common_divisor(int a,int b){//辗转相除法求
    int max=a>b?a:b;
    int min=a<b?a:b;//获得ab中大数与小数
    int c=max%min;//max=c*b min=a*b;取余即得|a-c|*b，连续取余使得|a-c|不断缩小到1
    if(c==0)return min;//此时即刚好
    else return max_common_divisor(c,min);
}
int least_common_multiple(int a,int b){//=a*c*b
    return a*b/max_common_divisor(a,b);
}
int main(void){
    puts("This is a program that calculate max_common_divisor & least_common_multiple of 2 integers.");
    int first,second;
    puts("Please input the first number:");scanf_s("%d",&first);
    puts("Please input the second number:");scanf_s("%d",&second);
    printf_s("Max_common_divisor=%d\nMin_common_multiple=%d\n",max_common_divisor(first,second),least_common_multiple(first,second));
    return 0;
}

/* 题目：写2个函数，求2个整数最大公约数和最小公倍数
 * 思路：循环除法，利用公式(a,b)*[a,b]=ab,其中(a,b)最大公约数[a,b]为最小公倍数
 */
