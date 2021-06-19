//!encoding: utf-8
//IDE: Clion 2019.2.1
//Architecture: Windows 10 SDK version 1903
//File Name: A710张彦哲第4题.c
//Author: Sean Peldom Zhang
//Create Time: 2019/09/22 10:08
#include <stdio.h>
int max(int a[3]){
    int max;
    if(a[0]<a[1])max=a[1];
    else max=a[0];
    if(max<a[2])max=a[2];
    return max;
}

int main()
{
    int a[3];
    puts("This is a program that max 3 number you've put:");
    for (int i = 0; i <3 ; i++) {
        printf_s("%d:\n",i+1);
        scanf_s("%d",&a[i]);
    }
    printf_s("%d",max(a));
    return 0;
}
