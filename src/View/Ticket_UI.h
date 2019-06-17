#ifndef TICKET_UI_H_
#define TICKET_UI_H_
#include "../Common/List.h"
#include "../Service/Ticket.h"
#include "../Service/Seat.h"
#include "../Service/Schedule.h"

static const int TICKET_PAGE_SIZE=8;

int Ticket_UI_MgtEntry(int schedule_id);

void Ticket_UI_Query(void);

int Ticket_UI_ShowTicket (int ticket_id);



#endif /* TICKET_UI_H_ */
