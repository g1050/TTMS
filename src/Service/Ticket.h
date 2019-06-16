#ifndef TICKET_H_
#define TICKET_H_
#include "../View/Schedule_UI.h"

int  Ticket_Srv_GenBatch(schedule_t *rec,int id);

int Ticket_Srv_DeleteBatch(int id);
#endif