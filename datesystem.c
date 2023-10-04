#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARINGS

//�������꣬ƽ���·��Լ�һ������������
int run [12]={31,29,31,30,31,30,31,31,30,31,30,31} ;
int ping [12]={31,28,31,30,31,30,31,31,30,31,30,31} ;
char *weekday [15]={"��","һ","��","��","��","��","��"};

//�����������ı߿� 
void boundary()
{
	printf("-----------------------------------------------------\n");
}

//�����������ı߿� 
void title()
{
	int i ;
	printf("\t\t\t�� �� ��\t\t\t\n");
	boundary();
	printf("\n");
	for ( i = 0; i < 7;i ++)
	{
		printf("%s\t",weekday[i]);
	}
	printf("\n");
} 

//�ж������ƽ�겢���������ܺ�
int daysum(int year,int month)
{
	int i,sum=0;//�����ʼ����
	for (i = 1900;i < year;i ++) //1900 1��1��Ϊ����һ��������ݵ����� 
	{
		//�ж������껹��ƽ�� 
		if (i % 4 == 0)
		{
			sum +=366;
		}
		else
		{
			sum +=365;
		}
	 } 
	 for (i = 0; i < month - 1; i ++) //�����·ݵ����� 
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
	 //printf("\n%d",sum);//���������Ƿ���ȷ 
	 return sum;
 } 
 
 //��ӡ����
int calendar(int sum,int month,int year,int day)
 {
 	int i,x,y = 0;//x�������ϸ�������������
	x = sum % 7;
	y = 7 - x;
	for (i = 0;i < x ;i ++)
	{
		printf("\t");
	}
	//��ӡ��������
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
			if ( i == y ||(i - y )% 7 ==0)//ÿ�ܻ��� 
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
				if ( i == y ||(i - y )% 7 ==0)//ÿ�ܻ��� 
			{
				printf("\n");
			}
		}
	printf("\n");
	}
	
 	
  } 


 //������ 
int main()
{
	int year,month,day;
	printf("�������� �� �գ�");
	//ʵ���ظ����� 
	for (;;)
	{
        scanf("%d %d %d",&year,&month,&day) ;
		//printf("%d",year);
		//�ж��������ݵ����� 
		if (year <1900 || year >19000)
		{
			printf("��������ȷ����ݣ�1900~19000��");
		}
		else if(month < 1||month > 12)
		{ 
			printf("��������ȷ���·ݣ�1~12��");
		}
		else if(year % 4 == 0 &&day > run[month])
		{
			printf("��������ȷ������");
		}
		else if(year % 4 != 0 && day >ping[month])
		{
			printf("��������ȷ������");
		}
		else if(day < 0)
		{
			printf("��������ȷ������");
		}
		else
		{
		    title();
	        int sum = daysum(year,month);
	        calendar(sum,month,year,day);
	        boundary();
		}
		printf("\n�������� �� �գ�");
    } 
	    
	
	return 0;
}
