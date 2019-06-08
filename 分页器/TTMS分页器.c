#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "List.h"

typedef struct 
{
    int ID;
    char name[20];
    int score;
}student_t;
typedef struct student_node
{
    student_t data;
    struct student_node *prev;
    struct student_node *next;
}student_node_t;
typedef student_node_t* student_list_t;

int CreateList_Tail(student_list_t list)
{
    int i = 0;
    student_node_t *p;
    for(i = 0;i<20;i++)
    {
        p = (student_node_t *)malloc(sizeof(student_node_t));
        if(!p) break;
        p->data.ID = i*5;
        p->data.score = i*10;
        sprintf(p->data.name,"%s%d","student-",i*5);
        List_AddTail(list,p);
    }
    return i;
}

void ShowListByPage(student_list_t list,int listSize)
{
    int pageSize,i;
    student_node_t *p;
    char choice;
    printf("输入页面大小:\n");
    scanf("%d",&pageSize);
    if(pageSize <= 5)
    {
        pageSize = 5;
    }
    Pagination_t paging;//定义了一个结构体类型的变量
    paging.pageSize = pageSize;
    paging.totalRecords = listSize;//对结构体成员进行了一个初始化处理

    Paging_Locate_FirstPage(list,paging);
    do
    {
        printf("==========================Student List================================\n");
        printf("%5s%20s%8s\n","ID","Name","Score");
        printf("----------------------------------------------------------------------\n");

        //根据分页器的paging使用宏函数遍历链表list当前页的每一个节点
        Paging_ViewPage_ForEach(list,paging,student_node_t,p,i)
        {
            printf("%5d%20s%8d\n",p->data.ID,p->data.name,p->data.score);
        }
        printf("--Total Records:%2d --------------- page %2d/%2d ---------------------\n",paging.totalRecords,Paging_CurPage(paging),Paging_TotalPages(paging));


        printf("你的选择是:\n");
        printf("'F'表示第一页，'P'表示前翻一页，'N'表示后翻一页，'L'表示最后一页\n");
        printf("输入E或者e表示退出\n");
        fflush(stdin);//清空缓冲区
        scanf("%c",&choice); 
        system("clear");
        switch (choice)
        {
            case 'F'://定位到第一页
                Paging_Locate_FirstPage(list,paging);break;
            case 'P'://向前翻页
                if(!Paging_IsFirstPage(paging))//通过宏函数检测是否为第一页
                {
                    Paging_Locate_OffsetPage(list,paging,-1,student_node_t);
                }
                break;
            case 'N'://向后翻页
                if(!Paging_IsLastPage(paging))//判断是否为最后一页
                {
                    Paging_Locate_OffsetPage(list,paging,1,student_node_t);
                }
                break;
            case 'L'://定位到最后一页
                Paging_Locate_LastPage(list,paging,student_node_t);
                break;
        
        }

    }while(choice != 'e' && choice != 'E');
}
int main()
{
    setvbuf(stdout,NULL,_IONBF,0);
    student_list_t list;//定义链表头指针变量
    int recCount = 0;
    List_Init(list,student_node_t);
    recCount = CreateList_Tail(list);//创建链表
    ShowListByPage(list,recCount); //分页显示链表内容
    List_Destroy(list,student_node_t);
    return 0;
}

