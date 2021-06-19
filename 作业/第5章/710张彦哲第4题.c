//!encoding: ASCII
//IDE: Clion 2019.2.1
//Architecture: Windows 10 SDK version 1903
//File Name: 710张彦哲第4题.c
//Author: Sean Peldom Zhang
//Create Time: 2019/09/18 17:04
#include <stdio.h>
int getend(const char *oristr){
    for (int i = 0; i < 300 ; ++i) {
        if (oristr[i] == 0 && oristr[i + 1] == oristr[i + 2])return i;//end is 0
    }
}
void analysis_str(const char *oristr,int end){
   int addblank=0,addalpha=0,addnum=0,addother=0;
   for(int i=0;i<end;i++){
       if(oristr[i]==32)addblank++;
       else if ((oristr[i]>='A'&& oristr[i]<='Z')|| (oristr[i]>='a' && oristr[i]<='z'))addalpha++;
       else if (oristr[i]>='0' && oristr[i]<='9')addnum++;
       else addother++;
   }
   printf_s("Blank:%d\nLetter:%d\nNumbers:%d\nOther:%d\nAll:%d",addblank,addalpha,addnum,addother,end);
}
int main(){
    puts("This is a program that add up its parts.Please input a string:");
    char getstr[300];
    gets_s(getstr,300);
    int end = getend(getstr);
    analysis_str(getstr,end);
    return 0;
}
/*
 * 题目：输入一行字符，统计其中的英文字母，空格，数字，和其他字符数
 */