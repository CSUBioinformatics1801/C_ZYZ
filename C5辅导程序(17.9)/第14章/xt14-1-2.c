    #include "stdio.h"
    #include "process.h"
    #define SIZE 9
    typedef struct tax_st                         //税率表结构体声明 
      {long left;                                   //区间上限 
       long right;                                  //区间下限 
       int tax;                                    //税率 
       long deduct;                               //速算扣除数 
    } TAX_LIST;

    void disp(TAX_LIST tax_list[])
      {double salary,s,tax,ff;                          //定义变量 
        int i;
        printf("请输入税前扣除数：");           //提示用户税前扣除数 
        scanf("%lf",&ff);
        printf("请输入月收入：");                //提示用户输入入 
        scanf("%lf",&salary);                         //接收用户输入的月收入 
        if (salary>=0)                               //月收入大于0，开始计算 
          { s=salary-ff;                            //计算全月应纳税所得额 
            if (s<=0)
                tax=0;                            //小于0，税额为0 
            else
              {for(i=0;i<8;i++)                   //根据数组内容计算税额 
                  {if (s<tax_list[i].right&&s>=tax_list[i].left)
                      tax=s*tax_list[i].tax/100.-tax_list[i].deduct;
                  }
               if (s>=tax_list[8].left)
                   tax=s*tax_list[8].tax/100.-tax_list[8].deduct;
              }
          }
        printf("应纳个人所得税额是%.2lf\n ",tax);
    }

    int main()
      { FILE *fp;                                      //定义文件指针 
        TAX_LIST tax_list [SIZE];                      //定义结构体数组 
        if ((fp=fopen("d:\\TAX.din","rb"))==NULL)      //想打开文件TAX.din                                          
          {printf("\ncannot open file\n");    
		   exit(1);                                    //打开文件失败，退出 
          }
        if (fread(tax_list,sizeof(TAX_LIST),SIZE,fp)!=SIZE)              //将SIZE个结构体一次读入数据区 
          {printf("file write error\n");
           exit(1);                        //读操作失败，退出 
          }
        disp(tax_list);                      //计算税额 
        fclose(fp) ;                         //关闭文件 
        return 0;
     }
