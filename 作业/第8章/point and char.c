//!encoding: UTF-8
//IDE: Clion 2019.2.2
//Architecture: Windows 10 SDK version 1903
//File Name: 710张彦哲第1题.c
//Author: Sean Peldom Zhang
//Create Time: 2019/10/09 16:43
#include <stdio.h>
#include <stdlib.h>

int main(void){
    char *p[3]={"Basic","C++","pascal"};
printf_s("%s,%s,%s\n",*(p+1),p[2]+3,*p+2);
printf_s("%c,%c,%c",*(p[2]+3),*p[2]+3,**p+2);
    return 0;
}

