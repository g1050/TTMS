#ifndef 	SALETICKET_UI_H_
#define 	SALETICKET_UI_H_

#include "../Service/Play.h"
#include "../Service/Schedule.h"
#include "../Service/Seat.h"
#include "../Service/Account.h"
#include "../Service/Ticket.h"


//���ݾ�ĿID��ʾ�ݳ��ƻ�
void Sale_UI_ShowScheduler(int playID);


//��Ʊ����
inline int Sale_UI_SellTicket(ticket_list_t tickList, seat_list_t seatList);

//������Ʊ��������
void Sale_UI_MgtEntry(void);

//��Ʊ
void Sale_UI_RetfundTicket();

#endif
