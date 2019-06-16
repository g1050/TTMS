/*Author : Linux_sky */
static const int SCHEDULE_PAGE_SIZE = 5;

#include "Schedule_UI.h"
#include "../Common/List.h"
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
    
// typedef struct 
// {
//     int id; //演出计划Id
//     int play_id; //上映剧目id
//     int studio_id;//演出厅id;
//     ttms_data_t date;//放映日期
//     ttms_time_t time; //放映时间
//     int seat_count;//座位数量
// }schedule_t;
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
        printf("choice = %c",choice);
		fflush(stdin);


        //����ѡ�������Ӧ�ĺ���
		// switch (choice) {
		// case 3:
        //     system("clear");
		// 	if (Studio_UI_Add()) //�����ӳɹ����������һҳ��ʾ
		// 	{
		// 		paging.totalRecords = Studio_Srv_FetchAll(head);
		// 		Paging_Locate_LastPage(head, paging, studio_node_t);
		// 	}
		// 	break;
		// case 4:
        //     system("clear");
		// 	printf("请输入要删除的演出厅ID:");
		// 	scanf("%d", &id);
		// 	if (Studio_UI_Delete(id)) {	//������������
		// 		paging.totalRecords = Studio_Srv_FetchAll(head);
		// 		List_Paging(head, paging, studio_node_t);
		// 	}
		// 	break;
		// case 5:
        //     system("clear");
		// 	printf("请输入要修改的演出厅ID");
		// 	scanf("%d", &id);
		// 	if (Studio_UI_Modify(id)) {	//������������
		// 		paging.totalRecords = Studio_Srv_FetchAll(head);
		// 		List_Paging(head, paging, studio_node_t);
		// 	}
		// 	break;
		// case 6:
        //     system("clear");
		// 	printf("请输入要管理座位的演出厅:");
		// 	scanf("%d", &id);
		// 	Seat_UI_MgtEntry(id);
		// 	paging.totalRecords = Studio_Srv_FetchAll(head);
		// 	List_Paging(head, paging, studio_node_t)
		// 	;
		// 	break;
		// case 1:
        //     system("clear");
		// 	if (!Pageing_IsFirstPage(paging)) {
		// 		Paging_Locate_OffsetPage(head, paging, -1, studio_node_t);
		// 	}
		// 	break;
		// case 2:
        //     system("clear");
		// 	if (!Pageing_IsLastPage(paging)) {
		// 		Paging_Locate_OffsetPage(head, paging, 1, studio_node_t);
		// 	}
		// 	break;
		// }
	} while (choice != 0);
	//�ͷ������ռ�
    system("clear");
	List_Destroy(head, schedule_node_t);

    return 0;
}


    