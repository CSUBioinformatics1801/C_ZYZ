//!encoding: ASCII
//IDE: Clion 2019.2.1
//Architecture: Windows 10 SDK version 1903
//File Name: 710张彦哲第14题.c
//Author: Sean Peldom Zhang
//Create Time: 2019/09/25 23:22
#include <stdio.h>
int stract_new(const char first[160],const char second[160]){
    int sum=0;
    for (int i = 0; i < 160; ++i) {
        if(first[i]!='\0' && second[i]!='\0')sum+=first[i]-second[i];
    }
    return sum;
}
int main(void) {
    char first[160],second[160];
    puts("This is a program that compare 2 string, now please input 2 strings:\nFirst one:");
    gets_s(first,159);
    puts("Second one:");
    gets_s(second,159);
    printf_s("First-Second=%d",stract_new(first,second));
    return 0;
}
/*
 * 题目：比较2个字符串，前者大输出整数，反之负数，等于则0；负数为ASCII的差值
 * 思路：很简单，相当于手写一个简化版的stract函数
 */
