#include "Play.h"
#include "../Common/List.h"

int Play_Srv_FetchAll(play_list_t list) {
	return Play_Perst_SelectAll(list);
}