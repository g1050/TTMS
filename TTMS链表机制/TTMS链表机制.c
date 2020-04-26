#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "List.h"
typedef struct 
{
    int ID;
    char name[20];
    int score;
}student_t;//实体struct结构体
typedef struct student_node
{
    student_t data;
    struct student_node *prev;
    struct student_node *next;
}student_node_t;//定义管理student的链表节点
typedef student_node_t *student__list_t;

int CreatList_Head(student__list_t list)//以头插法创建链表list,并返回创建的数据节点个数
{
    int i = 0;
    student_node_t *p;
    for(i = 0;i<10;i++)
    {
        p = (student_node_t*)malloc (sizeof(student_node_t));
        if(!p) break;
        p->data.ID = i*5;
        p->data.score = i*10;
        sprintf(p->data.name,"%s%d","student-",i*5);
        List_AddHead(list,p); //调用宏函数List_AddHead讲p插入到list头部
    }
    return i;
}

int CreatList_Tail(student__list_t list)
{
    int i = 0;
    student_node_t *p;
    for(i = 0;i<10;i++)
    {
        p = (student_node_t*)malloc(sizeof(student_node_t));
        if(!p) break;
        p->data.ID = i*5;
        p->data.score = i*10;
        sprintf(p->data.name,"%s%d","student-",i*5);
        List_AddTail(list,p); //调用宏函数
    }
}

void ShowList(student__list_t list)//输出链表内容
{
    student_node_t *p;
    printf("=======================Student List===============================\n");
    printf("%5s%20s%8s\n","ID","Name","Score");
    printf("------------------------------------------------------------------\n");
    List_ForEach(list,p)//根据输出需要编写循环体输出p指向当前节点的值
    {
        printf("%5d%20s%8d\n",p->data.ID,p->data.name,p->data.score);

    }

    printf("==================================================================\n");
    return ;
}

int Aaddnode(student__list_t list)//按ID顺序添加新节点，返回添加的节点个数
{
    student_node_t *p,*q;
    p = (student_node_t*)malloc(sizeof(student_node_t)); //申请节点占用空间
    if(!p) return 0;

    //创建新节点
    printf("请输入要添加的学生的ID\n");
    scanf("%d",&(p->data.ID));
    p->data.score = p->data.ID * 10;
    sprintf(p->data.name,"%s%d","student-",p->data.ID);
    //调用宏函数List_Foreach使用指针变量q遍历链表list，寻找插入位置
    List_ForEach(list,q)
    {
        if(q->data.ID == p->data.ID) //不允许ID重复｀
        {
            printf("ID重复该学生已经存在!\n");
            free(p);
            return 0;
        }
        else if(q->data.ID > p->data.ID)//ｑ指向的节点的ID大于ｐ的ＩＤ跳出循环
        {
            break;
        }

    }

    List_InsertBefore(q,p);//将p节点插入到q节点之前
    return 1;
}

int Deletenode(student__list_t list)//删除节点返回值为实际删除节点的个数
{
    int ID;
    printf("请输入要删除学生的ID\n");
    scanf("%d",&ID);
    student_node_t *q;

    //遍历
    List_ForEach(list,q)
    {
        if(q->data.ID == ID)
        {
            List_FreeNode(q);
            return 1;
        }
    }
    printf("该节点不存在!\n");
    return 0;
}
int main()
{
    student__list_t list = NULL;//定义链表头指针变量
    setvbuf(stdout,NULL,_IONBF,0);
    List_Init(list,student_node_t); //初始化链表
    printf("使用头插法创建链表!\n");
    CreatList_Head(list);//头插法创建链表数据节点
    ShowList(list);//输出链表内容
    List_Free(list,student_node_t);  //调用宏函数释放所有数据节点
    getchar();
    system("clear");
    printf("使用尾插法创建链表!\n"); 
    CreatList_Tail(list);
    ShowList(list);
    getchar();
    system("clear");
    printf("向链表中插入添加一个新的节点\n");
    Aaddnode(list);
    ShowList(list);
    printf("从链表中删除一个节点\n");
    Deletenode(list);
    ShowList(list);
    List_Destroy(list,student_node_t);
    return 0;
}

