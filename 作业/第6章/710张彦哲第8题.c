//!encoding: ASCII
//IDE: Clion 2019.2.1
//Architecture: Windows 10 SDK version 1903
//File Name: 710张彦哲第8题.c
//Author: Sean Peldom Zhang
//Create Time: 2019/09/25 21:17
#include <stdio.h>
#include <stdlib.h>
struct position{
    int a[10];
    int b[10];
}ponit;
enum is{yas=1,nos=0};
int main(void) {
    int matrix[10][10],max,get_position=0,check=yas,saddle=0;
    puts("This is a random 10*10 matrix:\n============================================================================");

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; ++j) {
            matrix[i][j]=rand()%1000+1;
            printf_s("%d\t",matrix[i][j]);//生成一个10*10随机矩阵，省得用户输入麻烦
        }
        puts("");
    }
    puts("============================================================================");

    for (int i = 0; i < 10; i++) {
        max=matrix[i][0];
        for (int j = 0; j < 10; ++j) {//先找出行中最大的10个数
           if(max<=matrix[i][j]) {
               max = matrix[i][j];
               ponit.a[get_position] = i;
               ponit.b[get_position] = j;
           }
        }
        get_position++;
    }

    printf_s("Min in each rows: [");//输出排序结果,以数组的模式
    for(int i=0;i<10;i++){
        printf_s("(%d,%d)=%d",ponit.a[i],ponit.b[i],matrix[ponit.a[i]][ponit.b[i]]);
        if(i==9)printf_s("];\n");
        else printf_s(",");
    }
    for (int k = 0; k < 10; ++k) {//检查该数是否是全列中最小的
        for(int l=0;l<10;l++){
            if(matrix[ponit.a[k]][ponit.b[k]]>matrix[ponit.a[k]][l]){
                check=nos;
            }//一个更大，满行皆输
        }
        if(check){printf_s("(%d,%d)=%d",ponit.a[k],ponit.b[k],matrix[ponit.a[k]][ponit.b[k]]);saddle++;}
    }
    if(saddle==0)puts("Oops! There's no saddle point at all in this matrix!");
    return 0;
}
/*
 * 题目：找出二维数组的鞍点
 * 思路：先找出每行最小的数的位置，赋给新的结构变量，然后检查是否是列最小的
 */