#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARINGS

//设置闰年，平年月份以及一周天数的数组
int run [12]={31,29,31,30,31,30,31,31,30,31,30,31} ;
int ping [12]={31,28,31,30,31,30,31,31,30,31,30,31} ;
char *weekday [15]={"日","一","二","三","四","五","六"};

//设置万年历的边框 
void boundary()
{
	printf("-----------------------------------------------------\n");
}

//设置万年历的边框 
void title()
{
	int i ;
	printf("\t\t\t万 年 历\t\t\t\n");
	boundary();
	printf("\n");
	for ( i = 0; i < 7;i ++)
	{
		printf("%s\t",weekday[i]);
	}
	printf("\n");
} 

//判断闰年和平年并计算天数总和
int daysum(int year,int month)
{
	int i,sum=0;//定义初始变量
	for (i = 1900;i < year;i ++) //1900 1月1日为星期一，加上年份的天数 
	{
		//判断是闰年还是平年 
		if (i % 4 == 0)
		{
			sum +=366;
		}
		else
		{
			sum +=365;
		}
	 } 
	 for (i = 0; i < month - 1; i ++) //加上月份的天数 
	 {
	 	if(year % 4 ==0 )
	 	{
	 		sum +=run[i];
		 }
		else
		{
			sum +=ping[i];
		}
	 }
	 //printf("\n%d",sum);//测试天数是否正确 
	 return sum;
 } 
 
 //打印日历
int calendar(int sum,int month,int year,int day)
 {
 	int i,x,y = 0;//x求日历上个月遗留的天数
	x = sum % 7;
	y = 7 - x;
	for (i = 0;i < x ;i ++)
	{
		printf("\t");
	}
	//打印本月日历
	if (year % 4 == 0)
	{
		for (i = 1; i <= run[month -1] ;i ++) 
		{
			if (i == day)
			{
				printf("*%d\t",i);
			}
			else
			{
				printf("%d\t",i);
			}
			if ( i == y ||(i - y )% 7 ==0)//每周换行 
			{
				printf("\n");
			}
		}
	printf("\n");
	}
	else 
	{
		for (i = 1;i <= ping[month -1];i ++)
		{
			if (i == day)
			{
				printf("*%d\t",i);
			}
			else
			{
				printf("%d\t",i);
			}
				if ( i == y ||(i - y )% 7 ==0)//每周换行 
			{
				printf("\n");
			}
		}
	printf("\n");
	}
	
 	
  } 


 //主代码 
int main()
{
	int year,month,day;
	printf("请输入年 月 日：");
	//实现重复输入 
	for (;;)
	{
        scanf("%d %d %d",&year,&month,&day) ;
		//printf("%d",year);
		//判断输入数据的正误 
		if (year <1900 || year >19000)
		{
			printf("请输入正确的年份（1900~19000）");
		}
		else if(month < 1||month > 12)
		{ 
			printf("请输入正确的月份（1~12）");
		}
		else if(year % 4 == 0 &&day > run[month])
		{
			printf("请输入正确的日期");
		}
		else if(year % 4 != 0 && day >ping[month])
		{
			printf("请输入正确的日期");
		}
		else if(day < 0)
		{
			printf("请输入正确的日期");
		}
		else
		{
		    title();
	        int sum = daysum(year,month);
	        calendar(sum,month,year,day);
	        boundary();
		}
		printf("\n请输入年 月 日：");
    } 
	    
	
	return 0;
}
