#include "Play.h"
#include "../Common/List.h"
#include "../Persistence/Play_Persist.h"
#include <string.h>


inline int Play_Srv_Add( play_t *data) {
	return Play_Perst_Insert(data);
}

inline int Play_Srv_Modify( play_t *data) {
	return 0;
}

inline int Play_Srv_DeleteByID(int ID) {
	return 0;
}

inline int Play_Srv_FetchByID(int ID, play_t *buf) {
	return 0;
}

inline int Play_Srv_FetchAll(play_list_t list) {
	return 0;
}

//根据剧目名称载入剧目，返回载入的剧目数量
int Play_Srv_FetchByName(play_list_t list, char condt[]){
	return 0;

}



//根据剧目名称过滤词filter对list进行过滤，返回过滤后剩余的剧目数量
int Play_Srv_FilterByName(play_list_t list, char filter[]){
	return 0;
}


