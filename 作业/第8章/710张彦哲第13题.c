#include <stdio.h>
#include <math.h>
#include <assert.h>
int main(void){
    puts("This is a program that do the integrals.\nPlease input range like [a,b]:");
    double intergral_sin=0,intergral_cos=0,intergral_ex=0,range_min,range_max;
    scanf_s("[%lf,%lf]",&range_min,&range_max);
    assert(fabs(range_max-range_min)>0.001 && fabs(range_max-range_min)<20.0);//min units:0.001
    if(range_max<range_min){
        double temp_max=range_min;
        range_min=range_max;
        range_max=temp_max;
    }
    double count_subunit=range_min;
    while(count_subunit<range_max){//huge computation
        intergral_cos+=cos(count_subunit);
        intergral_sin+=sin(count_subunit);
        intergral_ex+=exp(count_subunit);
        count_subunit+=0.001;
    }
    printf_s("sin=%lf,cos=%lf,ex=%lf",intergral_sin,intergral_cos,intergral_ex);
}