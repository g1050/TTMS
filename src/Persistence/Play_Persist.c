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
	//��ԭʼ�ļ���������Ȼ���ȡ��������д�뵽�����ļ��У�����Ҫɾ����ʵ����˵���
	//���������ļ���ʵ�ּ�¼ɾ��
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

