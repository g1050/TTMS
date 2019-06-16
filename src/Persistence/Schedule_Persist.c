#include "../View/Schedule_UI.h"
#include "EntityKey_Persist.h"	 
#include "../Common/List.h"
#include <stdio.h>

static const char SCHEDULE_DATA_FILE[] = "Schedule.dat"; 
static const char SCHEDULE_DATA_TEMP_FILE[] = "ScheduleTmp.dat"; 
static const char SCHEDULE_KEY_NAME[] = "Schedule"; 

int Schedule_Perst_SelectAll(schedule_list_t list)
{
    schedule_node_t *newNode;
	schedule_t data;
	int recCount = 0;

	assert(NULL!=list);

	List_Free(list, schedule_node_t);

	FILE *fp = fopen(SCHEDULE_DATA_FILE, "rb");
	if (NULL == fp) { //�ļ�������
		return 0;
	}

	while (!feof(fp)) {
		if (fread(&data, sizeof(schedule_t), 1, fp)) {
			newNode = (schedule_node_t*) malloc(sizeof(schedule_node_t));
			if (!newNode) {
				printf(
						"Warning, Memory OverFlow!!!\n Cannot Load more Data into memory!!!\n");
				break;
			}
			newNode->data = data;
			List_AddTail(list, newNode);
			recCount++;
		}
	}
	fclose(fp);
	return recCount;
}