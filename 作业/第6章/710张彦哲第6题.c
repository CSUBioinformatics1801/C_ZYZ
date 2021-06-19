//!encoding: ASCII
//IDE: Clion 2019.2.1
//Architecture: Windows 10 SDK version 1903
//File Name: 710张彦哲第6题.c
//Author: Sean Peldom Zhang
//Create Time: 2019/09/25 19:31
#include<stdio.h>
long long int factorial(long long int i) {//返回i的阶乘
    if (i == 1 || i == 0)
        return 1;//1!,0!=1
    return i * factorial(i - 1);//这样会降低效率但足够用
}
int main() {
    int i, j,n;long long int coefficient;       //i代表行数，n打印的行数
    puts("This is a program that print Pascal's triangle.\nPlease input a height:");
    scanf_s("%d",&n);
    for (i = 0; i < n; i++) {//二项式定理展开求系数公式:nCm=n!/(n-m)!/m!据说阶乘并不快
        for (j = 0; j <= i ; j++) {//打印单个系数
            coefficient = factorial(i) / (factorial(i - j)*factorial(j));
            printf_s("%lld\t", coefficient);
        }
        printf_s("\n");//进入下一行
    }
    for (int k = 0; k < n; ++k) {
        printf_s("*\t");
    }
    return 0;
}
/*
 * 题目：输出杨辉三角
 * 思路：利用二项式定理展开求系数公式:nCm=n!/(n-m)!/m!
 *大佬的代码：（可以打印出三角形）来源：https://blog.csdn.net/weixin_33704234
#include <stdio.h>
#define line 10
int main(int argc, const char * argv[]) {
    //printf("%lu", sizeof(int));
    // 初始化 变量
    int i, j, n = line;
    // 初始化 数组
    // 两个数组用来保存两行数字
    int array1[line] = { 0 };
    int array2[line] = { 0 };
    int* pUp = array1; // 指向保存上一行数字的数组
    int* pDown = array2; // 指向保存当前行数组的数组
    int* p = NULL; // 空指针用来进行指针交换
    int index = 0; // 访问下标
    // 每行左右两边都是 1
    // 从第二行起，中间的每一个数是上一行里相邻两个数之和
    // 第 n 行 有 n 个数字
    // 因为第1行 第2行 均为已知
    // 所以 从第三行开始
    // 从第三行开始计算（i = 2）
    // 每一个空格的内容都是它左上方和上方两个元素之和
    int k;
    for (i = 0; i < n; i++) {
        // 打印每行前面的空格
        for (k = i; k < n - 1; k++) {
            printf_s("   ");
        }
        // 打印每行第一个元素
        printf("%6d", 1);
        *(pDown + index++) = 1;
        for (j = 1; j <= i; j++) {
            // 计算 填充数组
            *(pDown + index) = *(pUp + index - 1) + *(pUp + index);
            printf("%6d", *(pDown + index));
            index++;
        }
        index = 0;
        // 两个指针指向内容交换
        p = pUp;
        pUp = pDown;
        pDown = p;
        printf("\n");
    }
    return 0;
}
 */