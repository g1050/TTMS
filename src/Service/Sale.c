#include "../Persistence/Sale_Persist.h"

//添加新订单信息
int Sale_Srv_Add(sale_t *data){
	return 0;
}

//修改票状态
int Ticket_Srv_Modify (const ticket_t *data){
	return 0;
}


//根据演出计划ID获取票的数据
int Ticket_Srv_FetchBySchID(ticket_list_t list, int schedule_id){
	return 0;

}


//根据ID获取票
ticket_node_t * Ticket_Srv_FetchBySeatID (ticket_list_t list, int seat_id){
	return 0;
}

