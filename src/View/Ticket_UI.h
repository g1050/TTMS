#ifndef TICKET_UI_H_
#define TICKET_UI_H_
#include "Schedule_UI.h"
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

int Ticket_UI_Mgtent(int id);

#endif