#ifndef SALE_H_
#define SALE_H_
#include "../Common/common.h"
#include "Account.h"
#include "Ticket.h"
#include "Schedule.h"

//�������ͣ�Ϊ��Ʊ����Ʊ
typedef enum{
	SALE_SELL=1,	//��Ʊ
	SALE_RETURN=-1	//��Ʊ
}sale_type_t;


typedef struct {
	long id;      		//���ۼ�¼ID
	int user_id;		//��ƱԱID
	int ticket_id;		//ƱID
	ttms_date_t date ;	//��������
	ttms_time_t time;	//����ʱ��
	int value;			//Ʊ��
	sale_type_t type; //��������
}sale_t;

//˫������
typedef struct sale_node {
	sale_t data;
	struct sale_node *next, *prev;
} sale_node_t, *sale_list_t;

//�����¶�����Ϣ
int Sale_Srv_Add(sale_t *data);
//�޸�Ʊ״̬
int Ticket_Srv_Modify (const ticket_t *data);

//�����ݳ��ƻ�ID��ȡƱ������
//int Ticket_Srv_FetchBySchID(ticket_list_t list, int schedule_id);

//�����ݳ��ƻ�ID��ȡƱ������
int Ticket_Srv_FetchBySchID(ticket_list_t list, int schedule_id);

//�����ݳ��ƻ�ID��ȡƱ������
//int Ticket_Srv_FetchBySchID(int ID, ticket_list_t list);

//����ID��ȡƱ
ticket_node_t * Ticket_Srv_FetchBySeatID (ticket_list_t list, int seat_id);

int Sale_Srv_FetchAll(sale_list_t list);

int Sale_Srv_FetchByticket(int schedule_id,sale_t *sale);
#endif //SALE_H_

