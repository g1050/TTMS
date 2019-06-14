/*
* Copyright(C), 2007-2008, XUPT Univ.	 
* ������ţ�TTMS_UC_02
* File name: Seat.h	  
* Description : ������λ�����־û���ͷ�ļ�	
* Author:   XUPT  		 
* Version:  v.1 	 
* Date: 	2015��4��22��	
*/

#ifndef SEATPERSIST_H_
#define SEATPERSIST_H_

#include "../Service/Seat.h"

//��ʶ���� TTMS_SCU_Seat_Perst_Insert
//���ܣ����ļ��д洢����λ
int Seat_Perst_Insert(seat_t *data);	

//��ʶ����TTMS_SCU_Seat_Perst_InsertBatch
//���ܣ����ļ��������洢��λ
int Seat_Perst_InsertBatch(seat_list_t list);

//��ʶ����TTMS_SCU_Seat_Perst_Update
//���ܣ����ļ��и�����λ
int Seat_Perst_Update(seat_list_t*data);


//��ʶ����TTMS_SCU_Seat_Perst_DelByID
//���ܣ�������λIDɾ����λ 
int Seat_Perst_DeleteByID(int ID);

//��ʶ����TTMS_SCU_Seat_Perst_DelAllByID
//���ܣ������ݳ���IDɾ����λ 
int Seat_Perst_DeleteAllByRoomID(int roomID);

//��ʶ����TTMS_SCU_Seat_Perst_SelByRoomID
//���ܣ������ݳ���ID���ļ�������������λ
int Seat_Perst_SelectByRoomID(seat_list_t list, int roomID);

//��ʶ����TTMS_SCU_Studio_Perst_SelByID
//���ܣ�����ID���ļ���������λ 
int Seat_Perst_SelectByID(int ID, seat_t *buf);

//��ʶ����TTMS_SCU_Seat_Perst_SelAll
//���ܣ����ļ�������������λ 
int Seat_Perst_SelectAll(seat_list_t list);

#endif /* SEATPERSIST_H_ */
