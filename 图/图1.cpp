#include<stdio.h>
#include<stdlib.h>
#define INFINITY 65535
#define MAX_VERTEX_NUM  7
 int  visited[ MAX_VERTEX_NUM ];
typedef struct ArcCell{
	int  adj;
	int  *info;
}ArcCell,AdjMatrix[MAX_VERTEX_NUM] [MAX_VERTEX_NUM];
typedef struct{
	char vexs[MAX_VERTEX_NUM];
	AdjMatrix arcs;
	int vexnum,arcnum;
}MGraph;
int LocateVex(MGraph G,char v)
{
	 int i;
	 for(i=0;i<G.vexnum;i++)
	 {
		 if(v==G.vexs[i])
			return i;
	 }
	 return -1;
 }
void CreateAN(MGraph &G)
{
	char v1,v2;
	int w,i,j,k,n,m;
	printf("请输入顶点个数与边数");
	scanf("%d %d",&n,&m);
	G.vexnum=n;
	G.arcnum=m;
	printf("输入顶点的一维数组序列");
	fflush(stdin);
	for( i=0;i<G.vexnum;i++)
	{
		scanf("%c",&G.vexs[i]);
	}                                                                                                                                       
  	for( i=0;i<G.vexnum;i++)
	{
		for( j=0;j<G.vexnum;j++)	
			G.arcs[i][j].adj=INFINITY;
	}
	for( k=0;k<G.arcnum;++k)
		{ 
			printf("输入一条边依附的两个顶点和权值：");
			fflush(stdin);
			scanf("%c%c",&v1,&v2);
			scanf("%d",&w);
			i=LocateVex(G,v1);
			j=LocateVex(G,v2);
			G.arcs[i][j].adj=w;
			G.arcs[j][i]=G.arcs[i][j];
		}
}
void Print1(MGraph G)
{
	int i,j;
	printf("顶点表信息为:\n");
	for(i=0;i<G.vexnum;i++)
		printf("%c",G.vexs[i]);
	printf("\n输出邻接矩阵:\n");
	printf("\t");
		for(i=0;i<G.vexnum;i++)
	{
			printf("\n");
		for(j=0;j<G.vexnum;j++)
			if(G.arcs[i][j].adj==65535)
		    	printf("%d\t",0);
			else
				printf("%d\t",G.arcs[i][j].adj);
	}

}
void DFS(MGraph G,int i)
{
	int j;
	printf("%c",G.vexs[i]);
	visited[i]=1;
	for(j=0;j<G.vexnum;j++)
		if(!visited[j]&&G.arcs[i][j].adj)
			DFS(G,j);
}
void DFSTrav(MGraph G)
{
	char m;
	int i,j;
	for(i=0;i<G.vexnum;i++)
		visited[i]=0;
	 printf("请输入开始遍历的第一个顶点:");
	 getchar();
     scanf("%c",&m);
	 j=LocateVex(G,m);
	for(i=0;i<G.vexnum;i++)
	{
		if(!visited[i])
			DFS(G,j);
	}
}
int OperatMenu()
{
	int i;
	printf("\n********请输入操作选项********\n");
	printf("-0 退出\n");
		printf("-1 建图 \n"); printf("-2  打印顶点表和邻接矩阵 \n");
	    printf("-3 深度遍历顶点集打印输出\n");printf("请输入选项:");
		scanf("%d",&i);
		return i;
}
void main()
{
	int k;
    MGraph G;
	char Flag=false;
	while(1)
	{
		 k=OperatMenu(); 
		 switch(k)
		 {
		 case 0:
			  exit(0);
			  break;
		 case 1:
               CreateAN(G);
			   Flag=true;
			   break;
		 case 2:
			 if(Flag)
               Print1(G);
			 else
				 printf("图未建,请先建无向图！\n");
			   break; 
		 case 3:
			 if(Flag)
               DFSTrav(G);
			 else
				 printf("图未建,请先建无向图！\n");
			   break;
   		 default:
			 printf("输入有误，请重新输入：");
			 break;
		 }
	}
}








			





	
