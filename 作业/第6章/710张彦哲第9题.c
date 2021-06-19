//!encoding: ASCII
//IDE: Clion 2019.2.1
//Architecture: Windows 10 SDK version 1903
//File Name: 710张彦哲第9题.c
//Author: Sean Peldom Zhang
//Create Time: 2019/09/25 21:36
#include <stdio.h>
#include <stdlib.h>
int binSearch(int x, int fif[], int n){
    int low = 0, high= n-1, mid;
    while(low <= high){
        mid = (low + high) / 2;
        if(x < fif[mid])high = mid - 1;//看看x与中间值孰大孰小
        else if(x > fif[mid])low = mid + 1;//如果x比中间值小，重新定义最小范围
        else return mid;//此时找到最终结果
    }
    return -1;
}
int main(void) {
    int fif[15],n,position;
    puts("This is a random array with 15 unit:\n=========================================================");

    fif[0]=rand()%10+1;//生成15位的随机顺序排列的数组
    for (int i = 1; i < 15; i++) {
            fif[i]=fif[i-1]+rand()%10+1;
    }
    printf_s("The array: [");//输出排序结果,以数组的模式
    for(int i=0;i<15;i++){
        printf_s("%d",fif[i]);
        if(i==14)printf_s("]\n");
        else printf_s(",");
    }
    puts("=========================================================\nYou are going to search a number among the units above:");
    wrong:
    scanf_s("%d",&n);
    position=binSearch(n,fif,15);
    if(position==-1){printf_s("No founding.Please try again:");goto wrong;}
    else printf_s("This is the %dth unit.",position+1);
    return 0;
}
/*
 * 题目：用折半法查找15位由小到大排列的数组中任意一个数，若无此数，输出‘无此数’
 * 思路：先生成一个15位由小到大排列的数组，然后二分法查找输出
 */