#ifndef STUDIO_H_
#define STUDIO_H_
#include "../View/Schedule_UI.h"
int Schedule_Perst_SelectAll(schedule_list_t list);

int Schedule_Perst_Insert(schedule_t *data);

int Schedule_Perst_DeleteByID(int ID);

int Schedule_Perst_Update(schedule_t* data);

#endif