/*
* Copyright(C), 2007-2008, XUPT Univ.
* ������ţ�TTMS_UC_02	 
* File name: Seat.h	  
* Description : ������λ�����־û���	
* Author:   XUPT  		 
* Version:  v.1 	 
* Date: 	2015��4��22��	
*/

#include "Seat_Persist.h"
#include "../Service/Seat.h"
#include "../Common/List.h"
#include <stdlib.h>
#include <stdio.h>
#include<unistd.h>
#include <assert.h>
#include "./EntityKey_Persist.h"

static const char SEAT_DATA_FILE[] = "Seat.dat";
static const char SEAT_DATA_TEMP_FILE[] = "SeatTmp.dat";

//���Ӷ���������ʶ����
static const char SEAT_KEY_NAME[] = "Seat";

/*
�������ܣ��������ļ�������һ������λ���ݡ�
����˵����dataΪseat_t����ָ�룬��ʾ��Ҫ���ӵ���λ���ݽ�㡣
�� �� ֵ�����ͣ���ʾ�Ƿ�ɹ���������λ�ı�־��
*/ 
int Seat_Perst_Insert(seat_t *data) {   
	assert(NULL!=data);
	return 0;
}

/*
��ʶ����TTMS_SCU_Seat_Perst_InsertBatch
�������ܣ��������ļ�������һ����λ���ݡ�
����˵����listΪseat_list_t���ͣ���ʾ��Ҫ���ӵ�һ����λ������ͷָ�롣
�� �� ֵ�����ͣ���ʾ�ɹ�����һ����λ�ĸ�����
*/
int Seat_Perst_InsertBatch(seat_list_t list) {
	seat_node_t *p;
	int len = 0;
	int rtn  = 0;
	assert(NULL!=list);
	List_ForEach(list,p)
	{
		len++;
	}
	int key = EntKey_Perst_GetNewKeys(SEAT_KEY_NAME,len);
	if(key <= 0)
	{
		printf("key <= 0 \n");
		return 0;
	} 
	else
	{
		
		FILE *fp = fopen(SEAT_DATA_FILE,"ab");
		if(fp == NULL) 
		{
			printf("SEAT_DATA_FILE打开文件失败!\n");
			return 0;
		}
		List_ForEach(list,p)
		{
				
				p->data.id = key++;
				rtn++;
				fwrite(p,sizeof(seat_node_t),1,fp);
		}
		fclose(fp);
		
		}
	
	//printf("rtn = %d",rtn);
	return rtn;
}

/*
��ʶ����TTMS_SCU_Seat_Perst_Update
�������ܣ��������ļ��и���һ����λ���ݡ�
����˵����dataΪseat_t����ָ�룬��ʾ��Ҫ���µ���λ���ݽ�㡣
�� �� ֵ�����ͣ���ʾ�Ƿ�ɹ���������λ�ı�־��
*/
int Seat_Perst_Update(const seat_t *seatdata) {
	assert(NULL!=seatdata);
	return 0;

}

/*
ʶ����TTMS_SCU_Seat_Perst_DelByID
�������ܣ����ڴ��ļ���ɾ��һ����λ�����ݡ�
����˵��������IDΪ���ͣ���ʾ��Ҫɾ������λID�� 
�� �� ֵ�����ͣ���ʾ�Ƿ�ɹ�ɾ������λ�ı�־��
*/
int Seat_Perst_DeleteByID(int ID) {
	
	return 0;
}

/*
��ʶ����TTMS_SCU_Seat_Perst_DelAllByID
�������ܣ����ݱ�����ڴ��ļ���ɾ����λ���ݡ�
����˵��������roomIDΪ���ͣ���ʾ�ݳ���ID�� 
�� �� ֵ�����ͣ���ʾ�Ƿ�ɹ�ɾ������λ�ı�־��
*/ 
int Seat_Perst_DeleteAllByRoomID(int roomID) {
	
	return 0;
}

/*
��ʶ����TTMS_SCU_Studio_Perst_SelByID
�������ܣ����ڴ��ļ�������һ����λ�����ݡ�
����˵������һ������IDΪ���ͣ���ʾ��Ҫ�������ݵ���λID���ڶ�������bufΪseat_tָ�룬ָ��������λ���ݵ�ָ�롣
�� �� ֵ�����ͣ���ʾ�Ƿ�ɹ���������λ�ı�־��
*/
int Seat_Perst_SelectByID(int ID, seat_t *buf) {
	
	return 0;
}

/*
��ʶ����TTMS_SCU_Seat_Perst_SelAll
�������ܣ����ڴ��ļ�������������λ���ݡ�
����˵����listΪseat_list_t���ͣ���ʾ��Ҫ�������λ����ͷָ�롣
�� �� ֵ�����ͣ��ɹ�������λ�ĸ�����
*/
int Seat_Perst_SelectAll(seat_list_t list) {
	
	return 0;
}

/*
��ʶ����TTMS_SCU_Seat_Perst_SelByRoomID
�������ܣ��������ļ��и����ݳ���ID����������λ���ݡ�
����˵������һ������listΪseat_list_t���ͣ���ʾ��Ҫ�������λ����ͷָ�룬�ڶ�������roomIDΪ���ͣ���ʾ�ݳ���ID��
�� �� ֵ�����ͣ���ʾ�ɹ��������ݳ�����λ�ĸ�����
*/
int Seat_Perst_SelectByRoomID(seat_list_t list, int roomID) {
	int recCount = 0;
	if(access(SEAT_DATA_FILE,F_OK) == -1)//文件不存在
	{
		//printf("SEAT_DATA_FILE文件不存在\n");
		return 0;
	}
	else
	{
		seat_node_t *p ;
		p = (seat_list_t)malloc(sizeof(seat_node_t));
		FILE *fp = fopen(SEAT_DATA_FILE,"rb");
		while(1)
		{
				
				if(fread(p,sizeof(seat_node_t),1,fp) < 1) break;
				if(p->data.roomID == roomID)
				{
					List_AddTail(list,p);
					recCount++;
				}
				else
				{
					free(p);
				}
				//优化不用全部遍历其实
				p = (seat_list_t)malloc(sizeof(seat_node_t));
		}
		fclose(fp);

		return recCount;
	}
	
}
