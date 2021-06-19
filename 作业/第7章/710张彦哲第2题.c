//!encoding: UTF-8
//IDE: Clion 2019.2.2
//Architecture: Windows 10 SDK version 1903
//File Name: 710张彦哲第2题.c
//Author: Sean Peldom Zhang
//Create Time: 2019/10/09 16:57
#include <stdio.h>
int delta(double a,double b,double c){
    return b*b-4*a*c;
}
int main(void){
    puts("This is a program that solve quadratic equations.Please input a equation as follows:(ax^2+bx+c=0)");
    double a,b,c,delta;
    scanf_s("%lfx^2+%lfx+%lf=0",&a,&b,&c);
    if(delta(a,b,c)<0)puts("\nOops! No solution for the equation!\n");
    else if(delta(a,b,c)==0)printf_s("2 solutions are the same:\nx=%lf\n",-b/2/a);
    else if(delta(a,b,c)>0)printf_s("2 different solutions:\nx1=%lf\nx2=%lf\n",(-b+delta(a,b,c))/2/a,(-b-delta(a,b,c))/2/a);
    return 0;
}

/* 题目：求二次方程的根
 * 思路：太简单了
 */
