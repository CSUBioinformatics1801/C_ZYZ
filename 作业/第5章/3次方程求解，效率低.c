#include <stdio.h>
#include <math.h>
#include <conio.h>
float a,b,c,d; //定义外部变量，使全局可以调用
float f(float x) //x函数
{
   float y;
   y=a*x*x*x+b*x*x+c*x+d;
   return y;
}

float xpoint(float x1,float x2) //求弦与x轴交点坐标
{
    float y;
    y=(x1*f(x2)-x2*f(x1))/(f(x2)-f(x1));
    return y;
}

float root(float x1,float x2) //求根函数
{
    float x,y,y1;
    y1=f(x1);//y1为x1纵坐标
    do{
        x=xpoint(x1,x2); //求x1与x2之间弦与x轴交点赋值于x
        y=f(x); //代入方程中求得y
        if(y*y1>0) //判断y与y1是否同号
        {
           x1=x;
          y1=y;
           }
        else
        x2=x;
        }
    while(fabsf(y)>=0.00001); //设定精度
    return(x);
}

int main() //主函数
{
    float x1,x2,f1,f2,x;
    printf_s("ax^3+bx^2+cx+d=0\n");
    printf_s("a b c d input\n");
    scanf_s("%f,%f,%f,%f",&a,&b,&c,&d);//获取abcd值并赋值
    do{
        printf_s("input x1 x2，blank:\n");
        scanf_s("%f %f",&x1,&x2);
        f1=f(x1);
        f2=f(x2);
        if(f1*f2>=0)
        printf_s("x1x2no root，input again\n");
        }
    while(f1*f2>=0);//do...while函数为了得到x1与x2的函数值为异号，这样x1 x2中才有根
    x=root(x1,x2); //将x1 x2送到求根函数中返回值赋到x中
    printf_s("one of:%g\n",x);
    return 0;
}
