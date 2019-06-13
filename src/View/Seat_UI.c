/*
* Copyright(C), 2007-2008, XUPT Univ.	 
* ������ţ�TTMS_UC_02
* File name: Seat_UI.c			  
* Description : ������λ���������	
* Author:   XUPT  		 
* Version:  v.1 	 
* Date: 	2015��4��22��	
*/

#include "Seat_UI.h"
#include "../Service/Seat.h"

#include "../Service/Studio.h"
#include "../Common/List.h"
#include <stdio.h>

/*
��ʶ����TTMS_SCU_Seat_UI_S2C 
�������ܣ�������λ״̬��ȡ������ʾ���š�
����˵����statusΪseat_status_t���ͣ���ʾ��λ״̬��
�� �� ֵ���ַ��ͣ���ʾ��λ�Ľ�����ʾ���š�
*/
inline char Seat_UI_Status2Char(seat_status_t status) {

	return "#";
}

/*
��ʶ����TTMS_SCU_Seat_UI_C2S
�������ܣ�����������Ż�ȡ��λ״̬��
����˵����statusCharΪ�ַ��ͣ���ʾ������λ��������š�
�� �� ֵ��seat_status_t���ͣ���ʾ��λ��״̬��
*/
inline seat_status_t Seat_UI_Char2Status(char statusChar) {
	return SEAT_NONE;
}

/*
��ʶ����TTMS_SCU_Seat_UI_MgtEnt
�������ܣ�����������λ����ں�������ʾ��ǰ����λ���ݣ����ṩ��λ�������ӡ��޸ġ�ɾ�����ܲ�������ڡ�
����˵����roomIDΪ���ͣ�����Ҫ������λ���ݳ���ID��
�� �� ֵ���ޡ�
*/ 
void Seat_UI_MgtEntry(int roomID) {
	studio_t buf;
	if(Studio_Srv_FetchByID(roomID,&buf))
	{
		//printf("演出厅存在!\n");
				seat_list_t list;
				List_Init(list,seat_node_t);
				
				if( Seat_Srv_FetchByRoomID(list,roomID)== 0)//list用于存放座位信息
				{//不存在座位
					Seat_Srv_RoomInit(list,roomID,buf.rowsCount,buf.colsCount);
					buf.seatsCount = buf.colsCount*buf.rowsCount;
					Studio_Srv_Modify(&buf);
					printf("座位初始化完成!\n");
					printf("按[ENTER]继续\n");
					setbuf(stdin,NULL);
					getchar();
				}
				else
				{
						seat_list_t p;
						char map[buf.rowsCount+5][buf.colsCount+5];
						Seat_Srv_map(list,(char*)map,buf.colsCount);
						//printf("输出座位!\n");
						for(int  i =1;i<=buf.rowsCount;i++)
						{
							printf("第%d行 ",i);
							for(int j = 1;j<=buf.colsCount;j++)
							{
								printf("%c ",*((char *)map+i*buf.colsCount+j));
							}
							printf("\n");
						}
						//printf("map[2][2] = %c",map[2][2]);
						
						int choice ;
						do
						{
							printf(
									"******************************************************************\n");
							printf(
									"[1]添加座位|[2]删除座位 |  [0]返回上层");
							printf(
									"\n\n\n\n==================================================================\n");
							printf("请输入您要进行的操作:");
							setbuf(stdin,NULL);
							scanf("%d",&choice);


							switch (choice)
							{
										case 1:
												system("clear");
												break;


									case 2:
										system("clear");
										break;


									case 3:
										system("clear");
										break;



									default:
										printf("输入有误，请重新输入!\n");
										break;
							}
									
						}while(choice != 0);
						system("clear");
							
				}
		
	}
	else
	{
		printf("演出厅不存在!\n");
		return ;
	}
	
	//展示菜单
}

/*
ʶ����TTMS_SCU_Seat_UI_Add
�������ܣ���������һ���µ���λ���ݡ�
����˵������һ������listΪseat_list_t����ָ�룬ָ����λ����ͷָ�룬
         �ڶ�������rowsCountΪ���ͣ���ʾ��λ�����кţ�����������colsCountΪ���ͣ���ʾ��λ�����кš�
�� �� ֵ�����ͣ���ʾ�Ƿ�ɹ���������λ�ı�־��
*/
int Seat_UI_Add(seat_list_t list, int roomID, int row, int column) {  //����һ����λ

	return 0;
}

/*
��ʶ����TTMS_SCU_Seat_UI_Mod 
�������ܣ������޸�һ����λ���ݡ�
����˵������һ������listΪseat_list_t����ָ�룬ָ����λ����ͷָ�룬�ڶ�������rowsCountΪ���ͣ���ʾ��λ�����кţ�����������colsCountΪ���ͣ���ʾ��λ�����кš�
�� �� ֵ�����ͣ���ʾ�Ƿ�ɹ��޸�����λ�ı�־��
*/
int Seat_UI_Modify(seat_list_t list, int row, int column) {

	return 0;

}

/*
��ʶ����TTMS_SCU_Seat_UI_Del
�������ܣ�����ɾ��һ����λ�����ݡ�
����˵������һ������listΪseat_list_t����ָ�룬ָ����λ����ͷָ�룬�ڶ�������rowsCountΪ���ͣ���ʾ��λ�����кţ�����������colsCountΪ���ͣ���ʾ��λ�����кš�
�� �� ֵ�����ͣ���ʾ�Ƿ�ɹ�ɾ������λ�ı�־��
*/
int Seat_UI_Delete(seat_list_t list, int row, int column) {

	return 0;

}

