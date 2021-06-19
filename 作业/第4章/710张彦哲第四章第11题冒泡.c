//!encoding: utf-8
//IDE: Clion 2019.2.1
//Architecture: Windows 10 SDK version 1903
//File Name: 710张彦哲第11题.c
//Author: Sean Peldom Zhang
//Create Time: 2019/09/15 16:33
#include <stdio.h>
int main(){
    float origin[4],t;
    puts("Please input 4 numbers, enter each.");
    for (int iput=0;iput<4;iput++){
        scanf_s("%f",&origin[iput]);
    }//把stdin4个数读到数组里
    for(int i=0;i<4-1;i++){//这里冒泡排序，先排前n-1轮
        for(int k=0;k<4-1-i;k++){//这里排n-1-i，排没有排过的
            if(origin[k]>origin[k+1]){//如果前一项大于后一项，交换
                t=origin[k];origin[k]=origin[k+1];origin[k+1]=t;//交换前后项
            }
        }
    }
    printf_s("[");//输出结果,以数组的模式
    for(int i=0;i<4;i++){
        printf_s("%-6.2lf",origin[i]);
        if(i==3)printf_s("]\n");
        else printf_s(",");
    }
    return 0;
}
