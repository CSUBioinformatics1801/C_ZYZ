//!encoding: ASCII
//IDE: Clion 2019.2.1
//Architecture: Windows 10 SDK version 1903
//File Name: 710张彦哲第10题.c
//Author: Sean Peldom Zhang
//Create Time: 2019/09/25 22:35
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LINE 4096
void createtxt(void){
    FILE *fp;errno_t err;
    if ((err = fopen_s(&fp, "Ilovepython.txt", "w+")) !=0)    //不同点2
    {
        printf("Unable to write the file.\n");            //如果打不开，就输出打不开
        exit(0);                               //终止程序
    }
    fprintf_s(fp,"The Zen of Python, by Tim Peters\n"//这里写入经典的import this from python V3.7.3
               "\n"
               "Beautiful is better than ugly.\n"
               "Explicit is better than implicit.\n"
               "Simple is better than complex.\n"
               "Complex is better than complicated.\n"
               "Flat is better than nested.\n"
               "Sparse is better than dense.\n"
               "Readability counts.\n"
               "Special cases aren't special enough to break the rules.\n"
               "Although practicality beats purity.\n"
               "Errors should never pass silently.\n"
               "Unless explicitly silenced.\n"
               "In the face of ambiguity, refuse the temptation to guess.\n"
               "There should be one-- and preferably only one --obvious way to do it.\n"
               "Although that way may not be obvious at first unless you're Dutch.\n"
               "Now is better than never.\n"
               "Although never is often better than *right* now.\n"
               "If the implementation is hard to explain, it's a bad idea.\n"
               "If the implementation is easy to explain, it may be a good idea.\n"
               "Namespaces are one honking great idea -- let's do more of those!");
    fclose(fp);
}

void opentxt(void){//这里读取文件
    char data;
    int ana_capital=0,ana_lc=0,ana_num=0,ana_blank=0,ana_other=0;
    FILE *fp=fopen("Ilovepython.txt","rt");
    if(!fp)
    {
        printf("Can't open file\n");
        exit (1);
    }
    while(!feof(fp))//这里对文件每个数据依次读取，依次分析
    {
        fscanf_s(fp,"%c",&data);
        printf_s("%c",data);
        if(data>='a' && data<='z')ana_lc++;
        else if(data>='A'&& data<='Z')ana_capital++;
        else if(data>='0'&& data<='9')ana_num++;
        else if(data==' ')ana_blank++;
        ana_other++;
    }
    ana_other-=ana_num-ana_capital-ana_blank-ana_lc;
    printf_s("Summary:\nNumbers:%d\nCapital:%d\nLower Case:%d\nBlank:%d\nOther:%d\n",ana_num,ana_capital,ana_lc,ana_blank,ana_other);
    fclose(fp);
}

int main(void) {
    createtxt();
    opentxt();
    return 0;
}
/*
 * 题目：统计一篇文章（有几行）中的各字符情况：英文大写，英文小写，数字，空格，其他字符
 * 思路：先生成一个txt文件，把文章输进去，然后读出来，一个个统计
 */
//    char buf[MAX_LINE];  /*缓冲区*/
//    FILE *fp;            /*文件指针*/
//    int len;             /*行字符个数*/
//    if((fp = fopen("C:\\Users\\pc\\CLionProjects\\untitled1\\Ilovepython.txt","r")) == NULL)/*读取main.c同目录下的一个txt文件*/
//    {
//        perror("Fail to read");
//        exit (1) ;
//    }
//    while(fgets(buf,MAX_LINE,fp) != NULL)
//    {
//        len = strlen(buf);
//        buf[len-1] = '\0';  /*去掉换行符*/
//        printf("%s %d \n",buf,len - 1);
//    }
