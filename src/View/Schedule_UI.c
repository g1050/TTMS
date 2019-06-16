/*Author : Linux_sky */
static const int SCHEDULE_PAGE_SIZE = 5;

#include "Schedule_UI.h"
#include "../Common/List.h"
#include "Ticket_UI.h"
#include <stdio.h>
#include <stdlib.h>

int schedule_UI_MgtENtry()
{
    int i, id;
	int choice;

	schedule_list_t head;
	schedule_node_t *pos;
	Pagination_t paging;

	List_Init(head, schedule_node_t);
	paging.offset = 0;
	paging.pageSize = SCHEDULE_PAGE_SIZE;

	paging.totalRecords = Schedule_Srv_FetchAll(head);
	Paging_Locate_FirstPage(head, paging);
    

	do {
        //��ӡ��ӳ���Ļ�����Ϣ
		printf(
				"\n==================================================================\n");
		printf(
				"********************** 演出计划信息 **********************\n");
		printf("%8s %8s  %8s  %8s  %8s %8s\n", "演出计划ID", "上映剧目ID", "演出厅ID",
				"放映日期", "放映时间","座位数");
		printf(
				"------------------------------------------------------------------\n");
		
		Paging_ViewPage_ForEach(head, paging, schedule_node_t, pos, i){
			printf("%8d %8d  %8d  %d/%d/%d  %d/%d/%d %8d \n", pos->data.id,
					pos->data.play_id, pos->data.studio_id, pos->data.date.year,
					pos->data.date.month,pos->data.date.day,pos->data.time.hour,
					pos->data.time.minute,pos->data.time.second,pos->data.seat_count);
		}

		printf(
				"------- 共:%2d页 ----------------------- 页数 :%2d/%2d ----\n",
				paging.totalRecords, Pageing_CurPage(paging),
				Pageing_TotalPages(paging));
		
        
        
        printf("\n\n\n\n"); 
        
        
        printf(
				"******************************************************************\n");
		printf(
				"[1]上一页|[2]下一页 | [3]添加演出计划|[4]删除演出计划|[5]修改演出计划 | [6]生成演出票| [0]返回上层");
		printf(
				"\n\n\n\n==================================================================\n");
        printf("请输入您要进行的操作:");
		fflush(stdin);
        setbuf(stdin,NULL);
		scanf("%d", &choice);
		setbuf(stdin,NULL);
		fflush(stdin);


     
		switch (choice) {
		case 3:
            system("clear");
			if (Schedule_UI_Add()) 
			{
				paging.totalRecords = Schedule_Srv_FetchAll(head);
				Paging_Locate_LastPage(head, paging, schedule_node_t);
			}
			break;
		case 4:
            system("clear");
			printf("请输入要删除的演出计划ID:");
			scanf("%d", &id);
			if (Schedule_UI_Delete(id)) {	
				paging.totalRecords = Schedule_Srv_FetchAll(head);
				List_Paging(head, paging, schedule_node_t);
			}
			break;
		case 5:
            system("clear");
			printf("请输入要修改的演出计划ID");
			scanf("%d", &id);
			if (Schedule_UI_Modify(id)) {	
				paging.totalRecords = Schedule_Srv_FetchAll(head);
				List_Paging(head, paging, schedule_node_t);
			}
			break;
		case 6:
            system("clear");
			int id;
			printf("请选择要生成哪个演出计划的演出票(ID):");
			scanf("%d",&id);
			Ticket_UI_Mgtent(id);
			break;
		case 1:
            system("clear");
			if (!Pageing_IsFirstPage(paging)) {
				Paging_Locate_OffsetPage(head, paging, -1, schedule_node_t);
			}
			break;
		case 2:
            system("clear");
			if (!Pageing_IsLastPage(paging)) {
				Paging_Locate_OffsetPage(head, paging, 1, schedule_node_t);
			}
			break;
		}
	} while (choice != 0);
	//�ͷ������ռ�
    system("clear");
	List_Destroy(head, schedule_node_t);

    return 0;
}
// typedef struct 
// {
//     int id; //演出计划Id
//     int play_id; //上映剧目id
//     int studio_id;//演出厅id;
//     ttms_data_t date;//放映日期
//     ttms_time_t time; //放映时间
//     int seat_count;//座位数量
// }schedule_t;
int Schedule_UI_Add(void) {
	schedule_t rec;
	int newRecCount = 0;
	char choice;

	do {
		system("clear");
		printf("\n=======================================================\n");
		printf("****************  添加新剧目  ****************\n");
		printf("-------------------------------------------------------\n");
		
		printf("演出的剧目ID:");
		fflush(stdin);
		setbuf(stdin,NULL);
		scanf("%d",&rec.play_id);

		printf("演出厅ID:");
		fflush(stdin);
		setbuf(stdin,NULL);
		scanf("%d",&rec.studio_id);
		
		printf("放映日期(年/月/日):");
		fflush(stdin);
		setbuf(stdin,NULL);
		scanf("%d/%d/%d",&rec.date.year,&rec.date.month,&rec.date.day);

		printf("放映时间(时/分/秒):");
		fflush(stdin);
		setbuf(stdin,NULL);
		scanf("%d/%d/%d",&rec.time.hour,&rec.time.minute,&rec.time.second);

		printf("座位数量:");
		fflush(stdin);
		setbuf(stdin,NULL);
		scanf("%d",&rec.seat_count);
		
		printf("=======================================================\n");

		if (Schedule_Srv_Add(&rec)) {
			newRecCount += 1;
			printf("新演出计划添加成功!\n");

		} else
			printf("新演出计划添加失败!\n");

		printf("-------------------------------------------------------\n");
		printf("[A]继续添加, [R]返回上层:");
		fflush(stdin);

		while (getchar() != '\n');
		
		scanf("%c", &choice);
	} while ('a' == choice || 'A' == choice);
	system("clear");
	return newRecCount;
}

int Schedule_UI_Delete(int id)
{
	int rtn = 0;

	if (Schedule_Srv_DeleteByID(id)) {
		printf(
				"成功删除该演出计划!\n按下[Enter] 返回上层!\n");
		rtn = 1;
	} else {
		printf("该演出计划不存在!\n按下 [Enter] 返回上层!\n");
	}
	setbuf(stdin,NULL);
	getchar();
	return rtn;

}

int Schedule_UI_Modify(int id)
{
	int rtn = 0;
	schedule_t rec;
	schedule_list_t list;
	int seatcount;

	/*Load record*/
	if (!Schedule_Srv_FetchByID(id, &rec)) {
		printf("该演出计划不存在!\n按 [Enter] 返回上层!\n");
		setbuf(stdin,NULL);
		getchar();
		return 0;
	}
	else
	{
		
	
	

	printf("\n=======================================================\n");
	printf("****************  修改演出计划  ****************\n");
	printf("-------------------------------------------------------\n");

		printf("演出的剧目ID:");
		fflush(stdin);
		setbuf(stdin,NULL);
		scanf("%d",&rec.play_id);

		printf("演出厅ID:");
		fflush(stdin);
		setbuf(stdin,NULL);
		scanf("%d",&rec.studio_id);
		
		printf("放映日期(年/月/日):");
		fflush(stdin);
		setbuf(stdin,NULL);
		scanf("%d/%d/%d",&rec.date.year,&rec.date.month,&rec.date.day);

		printf("放映时间(时/分/秒):");
		fflush(stdin);
		setbuf(stdin,NULL);
		scanf("%d/%d/%d",&rec.time.hour,&rec.time.minute,&rec.time.second);

		printf("座位数量:");
		fflush(stdin);
		setbuf(stdin,NULL);
		scanf("%d",&rec.seat_count);

	

	printf("-------------------------------------------------------\n");

	if (Schedule_Srv_Modify(&rec)) {
		rtn = 1;
		printf(
				"成功修改剧目信息!\n按下 [Enter] 返回上层!\n");
	} else
		printf("修改剧目信息失败!\nPress [Enter]返回上层!\n");

	setbuf(stdin,NULL);
	getchar();
}
	return rtn;
}


    