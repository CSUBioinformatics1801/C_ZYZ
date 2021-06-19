//!encoding: utf-8
//IDE: Clion 2019.2.1
//Architecture: Windows 10 SDK version 1903
//File Name: A710张彦哲第9题.c
//Author: Sean Peldom Zhang
//Create Time: 2019/09/22 20:16
#include <stdio.h>
enum isornot {yas=1,nos=0};
int isprime(int n){
    int prime=yas;
    for(int j=2;j<n;j++){
        if(n%j==0){
            prime=nos;
        }
    }
    return prime;
}
int main(){
    puts("This is a program that find 'perfact' number if it's equal to adding all its factors ");
    int prime[1000];//define素数数组
    int p=0;
    for(int i=1;i<=1000;i++){
        if(isprime(i)){prime[p]=i;p++;}
    }//initiate素数数组
//    int fac[][1000]={0};//define约数矩阵
int pef[1000]={0};int pefadd=0;
    for(int n=1;n<=1000;n++) {//从1到1000的大循环
        int nsfac = 0;
        printf_s("%d=", n);
        printf_s("1");if(n!=1)printf_s("x");//行首打印n=1x

        for (int i = 0; i <= n; i++) {//小循环针对每个n，赋值并打印fac数组，如果可以整除，从prime数组取值打印
            int nf = n, t = 0;//nf用于不断被除,t为fac横向赋值点
            while (nf%prime[i]==0 && nf!= prime[i] && prime[i]!=1) {//现在的nf可被这一个质数整除切不等于该整数
                    nf /= prime[i];
                    nsfac += prime[i];
//                fac[n][t]=prime[i];//该方案已放弃，二维数组是const，麻烦
//                t++;
                    printf_s("%dx", prime[i]);
            }
                //todo:怎么一直除一个prime呢？比如16=1x2x2x2x2,这里要3个循环
                if (nf == prime[i]&&n!=1){
                    nsfac+=prime[i];
                    printf_s("%d", prime[i]);
                }
        }
        if(nsfac+1==n){
            pef[pefadd]=n;
            pefadd++;
        }//之前跳过了1，这里加1
        puts("");
//        int pfct_foc=0,facay[50]={0},addfacay=0;
//        for (int i = 1; i < n; i++) {
//            if(n%i==0){//whether is a fac
//                pfct_foc+=i;//i is a factor of n
//                facay[addfacay]=i;
//                addfacay++;
//            }
//        }
//        if(pfct_foc==n)ispfct=yas;
//        else ispfct=nos;
//        for (int k = 0; k < n; ++k) {
//            printf_s("%d,",facay[k]);
//        }
//        puts("");
//        if(ispfct==yas){
//            printf_s("%d=\n",n);
//            for(int j=1;j<n;j++){
//                printf_s("%d",facay[j]);
//            }
//        }
    }
    puts("These are the perfect number among 1 to 1000:");
    for (int j = 0; j <= pefadd-1; j++) {
        printf_s("%d\n",pef[j]);
    }
    return 0;
}
