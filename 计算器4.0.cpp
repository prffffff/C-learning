#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>


//创建符号链栈 
typedef struct  FUHAOLIST{
    char fuhao;
    int i;
    struct FUHAOLIST *next;
}fuhaolist,*LPNODE;

//创建符号栈链栈底 
LPNODE FUHAOBASE()
{
	LPNODE fuhaobase = (LPNODE)malloc(sizeof(fuhaolist));//动态分配栈底内存 
	if (fuhaobase == NULL)
		return NULL; 
	fuhaobase->next  = NULL;
	return fuhaobase;
}


//打印符号栈 
void printfuhao(LPNODE fuhaobase)
{
	LPNODE pmove = fuhaobase->next ;
	while (pmove != NULL)
	{
		printf("%c  %d",pmove->fuhao,pmove->i  );
		pmove = pmove->next ;//使得指针不断指向next输出链表 
	}
	printf("\n"); 
}

//符号入栈 
void pushfuhao(LPNODE fuhaobase,char c)
{
	LPNODE newNode = (LPNODE)malloc(sizeof(fuhaolist)) ;
	if(newNode == NULL)
	{
	   return;
    }
    newNode->fuhao = c;
    //给不同算符赋值，优先级低的数值也低 
    if (c == '+'||c == '-')
    {
    	newNode->i =0; 
	}
	else if (c == '*'|| c =='/')
	{
		newNode->i = 1;
	}
	newNode->next =fuhaobase->next ;//先接后断 
	fuhaobase->next  = newNode; 
    
 }
 
 
 //符号出栈 
char popfuhao(LPNODE fuhaobase)
{
    LPNODE newnode = fuhaobase->next ;//这里的newnode其实就是栈顶 
	if(newnode == NULL)//判断栈是否为空 
	{
		printf("程序出现错误");
		exit(1);
	}
	char  c = newnode->fuhao ;//符号出栈 
	//释放该结点 
	fuhaobase->next = newnode->next  ;
	free(newnode);
	return c;
	
 } 
  
 
 //释放符号栈 
void deletefuhao(LPNODE fuhaobase) 
{
	LPNODE p = fuhaobase->next ;
	while ( p != NULL)
	{
		LPNODE temp = p;
		p = p->next;
		free(temp);
	}
	fuhaobase->next  = NULL;//释放完所有节点后，将节点指向NULL 
}

//创建操作数链栈 
typedef struct  DATALIST{
    int data;
    struct DATALIST *next;
}datalist,*lpnode;

//创建操作数链栈栈底 
lpnode DATABASE()
{
	lpnode database = (lpnode)malloc(sizeof(datalist));//给栈底动态分配内存 
	if (database == NULL)
		return NULL; 
	database->next =NULL;
	return database;
}


//打印操作数栈 
void printdata(lpnode database)
{
	lpnode pmove = database->next  ;
	while (pmove != NULL)
	{
		printf(" %d",pmove->data  );
		pmove = pmove->next ;
	}
	printf("\n"); 
}

//操作数入栈 
void pushdata(lpnode database,int i)
{
	lpnode newNode = (lpnode)malloc(sizeof(datalist));
	if(newNode == NULL)
	{
	   return;
    }
    newNode->data = i;
    //先接后断 
    newNode->next = database->next  ;
	database->next  = newNode; 
    
 }
 
 
 //操作数出栈 
int popdata(lpnode database)
{
    lpnode newnode = database->next ;//这里的newnode也是栈顶 
	if(newnode == NULL)
	{
		printf("程序出现错误");
		exit(1);
	}
	int i = newnode->data  ;
	//释放该结点 
	database->next  = newnode->next  ;
	free(newnode);
	return i;
	
 } 
  
 
 //释放操作数栈 
void deletedata(lpnode database) 
{
	lpnode p = database->next  ;
	while ( p != NULL)
	{
		lpnode temp = p;
		p = p->next;
		free(temp);
	}
	database->next   = NULL;//释放完所有节点后，将节点指向NULL 
}

 //操作函数
int operate(LPNODE fuhaobase,lpnode database) 
{
	int b = popdata(database);
	int a = popdata(database);
	char c =popfuhao(fuhaobase);
	int result ;
	//实现算式运算功能 
	if (c == '+')
	{
		result = a+b;
	}
	else if(c == '-')
	{
		result = a-b;
	}
	else if(c == '*')
	{
		result = a*b;
	}
	else if(c == '/')
	{
		if(b == 0)
		{
			printf("抱歉，除数不能为0");
			exit(1);
		 } 
		else 
		{
			result = a/b;
		}
	}
	else
	{
		printf("程序出现错误");
		exit(1);
	}
	return result;
}

//符号栈判断函数
void judge(LPNODE fuhaobase,lpnode database,char c)
{
	LPNODE top = fuhaobase->next;
    LPNODE newnode = (LPNODE)malloc(sizeof(fuhaolist)); // 分配新节点内存 
    if (newnode == NULL) {
        printf("内存分配失败\n");
        exit(1);
    }
    if (c >= '0' && c <= '9') {
        int num = c - '0';
        pushdata(database, num);
    }
	else
	{
		if(top == NULL )
		{
			if(c == '+' || c =='-')
			{
				newnode->i = 0;
				newnode->fuhao = c;
			}
			else if(c == '*' || c == '/')
			{
				newnode->i =1;
				newnode->fuhao = c;
			}
			pushfuhao(fuhaobase,c);
		}
		else
		{
			if(c ==')' ||(newnode->i >top->i ) ||c == '(')
			{
				pushfuhao(fuhaobase,c);
			}
			else
			{
				int result = operate(fuhaobase,database);
				pushdata(database,result);
				judge(fuhaobase,database,c);//递归调用judge函数循环判断符号 
			}
		}
	}
}

 
//主函数
int main()
{
	LPNODE fuhaobase = FUHAOBASE();
	lpnode database = DATABASE();
	char exp[20];
	int result = 0;
	printf("请输入一个算式：");
	//printf("1");
	scanf("%s",exp);
	
	//实现遍历字符并区分算符和操作数 
	int cnt = 0;
	while (exp[cnt] != '\0')
	{
		if (exp[cnt] >= '0' && exp[cnt] <='9')
		{
			//printf("2");
			int num = exp[cnt] - '0';//利用ASC码实现char到int的转换 
			pushdata(database,num);
			cnt ++;
		}
		else
		{
			//printf("3");
			judge(fuhaobase,database,exp[cnt]);
			cnt ++;
		}
	}
	//printf("4");
	//printfuhao(fuhaobase);
	//printdata(database);
	
	//入栈完毕后逐个出栈运算 
	while (fuhaobase->next  != NULL)
	{
		result = operate(fuhaobase,database);
	//printfuhao(fuhaobase);
    //printdata(database);
     //	printf("\n");
	}
	printf("该算式结果为：%d\n",result);
	
	//释放链表内存 
	deletefuhao(fuhaobase);
	deletedata(database);
	return 0;
 } 
