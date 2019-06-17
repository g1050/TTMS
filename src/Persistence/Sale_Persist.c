#include "Sale_Persist.h"
#include "../Common/List.h"
#include "../Service/Sale.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/io.h>
#include <string.h>
#include "EntityKey_Persist.h"


static const char SALE_DATA_FILE[] = "Sale.dat";
static const char SALE_DATA_TEMP_FILE[] = "SaleTmp.dat";

//�洢�¶���
int Sale_Perst_Insert (sale_t *data){
	return 0;
}

//����Ʊ״̬
int Ticket_Perst_Update (const ticket_t *data){
	return 0;
}

//�����ݳ��ƻ�ID����Ʊ������
int Ticket_Srv_SelBySchID(int id, ticket_list_t list){
	return 0;
}

//����ƱID�������ۼ�¼
int Sale_Perst_SelByTicketID (int ticket_id, sale_t *sale){
	return 0;
}

//����ID�������ۼ�¼
int Sale_Perst_SelByID (sale_list_t list, int usrID){
	return 0;

}
