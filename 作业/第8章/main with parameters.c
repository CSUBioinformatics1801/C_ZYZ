#include <stdio.h>
int main(int argc,char*argv[]){
    while (argc-->1){
        printf_s("%s,",*++argv);//*(argv+i),able to plus itself
    }
    return 0;
}

