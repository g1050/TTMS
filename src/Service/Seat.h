/*
* Copyright(C), 2007-2008, XUPT Univ.
* ������ţ�TTMS_UC_02	 
* File name: Seat.h	  
* Description : ������λ����ҵ���߼���ͷ�ļ�	
* Author:   XUPT  		 
* Version:  v.1 	 
* Date: 	2015��4��22��	
*/

#ifndef SEAT_H_
#define SEAT_H_

//��λ״̬ 
typedef enum{
	SEAT_NONE=0,			//��λ
	SEAT_GOOD=1,			//����λ
	SEAT_BROKEN=9			//�𻵵���λ
}seat_status_t;

//��λ���ݽṹ 
typedef struct {
	int id;					//��λid
	int roomID;				//�����ݳ���id
	int row;           		//��λ�к�
    int column;        		//��λ�к�
   int status;	//��λ�ڸ��е�״̬��0��ʾû����λ��1��ʾ����λ����չ2�ɱ�ʾ��λ����
} seat_t;


//˫������
typedef struct seat_node {
	seat_t data;
	struct seat_node *next, *prev;
} seat_node_t, *seat_list_t;

/*
��ʶ����TTMS_SCU_Seat_Srv_RoomInit
���ܣ������С�������ʼ���ݳ�������λ
*/ 
int Seat_Srv_RoomInit(seat_list_t list, int roomID,int rowsCount,int colsCount);

/*
��ʶ����TTMS_SCU_Seat_Srv_SortSeatList 
���ܣ�����λ����list��������
*/
void Seat_Srv_SortSeatList(seat_list_t list );

/*
��ʶ����TTMS_SCU_Seat_Srv_AddSortedList
���ܣ������node���뵽����������list��*/
void Seat_Srv_AddToSoftedList(seat_list_t list , seat_node_t *node);

/*
��ʶ����TTMS_SCU_Seat_Srv_Add
���ܣ�����������λ
*/
int Seat_Srv_Add(const seat_t *data);

/*
��ʶ����TTMS_SCU_Seat_Srv_AddBatch 
���ܣ�����������λ
*/
int Seat_Srv_AddBatch(seat_list_t list);

/*
��ʶ����TTMS_SCU_Seat_ Srv_Mod 
���ܣ��޸���λ
*/
int Seat_Srv_Modify(const seat_t *data);

/*
��ʶ����TTMS_SCU_Seat_Srv_DelByID 
���ܣ�ɾ����λ
*/
int Seat_Srv_DeleteByID(int ID);

/*
��ʶ����TTMS_SCU_Seat_Srv_DeleteAllByRoomID 
���ܣ�����ɾ����λ
*/
int Seat_Srv_DeleteAllByRoomID(int roomID);

/*
��ʶ����TTMS_SCU_Seat_Srv_ FetchValidByRoomID 
���ܣ����ݷ�ӳ��ID��ȡ��Ч����λ
*/
int Seat_Srv_FetchValidByRoomID(seat_list_t list, int roomID);

/*
��ʶ����TTMS_SCU_Seat_Srv_FetchByID 
���ܣ�����ID��ȡ��λ����
*/ 
int Seat_Srv_FetchByID(int ID, seat_t *buf);

/*
��ʶ������ʶ����TTMS_SCU_Seat_Srv_FetchByRoomID 
���ܣ������ݳ���ID��ȡ������λ����
*/
int Seat_Srv_FetchByRoomID(seat_list_t list, int roomID);

/*
��ʶ����TTMS_SCU_Seat_Srv_FetchByRoomID
���ܣ����ݷ�ӳ��ID��ȡ��Ч����λ
*/
int Seat_Srv_FetchValidByRoomID(seat_list_t list, int roomID);

/*
��ʶ����TTMS_SCU_Seat_Srv_FindByRC
���ܣ��������кŻ�ȡ��λ����
*/
seat_node_t * Seat_Srv_FindByRowCol(seat_list_t list, int row, int column);

/*
��ʶ����TTMS_SCU_Studio_Srv_FindByID
���ܣ�����ID�������л�ȡ��λ����*/ 
seat_node_t * Seat_Srv_FindByID(seat_list_t list, int seatID);


#endif //SEAT_H_





