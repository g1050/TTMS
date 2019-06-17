#include "Schedule_UI.h"
#include "../Common/List.h"
#include "../Service/Schedule.h"
#include "../Service/Play.h"
#include "../Service/Studio.h"

#include <stdio.h>
#include <stdlib.h>

void Schedule_UI_ListAll(void) {
}

int Schedule_UI_Add(int play_id) {
	return 0;
}

int Schedule_UI_Modify(int id) {
	return 0;
}

int Schedule_UI_Delete(int id) {
	return 0;
}
int Schedule_UI_Query(int id) {
	return 0;
}

/*以列表模式显示给定剧目的演出计划信息*/
void Schedule_UI_ListByPlay(play_t *play, schedule_list_t list,
		Pagination_t paging) {
}

void Schedule_UI_MgtEntry(int play_id) {
}
