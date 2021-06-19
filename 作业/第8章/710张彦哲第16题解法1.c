//!encoding: UTF-8
//IDE: Clion 2019.2.2
//Architecture: Windows 10 SDK version 1903
//File Name: 710张彦哲第10题.c
//Author: Sean Peldom Zhang
//Create Time: 2019/10/10 11:57
#include <stdio.h>
#include <math.h>
#include <assert.h>
struct Int{
    char *start_position;
    int length;
};
struct Int Inteach[1000];int Inteach_unit=0;
int int_counts[1000]={0};
int is_int(char check_char){//检查是否为数字
    if(check_char>='0'&& check_char<='9')return 1;
    else return 0;
}
void get_word_length(char *a) {
    assert(a != NULL);
    char *scanword = a;scanword++;//从" "中的“ ”开始
    int scancount = 0;
    int acRAM = 0;
    while (*scanword != '\0') {
        if(is_int(*scanword)==1){//是数字的情况
            if(is_int(*(scanword-1))==0){//上一个不是数字，说明是连续数字开始
                Inteach[scancount].length = 1;//初始化
                Inteach[scancount].start_position = a+acRAM+1;//记录此时连续的起始点
            } else Inteach[scancount].length++;//上一个是数字，数字延续
        } else{//不是字母的情况
            if(is_int(*(scanword-1))==0){//上一个不是数字
                ;
            } else{//上一个是数字，说明是两数字间隔
                scancount++;
            }
        }
        scanword++;
        acRAM++;
    }
    Inteach_unit = scancount + 1;//scancount在函数内会释放，用外部变量Inteach_unit储存数字数量
}
void fill_int_counts(){//填充提取出的数字字符，并转化成int型储存在int_counts[]中
    int fill_int_countor=0;
    for (int i = 0; i < Inteach_unit; ++i) {
        for (int j = 0; j < Inteach[i].length; ++j) {
            int_counts[fill_int_countor]+=(*Inteach[i].start_position-'0')*(int)pow(10,Inteach[i].length-j-1);
            Inteach[i].start_position++;
        }
        fill_int_countor++;//计算下一个元素
    }
    printf_s("Extracted: [");//print the initiated origin_array
    for(int i=0;i<Inteach_unit;i++){
        printf_s("%d",int_counts[i]);
        if(i==Inteach_unit-1)printf_s("];\n");
        else printf_s(",");
    }

}
int main(void){
    puts("This is a program that print the constant integers from string you've input:");
    char getstr[998];gets_s(getstr,997);
    char bkstr[1000];bkstr[0]=' ';//在getstr前加上一个空格，方便处理
    for (int i = 0; i < 998; ++i) {
        if(getstr[i]!='\0')bkstr[i+1]=getstr[i];
        else if(getstr[i]=='\0'){
            bkstr[i+1]=getstr[i];
            break;//结束，赋值结尾后跳出循环
        }
    }
    puts("Counting...\n================================================");
    get_word_length(bkstr);
    for (int j = 0; j < Inteach_unit; ++j) {
        printf_s("Integer%d,length=%d,position=%x\n",j+1,Inteach[j].length,Inteach[j].start_position);
    }
    puts("================================================");
    fill_int_counts();
    return 0;
}
/*
 * 思路：统计所有单词长度，以空格为间隔，结构体，有单词起始位点和长度组成
 * 输入的可能成分：字母，空格，标点，换行符；空格或换行符作为起始点，标点符号为终止
 * 单词开始有3种情况：1.文章开始 2.句子末尾 3.单词末尾 4.换行
 * 为了方便，去除情况1，放入情况2中
 */

