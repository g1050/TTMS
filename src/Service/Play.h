#ifndef PLAY_H_
#define PLAY_H_
#include "../View/Play_UI.h"

#include "../Common/List.h"


int Play_Srv_FetchAll(play_list_t list) ;

int Play_Srv_Add(play_t *data);

int Play_Srv_DeleteByID(id);

int Play_Srv_FetchByID(int id,play_t* buf);

int Play_Srv_Modify(play_t *buf);
#endif 
//#endif