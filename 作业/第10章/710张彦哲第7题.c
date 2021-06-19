//!encoding: UTF-8
//IDE: Clion 2019.2.2
//Architecture: Windows 10 SDK version 1903
//File Name: 710�����ܵ�5��.c
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
    unsigned int Student_ID;//a��ȫΪ2n-1��b��ȫΪ2n����ʹa��bӦ�ò�ͬҲ�����ظ�
    char *name;//����û��ϵ������������������
    struct scores subject;
}st_node[10];//�����10-1��ѧ�����㹻����
struct names{
    char name[15];//store names
}st_name[10];
void print_each_score_type_standard(unsigned int Student_ID,char *name, float Physics, float Chemistry, float Biology,
                                    float avg){
    printf_s("%u\t%s\t%.1f\t%.1f\t%.1f\t%.1f\n",Student_ID,name,Physics,Chemistry,Biology,avg);
}
void puts_line(){
    puts("===========================================================");
}
int checkin100(float checked){
    if(checked<=100 && checked>=0) return 1;
    else return 0;
}
int read_from_file(){
    FILE *fp;errno_t err;
    err=fopen_s(&fp,"stud.txt","r+");
    char line[128];
    fgets(line,sizeof(line),fp);//������1��\n֮ǰ�����У����ڵ�һ�б�ͷ
    int struct_count=0;
   while(!feof(fp)){   //����������ݣ�����ʾ�������˳�
       st_node[struct_count].name=st_name[struct_count].name;//��ʼ������ָ��
       fscanf_s(fp,"%u\t%s\t%f\t%f\t%f\t%f\n",
               &st_node[struct_count].Student_ID,
               st_node[struct_count].name,14,
               &st_node[struct_count].subject.Physics,
               &st_node[struct_count].subject.Chemistry,
               &st_node[struct_count].subject.Biology,
               &st_node[struct_count].subject.avg);

       print_each_score_type_standard(
               st_node[struct_count].Student_ID,
               st_node[struct_count].name,
               st_node[struct_count].subject.Physics,
               st_node[struct_count].subject.Chemistry,
               st_node[struct_count].subject.Biology,
               st_node[struct_count].subject.avg);
       struct_count++;
   }
    fclose(fp);
    return struct_count;
}
int insert_st_info(int st_number){
    int insert_st_num;
    puts("How many student you want to insert in?");
    scanf_s("%d",&insert_st_num);
    assert(st_number+insert_st_num<=10 && insert_st_num>=1);//��Ȼ�ռ䲻���岻��
    for (int i = 0; i < insert_st_num; ++i) {
        st_node[st_number].name=st_name[st_number].name;
        puts("Input the St_ID you are going to insert in.(St_ID)");
        scanf_s("%d",&st_node[st_number].Student_ID);
        setbuf(stdin,NULL);
        printf_s("Input No.%d student's name\n",st_node[st_number].Student_ID);
        gets_s(st_node[st_number].name,15);
        printf_s("Please keystroke %s's(St_ID:%d) score:\n(Physics,Chemistry,Biology)\n",st_node[st_number].name,st_node[st_number].Student_ID);
        scanf_s("%f,%f,%f",&st_node[st_number].subject.Physics,&st_node[st_number].subject.Chemistry,&st_node[st_number].subject.Biology);
        assert(checkin100(st_node[st_number].subject.Physics)&&checkin100(st_node[st_number].subject.Chemistry)&&checkin100(st_node[st_number].subject.Biology));
        printf_s("%s's information is inserted successfully, thank you.\n",st_node[st_number].name);
        st_node[st_number].subject.avg=(st_node[st_number].subject.Physics+st_node[st_number].subject.Chemistry+st_node[st_number].subject.Biology)/3.0;
    }
    return st_number+insert_st_num;
}
void sort_by_avg(int st_number){
    unsigned int temp_st_id;
    char *temp_name;
    float temp_physics,temp_chemistry,temp_biology,temp_avg;
    for(int i=0;i<st_number-1;i++){//����ð����������ǰn-1��
        for(int k=0;k<st_number-1-i;k++){//������n-1-i����û���Ź���
            if(st_node[k].subject.avg>st_node[k+1].subject.avg){//���ǰһ����ں�һ�����
                temp_st_id=st_node[k].Student_ID;st_node[k].Student_ID=st_node[k+1].Student_ID;st_node[k+1].Student_ID=temp_st_id;
                temp_name=st_node[k].name;st_node[k].name=st_node[k+1].name;st_node[k+1].name=temp_name;
                temp_physics=st_node[k].subject.Physics;st_node[k].subject.Physics=st_node[k+1].subject.Physics;st_node[k+1].subject.Physics=temp_physics;
                temp_chemistry=st_node[k].subject.Chemistry;st_node[k].subject.Chemistry=st_node[k+1].subject.Chemistry;st_node[k+1].subject.Chemistry=temp_chemistry;
                temp_biology=st_node[k].subject.Biology;st_node[k].subject.Biology=st_node[k+1].subject.Biology;st_node[k+1].subject.Biology=temp_biology;
                temp_avg=st_node[k].subject.avg;st_node[k].subject.avg=st_node[k+1].subject.avg;st_node[k+1].subject.avg=temp_avg;
            }
        }
    }
}
void file_write(int st_number){
    FILE *fp;errno_t err;
    err=fopen_s(&fp,"stud_new.txt","w");
    fputs("St_ID\tSt_name\tPhysics\tChem\tBiology\tAvg_Sc\n",fp);
    for (int i = 0; i < st_number; ++i) {
        fprintf(fp,"%u\t%s\t%.1f\t%.1f\t%.1f\t%.1f\n",
                st_node[i].Student_ID,
                st_node[i].name,
                st_node[i].subject.Physics,
                st_node[i].subject.Chemistry,
                st_node[i].subject.Biology,
                st_node[i].subject.avg);
    }
    fclose(fp);
}
int main(void){
    puts("This is a program that analyse class A in final exam scores.");
    puts("St_ID\tSt_name\tPhysics\tChem\tBiology\tAvg_Sc");
    puts_line();
    int st_number=read_from_file();
    puts_line();
    printf_s("There %d students in class A at present.\n",st_number);
    st_number=insert_st_info(st_number);
    sort_by_avg(st_number);
    file_write(st_number);
    system("stud.txt");
    system("stud_new.txt");
    return 0;
}
