#include<stdio.h>
#include<stdlib.h>
#define STACKinitsize  100
#define STACKincrement 10
typedef struct{
	int *base;    //��ջ����֮ǰ������֮��baseֻΪnull
	int *top;     //ջ��ָ��
	int stacksize;  //��ǰ�ѷ���Ĵ���ռ䣬��Ԫ��Ϊ��λ
}SqStack;
int InitStack(SqStack &S)   //����һ����ջS
{
	S.base=(int*)malloc(STACKinitsize*sizeof(int));
	if(!S.base)   
		exit(0);    //�洢����ʧ��
	S.top=S.base;
	S.stacksize=STACKinitsize;
	return 1;
}
void Create(SqStack &S)    //����ջ
{
	int n,i;
	printf("������Ԫ�ظ�����");
	scanf("%d",&n);
	printf("������Ԫ�أ�");
    while(n--)
	{ 
         scanf("%d",&i);
		 *S.top++=i;
	}
	printf("ջ�����ɹ�!");
}
int Pop(SqStack &S,int &e)      //��ջ���գ���ɾ��S��ջ��Ԫ�أ���e������ֵ
{
	
	if(S.top==S.base)
		return 0;
	e=*(--S.top);
	return 1;
}
int Push(SqStack &S,int e)    //����Ԫ��eΪ�µ�ջ��Ԫ��
{
	if(S.top-S.base>=S.stacksize)   //ջ������׷�Ӵ洢�ռ�
	{
		S.base=(int*)realloc(S.base,S.stacksize+STACKincrement*sizeof(int));
		if(!S.base)
			exit(0);   //�洢����ʧ��
		S.top=S.base+S.stacksize;
		S.stacksize+=STACKincrement;
	}
	      
	*S.top++=e;
	return 1;
}
int StackEmpty(SqStack &S)     
{
	if(S.top==S.base)  //ջ�գ�����1�����򷵻�0
		return 1;
	else
		return 0;
}
void PrintStack(SqStack &S)   //��ӡջԪ��
{
	
	int *p;
	p=S.base;  //ָ��pָ��Sջ��ջ��
	if(S.top==S.base)     //ջ������ջ�ף�ջΪ��ջ
		printf("��ջ!!!���޷����");
	else
	{
	 while( p!=S.top)   //ָ��pû��ָ��ջ��
	 { 
	 printf("%d",*p);   //���p��ָ���Ԫ��
	 p++;    //p���ϼ�1
	 }
	}
}
int OperatMenu()
{ 
	int i;
	printf("-------���������²���ѡ��----------\n");
	printf("-0:�˳�\n"); printf("-1:����Ԫ��\n");
	printf("-2:ɾ��Ԫ��\n"); printf("-3:�п�\n");
	printf("-4:����ջ\n");
	scanf("%d",&i);
      return i;
}
void main()
{
	SqStack S;
	int e;
	int k,j;
	while(1)
	{
		k=OperatMenu();
		switch(k)
		{
	       	case 0:
		        	exit(0);
			      break;
		    case 1:
				    printf("������Ҫ�����Ԫ�أ�");
					scanf("%d",&e);
                    if(Push(S,e))
					{	printf("�µ�ջΪ��");
				    	printf("\n");
			            PrintStack(S);
					}
			        else
			        	printf("�޷�����");
			      break; 
		     case 2:
				      
                    if(Pop(S,e))
					{
						printf("��ջ��Ԫ��Ϊ%d",e);
						printf("\n");
				       printf("�µ�ջΪ:");
				       PrintStack(S);
					}
			        else
				       printf("�޷�ɾ��!");
			       break;
		     case 3:
			        if(StackEmpty(S))
				        printf("ջΪ��");
			        else
				        printf("ջ��Ϊ��");
			       break;
		     case 4:
                   InitStack(S);
			        Create(S);
					printf("\n");
					printf("��ջΪ��");
			        PrintStack(S);
			       break;
		     default:
			        printf("������������������:");
			       break;
		}
	}
}

			   



	
