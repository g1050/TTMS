

#include "../View/Schedule_UI.h"


int Schedule_Srv_FetchAll(schedule_list_t list)
{
        return Schedule_Perst_SelectAll(list);
}

int Schedule_Srv_Add(schedule_t *data) {
	return Schedule_Perst_Insert(data);
}

int Schedule_Srv_DeleteByID(int ID)
{
	return Schedule_Perst_DeleteByID(ID);
}

int Schedule_Srv_Modify(const schedule_t *data)
 {
	return Schedule_Perst_Update(data);
}

int Schedule_Srv_FetchByID(int id,schedule_t *buf)
{
	return Schedule_Perst_SelectByID(id,buf);
}

