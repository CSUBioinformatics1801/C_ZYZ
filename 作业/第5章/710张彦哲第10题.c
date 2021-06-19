//!encoding: ASCII
//IDE: Clion 2019.2.1
//Architecture: Windows 10 SDK version 1903
//File Name: 710张彦哲第10题.c
//Author: Sean Peldom Zhang
//Create Time: 2019/09/18 17:36
#include <stdio.h>
#include <math.h>
int main(){
    puts("This is a program that calculate a series:\n2/1,3/2,5/3,8/5,...\nInput a number:");
    long int An,feb1=1,feb2=2;double Sn=0.0;
    scanf_s("%d",&An);
    for(int i=0;i<abs(An);i++){
        printf_s("%d,%d\n",feb1,feb2);
        Sn+=(float)feb2/(float)feb1;//get An to Sn
        feb1=feb1+feb2;//as new feb1(feb3)
        feb2=feb1+feb2;//as new feb2(feb4)
    }
    printf_s("%-10.2lf",Sn);
    return 0;
}
/*
 * 题目：求数列2/1,3/2,5/3,8/5,...的前20项和
 */