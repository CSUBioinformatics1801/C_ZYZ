#include <stdio.h>
#include <assert.h>
#include <string.h>
struct str_store{
    char this_is_a_string[30];
}all_strings_n[20];
char *point_to_all_strings[20];
int spilt_strings_and_fill_all_strings(char *point_temp_store){//好麻烦，python里直接有现成的函数
    assert(point_temp_store!=NULL);
    int fill_all_strings_n_counter=0,fill_each_string=0;
    while (*point_temp_store){
        if(*point_temp_store==','){//split
            all_strings_n[fill_all_strings_n_counter].this_is_a_string[fill_each_string+1]='\0';//make stop
            fill_all_strings_n_counter++;//to next b1 string
            fill_each_string=0;//return and count again
            point_temp_store++;//skip ','
        }
        all_strings_n[fill_all_strings_n_counter].this_is_a_string[fill_each_string]=*point_temp_store;
        fill_each_string++;//next a2 string
        point_temp_store++;//next temp string
    }
    if(*point_temp_store!=',')all_strings_n[fill_all_strings_n_counter].this_is_a_string[fill_all_strings_n_counter+1]='\0';//last one
    return fill_all_strings_n_counter+1;
}
void sorting(int string_number){
    char *temp;
    for (int j = 0; j < string_number; ++j) {
        point_to_all_strings[j]=all_strings_n[j].this_is_a_string;
    }
    for(int i=0;i<string_number-1;i++){//这里冒泡排序，先排前n-1轮
        for(int k=0;k<string_number-1-i;k++){//这里排n-1-i，排没有排过的
            if(strcmp(point_to_all_strings[k],point_to_all_strings[k+1])>0){//如果前一项大于后一项，交换
                temp=point_to_all_strings[k];
                point_to_all_strings[k]=point_to_all_strings[k+1];
                point_to_all_strings[k+1]=temp;//交换前后项
            }
        }
    }
}
int main(void) {
    puts("This is a program that sort your strings from Stdin:\nPlease input some strings(split them by ',')");
    char temp_store[600];gets_s(temp_store,600-1);char *point_temp_store=temp_store;
    int string_number=spilt_strings_and_fill_all_strings(point_temp_store);
    assert(string_number!=0);
    for (int i = 0; i < string_number; ++i) {
        printf_s("%s", all_strings_n[i].this_is_a_string);
        if(i!=string_number-1)printf_s(",");
    }
    printf_s("\nThere are %d strings.\n",string_number);
    sorting(string_number);
    puts("==========================\nSorted:");
    for (int j = 0; j < string_number; ++j) {
        printf_s("%s",point_to_all_strings[j]);
        if(j!=string_number-1)printf_s(",");
    }
    return 0;
}
