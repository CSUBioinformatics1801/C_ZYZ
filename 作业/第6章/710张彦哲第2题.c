//!encoding: ASCII
//IDE: Clion 2019.2.1
//Architecture: Windows 10 SDK version 1903
//File Name: 710张彦哲第2题.c
//Author: Sean Peldom Zhang
//Create Time: 2019/09/25 17:00
#include <stdio.h>
int main(void){
    int ori[10],trans[10],min;
    int min_position=0;
    puts("This is a program that sort 10 integers you've input by 'selection sort method.'\nPlease input 10 integers:");
    for (int i = 0; i < 10; i++) {
        scanf_s("%d",&ori[i]);
    }

    printf_s("Origin: [");//输出原始结果,以数组的模式
    for(int i=0;i<10;i++){
        printf_s("%d",ori[i]);
        if(i==9)printf_s("];\n");
        else printf_s(",");
    }

    for (int j = 0; j < 10; j++) {
        min=ori[0];
        for (int k = 0; k < 10; k++) {
            if(min>=ori[k]){min=ori[k];min_position=k;};//get min's position
        }
        trans[j]=min;
        ori[min_position]=99999999;//renew ori[k],a huge number
    }

    printf_s("Sorted: [");//输出排序结果,以数组的模式
    for(int i=0;i<10;i++){
        printf_s("%d",trans[i]);
        if(i==9)printf_s("];\n");
        else printf_s(",");
    }
    return 0;
}
/*
 * 第2题：用选择法对10个数排序（选择法，每次取出排序最小（大）的数）
 * 思路：
 * 1.初始化min，并把ori第一位赋给min
 * 2.逐一比较min和后9位，找到原始数据里最小的数，赋给min；然后把这个最小的数变成最大的数
 * 3.min赋给trans[k]
 * 4.min再重新初始成第一位
 */
//todo:
//#include <stdlib.h>
//double *ipnums(int n){
//    if(n<=0)return NULL;
//    else{
//        double *r,ori[n];
//        r=(double*)malloc(sizeof(n));
//        for (int i = 0; i < n; i++) {
//            scanf_s("%d",&ori[i]);
//        }
//        return r;
//    }
//}
//double *sort(double *r){
//    for (int i = 0; i < sizeof(r)/ sizeof(r[0]); ++i) {
//
//    }
//}