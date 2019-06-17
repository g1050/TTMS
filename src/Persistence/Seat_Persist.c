/*
 *  Seat_Persist.c
 *
 *  Created on: 2015��5��23��
 *  Author: lc
 */

#include "Seat_Persist.h"
#include "../Service/Seat.h"
#include "EntityKey_Persist.h"
#include "../Common/List.h"
#include <stdlib.h>
#include <stdio.h>
#include<unistd.h>
#include <assert.h>

static const char SEAT_DATA_FILE[] = "Seat.dat";
static const char SEAT_DATA_TEMP_FILE[] = "SeatTmp.dat";

//���Ӷ���������ʶ����
static const char SEAT_KEY_NAME[] = "Seat";


int Seat_Perst_Insert(seat_t *data) {   
	assert(NULL!=data);
	return 0;
}

int Seat_Perst_InsertBatch(seat_list_t list) 
{
	int rtn = 0;
	seat_node_t *p;
	assert(NULL!=list);

	int len = 0;
	List_ForEach(list,p)
	{
		len++;
	}
	int key = EntKey_Perst_GetNewKeys(SEAT_KEY_NAME,len);
	if(key <= 0) 
	{
		printf("分配主键失败!\n");
		return 0;
	}
	else
	{
		FILE *fp = fopen(SEAT_DATA_FILE,"ab");
		if(fp == NULL) 
		{
			printf("打开文件失败%s",SEAT_DATA_FILE);
			return 0;
		}
		else
		{
			List_ForEach(list,p)
			{
				p->data.id = key++;
				fwrite(&p->data,sizeof(seat_t),1,fp);
				rtn++;
			}
		}
		
		
	}
	
	return rtn;
}

int Seat_Perst_Update(const seat_t *seatdata) {
	assert(NULL!=seatdata);
	return 0;

}

int Seat_Perst_DeleteByID(int ID) {
	
	return 0;
}


int Seat_Perst_DeleteAllByRoomID(int roomID) {
	
	return 0;
}

int Seat_Perst_SelectByID(int ID, seat_t *buf) {
	
	return 0;
}

int Seat_Perst_SelectAll(seat_list_t list) {
	
	return 0;
}

int Seat_Perst_SelectByRoomID(seat_list_t list, int roomID) 
{
	int recCount = 0;
	if(access(SEAT_DATA_FILE,F_OK) == -1)//文件不存在
	{
		printf("SEAT_DATA_FILE文件不存在\n");
		return 0;
	}
	else
	{
		seat_node_t *p ;
		p = (seat_list_t)malloc(sizeof(seat_node_t));
		FILE *fp = fopen(SEAT_DATA_FILE,"rb");
		seat_t q;
		while(1)
		{
				
				if(fread(&q,sizeof(seat_t),1,fp) < 1) break;
				printf("q.roomid = %d\n",q.roomID);
				if(q.roomID == roomID)
				{
					p->data = q;
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

		
	}
	printf("recCount = %d",recCount);
	return recCount;
}
