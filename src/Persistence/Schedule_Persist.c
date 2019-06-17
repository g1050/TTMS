#include "Schedule_Persist.h"
#include "../Service/Schedule.h"
#include "../Common/List.h"
#include "EntityKey_Persist.h"
#include <stdlib.h>
#include <stdio.h>
#include<unistd.h>
#include <assert.h>


static const char SCHEDULE_DATA_FILE[] = "Schedule.dat";
static const char SCHEDULE_DATA_TEMP_FILE[] = "ScheduleTmp.dat";
static const char SCHEDULE_KEY_NAME[]="Schedule";

int Schedule_Perst_Insert(schedule_t *data){
	return 0;
}

int Schedule_Perst_Update( schedule_t *data){
	return 0;
}

int Schedule_Perst_RemByID(int ID){
	return 0;
}

int Schedule_Perst_SelectByID(int ID, schedule_t *buf){
	return 0;
}

int Schedule_Perst_SelectAll(schedule_list_t list){
	return 0;
}

int Schedule_Perst_SelectByPlay(schedule_list_t list, int play_id){
	return 0;
}
