//!encoding: UTF-8
//IDE: Clion 2019.2.2
//Architecture: Windows 10 SDK version 1903
//File Name: 710张彦哲第13题.c
//Author: Sean Peldom Zhang
//Create Time: 2019/09/25 23:22
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
char *strcat_array(char first[160],char second[160]){//数组处理方式
    assert(first!= NULL && second!= NULL);
    unsigned int i=strlen(first),k=strlen(second);//i为first字符长度，k为second字符长度
    for (unsigned int j = i+1; j < i+k; j++) {
        first[j]=second[j-i];
    }
    return first;//但是这样改变了原始数据
}
void strcat_malloc(){
    char *s1,*s2;
    s1=(char*)malloc(50* sizeof(char));
    s2=(char*)malloc(50* sizeof(char));
    puts("First one:");gets_s(s1,50);//初始化s1
    puts("Second one:");gets_s(s2,50);//初始化s2
    int str1st=strlen(s1),str2nd=strlen(s2);
    int strall = str1st+str2nd;
    s1=(char*)realloc(s1,strall * sizeof(char));//改变s1大小
    for(int i=str1st;i<strall;i++)//此处和字符处理相同
        s1[i]=s2[i-str1st];
    s1[strall]='\0';//终止字符
    puts(s1);
    free(s1);free(s2);
}
char *strcat_str(char *a,char *b){//字符串处理方法
    char *p=a,*q=b;
    while (*p)p++;//找到p的末尾
    while (*q)*p++=*q++;//从p的末尾开始吧q逐一赋给p
    *p='\0';//p的末尾为\0
    //上面2句可压缩成：while ((*p++ = *q++) != '\0');
    return a;//p和a是一样的，返回a；
}
//char *strcat_str(char *a,char *b)__attribute__((__nonnull__(1, 2)));//1,2个参数自动判断非空
int main(void) {
    char first[160],second[160];
    puts("This is a program that connect 2 string, now please input 2 strings:\nFirst one:");
    gets_s(first,159);
    puts("Second one:");
    gets_s(second,159);
    printf_s("Array=%s\nPoint=%s\n",strcat_str(first,second),strcat_array(first,second));
    puts("Now try malloc:");//第3种
    strcat_malloc();
    return 0;
    strcat()
}


/*
 * 题目：把2个字符串连接起来，不能用strcat函数
 * 思路：
 * 1.数组
 * 2.字符指针
 * 3.文件
 * 4.线性链表
 * 5.直接分配内存
 */
//原函数：
//_Check_return_wat_
//_ACRTIMP errno_t __cdecl strcat_s(
//        _Inout_updates_z_(_SizeInBytes) char*       _Destination,
//        _In_                            rsize_t     _SizeInBytes,
//        _In_z_                          char const* _Source
//);
