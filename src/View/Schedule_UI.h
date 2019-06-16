/*Author : Linux_sky */
#ifndef SCHEDULE_UI_H_
#define SCHEDULE_UI_H_
#include "Play_UI.h"


//演出计划数据结构

typedef struct  
{
    int hour;
    int minute;
    int second;
}ttms_time_t;

typedef struct 
{
    int id; //演出计划Id
    int play_id; //上映剧目id
    int studio_id;//演出厅id;
    ttms_data_t date;//放映日期
    ttms_time_t time; //放映时间
    int seat_count;//座位数量
}schedule_t;

typedef struct schedule_node
{
    schedule_t data;
    struct  schedule_node *next;
    struct schedule_node *prev;
}schedule_node_t,*schedule_list_t;

int schedule_UI_MgtENtry();

int Schedule_UI_Add(void);

int Schedule_UI_Delete(int id);

#endif