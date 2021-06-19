//!encoding: UTF-8
//IDE: Clion 2019.2.2
//Architecture: Windows 10 SDK version 1903
//File Name: 710张彦哲第5题.c
//Author: Sean Peldom Zhang
//Create Time: 2019/11/2 00:45
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
struct scores{
    float Physics;
    float Chemistry;
    float Biology;
    float avg;
};
struct node{
    unsigned int Student_ID;//a班全为2n-1，b班全为2n，即使a，b应该不同也不会重复
    char *name;//重名没关系，反正不是排序依据
    struct scores subject;
}students[5];
struct names{
    char name[15];//store names
}st_names[5];
void print_each_score_type_standard(unsigned int Student_ID,char *name, float Physics, float Chemistry, float Biology){
    printf_s("%u\t%s\t%.1f\t%.1f\t%.1f\t",Student_ID,name,Physics,Chemistry,Biology);
}
void puts_line(){
    puts("===========================================================");
}
int checkin100(float checked){
    if(checked<=100 && checked>=0) return 1;
    else return 0;
}
void input() {
    puts_line();
    for (unsigned int j = 0; j < 5; ++j) {
        students[j].name=st_names[j].name;
        puts("Input the St_ID you are going to insert in.(St_ID)");
        scanf_s("%d",&students[j].Student_ID);
        setbuf(stdin,NULL);
        printf_s("Input No.%d student's name\n",students[j].Student_ID);
        gets_s(st_names[j].name,15);
        printf_s("Please keystroke %s's(St_ID:%d) score:\n(Physics,Chemistry,Biology)\n",students[j].name,students[j].Student_ID);
        scanf_s("%f,%f,%f",&students[j].subject.Physics,&students[j].subject.Chemistry,&students[j].subject.Biology);
        assert(checkin100(students[j].subject.Physics)&&checkin100(students[j].subject.Chemistry)&&checkin100(students[j].subject.Biology));
        printf_s("%s's information is inserted successfully, thank you.\n",students[j].name);
        students[j].subject.avg=(students[j].subject.Physics+students[j].subject.Chemistry+students[j].subject.Biology)/3.0;
    }
    puts_line();
}
int max_f(){//max是特殊字符，用max_f代替
    int max_num=0;//among 0~4
    for (int i = 1; i < 5; ++i) {
        if(students[max_num].subject.avg<students[i].subject.avg){
            max_num=i;
        }
    }
    return max_num;
}
void links_to_file(){
    FILE *fp;errno_t err;
    err=fopen_s(&fp,"stud.txt","a+");
    fputs("St_ID\tSt_name\tPhysics\tChem\tBiology\tAvg_Sc\n",fp);
    for (int i = 0; i < 5; ++i) {
        fprintf(fp,"%u\t%s\t%.1f\t%.1f\t%.1f\t%.1f\n",
                students[i].Student_ID,
                students[i].name,
                students[i].subject.Physics,
                students[i].subject.Chemistry,
                students[i].subject.Biology,
                students[i].subject.avg);
    }
    fclose(fp);
}
void sort_by_avg(){
    unsigned int temp_st_id;
    char *temp_name;
    float temp_physics,temp_chemistry,temp_biology,temp_avg;
    for(int i=0;i<5-1;i++){//这里冒泡排序，先排前n-1轮
        for(int k=0;k<5-1-i;k++){//这里排n-1-i，排没有排过的
            if(students[k].subject.avg>students[k+1].subject.avg){//如果前一项大于后一项，交换
                temp_st_id=students[k].Student_ID;students[k].Student_ID=students[k+1].Student_ID;students[k+1].Student_ID=temp_st_id;
                temp_name=students[k].name;students[k].name=students[k+1].name;students[k+1].name=temp_name;
                temp_physics=students[k].subject.Physics;students[k].subject.Physics=students[k+1].subject.Physics;students[k+1].subject.Physics=temp_physics;
                temp_chemistry=students[k].subject.Chemistry;students[k].subject.Chemistry=students[k+1].subject.Chemistry;students[k+1].subject.Chemistry=temp_chemistry;
                temp_biology=students[k].subject.Biology;students[k].subject.Biology=students[k+1].subject.Biology;students[k+1].subject.Biology=temp_biology;
                temp_avg=students[k].subject.avg;students[k].subject.avg=students[k+1].subject.avg;students[k+1].subject.avg=temp_avg;
            }
        }
    }
}
int main(void){
    puts("This is a program that analyse class A in final exam scores.");
    input();
    int max_num=max_f();
    puts("St_ID\tSt_name\tPhysics\tChem\tBiology\tAvg_Sc");
    for (int i = 0; i < 5; ++i) {
        print_each_score_type_standard(students[i].Student_ID,students[i].name,students[i].subject.Physics,students[i].subject.Chemistry,students[i].subject.Biology);
        printf_s("%.2f\n",students[i].subject.avg);
    }
    puts_line();
    printf_s("Study bug in Class A:\n"
             "St_ID\tSt_name\tPhysics\tChem\tBiology\tAvg_Sc\n"
             "%u\t%s\t%.1f\t%.1f\t%.1f\t%.1f\n",
             students[max_num].Student_ID,students[max_num].name,students[max_num].subject.Physics,students[max_num].subject.Chemistry,students[max_num].subject.Biology,students[max_num].subject.avg);
    sort_by_avg();
    links_to_file();
    system("stud.txt");
    return 0;
}