/*
 * salesanalysis.c
 *
 *  Created on: 2015��6��12��
 *      Author: Administrator
 */
#include <string.h>
#include <stdio.h>
#include "SalesAnalysis.h"
#include "Sale.h"
#include "Ticket.h"
#include "Play.h"
#include "Schedule.h"
#include "../Common/List.h"

//��ȡ��ĿƱ��
int SalesAnalysis_Srv_StaticSale(salesanalysis_list_t list){
	return 0;

}

//��ĿƱ������
void SalesAnalysis_Srv_SortBySale(salesanalysis_list_t list){

}

//�����ݳ��ƻ�ID��ȡƱ��
int Ticket_Srv_StatRevBySchID(int schedule_id, int *soldCount){
	return 0;

}


//����ƱID��ȡ���ۼ�¼
int Sale_Srv_FetchByTicketID(int ticket_id, sale_t *sale){
	return 0;

}
