#include "Ticket.h"
#include "../Common/List.h"
#include "../Service/Schedule.h"
#include "../Service/Play.h"
#include "../Persistence/Ticket_Persist.h"
#include "../Persistence/Play_Persist.h"
#include "../Persistence/Schedule_Persist.h"
#include "../Service/Seat.h"

#include <stdio.h>
#include <stdlib.h>

int Ticket_Srv_GenBatch(int schedule_id, int studio_id){
	return 0;
}

int Ticket_Srv_DeleteBatch(int schedule_id) {
	return 0;
}


int Ticket_Srv_FetchByID (int id, ticket_t *buf){
	return 0;
}

