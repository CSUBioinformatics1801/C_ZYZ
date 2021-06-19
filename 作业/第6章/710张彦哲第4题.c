//!encoding: ASCII
//IDE: Clion 2019.2.1
//Architecture: Windows 10 SDK version 1903
//File Name: 710张彦哲第2题.c
//Author: Sean Peldom Zhang
//Create Time: 2019/09/25 17:00
#include <stdio.h>
#include <stdlib.h>
int main(void){
    int a[10],b[10],c[11];//a is random, b is ranked,c is newly ranked after inserted
    int min_position=0,min;//selecting method to rank
    for (int i = 0; i < 10; ++i) {
        a[i]=rand()%100+1;

    }
    printf_s("Random: [");//输出原始结果,以数组的模式
    for(int i=0;i<10;i++){
        printf_s("%d",a[i]);
        if(i==9)printf_s("];\n");
        else printf_s(",");
    }

    for (int j = 0; j < 10; j++) {
        min=a[0];
        for (int k = 0; k < 10; k++) {
            if(min>=a[k]){min=a[k];min_position=k;};//get min's position
        }
        b[j]=min;
        a[min_position]=99999999;//renew ori[k],a huge number
    }
    puts("Sorting...");
    printf_s("Sorted: [");//输出排序结果,以数组的模式
    for(int i=0;i<10;i++){
        printf_s("%d",b[i]);
        if(i==9)printf_s("];\n");
        else printf_s(",");
    }
    puts("Please input a integer:");
    int insertn;scanf_s("%d",&insertn);
    int insertnb=0;
    for (int l = 0; l < 10; ++l) {//逐一查找插入位置，如有相同，默认最后,l是插入数插入位置前1个数的位置,找不到就是0
        if(insertn>=b[l])insertnb=l;
    }
    for (int m = 0; m < 11;++m) {
        if(m<=insertnb)c[m]=b[m];//现在对l及之前的数赋值
        else if(m==insertnb+1)c[m]=insertn;
        else if(m>insertnb+1)c[m]=b[m-1];
    }
    printf_s("Inserted: [");//输出排序结果,以数组的模式
    for(int i=0;i<11;i++){
        printf_s("%d",c[i]);
        if(i==10)printf_s("];\n");
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