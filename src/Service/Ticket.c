#include "Ticket.h"
#include "Seat.h"
#include "../Common/List.h"
#include "../View/Ticket_UI.h"
#include "Play.h"
#include  <stdio.h>


int  Ticket_Srv_GenBatch(schedule_t *rec,int id)//演出计划信息直接传过来
{
    ticket_list_t list;
    List_Init(list,ticket_node_t);

   
    //获取座位信息
    seat_list_t seat_list;
    List_Init(seat_list,seat_node_t);

    int seatCount = Seat_Srv_FetchValidByRoomID(seat_list,id);

   
    //获取剧目信息
    play_t buf;//int Play_Srv_FetchByID(int id,play_t* buf);
    Play_Srv_FetchByID(rec->play_id,&buf);
  
    if(!seatCount)
    {
        printf("该演出厅无可用座位或该演出厅不存在!\n");
        return 0;
    }
    else
    {
//         printf("Insert\n");
//         typedef struct 
// {
//     int id; //票id
//     int schedule_id;//演出计划id
//     int seat_id; //座位id
//     int price; //票价
//     int status;//票的状态
// }ticket_t;
         
        ticket_list_t p2;
        seat_list_t p;
        List_ForEach(seat_list,p)
        {
                p2 = (ticket_list_t)malloc(sizeof(ticket_node_t));
                p2->data.seat_id = p->data.id;
                p2->data.status = 1;//三种状态
                p2->data.schedule_id = rec->id;
                p2->data.price = buf.price;
                List_AddTail(list,p2);
        }
    int Ticket_Srv_DeleteBatch(int id);
        return Ticket_Perst_Insert(list);
    }
    

    
}


int Ticket_Srv_DeleteBatch(int id)
{
     return Ticket_Perst_Rem(id);
}