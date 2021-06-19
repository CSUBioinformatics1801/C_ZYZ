//!encoding: UTF-8
//IDE: Clion 2019.2.2
//Architecture: Windows 10 SDK version 1903
//File Name: 710张彦哲第4题.c
//Author: Sean Peldom Zhang
//Create Time: 2019/10/10 11:57
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <time.h>
struct random_trans{
    int *point_sorted;
    int random;
}random20[20];
int original_matrix[5][5];
int sorted[25];
int replaced_matrix[5][5];
void puts_lines(void){
    puts("=======================================================");
}
void initiate_matrix(void){
    srand((unsigned)time(NULL));
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            original_matrix[i][j]=rand()%100+1;
        }
    }
    puts_lines();
    puts("Origin:");
    for(int i=0;i<5;i++){
        for (int j = 0; j < 5; ++j) {
            printf_s("%d\t",original_matrix[i][j]);
        }
        puts("");
    }
    puts_lines();
}
void sorted_matrix(void){
    int fill_sorted=0,t;
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            sorted[fill_sorted]=original_matrix[i][j];
            fill_sorted++;
        }
    }
    puts("Sorting...");
    for(int i=0;i<25-1;i++){//这里冒泡排序，先排前n-1轮
        for(int k=0;k<25-1-i;k++){//这里排n-1-i，排没有排过的
            if(sorted[k]>sorted[k+1]){//如果前一项大于后一项，交换
                t=sorted[k];sorted[k]=sorted[k+1];sorted[k+1]=t;//交换前后项
            }
        }
    }
    puts_lines();
    printf_s("[");//输出结果,以数组的模式
    for(int i=0;i<25;i++){
        printf_s("%d",sorted[i]);
        if(i==24)printf_s("]\n");
        else printf_s(",");
    }
    puts_lines();
}
void fill_replaced_matrix_corners_and_center(){
    replaced_matrix[2][2]=sorted[24];
    replaced_matrix[0][0]=sorted[0];
    replaced_matrix[0][4]=sorted[1];
    replaced_matrix[4][0]=sorted[2];
    replaced_matrix[4][4]=sorted[3];
}
void fill_replaced_matrix_rest_randomly(){

}
void initiate_random_trans(){
    srand((unsigned)time(NULL));
    for (int i = 0; i < 20; ++i) {
      random20[i].random=rand()%100+1;
      random20[i].point_sorted=&sorted[i+4];
    }
    int temp_random,*temp_point,fill_random_count=0;
    for(int i=0;i<20-1;i++){//这里冒泡排序，先排前n-1轮
        for(int k=0;k<20-1-i;k++){//这里排n-1-i，排没有排过的
            if(random20[k].random>random20[k+1].random){//如果前一项大于后一项，交换
                temp_random=random20[k].random;random20[k].random=random20[k+1].random;random20[k+1].random=temp_random;//交换前后项值
                temp_point=random20[k].point_sorted;random20[k].point_sorted=random20[k+1].point_sorted;random20[k+1].point_sorted=temp_point;//交换指针
            }
        }
    }
    for (int j = 0; j < 5; ++j) {
        for (int i = 0; i < 5; ++i) {
            if((i==0 &&j==0)||(i==2 &&j==2)||(i==0&&j==4)||(i==4&&j==4)||(i==4&&j==0))continue;//前面赋值过了，跳过
            else {
                replaced_matrix[i][j]=*random20[fill_random_count].point_sorted;
                fill_random_count++;
            }
        }
    }
    puts("Replaced:");
    puts_lines();
    for(int i=0;i<5;i++){
        for (int j = 0; j < 5; ++j) {
            printf_s("%d\t",replaced_matrix[i][j]);
        }
        puts("");
    }
    puts_lines();
}
int main(void){
   puts("This is a program that get the biggest number from a 5x5 matrix and replace it to the center, then surround the 4 fewest at the corners.");
   initiate_matrix();
   sorted_matrix();
   fill_replaced_matrix_corners_and_center();
   initiate_random_trans();
   fill_replaced_matrix_rest_randomly();
   return 0;
}

