//!encoding: UTF-8
//IDE: Clion 2019.2.2
//Architecture: Windows 10 SDK version 1903
//File Name: 710张彦哲第5题.c
//Author: Sean Peldom Zhang
//Create Time: 2019/11/2 00:45
#include <stdio.h>
#include <assert.h>
int main(void) {
    puts("This is a program that comparing 3 numbers. Please input 3 numbers as follows:");
    double *point_to_chars[3];double store_int[3]={0.0};
    for (int i = 0; i < 3; ++i) {
        printf_s("Input string %d:\n",i+1);
        scanf_s("%lf",&store_int[i]);
        point_to_chars[i]=&store_int[i];
        assert(*point_to_chars[i]!=0.0);
    }
    printf_s("Origin str:[%.2lf,%.2lf,%.2lf]\n",*point_to_chars[0],*point_to_chars[1],*point_to_chars[2]);
    puts("Sorting...");
    double *t;//t=temp
    for(int i=0;i<3-1;i++){//这里冒泡排序，先排前n-1轮
        for(int k=0;k<3-1-i;k++){//这里排n-1-i，排没有排过的
            if(*point_to_chars[k]>=*point_to_chars[k+1]){//如果前一项大于后一项，交换
                t=point_to_chars[k];point_to_chars[k]=point_to_chars[k+1];point_to_chars[k+1]=t;//交换前后项
            }
        }
    }
    printf_s("Origin str:[%.2lf,%.2lf,%.2lf]",*point_to_chars[0],*point_to_chars[1],*point_to_chars[2]);
    return 0;
}