#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>


//����������ջ 
typedef struct  FUHAOLIST{
    char fuhao;
    int i;
    struct FUHAOLIST *next;
}fuhaolist,*LPNODE;

//��������ջ��ջ�� 
LPNODE FUHAOBASE()
{
	LPNODE fuhaobase = (LPNODE)malloc(sizeof(fuhaolist));//��̬����ջ���ڴ� 
	if (fuhaobase == NULL)
		return NULL; 
	fuhaobase->next  = NULL;
	return fuhaobase;
}


//��ӡ����ջ 
void printfuhao(LPNODE fuhaobase)
{
	LPNODE pmove = fuhaobase->next ;
	while (pmove != NULL)
	{
		printf("%c  %d",pmove->fuhao,pmove->i  );
		pmove = pmove->next ;//ʹ��ָ�벻��ָ��next������� 
	}
	printf("\n"); 
}

//������ջ 
void pushfuhao(LPNODE fuhaobase,char c)
{
	LPNODE newNode = (LPNODE)malloc(sizeof(fuhaolist)) ;
	if(newNode == NULL)
	{
	   return;
    }
    newNode->fuhao = c;
    //����ͬ�����ֵ�����ȼ��͵���ֵҲ�� 
    if (c == '+'||c == '-')
    {
    	newNode->i =0; 
	}
	else if (c == '*'|| c =='/')
	{
		newNode->i = 1;
	}
	newNode->next =fuhaobase->next ;//�ȽӺ�� 
	fuhaobase->next  = newNode; 
    
 }
 
 
 //���ų�ջ 
char popfuhao(LPNODE fuhaobase)
{
    LPNODE newnode = fuhaobase->next ;//�����newnode��ʵ����ջ�� 
	if(newnode == NULL)//�ж�ջ�Ƿ�Ϊ�� 
	{
		printf("������ִ���");
		exit(1);
	}
	char  c = newnode->fuhao ;//���ų�ջ 
	//�ͷŸý�� 
	fuhaobase->next = newnode->next  ;
	free(newnode);
	return c;
	
 } 
  
 
 //�ͷŷ���ջ 
void deletefuhao(LPNODE fuhaobase) 
{
	LPNODE p = fuhaobase->next ;
	while ( p != NULL)
	{
		LPNODE temp = p;
		p = p->next;
		free(temp);
	}
	fuhaobase->next  = NULL;//�ͷ������нڵ�󣬽��ڵ�ָ��NULL 
}

//������������ջ 
typedef struct  DATALIST{
    int data;
    struct DATALIST *next;
}datalist,*lpnode;

//������������ջջ�� 
lpnode DATABASE()
{
	lpnode database = (lpnode)malloc(sizeof(datalist));//��ջ�׶�̬�����ڴ� 
	if (database == NULL)
		return NULL; 
	database->next =NULL;
	return database;
}


//��ӡ������ջ 
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

//��������ջ 
void pushdata(lpnode database,int i)
{
	lpnode newNode = (lpnode)malloc(sizeof(datalist));
	if(newNode == NULL)
	{
	   return;
    }
    newNode->data = i;
    //�ȽӺ�� 
    newNode->next = database->next  ;
	database->next  = newNode; 
    
 }
 
 
 //��������ջ 
int popdata(lpnode database)
{
    lpnode newnode = database->next ;//�����newnodeҲ��ջ�� 
	if(newnode == NULL)
	{
		printf("������ִ���");
		exit(1);
	}
	int i = newnode->data  ;
	//�ͷŸý�� 
	database->next  = newnode->next  ;
	free(newnode);
	return i;
	
 } 
  
 
 //�ͷŲ�����ջ 
void deletedata(lpnode database) 
{
	lpnode p = database->next  ;
	while ( p != NULL)
	{
		lpnode temp = p;
		p = p->next;
		free(temp);
	}
	database->next   = NULL;//�ͷ������нڵ�󣬽��ڵ�ָ��NULL 
}

 //��������
int operate(LPNODE fuhaobase,lpnode database) 
{
	int b = popdata(database);
	int a = popdata(database);
	char c =popfuhao(fuhaobase);
	int result ;
	//ʵ����ʽ���㹦�� 
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
			printf("��Ǹ����������Ϊ0");
			exit(1);
		 } 
		else 
		{
			result = a/b;
		}
	}
	else
	{
		printf("������ִ���");
		exit(1);
	}
	return result;
}

//����ջ�жϺ���
void judge(LPNODE fuhaobase,lpnode database,char c)
{
	LPNODE top = fuhaobase->next;
    LPNODE newnode = (LPNODE)malloc(sizeof(fuhaolist)); // �����½ڵ��ڴ� 
    if (newnode == NULL) {
        printf("�ڴ����ʧ��\n");
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
				judge(fuhaobase,database,c);//�ݹ����judge����ѭ���жϷ��� 
			}
		}
	}
}

 
//������
int main()
{
	LPNODE fuhaobase = FUHAOBASE();
	lpnode database = DATABASE();
	char exp[20];
	int result = 0;
	printf("������һ����ʽ��");
	//printf("1");
	scanf("%s",exp);
	
	//ʵ�ֱ����ַ�����������Ͳ����� 
	int cnt = 0;
	while (exp[cnt] != '\0')
	{
		if (exp[cnt] >= '0' && exp[cnt] <='9')
		{
			//printf("2");
			int num = exp[cnt] - '0';//����ASC��ʵ��char��int��ת�� 
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
	
	//��ջ��Ϻ������ջ���� 
	while (fuhaobase->next  != NULL)
	{
		result = operate(fuhaobase,database);
	//printfuhao(fuhaobase);
    //printdata(database);
     //	printf("\n");
	}
	printf("����ʽ���Ϊ��%d\n",result);
	
	//�ͷ������ڴ� 
	deletefuhao(fuhaobase);
	deletedata(database);
	return 0;
 } 
