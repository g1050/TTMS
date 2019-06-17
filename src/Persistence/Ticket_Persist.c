#include "Ticket_Persist.h"
#include "Schedule_Persist.h"
#include "EntityKey_Persist.h"	
#include "Play_Persist.h"
#include "../Service/Ticket.h"
#include "../Service/Seat.h"
#include "../Service/Play.h"
#include <stdlib.h>
#include <stdio.h>
#include<unistd.h>
#include <assert.h>

static const char TICKET_DATA_FILE[]="Ticket.dat";
static const char TICKET_DATA_TEMP_FILE[]="TicketTemp.dat";
static const char TICKET_KEY_NAME[]="Ticket";

int Ticket_Perst_Insert(int schedule_id,seat_list_t list){
	return 0;
}

int Ticket_Perst_Rem(int schedule_id){
	return 0;
}

//根据ID载入演出票
int Ticket_Perst_SelByID(int id, ticket_t *buf){
	return 0;
}
