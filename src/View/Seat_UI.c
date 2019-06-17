/*
 *  Seat_UI.c
 *
 *  Created on: 2015��5��23��
 *  Author: lc
 */
#include "Seat_UI.h"

#include "../Service/Seat.h"
#include "../Service/Studio.h"
#include "../Common/List.h"
#include <stdio.h>

//����״̬���ض�Ӧ��ʾ״̬����
inline char Seat_UI_Status2Char(seat_status_t status) {

	return "#";
}

//����״̬���ŷ�����λ״̬
inline seat_status_t Seat_UI_Char2Status(char statusChar) {
	return SEAT_NONE;
}

void Seat_UI_MgtEntry(int roomID)
 {
	 	studio_t buf;
	if(Studio_Srv_FetchByID(roomID,&buf))
	{//演出厅存在
		seat_list_t list;
		List_Init(list,seat_node_t);
		if(!Seat_Srv_FetchByRoomID(list,roomID))//判断座位是否存在
		{//不存在座位
			
			buf.seatsCount = Seat_Srv_RoomInit(list,roomID,buf.rowsCount,buf.colsCount);
			Studio_Srv_Modify(&buf);
			printf("座位初始化完成!\n");
			printf("按[ENTER]继续\n");
			setbuf(stdin,NULL);
			getchar();
		}
		else
		{
			printf("座位存在!\n");
		}
		
		
	}
	else
	{
		printf("演出厅不存在!\n");
		printf("按[ENTER]返回上层");
		setbuf(stdin,NULL);
		getchar();
		system("clear");
		return ;
	}
	return ;
}

int Seat_UI_Add(seat_list_t list, int roomID, int row, int column) {  //����һ����λ

	return 0;
}

int Seat_UI_Modify(seat_list_t list, int row, int column) {

	return 0;

}

int Seat_UI_Delete(seat_list_t list, int row, int column) {

	return 0;

}

