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

//���ݾ�Ŀ���������Ŀ����������ľ�Ŀ����
int Play_Srv_FetchByName(play_list_t list, char condt[]){
	return 0;

}



//���ݾ�Ŀ���ƹ��˴�filter��list���й��ˣ����ع��˺�ʣ��ľ�Ŀ����
int Play_Srv_FilterByName(play_list_t list, char filter[]){
	return 0;
}


