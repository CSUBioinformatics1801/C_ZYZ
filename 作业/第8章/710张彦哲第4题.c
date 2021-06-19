//!encoding: UTF-8
//IDE: Clion 2019.2.2
//Architecture: Windows 10 SDK version 1903
//File Name: 710张彦哲第4题.c
//Author: Sean Peldom Zhang
//Create Time: 2019/10/09 16:43
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
int origin[51]={0},trans[51]={0};//more than 1 '0' inside
int *origin_point=origin;int *trans_point=trans;
int get_less_random_m(int random_n){
    srand((unsigned)(time(NULL)));
    int random_m;
    do{
        random_m=rand()%100+1;
        if(random_m<random_n)break;
    }while (random_m>=random_n);
    return random_m;
}
void transplant_array(int random_n,int random_m){
    assert(random_m<random_n);//theoretically m<n
    for (int i = 0; i < random_n-random_m; ++i) {
        origin_point++;
    }//read from m
    while (*origin_point)*trans_point++=*origin_point++;//assign m one by one
    for (int j = 0; j < random_n; ++j) {//return origin_point to the beginning
        origin_point--;
    }
    for (int k = 0; k < random_n-random_m; ++k) {//assign n one by one
        *trans_point++=*origin_point++;
    }
}
int main(void){
    puts("This is a program that replace former n-m units and last m units from an array with n units");

    srand((unsigned)(time(NULL)));
    int random_n=(rand()%100+1)/4+25;//25<=n<=50
    int random_m=get_less_random_m(random_n);//1<=m<n
    printf_s("n=%d,m=%d\n",random_n,random_m);
    puts("================================================================================================");
    for (int i = 0; i < random_n; ++i) {
        origin[i]=rand()%100+1;
    }//initiate origin_array

    printf_s("Origin: [");//print the initiated origin_array
    for(int i=0;i<random_n;i++){
        if(origin[i]!=0)printf_s("%d",origin[i]);
        if(i==random_n-1)printf_s("];\n");
        else printf_s(",");
    }

    transplant_array(random_n,random_m);

    printf_s("Trans: [");//print the transplanted origin_array
    for(int i=0;i<random_n;i++){
        if(origin[i]!=0)printf_s("%d",trans[i]);
        if(i==random_n-1)printf_s("];\n");
        else printf_s(",");
    }
    puts("================================================================================================");

    return 0;
}

