#ifndef STUDIO_H_
#define STUDIO_H_
#include "../View/Schedule_UI.h"

int Schedule_Srv_FetchAll(schedule_list_t list);

int Schedule_Srv_Add(schedule_t *data);

int Schedule_Srv_DeleteByID(int ID);

int Schedule_Srv_Modify(const schedule_t *data) ;

int Schedule_Srv_FetchByID(int id,schedule_t *buf);

#endif