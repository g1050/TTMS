/*
* Copyright(C), 2007-2008, XUPT Univ.	
* ������ţ�TTMS_UC_02 
* File name: Seat.c		  
* Description : ������λ����ҵ���߼���	
* Author:   XUPT  		 
* Version:  v.1 	 
* Date: 	2015��4��22��	
*/

#include <stdlib.h>
#include "../Common/List.h"
#include "Seat.h"
#include "../Persistence/Seat_Persist.h"

/*
�������ܣ���������һ������λ���ݡ�
����˵����dataΪseat_t����ָ�룬��ʾ��Ҫ���ӵ���λ���ݽ�㡣
�� �� ֵ�����ͣ���ʾ�Ƿ�ɹ���������λ�ı�־��
*/
int Seat_Srv_Add(const seat_t *data){
	// �벹������
       return 0;
}

/*
�������ܣ�����������λ���ݡ�
����˵����listΪseat_list_t����ָ�룬��ʾ��Ҫ���ӵ�������λ�����γɵ�������
�� �� ֵ�����ͣ���ʾ�Ƿ�ɹ�������������λ�ı�־��
*/
int Seat_Srv_AddBatch(seat_list_t list){
	// �벹������
       return 0;
}

/*
�������ܣ������޸�һ����λ���ݡ�
����˵����dataΪseat_t����ָ�룬��ʾ��Ҫ�޸ĵ���λ���ݽ�㡣
�� �� ֵ�����ͣ���ʾ�Ƿ�ɹ��޸�����λ�ı�־��
*/
int Seat_Srv_Modify(seat_list_t *data){
	
       Seat_Perst_Update(data);//Seat_Perst_Update(const seat_list_t *seatdata)
       return 0;
}

/*
�������ܣ�������λIDɾ��һ����λ��
����˵����IDΪ���ͣ���ʾ��Ҫɾ������λ���ݽ�㡣
�� �� ֵ�����ͣ���ʾ�Ƿ�ɹ�ɾ������λ�ı�־��
*/
int Seat_Srv_DeleteByID(int ID){
	// �벹������
       Seat_Perst_DeleteByID(ID);
       return 1;
}

/*
�������ܣ�������λID��ȡ��λ���ݡ�
����˵������һ������IDΪ���ͣ���ʾ��λID���ڶ�������bufΪseat_tָ�룬ָ�����ȡ����λ���ݽ�㡣
�� �� ֵ�����ͣ���ʾ�Ƿ�ɹ���ȡ����λ�ı�־��
*/
int Seat_Srv_FetchByID(int ID, seat_t *buf){
	// �벹������
       return 0;
}

/*
�������ܣ������ݳ���IDɾ��������λ��
����˵����roomIDΪ���ͣ���ʾ��Ҫɾ��������λ���ݳ���ID��
�� �� ֵ�����ͣ���ʾ�Ƿ�ɹ�ɾ�����ݳ���������λ�ı�־��
*/
inline int Seat_Srv_DeleteAllByRoomID(int roomID){
       
	// �벹������
       return Seat_Perst_DeleteAllByRoomID(roomID);
}

/*
�������ܣ����ݸ����ݳ������С�������ʼ���ݳ�����������λ���ݣ�����ÿ����λ��㰴�в�����λ������
����˵������һ������listΪseat_list_t����ָ�룬ָ����λ����ͷָ�룬�ڶ�������rowsCountΪ���ͣ���ʾ��λ�����кţ�����������colsCountΪ���ͣ���ʾ��λ�����кš�
�� �� ֵ�����ͣ���ʾ�Ƿ�ɹ���ʼ�����ݳ�����������λ��
*/
int Seat_Srv_FetchByRoomID(seat_list_t list, int roomID){
       // �벹������
       int seatCount = 0;
       seatCount = Seat_Perst_SelectByRoomID(list,roomID);
       //Seat_Srv_SortSeatList(list);
       return seatCount;
}

/*
�������ܣ������ݳ���ID��ø��ݳ�������Ч��λ��
����˵������һ������listΪseat_list_t���ͣ���ʾ��ȡ������Ч��λ����ͷָ�룬�ڶ�������roomIDΪ���ͣ���ʾ��Ҫ��ȡ��Ч��λ���ݳ���ID��
�� �� ֵ�����ͣ���ʾ�ݳ�������Ч��λ������
*/
int Seat_Srv_FetchValidByRoomID(seat_list_t list, int roomID)
{
       // �벹������
       return 0;
}

/*
�������ܣ����ݸ����ݳ������С�������ʼ���ݳ�����������λ���ݣ�����ÿ����λ��㰴�в�����λ������
����˵������һ������listΪseat_list_t����ָ�룬ָ����λ����ͷָ�룬�ڶ�������rowsCountΪ���ͣ���ʾ��λ�����кţ�����������colsCountΪ���ͣ���ʾ��λ�����кš�
�� �� ֵ�����ͣ���ʾ�Ƿ�ɹ���ʼ�����ݳ�����������λ��
*/
int Seat_Srv_RoomInit(seat_list_t list, int roomID, int rowsCount,int colsCount)
 {
	// �벹������
       int i,j;
       seat_list_t p;
       for(i = 1;i<=rowsCount;i++)
       {
              for(j = 1;j<=colsCount;j++)
              {
                     p = (seat_list_t)malloc(sizeof(seat_node_t));
                     p->data.roomID = roomID;
                     p->data.row = i;
                     p->data.column = j;
                     p->data.status = 1;
                     List_AddTail(list,p);
                   
              }
       }
        Seat_Perst_InsertBatch(list);//Seat_Perst_InsertBatch(seat_list_t list)
       return 1;
}

/*
�������ܣ�����λ����list����λ�кš��кŽ�������
����˵����listΪseat_list_t���ͣ���ʾ��������λ����ͷָ�롣
�� �� ֵ���ޡ�
*/
void Seat_Srv_SortSeatList(seat_list_t list) {
       seat_list_t listLeft,p;
       if(list == NULL) return ;
       list->prev->next = NULL;//断开循环链表
       listLeft = list->next;
       list->next = list->prev = list;
       if(listLeft == NULL) return ;
       else
       {
              p = listLeft;
              listLeft = listLeft->next;
              Seat_Srv_AddToSoftedList(list,p);
       }
       return ;
       // �벹������
}

/*
�������ܣ���һ����λ�����뵽���������λ�����С�
����˵������һ������listΪseat_list_t���ͣ���ʾ�����������λ����ͷָ�룬�ڶ�������nodeΪseat_node_tָ�룬��ʾ��Ҫ�������λ���ݽ�㡣
�� �� ֵ���ޡ�
*/
void Seat_Srv_AddToSoftedList(seat_list_t list, seat_node_t *node) {
       // �벹������
       seat_list_t p  = list->next;//可能有问题
       if(list == NULL) 
       {
              List_AddTail(list,node);
       }
       else
       {
              while(p!= list && (p->data.row < node->data.row || (p->data.row == node->data.row && p->data.column < node->data.column)))
              {
                     p = p->next;
              }
              List_AddHead(p,node);
       }
       return ;
}

/*
�������ܣ�������λ���С��кŻ�ȡ��λ���ݡ�
����˵������һ������listΪseat_list_t���ͣ���ʾ��λ����ͷָ�룬
         �ڶ�������rowΪ���ͣ���ʾ����ȡ��λ���кţ�����������columnΪ���ͣ���ʾ����ȡ��λ���кš�
�� �� ֵ��Ϊseat_node_tָ�룬��ʾ��ȡ������λ���ݡ�
*/
seat_node_t * Seat_Srv_FindByRowCol(seat_list_t list, int row, int column) {
       
       seat_list_t p;
       List_ForEach(list,p)
       {
              if(p->data.column == column &&  p->data.row == row)
              {//找到该座位
                     return p;
              }
       }
       return NULL;
}

/*
�������ܣ�������λID�������л�ȡ��λ���ݡ�
����˵������һ������listΪseat_list_t���ͣ�ָ����λ�����������ڶ�������IDΪ���ͣ���ʾ��λID��
�� �� ֵ��seat_node_t���ͣ���ʾ��ȡ����λ���ݡ�
*/
seat_node_t * Seat_Srv_FindByID(seat_list_t list, int rowID) {
       // �벹������
       return NULL;
}

void Seat_Srv_map(seat_list_t list,char *map,int col)
{//1好２坏３过道 # * -
       seat_list_t   p;
       int cnt = 0;
       List_ForEach(list,p)
       {
              if(p->data.status == 1)  *(map + p->data.row*col+p->data.column) = '#';
              if(p->data.status == 2)  *(map + p->data.row*col+p->data.column) = '*';
              if(p->data.status == 3 ||  p->data.status == 4 )  *(map + p->data.row*col+p->data.column) = ' ';
              //printf("%d %d\n",p->data.row,p->data.column);
             // printf("%c ",*(map + p->data.row*col+p->data.column));
       }

       return ;
}