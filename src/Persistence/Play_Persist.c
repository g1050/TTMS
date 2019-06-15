#include "Play_Persist.h"
#include "../Common/List.h"
#include <stdio.h>

static const char PLAY_DATA_FILE[] = "play.dat"; 
static const char PLAY_DATA_TEMP_FILE[] = "play.dat"; 
static const char PLAY_KEY_NAME[] = "play";


int Play_Perst_SelectAll(play_list_t list)
{
    play_node_t *newNode;
	play_t data;
	int recCount = 0;

	assert(NULL!=list);

    List_Free(list,play_node_t);
	//List_Free(list, play_node_t);

	FILE *fp = fopen(PLAY_DATA_FILE, "rb");
	if (NULL == fp) { //�ļ�������
		return 0;
	}

	while (!feof(fp)) {
		if (fread(&data, sizeof(play_t), 1, fp)) {
			newNode = (play_t*) malloc(sizeof(play_node_t));
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