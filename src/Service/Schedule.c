#include "Schedule.h"
#include "../Common/List.h"
#include "../Persistence/Schedule_Persist.h"
#include "Ticket.h"
#include <stdio.h>

 int Schedule_Srv_Add( schedule_t *data) {
		return 0;
}

int Schedule_Srv_Modify( schedule_t *data) {
	return 0;
}

 int Schedule_Srv_DeleteByID(int ID) {
		return 0;
}

 int Schedule_Srv_FetchByID(int ID, schedule_t *buf) {

		return 0;
}

 int Schedule_Srv_FetchAll(schedule_list_t list) {
		return 0;
}

 int Schedule_Srv_FetchByPlay(schedule_list_t list,int play_id) {
		return 0;
}


//���ݾ�ĿID��ȡƱ��
int Schedule_Srv_StatRevByPlay(int play_id, int *soldCount){
	return 0;

}

//�����ݳ�ID��ͳ�������ʼ�Ʊ��������Ʊ��������
//int Schedule_Srv_StatRevByPlay(int play_id, int *soldCount, int *totalCount) {
//	return 0;
//}

