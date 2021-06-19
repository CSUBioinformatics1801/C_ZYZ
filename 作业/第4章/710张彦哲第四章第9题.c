//!encoding: utf-8
//IDE: Clion 2019.2.1
//Architecture: Windows 10 SDK version 1903
//File Name: A710张彦哲第9题.c
//Author: Sean Peldom Zhang
//Create Time: 2019/09/22 11:07
#include <stdio.h>
#include <string.h>

int main()
{
    char num[100];
    puts("This is a program that analyse a integer you've put:");
    gets_s(num,100);
    printf_s("Digits:%d\n",strlen(num));
    for (int i = 0; i < strlen(num); i++) {
        if(i==0)printf_s("Each count:[");
        printf_s("%c",num[i]);
        if(i!=strlen(num)-1)printf_s(",");
        else printf_s("]\n");
    }
    printf_s("Reserved order:");
    for (int i = 0; i < strlen(num); i++) {
        printf_s("%c",num[strlen(num)-i]);
    }
    return 0;
}
