/*Author : Linux_sky */
#ifndef SCHEDULE_UI_H_
#define SCHEDULE_UI_H_
#include "Play_UI.h"
//票数据结构
typedef struct 
{
    int id; //票id
    int schedule_id;//演出计划id
    int seat_id; //座位id
    int price; //票价
    int status;//票的状态
}ticket_t;

typedef struct ticket_node
{
    ticket_t data;
    struct ticket_node *prev;
    struct ticket_node *next;
}ticket_node_t;

typedef ticket_node_t* ticket_list_t;

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



#endif