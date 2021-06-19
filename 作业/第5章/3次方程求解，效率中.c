#include <stdio.h>
#include <math.h>
int a,b,c,d; //定义外部变量，使全局可以调用，生成函数f(x)就是生成方程y=ax^3+bx^2+cx+d
float f(float x) //x函数
{
    float y;
    y=a*x*x*x+b*x*x+c*x+d;
    return(y);
}
//生成浮点数y 计算式 y=(x1*f(x2)-x2*f(x1))/(f(x2)-f(x1))
float xpoint(float x1,float x2) //求弦与x轴交点坐标
{
    float y;
    y=(x1*f(x2)-x2*f(x1))/(f(x2)-f(x1));
    return y;
}
//求根当y的绝对值小于0.0001时返回x
float root(float x1,float x2){ //求根函数
    float x,y,y1;
    y1=f(x1); //y1为x1纵坐标
    do
    {
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
    while(fabsf(y)>=0.0001); //设定精度
    return(x);
}
int main() //主函数
{
    float x1,x2,f1,f2,x;
    scanf_s("%d,%d,%d,%d",&a,&b,&c,&d);//定义变量，获取abcd常量值
    do
    {
        printf ("input x1,x2:\n");
        scanf_s("%f %f",&x1,&x2); //获取x1,x2值
        f1=f(x1);
        f2=f(x2);
    }
    while(f1*f2>=0);  //do...while函数为了得到x1与x2的函数值为异号，当f1*f2<0时跳出循环,这样x1 x2中才有根
    x=root(x1,x2); //将x1 x2送到求根函数中返回值赋到x中, 得出根
    printf("A root of equalation is %8.4f\n",x);
    return 0;
}
