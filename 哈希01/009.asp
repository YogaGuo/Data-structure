 
#include<stdio.h>                                                   //将stdio.h包含到本程序来
#include<stdlib.h>                                                  //将stdlib.h包含到本程序来,calloc()需要stdlib.h文件 
#include<string.h>                                                                                             
#define TRUE  1                                                   //对函数结果状态代码进行预定义
#define FALSE 0
#define OK    1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
#define HASHSIZE 30
#define MAXSIZE  20                                                                        //电话薄记录数量
#define MAX_SIZE 20                                                                            //人名的最大长度
typedef char NA[MAX_SIZE];
typedef int Status;

typedef struct
{
    NA name;
    NA tel;
    NA adr;
}Record;

typedef struct
{                                            
    Record *elem;                                                       //数据元素存储基址
    int count;                                                                    //当前数据元素个数
    int size;                                                                     //当前容量
}HashTable;

int Hash1(NA s)
{
    int i,m;
    i=strlen(s);
    m=i % HASHSIZE;
	return m;
}  
Status ChongTu(int p,int &c)
{
	int i,q;
    i=c/2+1;
    while(i<HASHSIZE)
    {
        if(c%2==0)
        {
            c++;
            q=(p+i*i) % HASHSIZE;
				return q;
        }
        else
        { 
			c++;
            q=(p-i*i) % HASHSIZE;
				return q;
        }
    }
    return ERROR;

}
Status InitHash(HashTable &H)
{
    H.elem=(Record *)malloc((HASHSIZE)*sizeof(Record));
	if(!H.elem)
	  exit(OVERFLOW);
    H.size=HASHSIZE;
    H.count=0;
    for(int i=0;i<HASHSIZE;i++)
	{
	  H.elem[i].name[0]='\0';
	  H.elem[i].adr[0]='\0';
	  H.elem[i].tel[0]='\0';
	}
	return OK;

}
Status CreateHash(HashTable &H,Record  a,int  Number)
{
	  int n,c,p;
	  c=0;
	  n=Hash1(a.name);
	  if(H.elem[n].name[0]!='\0')
	  {
	    while(H.elem[n].name[0]!='\0')
        {
            p=ChongTu(n,c);
			if(H.elem[p].name[0]!='\0')
			{
				continue;
			}
			else
			{
				H.elem[p]=a;                      //求得散列地址，将信息存入
		        H.count++;
				break;
			}
		}
	  }
	  else
	  {
        H.elem[n]=a;                      //求得散列地址，将信息存入
		H.count++;
	  }

	return OK;
}
Status SearchHash(HashTable H,int &c)
{
	int i=0,n,p;
	c=0;
	NA	s;
	printf("请输入要查找的姓名\n");
	scanf("%s",&s);
	p=Hash1(s);
	n=p;
	while((H.elem[n].name[0]!='\0') && (strcmp(s, H.elem[n].name)==1))
	{
		 n=ChongTu(p,c);
		 if((H.elem[n].name[0]!='\0') && (strcmp(s, H.elem[n].name)==0))
		 {
			 printf("查找成功!\n");
			 printf("用户信息如下:\n");
			 printf("姓名:%s",H.elem[n].name);
			 printf("电话号码:%s",H.elem[n].tel);
			 printf("联系地址:%s",H.elem[n].adr);
	 		 return OK;
		 }
	}
    if((H.elem[n].name[0]!='\0') && (strcmp(s, H.elem[n].name)==0))
	{
		printf("查找成功!\n");
	    printf("用户信息如下:\n");
		printf("姓名:%s",H.elem[n].name);
		printf("电话号码:%s",H.elem[n].tel);
		printf("联系地址:%s",H.elem[n].adr);
		return OK;
	}
	return ERROR;
}

Status DisPlay(HashTable H)                                                            //打印记录
{
	int i;
	for(i=0;i<HASHSIZE;i++)
	{
		if(H.elem[i].name[0]!='\0')
		{	
		printf("\n在哈希表中位序为:%d\t",i);
        printf("姓名:%s\t",H.elem[i].name);
        printf("电话号码:%s\t",H.elem[i].tel);
	    printf("联系地址:%s\n",H.elem[i].adr);
	
		}
		else
			continue;
	}
	return OK;
}
Status OperateMenu()
{
	int i;
	printf("\n-----------欢迎使用本程序--------------------------\n");
	printf("(0)---初始化哈希表\n");
    printf("(1)---构建哈希表              (2)---打印输出用户信息      \n");
	printf("(3)---查找用户信息            (4)---退出程序          \n");
    printf("请你选择所要进行的操作\n");
	printf("---------------------------------------------------\n");
   scanf("%d",&i);
   return i;
}
void main()
{
	int c, y,x=0;
    HashTable H;
	int Number;
	Record a;
    H.elem=NULL;
    while(1)
	 {
	   y=OperateMenu();
    	switch(y)
		{

	    	case 0:
			     if(InitHash(H)==OK)
					 printf("成功创建\n");
				 else
                     printf("程序执行错误\n");
			     break;
	    	case 1:
			     if(!H.elem)
			         printf("未创建哈希表\n");
                 else
				 {
					 printf("请你输入要录入的信息数:\n");
                     scanf("%d",&Number);
	                 for(int i=0;i<Number;i++)
					 {
		                printf("请您输入第%d个信息的姓名:\n",i+1);
			            scanf("%s",a.name);
		                printf("请您输入第%d个信息的电话:\n",i+1);
			            scanf("%s",a.tel);
		                printf("请您输入第%d个信息的地址:\n",i+1);
			            scanf("%s",a.adr);
					 
				     if(CreateHash(H,a,Number)==OK)
					     printf("成功创建\n");
				     else
                         printf("程序执行错误\n");
					 }
				 }
			     break;
	    	case 2:
		         if(!H.elem)
			             printf("未创建哈希表\n");
			     else
				 {
                    if(DisPlay(H)==OK)
					     printf("打印成功\n");
	                else
                         printf("程序执行错误\n");
				 }
		         break;
	         case 3:
			     if(!H.elem)
			             printf("未创建哈希表\n");
				 else
				 {
				     if(SearchHash(H,c)==OK)
					     printf("打印完毕\n");
				     else
                         printf("查找失败!此人不存在\n");
				 }
			     break;
				 
	        case 4:
			     printf("谢谢使用!");
			     exit(0);
				 break;
	    	default:
			     printf("你输入的序号有误\n");
			     break;
		}
	 }
}
		
	 
