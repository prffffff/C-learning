#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>


//�������� 
typedef struct  list{
	char name[100];
	char phone[100];//�����ֻ�����11λ��int�������ֻ��10λ 
	char relationship[100];
	struct list *next;
}List,*LPNODE,*LPLIST;

//���������ͷ 
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
//�����ڵ�
LPNODE NODE(LPLIST list)
{
	LPNODE newnode;
	newnode = list->next ;
	newnode->next =NULL;
	return newnode;
 } 

//��ӡ���� 
void printList(LPLIST list)
{
	LPNODE pmove = list->next ;
	while (pmove != NULL)
	{
		printf("%s\t%s\t%s\n",pmove->name ,pmove->phone,pmove->relationship );
		pmove = pmove->next ;
	}
}

//���Ӻ���������ڵ㣩 
void add(LPLIST list)
{
	//����ϵ�˵���Ϣ���һ���ڵ�
	bool flag = true; // ��ӱ�־λ
	LPNODE newNode = list;
	if(newNode == NULL)
	{
	   return;
    }
	while (flag == true) 
	{
	  LPNODE newNode = (LPNODE)malloc(sizeof(List));
	  printf("�������������ֻ��ţ���ϵ��");
	  scanf("%s %s %s",newNode->name ,newNode->phone ,newNode->relationship );
	  newNode->next = list->next ;
	  list->next = newNode; 
      // �û������ض��ַ�������ʱ����ѭ��
      printf("�Ƿ���������ϵ�ˣ���Y/N��");
      char choice;
      getchar();
      scanf("%c", &choice);
      if (choice == 'N' || choice == 'n' ) 
	  {
        flag = false;
      }
    }
    
 } 
 
 //�ͷ��ڴ溯��
void deletelist(LPLIST list) 
{
	LPNODE p = list->next ;
	while ( p != NULL)
	{
		LPNODE temp = p;
		p = p->next;
		free(temp);
	}
	list->next = NULL;//�ͷ������нڵ�󣬽��ڵ�ָ��NULL 
}
//��ӡ��Ϣ 
/*void printlist(LPLIST list,LPNODE pmove)
{
	
	printf("����\t�ֻ���\t��ϵ\n");
	printf("%s\t%s\t%s",pmove->name  ,pmove->phone ,pmove->relationship );
 } */
 
 //��ѯ����
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
		printf("��Ǹ��û�в鵽���ڴ���Ϣ����ϵ��");
	}
	else
	{
		printf("����\t�ֻ���\t��ϵ\n");
	    printf("%s\t%s\t%s\n",pmove->name ,pmove->phone,pmove->relationship );
	}
 } 
//�޸ĺ���
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
		printf("��Ǹ��û�в鵽���ڴ���Ϣ����ϵ��");
	}
	else
	{
		printf("����\t�ֻ���\t��ϵ\n");
	    printf("%s\t%s\t%s\n",pmove->name ,pmove->phone,pmove->relationship );
	}
	printf("��������Ҫ�޸ĵ���Ϣ��\n"); 
	printf("1������\n");
	printf("2���ֻ���\n");
	printf("3����ϵ\n");
	int i = 0;
	scanf("%d",&i) ;
	if (i == 1)
	{
		printf("�������޸ĺ��������");
		scanf("%s",pmove->name );
	}
	else if (i == 2)
	{
		printf("�������޸ĺ���ֻ��ţ�");
		scanf("%s",pmove->phone );
	}
	else if (i == 3)
	{
		printf("�������޸ĺ�Ĺ�ϵ��");
		scanf("%s",pmove->relationship );
	}
	else 
	{
		printf("��������ȷ��Ϣ");
		return;
	}
	printf("�޸ĳɹ���");
 } 
 
 //��������ɾ�� 
void deletebyname(LPLIST list,const char *posname)
{
	LPNODE preNode = list;
	LPNODE posNode = list->next;
	while(posNode != NULL && strcmp(posNode->name , posname) !=0)//��Ѱ�ҵ�ƥ�������������0 
	{
		preNode = posNode;
		posNode = posNode->next;
	}
	if (posNode == NULL)
	{
		printf("��Ǹ��û���ҵ���Ҫɾ������Ϣ");
		return;
	}
	else
	{
		preNode->next = posNode->next;
		free(posNode);
		posNode = NULL;
		printf("ɾ���ɹ�\n");
	}
 } 
 
 //�����ֻ���ɾ��
void deletebyphone(LPLIST list,const char *phone)
{
	LPNODE preNode = list;
	LPNODE posNode = list->next;
	while(posNode != NULL&&strcmp(posNode->name ,phone))//��Ѱ�ҵ�ƥ�������������0 
	{
		preNode = posNode;
		posNode = posNode->next;
	}
	if (posNode == NULL)
	{
		printf("��Ǹ��û���ҵ���Ҫɾ������Ϣ");
		return;
	}
	else
	{
		preNode->next = posNode->next;
		free(posNode);
		posNode = NULL;
		printf("ɾ���ɹ�\n");
	}
 }   

//���ݹ�ϵɾ��
 void deletebyrelationship(LPLIST list,const char* posrelationship)
{
	LPNODE preNode = list;
	LPNODE posNode = list->next;
	while(posNode != NULL&&strcmp(posNode->relationship ,posrelationship)!=0)//��Ѱ�ҵ�ƥ�������������0 
	{
		preNode = posNode;
		posNode = posNode->next;
	}
	if (posNode == NULL)
	{
		printf("��Ǹ��û���ҵ���Ҫɾ������Ϣ\n");
		return;
	}
	else
	{
		preNode->next = posNode->next;
		free(posNode);
		posNode = NULL;
		printf("ɾ���ɹ�\n");
	}
 } 
//�˵�ҳ��
void menu()
{
	printf("\n\t\t\tͨѶ¼�˵�\t\t\t\n");
	printf("--------------------------------------------------------");
	printf("\n\t1��������ϵ��");
	printf("\t\t2��ɾ����ϵ��");
	printf("\n\t3����ѯ��ϵ��");
	printf("\t\t4���޸���ϵ��");
	printf("\n--------------------------------------------------------\n");
 } 
 
 
 
 //������
 int main()
 {
 	// printf("1");
 	LPLIST list = createHead();
 	 //printf("2");
 	if (list == NULL)
 	{
 		printf("����Ϊ�գ�");
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
	  printf("����������ѡ��Ĺ��ܣ������ֱ�ʾ��");
	  scanf("%d",&op);
	  getchar();
	  switch (op)
	{
		case 1://������ϵ�� 
		
		add(list );
		
		printf("��ӳɹ���\n");
		
		
		//printList(list);
		break;
		case 2://ɾ����ϵ�� 
		printf("��ѡ��������Ҫɾ������ϵ�˵������Ϣ��\n");
		printf("1������\n");
		printf("2���ֻ���\n");
		printf("3����ϵ\n");
		printf("��������Ҫѡ��Ĺ��ܣ�");
		int i ;
		scanf("%d",&i);
        if ( i == 1){
			printf("������������");
			char posname[100];
			scanf("%s",posname);
			
			deletebyname(list,posname);}
		else if ( i == 2){
		    getchar(); 
		    printf("�������ֻ��ţ�");
		    char phone[100];
		    scanf("%s",phone);
		    
		    deletebyphone(list,phone);}
		else if ( i == 3){
			getchar();
			printf("�������ϵ��");
			char relationship[100];
			scanf("%s",relationship);
			
			deletebyrelationship(list,relationship);}
		else{
		    printf("���������Ϣ����\n");
		    return;
			}
		printList(list);
		break;
		case 3://Ѱ����ϵ�� 
		
		printf("��ѡ��������Ҫ��ѯ����ϵ�˵������Ϣ��\n");
		printf("1������\n");
		printf("2���ֻ���\n");
		printf("3����ϵ\n");
		printf("��������Ҫѡ��Ĺ��ܣ�");
		int a ;
		scanf("%d",&a);
		if ( a == 1){
			getchar();
			printf("������������");
			char posname[100];
			scanf("%s",posname);
	        research(list,posname);
			}
		else if ( a == 2){
		    printf("�������ֻ��ţ�");
		    char posphone[100];
			scanf("%s",posphone);
		    research(list,posphone);
			}
		else if ( a == 3){
			printf("�������ϵ��");
			char posrelationship[100];
			scanf("%s",posrelationship);
		    research(list,posrelationship);
			}
		else{
			printf("���������Ϣ����\n");
			return;
			}
		break;
		case 4://�޸���ϵ�� 
		printf("������Ҫ�޸ĵ���ϵ�˵�������");
		char name[100];
		scanf("%s",name);
		modify(list,name);
		break;
	    default:
		printf("��������ȷ�����֣�");
		menu();
	}
    }
    deletelist(list);
    
	return 0;
  } 
