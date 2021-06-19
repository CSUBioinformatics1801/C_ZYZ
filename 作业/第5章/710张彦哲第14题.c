//!encoding: ASCII
//IDE: Clion 2019.2.2
//Architecture: Windows 10 SDK version 1903
//File Name: 710张彦哲第14题.c
//Author: Sean Peldom Zhang
//Create Time: 2019/09/25 23:22
#include <stdio.h>
#include <math.h>
double fx(double x){
    return  2*pow(x,3)-4*pow(x,2)+3*x-6;
}
double f1x(double x){
    return 6*pow(x,2)-8*x+3;
}
int main(void) {
    puts("This is a program that solve 2x^3-4x^2+3x-6=0.\nInput one:");
    double x1,x2;
    scanf_s("%lf",&x1);
    x2=x1;
    x1=x2-fx(x2)/f1x(x2);int n=0;
    while(n<1000){
        x2=x1;
        x1=x2-fx(x2)/f1x(x2);
        n++;
 }
    //    do{
//        x2=x1;
//        x1=x2-fx(x2)/f1x(x2);
//    }while(fabs(x1-x2)>=1E8);
    printf_s("=================================\nx=%lf",x2);
    return 0;
}
/*
 * 题目：用牛顿迭代法求方程2x^3-4x^2+3x-6=0的根
 * 思路：运用迭代公式x2 = x1 - fx(x1)/f1x(x1);
 */
