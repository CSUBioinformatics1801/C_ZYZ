//!encoding: utf-8
//IDE: Clion 2019.2.1
//Architecture: Windows 10 SDK version 1903
//File Name: 710张彦哲第6题.c
//Author: Sean Peldom Zhang
//Create Time: 2019/09/15 15:09
#include <stdio.h>
float fx(float x){
    if (x<1){return x;}
    else if (1<=x && x<10){ return 2*x-1;}
    else return 3*x-11;
}
int main(){
    float input_x;
    int n=0;
    if (n<10) {
        puts("Please input an number,the program will output its y:");
        scanf_s("%f", &input_x);
        printf_s("y=%-9.2lf",fx(input_x));
        n++;//防止无穷循环
    }
    return 0;
}
