//!encoding: ASCII
//IDE: Clion 2019.2.1
//Architecture: Windows 10 SDK version 1903
//File Name: 710张彦哲第3题.c
//Author: Sean Peldom Zhang
//Create Time: 2019/09/25 17:22
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(void){
    int matrix[5][5],diagonal=0;
    puts("This is a random 5*5 matrix:\n==================================");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; ++j) {
            matrix[i][j]=rand()%10+1;
            printf_s("%d\t",matrix[i][j]);//生成一个3*3随机矩阵，省得用户输入麻烦
            if(i==j)diagonal+=matrix[i][j];
        }
        puts("");
    }
    puts("==================================");
    printf_s("Summation of diagonal unit is %d.",diagonal);
    return 0;
}
/*
 * 第2题：求一个整形3*3矩阵的整形矩阵对角线元素之和
 * 思路：随机生成一个矩阵，对角线相加，很简单
 */
