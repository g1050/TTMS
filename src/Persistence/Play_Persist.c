#include "Play_Persist.h"
#include "../Service/Play.h"
#include "../Common/List.h"
#include "../Persistence/EntityKey_Persist.h"
#include <stdlib.h>
#include <stdio.h>
#include<unistd.h>
#include <assert.h>
#include <string.h>

static const char PLAY_DATA_FILE[] = "Play.dat";
static const char PLAY_DATA_TEMP_FILE[] = "PlayTmp.dat";
static const char PLAY_KEY_NAME[]="Play";

int Play_Perst_Insert( play_t *data) {
	return 0;

}

int Play_Perst_Update( play_t *data) {
	return 0;
}

int Play_Perst_RemByID(int ID) {
	//将原始文件重命名，然后读取数据重新写入到数据文件中，并将要删除的实体过滤掉。
	//借助辅助文件，实现记录删除
	return 0;
}

int Play_Perst_SelectByID(int ID, play_t *buf) {
	return 0;
}

int Play_Perst_SelectAll(play_list_t list) {
	return 0;
}

int Play_Perst_SelectByName(play_list_t list, char condt[]) {
	return 0;
}

