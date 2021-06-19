//!encoding: UTF-8
//IDE: Clion 2019.2.2
//Architecture: Windows 10 SDK version 1903
//File Name: 710张彦哲第10题.c
//Author: Sean Peldom Zhang
//Create Time: 2019/10/10 11:57
#include <stdio.h>
#include <stdlib.h>
struct student_subjuct{
    int Forgettenlogy;
    int Atomic_physics;
    int Genetics;
    int Topology;
    int Celestial_mechanics;
};
struct student_score{
    char *pname;
    struct student_subjuct subjuct;
    double avg_score;
}myclass[10];
struct myclass_subject{
    char *subjuct_name;
    double subject_avg;
    char *highest_st_name;
    int highest;
}mysubjects[5];
char *point_name[10]={"Garen","Davide","Alita","Brion","Ewen","Haze","Nicolas","Kana","Phil","Delon"};
char *point_subject[5]={"Forgettenlogy","Atomic_physics","Genetics","Topology","Celestial_mechanics"};
void initiate_myclass(void){//随机生成
    printf_s("St_name\t"
             "Fgtlogy\t"
             "Atom_cs\t"
             "Genecs\t"
             "Tplogy\t"
             "Clcnics\t"
             "Avgscr\n");
    for (int i = 0; i < 10; ++i) {
        myclass[i].pname=point_name[i];
        myclass[i].subjuct.Forgettenlogy=rand()%100+1;
        myclass[i].subjuct.Atomic_physics=rand()%100+1;
        myclass[i].subjuct.Genetics=rand()%100+1;
        myclass[i].subjuct.Topology=rand()%100+1;
        myclass[i].subjuct.Celestial_mechanics=rand()%100+1;
        myclass[i].avg_score=(myclass[i].subjuct.Forgettenlogy+
                myclass[i].subjuct.Atomic_physics+
                myclass[i].subjuct.Genetics+
                myclass[i].subjuct.Topology+
                myclass[i].subjuct.Celestial_mechanics)/5.0;
        printf_s("%s\t%d\t%d\t%d\t%d\t%d\t%.2lf\n",
                myclass[i].pname,
                myclass[i].subjuct.Forgettenlogy,
                myclass[i].subjuct.Atomic_physics,
                myclass[i].subjuct.Genetics,
                myclass[i].subjuct.Topology,
                myclass[i].subjuct.Celestial_mechanics,
                myclass[i].avg_score);
    }
}
void initiate_mysubject(void){
    for (int i = 0; i < 5; ++i) {
        mysubjects[i].subjuct_name=point_subject[i];
        mysubjects[i].subject_avg =0;//初始化
    }
    for (int j = 0; j < 10; ++j) {
        mysubjects[0].subject_avg +=((myclass[j].subjuct.Forgettenlogy)/10.0);
        mysubjects[1].subject_avg +=((myclass[j].subjuct.Atomic_physics)/10.0);
        mysubjects[2].subject_avg +=((myclass[j].subjuct.Genetics)/10.0);
        mysubjects[3].subject_avg +=((myclass[j].subjuct.Topology)/10.0);
        mysubjects[4].subject_avg +=((myclass[j].subjuct.Celestial_mechanics)/10.0);
        if(j==0){//initiate 5 highests
            for (int i = 0; i < 5; ++i) {
                mysubjects[i].highest =10*mysubjects[i].subject_avg;
                mysubjects[i].highest_st_name=point_name[0];//supposing Garen
            }
        }
        if(mysubjects[0].highest<myclass[j].subjuct.Forgettenlogy){
            mysubjects[0].highest =myclass[j].subjuct.Forgettenlogy;
            mysubjects[0].highest_st_name=point_name[j];
        }
        if(mysubjects[1].highest<myclass[j].subjuct.Atomic_physics){
            mysubjects[1].highest =myclass[j].subjuct.Atomic_physics;
            mysubjects[1].highest_st_name=point_name[j];
        }
        if(mysubjects[2].highest<myclass[j].subjuct.Genetics){
            mysubjects[2].highest =myclass[j].subjuct.Genetics;
            mysubjects[2].highest_st_name=point_name[j];
        }
        if(mysubjects[3].highest<myclass[j].subjuct.Topology){
            mysubjects[3].highest =myclass[j].subjuct.Topology;
            mysubjects[3].highest_st_name=point_name[j];
        }
        if(mysubjects[4].highest<myclass[j].subjuct.Celestial_mechanics){
            mysubjects[4].highest =myclass[j].subjuct.Celestial_mechanics;
            mysubjects[4].highest_st_name=point_name[j];
        }
    }
}
void analysissb(void){
    printf_s("Avg\t%.2lf\t%.2lf\t%.2lf\t%.2lf\t%.2lf\t%.2lf\n",
             mysubjects[0].subject_avg,
             mysubjects[1].subject_avg,
             mysubjects[2].subject_avg,
             mysubjects[3].subject_avg,
             mysubjects[4].subject_avg,
             (mysubjects[0].subject_avg+
              mysubjects[1].subject_avg+
              mysubjects[2].subject_avg+
              mysubjects[3].subject_avg+
              mysubjects[4].subject_avg)/5.0);
    printf_s("Hst\t%d\t%d\t%d\t%d\t%d\n",
             mysubjects[0].highest,
             mysubjects[1].highest,
             mysubjects[2].highest,
             mysubjects[3].highest,
             mysubjects[4].highest);
    printf_s("Name\t%s\t%s\t%s\t%s\t%s\n",
             mysubjects[0].highest_st_name,
             mysubjects[1].highest_st_name,
             mysubjects[2].highest_st_name,
             mysubjects[3].highest_st_name,
             mysubjects[4].highest_st_name);
}
void findhighest(void){
    char *highest_st_name=mysubjects[0].highest_st_name;
    int highest_score=mysubjects[0].highest;
    char *highest_subject=point_subject[0];
    for (int i = 1; i < 5; ++i) {
        if(highest_score<mysubjects[i].highest){
            highest_score=mysubjects[i].highest;
            highest_st_name=mysubjects[i].highest_st_name;
            highest_subject=mysubjects[i].subjuct_name;
        }
    }
    printf_s("\nHighest Score:%d from %s on %s\n",highest_score,highest_st_name,highest_subject);
}
void putpartingline(){
    puts("=======================================================");
}
int main(void) {
    puts("Student's score in Bioinfomatics class 1801:");
    putpartingline();
    initiate_myclass();
    initiate_mysubject();
    putpartingline();
    analysissb();
    putpartingline();
    findhighest();
    return 0;
}