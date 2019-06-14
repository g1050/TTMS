/*
* Copyright(C), 2007-2008, XUPT Univ.
* ������ţ�TTMS_UC_02		 
* File name: Seat_UI.h			  
* Description : ������λ���������ͷ�ļ�	
* Author:   XUPT  		 
* Version:  v.1 	 
* Date: 	2015��4��22��	
*/

#ifndef SEAT_UI_H_
#define SEAT_UI_H_
#include "../Common/List.h"
#include "../Service/Seat.h"

//��ʶ����TTMS_SCU_Seat_UI_MgtEnt 
//���ܣ�������λ����
void Seat_UI_MgtEntry(int roomID);

//��ʶ����TTMS_SCU_Seat_UI_S2C 
//���ܣ�������λ״̬��ȡ������ʾ���Ž���
char Seat_UI_Status2Char(seat_status_t status);

//��ʶ����TTMS_SCU_Seat_UI_C2S
//���ܣ�����������Ż�ȡ��λ״̬����
seat_status_t Seat_UI_Char2Status(char statusChar);

//��ʶ����TTMS_SCU_Seat_UI_Add
//���ܣ���������λ���� 
int Seat_UI_Add(seat_list_t list,  int rowsCount,int colsCount);

//��ʶ����TTMS_SCU_Seat_UI_Mod 
//���ܣ��޸���λ����
int Seat_UI_Modify(seat_list_t list, int rowsCount, int colsCount);

//��ʶ����TTMS_SCU_Seat_UI_Del
//���ܣ���ɾ����λ����
int Seat_UI_Delete(seat_list_t list, int rowsCount, int colsCount);


#endif /* SEAT_UI_H_ */
