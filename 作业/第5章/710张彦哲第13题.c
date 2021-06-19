//!encoding: ASCII
//IDE: Clion 2019.2.1
//Architecture: Windows 10 SDK version 1903
//File Name: 710张彦哲第13题.c
//Author: Sean Peldom Zhang
//Create Time: 2019/09/18 19:05
#include <stdio.h>
#include <math.h>
int main(){
    puts("This is a program that the square root of a number by iteration method.\nFormula: Xn+1=1/2*(Xn+a/Xn)\nPlease input a number:");
    long double x;int n=0;
    scanf_s("%lf",&x,1);
    while(x<0){
        puts("X must be larger than 0.Please import again:");
        scanf_s("%lf",&x,1);
    }
    long double xn=x;
    while(xn-sqrtl(x)>1.0E-5){
        xn=0.5*(xn+x/xn);
        n++;
    }
    printf_s("True square number is %lf.\nThe iteration result is %lf.\nTo get error less than 1.0E-5,we've calculate %d times.",sqrtl(x),xn,n);
    return 0;
}
/*
 * 题目：用迭代法求sqt(a)
 */
