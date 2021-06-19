//!encoding: UTF-8
//IDE: Clion 2019.2.2
//Architecture: Windows 10 SDK version 1903
//File Name: 710张彦哲第10题.c
//Author: Sean Peldom Zhang
//Create Time: 2019/10/10 11:57
#include <stdio.h>
#include <assert.h>
struct Word{
    char *start_position;
    int length;
};
struct Word Wordeach[1000];int Wordeach_unit=0;
int inalphabet(char check_char){//检查是否为字母和缩写字符“’”
    if((check_char>='A'&& check_char<='Z')||(check_char>='a'&&check_char<='z')||check_char=='\'')return 1;
    else return 0;
}
void get_word_length(char *a) {
    assert(a != NULL);
    char *scanword = a;scanword++;//从" "中的“ ”开始
    int scancount = 0;
    int acRAM = 0;
    while (*scanword != '\0') {
        if(inalphabet(*scanword)==1){//是字母的情况
            if(inalphabet(*(scanword-1))==0){//上一个不是字母，说明是单词开始
                Wordeach[scancount].length = 1;//初始化
                Wordeach[scancount].start_position = a+acRAM+1;//记录此时单词的起始点,注意不能用函数内消亡的变量
//debug                printf_s("acRAM=%d,Wordeach[%d].start_position=%x\n",acRAM,scancount);
            } else Wordeach[scancount].length++;//上一个是字母，单词延续
        } else{//不是字母的情况
            if(inalphabet(*(scanword-1))==0){//上一个不是字母，可能是句子结束如“! ”
                ;
            } else{//上一个是字母，说明是两单词间隔或者句子结尾如“e!”
                scancount++;
            }
        }
//todo:bug, 逻辑错误
//        if ((*scanword == ' ' || *scanword == '\t' || *scanword == '\n')) {//句子,段落开始计数,判断规则：此处为空格，前一处不为字母
//         //这是两个单词间隔1个空格的情况
//           Wordeach[scancount].length = 0;//初始化
//            Wordeach[scancount].start_position = a+acRAM;//记录此时单词的起始点,注意不能用函数内消亡的变量
//            printf_s("acRAM=%d,Wordeach[%d].start_position=%x\n",acRAM,scancount,Wordeach[scancount].start_position);
//            scancount++;
//        }else if (inalphabet(*scanword)){//为字母，开始计数
//            Wordeach[scancount].length++;
//        }else if (inalphabet(*scanword = 0) && *scanword!='\''){//非字母外的字符,终止计数,且不为缩写或‘s的情况
//            scancount++;//终止上一个，开始下一个
//        }
        scanword++;
        acRAM++;
    }
    Wordeach_unit = scancount + 1;//scancount在函数内会释放，用外部变量储存
}
void print_longest_word(void){
    int longest_word_length = Wordeach[0].length, longest_i = 0;
    for (int i = 1; i < Wordeach_unit; ++i) {//得到最大的单词在数组中的位置
        if (longest_word_length < Wordeach[i].length) {
            longest_word_length = Wordeach[i].length;
            longest_i = i;
        }
    }
    puts("Longest word:");
    printf_s("length=%d,", longest_word_length);

    for (int j = 0; j < longest_word_length; ++j) {
        printf_s("%c",*Wordeach[longest_i].start_position);
        Wordeach[longest_i].start_position++;
    }
puts("");
}
int main(void){
    puts("This is a program that print the longest word from string you've input:");
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
    for (int j = 0; j < Wordeach_unit; ++j) {
        printf_s("Word%d,length=%d,position=%x\n",j+1,Wordeach[j].length,Wordeach[j].start_position);
    }
    puts("================================================");
    printf_s("Words number=%d\n",Wordeach_unit);
    print_longest_word();
    return 0;
}
/*
 * 思路：统计所有单词长度，以空格为间隔，结构体，有单词起始位点和长度组成
 * 输入的可能成分：字母，空格，标点，换行符；空格或换行符作为起始点，标点符号为终止
 * 单词开始有3种情况：1.文章开始 2.句子末尾 3.单词末尾 4.换行
 * 为了方便，去除情况1，放入情况2中
 */

