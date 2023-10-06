#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>


//创建链表 
typedef struct  list{
	char name[100];
	char phone[100];//国内手机号有11位，int类型最大只有10位 
	char relationship[100];
	struct list *next;
}List,*LPNODE,*LPLIST;

//创建链表表头 
LPNODE createHead()
{
	LPNODE headNode = (LPNODE)malloc(sizeof(List));
	if (headNode == NULL)
		return NULL; 
	strcpy_s(headNode->name,sizeof(headNode->name )  ,"");
	strcpy_s(headNode->phone ,sizeof(headNode->phone ),"");
	strcpy_s(headNode->relationship,sizeof(headNode->relationship) ,"");
	headNode->next = NULL;
	return headNode;
}
//创建节点
LPNODE NODE(LPLIST list)
{
	LPNODE newnode;
	newnode = list->next ;
	newnode->next =NULL;
	return newnode;
 } 

//打印链表 
void printList(LPLIST list)
{
	LPNODE pmove = list->next ;
	while (pmove != NULL)
	{
		printf("%s\t%s\t%s\n",pmove->name ,pmove->phone,pmove->relationship );
		pmove = pmove->next ;
	}
}

//增加函数（插入节点） 
void add(LPLIST list)
{
	//把联系人的信息变成一个节点
	bool flag = true; // 添加标志位
	LPNODE newNode = list;
	if(newNode == NULL)
	{
	   return;
    }
	while (flag == true) 
	{
	  LPNODE newNode = (LPNODE)malloc(sizeof(List));
	  printf("请输入姓名，手机号，关系：");
	  scanf("%s %s %s",newNode->name ,newNode->phone ,newNode->relationship );
	  newNode->next = list->next ;
	  list->next = newNode; 
      // 用户输入特定字符或数字时跳出循环
      printf("是否继续添加联系人？（Y/N）");
      char choice;
      getchar();
      scanf("%c", &choice);
      if (choice == 'N' || choice == 'n' ) 
	  {
        flag = false;
      }
    }
    
 } 
 
 //释放内存函数
void deletelist(LPLIST list) 
{
	LPNODE p = list->next ;
	while ( p != NULL)
	{
		LPNODE temp = p;
		p = p->next;
		free(temp);
	}
	list->next = NULL;//释放完所有节点后，将节点指向NULL 
}
//打印信息 
/*void printlist(LPLIST list,LPNODE pmove)
{
	
	printf("姓名\t手机号\t关系\n");
	printf("%s\t%s\t%s",pmove->name  ,pmove->phone ,pmove->relationship );
 } */
 
 //查询函数
LPNODE research(LPLIST list,const char *posname)
{
	LPNODE pmove = list->next;
	while (pmove != NULL && strcmp(pmove->name,posname) != 0)
	{
		pmove = pmove->next;
		//int i = 0;
		//printf("%d",i);
		//i++;
	}
	if (pmove ==NULL)
	{
		printf("抱歉，没有查到关于此信息的联系人");
	}
	else
	{
		printf("姓名\t手机号\t关系\n");
	    printf("%s\t%s\t%s\n",pmove->name ,pmove->phone,pmove->relationship );
	}
 } 
//修改函数
void modify(LPLIST list,const char *posname)
{
	LPNODE preNode = list;
	LPNODE pmove = list->next;
	while (pmove != NULL && strcmp(pmove->name,posname) != 0)
	{
		pmove = pmove->next;
	}
	if (pmove ==NULL)
	{
		printf("抱歉，没有查到关于此信息的联系人");
	}
	else
	{
		printf("姓名\t手机号\t关系\n");
	    printf("%s\t%s\t%s\n",pmove->name ,pmove->phone,pmove->relationship );
	}
	printf("请输入需要修改的信息：\n"); 
	printf("1、姓名\n");
	printf("2、手机号\n");
	printf("3、关系\n");
	int i = 0;
	scanf("%d",&i) ;
	if (i == 1)
	{
		printf("请输入修改后的姓名：");
		scanf("%s",pmove->name );
	}
	else if (i == 2)
	{
		printf("请输入修改后的手机号：");
		scanf("%s",pmove->phone );
	}
	else if (i == 3)
	{
		printf("请输入修改后的关系：");
		scanf("%s",pmove->relationship );
	}
	else 
	{
		printf("请输入正确信息");
		return;
	}
	printf("修改成功！");
 } 
 
 //根据姓名删除 
void deletebyname(LPLIST list,const char *posname)
{
	LPNODE preNode = list;
	LPNODE posNode = list->next;
	while(posNode != NULL && strcmp(posNode->name , posname) !=0)//若寻找到匹配姓名，则输出0 
	{
		preNode = posNode;
		posNode = posNode->next;
	}
	if (posNode == NULL)
	{
		printf("抱歉，没有找到您要删除的信息");
		return;
	}
	else
	{
		preNode->next = posNode->next;
		free(posNode);
		posNode = NULL;
		printf("删除成功\n");
	}
 } 
 
 //根据手机号删除
void deletebyphone(LPLIST list,const char *phone)
{
	LPNODE preNode = list;
	LPNODE posNode = list->next;
	while(posNode != NULL&&strcmp(posNode->name ,phone))//若寻找到匹配姓名，则输出0 
	{
		preNode = posNode;
		posNode = posNode->next;
	}
	if (posNode == NULL)
	{
		printf("抱歉，没有找到您要删除的信息");
		return;
	}
	else
	{
		preNode->next = posNode->next;
		free(posNode);
		posNode = NULL;
		printf("删除成功\n");
	}
 }   

//根据关系删除
 void deletebyrelationship(LPLIST list,const char* posrelationship)
{
	LPNODE preNode = list;
	LPNODE posNode = list->next;
	while(posNode != NULL&&strcmp(posNode->relationship ,posrelationship)!=0)//若寻找到匹配姓名，则输出0 
	{
		preNode = posNode;
		posNode = posNode->next;
	}
	if (posNode == NULL)
	{
		printf("抱歉，没有找到您要删除的信息\n");
		return;
	}
	else
	{
		preNode->next = posNode->next;
		free(posNode);
		posNode = NULL;
		printf("删除成功\n");
	}
 } 
//菜单页面
void menu()
{
	printf("\n\t\t\t通讯录菜单\t\t\t\n");
	printf("--------------------------------------------------------");
	printf("\n\t1、增加联系人");
	printf("\t\t2、删除联系人");
	printf("\n\t3、查询联系人");
	printf("\t\t4、修改联系人");
	printf("\n--------------------------------------------------------\n");
 } 
 
 
 
 //主函数
 int main()
 {
 	// printf("1");
 	LPLIST list = createHead();
 	 //printf("2");
 	if (list == NULL)
 	{
 		printf("链表为空！");
 		printf("3");
		return -1; 
	}
	//printf("4");
 	//printf("5");
 	int op;
    //printf("6");
	while(true)
	{
 	  menu();
	  printf("请输入你想选择的功能（用数字表示）");
	  scanf("%d",&op);
	  getchar();
	  switch (op)
	{
		case 1://增加联系人 
		
		add(list );
		
		printf("添加成功！\n");
		
		
		//printList(list);
		break;
		case 2://删除联系人 
		printf("请选择输入你要删除的联系人的相关信息：\n");
		printf("1、姓名\n");
		printf("2、手机号\n");
		printf("3、关系\n");
		printf("请输入你要选择的功能：");
		int i ;
		scanf("%d",&i);
        if ( i == 1){
			printf("请输入姓名：");
			char posname[100];
			scanf("%s",posname);
			
			deletebyname(list,posname);}
		else if ( i == 2){
		    getchar(); 
		    printf("请输入手机号：");
		    char phone[100];
		    scanf("%s",phone);
		    
		    deletebyphone(list,phone);}
		else if ( i == 3){
			getchar();
			printf("请输入关系：");
			char relationship[100];
			scanf("%s",relationship);
			
			deletebyrelationship(list,relationship);}
		else{
		    printf("你输入的信息有误！\n");
		    return;
			}
		printList(list);
		break;
		case 3://寻找联系人 
		
		printf("请选择输入你要查询的联系人的相关信息：\n");
		printf("1、姓名\n");
		printf("2、手机号\n");
		printf("3、关系\n");
		printf("请输入你要选择的功能：");
		int a ;
		scanf("%d",&a);
		if ( a == 1){
			getchar();
			printf("请输入姓名：");
			char posname[100];
			scanf("%s",posname);
	        research(list,posname);
			}
		else if ( a == 2){
		    printf("请输入手机号：");
		    char posphone[100];
			scanf("%s",posphone);
		    research(list,posphone);
			}
		else if ( a == 3){
			printf("请输入关系：");
			char posrelationship[100];
			scanf("%s",posrelationship);
		    research(list,posrelationship);
			}
		else{
			printf("你输入的信息有误！\n");
			return;
			}
		break;
		case 4://修改联系人 
		printf("请输入要修改的联系人的姓名：");
		char name[100];
		scanf("%s",name);
		modify(list,name);
		break;
	    default:
		printf("请输入正确的数字！");
		menu();
	}
    }
    deletelist(list);
    
	return 0;
  } 
