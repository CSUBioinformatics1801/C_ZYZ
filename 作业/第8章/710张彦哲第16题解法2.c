//!encoding: UTF-8
//IDE: Clion 2019.2.2
//Architecture: Windows 10 SDK version 1903
//File Name: 710张彦哲第10题.c
//Author: Sean Peldom Zhang
//Create Time: 2019/10/10 11:57
#include <stdio.h>
#include <string.h>
int isnum(char n){
    if(n>='0'&&n<='9')return 1;
    else return 0;
}
int main(void){
    puts("This is a program that print the constant integers from string you've input:\n"
         "(the first one mustn't be number, the last one must be number)");
    char store_str[100];gets_s(store_str,100);//忽略第1个
    puts("Computing:\n======================================================");
    printf_s("[");
    for (unsigned int i = 1; i <strlen(store_str) ; ++i) {
        if(isnum(store_str[i]))putchar(store_str[i]);
        else if(isnum(store_str[i-1]))putchar(',');
    }
    printf_s("]");
    return 0;
}


