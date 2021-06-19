//!encoding: utf-8
//IDE: Clion 2019.2.1
//Architecture: Windows 10 SDK version 1903
//File Name: A710张彦哲第6题.c
//Author: Sean Peldom Zhang
//Create Time: 2019/09/22 13:51
#include <stdio.h>
long int factorial(int n){
    int fac=1;int all=1;
    if(n!=1){
        for (int i = 2; i <= n; i++) {
            fac*=i;
            all+=fac;
        }
    }
    return all;
}
int main()
{
    puts("This is a program that help you calculate summary of factorial numbers.\nPlease input a integer:");
    int n;scanf_s("%d",&n);
    printf_s("The summary of factorial is %ld.",factorial(n));
    return 0;
}
