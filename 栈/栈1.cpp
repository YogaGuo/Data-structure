#include<stdio.h>
#include<stdlib.h>
#define STACKinitsize  100
#define STACKincrement 10
typedef struct{
	int *base;    //在栈构造之前和销毁之后，base只为null
	int *top;     //栈顶指针
	int stacksize;  //当前已分配的储存空间，以元素为单位
}SqStack;
int InitStack(SqStack &S)   //构造一个空栈S
{
	S.base=(int*)malloc(STACKinitsize*sizeof(int));
	if(!S.base)   
		exit(0);    //存储分配失败
	S.top=S.base;
	S.stacksize=STACKinitsize;
	return 1;
}
void Create(SqStack &S)    //创建栈
{
	int n,i;
	printf("请输入元素个数：");
	scanf("%d",&n);
	printf("请输入元素：");
    while(n--)
	{ 
         scanf("%d",&i);
		 *S.top++=i;
	}
	printf("栈创建成功!");
}
int Pop(SqStack &S,int &e)      //若栈不空，则删除S的栈顶元素，用e返回其值
{
	
	if(S.top==S.base)
		return 0;
	e=*(--S.top);
	return 1;
}
int Push(SqStack &S,int e)    //插入元素e为新的栈顶元素
{
	if(S.top-S.base>=S.stacksize)   //栈满，则追加存储空间
	{
		S.base=(int*)realloc(S.base,S.stacksize+STACKincrement*sizeof(int));
		if(!S.base)
			exit(0);   //存储分配失败
		S.top=S.base+S.stacksize;
		S.stacksize+=STACKincrement;
	}
	      
	*S.top++=e;
	return 1;
}
int StackEmpty(SqStack &S)     
{
	if(S.top==S.base)  //栈空，返回1，否则返回0
		return 1;
	else
		return 0;
}
void PrintStack(SqStack &S)   //打印栈元素
{
	
	int *p;
	p=S.base;  //指针p指向S栈的栈底
	if(S.top==S.base)     //栈顶等于栈底，栈为空栈
		printf("空栈!!!，无法输出");
	else
	{
	 while( p!=S.top)   //指针p没有指向栈底
	 { 
	 printf("%d",*p);   //输出p所指向的元素
	 p++;    //p向上加1
	 }
	}
}
int OperatMenu()
{ 
	int i;
	printf("-------请输入以下操作选项----------\n");
	printf("-0:退出\n"); printf("-1:插入元素\n");
	printf("-2:删除元素\n"); printf("-3:判空\n");
	printf("-4:创建栈\n");
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
				    printf("请输入要插入的元素：");
					scanf("%d",&e);
                    if(Push(S,e))
					{	printf("新的栈为：");
				    	printf("\n");
			            PrintStack(S);
					}
			        else
			        	printf("无法插入");
			      break; 
		     case 2:
				      
                    if(Pop(S,e))
					{
						printf("出栈的元素为%d",e);
						printf("\n");
				       printf("新的栈为:");
				       PrintStack(S);
					}
			        else
				       printf("无法删除!");
			       break;
		     case 3:
			        if(StackEmpty(S))
				        printf("栈为空");
			        else
				        printf("栈不为空");
			       break;
		     case 4:
                   InitStack(S);
			        Create(S);
					printf("\n");
					printf("新栈为：");
			        PrintStack(S);
			       break;
		     default:
			        printf("输入有误，请重新输入:");
			       break;
		}
	}
}

			   



	
