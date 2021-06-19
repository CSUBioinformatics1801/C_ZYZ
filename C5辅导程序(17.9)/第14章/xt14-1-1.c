    #include "stdio.h"
    #include "process.h"
    #define SIZE 9
    typedef struct tax_st                            //税率表数据结构定义 
      {long left;                                    //区间上限 
        long right;                                  //区间下限 
        int tax;                                     //税率 
        long deduct;                                 //速算扣除数 
      }TAX_LIST;

    void acceptdata(TAX_LIST tax_list[])
    {   int i;
        for (i=0;i<SIZE;i++)                         //接收键盘输入的数据 
        {   printf("Please enter data:");
            scanf("%ld", &tax_list[i].left);         //输入区间上限 
            scanf("%ld", &tax_list[i].right);        //输入区间下限 
            scanf("%d", &tax_list[i].tax);           //输入税率 
            scanf("%ld", &tax_list[i].deduct);       //输入速算扣除数 
        }
    }

    int main()
    {
        FILE *fp;
        TAX_LIST tax_list [SIZE];
        if ((fp=fopen("d:\\TAX.din","wb"))==NULL)   //打开文件TAX.din 
        {   printf("\ncannot open file\n");
            exit(1);                                //打开失败退出 
        }
        acceptdata(tax_list);                      //调用函数从键盘接收数据 
        if (fwrite(tax_list,sizeof(TAX_LIST),SIZE,fp)!=SIZE)
                    //将数组tax_list的结构数据一次写入文件 
        printf("file write error\n");
        fclose(fp);                               //关闭文件 
        return 0;
    }
