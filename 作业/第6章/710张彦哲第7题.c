//!encoding: ASCII
//IDE: Clion 2019.2.2
//Architecture: Windows 10 SDK version 1903
//File Name: 710张彦哲第7题.c
//Author: Sean Peldom Zhang
//Create Time: 2019/09/26 23:22
#include <stdio.h>
#include <stdlib.h>
enum check{yes=1,no=0};
int checkf(int maxtrix[4][4]){
    int sum=0,sum_row[4]={0},sum_clum[4]={0},sum_dig[2]={0};

    for (int j = 0; j <4; ++j) {//生成各行的累和
        for (int i = 0; i < 4; ++i) {
            sum_row[j]+=maxtrix[i][j];
        }//检查隔行和是否相等
    }if(sum_row[0]!=sum_row[1] || sum_row[1]!=sum_row[2]||sum_row[2]!=sum_row[3])return no;

    for (int j = 0; j <4; ++j) {//生成各列的累和
        for (int i = 0; i < 4; ++i) {
            sum_clum[j]+=maxtrix[j][i];
        }//检查各列和是否相等
    }if(sum_clum[0]!=sum_clum[1] || sum_clum[1]!=sum_clum[2] ||sum_clum[2]!=sum_clum[3])return no;

    for (int j = 0; j <4; ++j) {//生成各对角线的累和
        sum_dig[0]+=maxtrix[j][j];
        sum_dig[1]+=maxtrix[4-j][4-j];
    }if(sum_dig[0]!=sum_dig[1])return no;

    //如果能执行到这一步，说明各行各列各对角线各自相等，然后检查3个是否相等
    if(sum_clum[0]==sum_dig[0] && sum_dig[0]==sum_row[0])return yes;
    else return no;
}
int main(void) {
    int matrix[4][4],checknum=no;
    puts("This is a random 5*5 matrix:\n==================================");
    for (int k = 0; k < 100000; ++k) {
        printf_s("%d\n",k);
        for (int i = 0; i < 4; i++) {//生成一个4*4随机矩阵，省得用户输入麻烦
            for (int j = 0; j < 4; ++j) {
                matrix[i][j]=rand()%10+1;
            }
            puts("");
        }

        if(checkf(matrix)){//检查是否为魔方阵
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4; ++j) {
                    printf_s("%d\t", matrix[i][j]);
                }
            }
            checknum=yes;
            goto end;
        }
    }
    end:
    if(checknum==no)printf_s("10000 no found");
    puts("==================================");

    return 0;
}
/*
 * 题目：输出一个魔方阵
 * 思路：数学不够，用枚举法，随机生成然后检查
 * 结果：10万次不能随机出1个，此方法效率太低
 */
