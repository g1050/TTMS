/*Author : Linux_sky */


#include "../View/Play_UI.h"

#include "../Common/List.h"
#include "../Service/Play.h"
#include "Schedule.h"
//#include "../Service/Seat.h"


static const int Play_PAGE_SIZE = 5;

#include <stdio.h>
#include <stdlib.h>



void Play_UI_MgtEntry() 
{
    play_list_t head;
	play_node_t *pos;
	Pagination_t paging;
	int i, id;
	int choice;

	
	List_Init(head, play_node_t);
	paging.offset = 0;
	paging.pageSize = Play_PAGE_SIZE;

	
	//��������
	paging.totalRecords = Play_Srv_FetchAll(head);
	Paging_Locate_FirstPage(head, paging);
   
    /* int cnt = 0; */
	do {
     
		printf(
				"\n==================================================================\n");
		printf(
				"********************** 剧目信息 **********************\n");
		printf("%5s %30s  %9s  %5s  %22s  %5s\n", "ID", "剧目名字", "出品地区",
				"时长", "开始->结束","票价");
		printf(
				"------------------------------------------------------------------\n");
		    //��ʾ����
		Paging_ViewPage_ForEach(head, paging, play_node_t, pos, i)
        {
			printf("%5d %15s  %9s  %5d  %d/%d/%d->%d/%d/%d  %5d\n", pos->data.id,pos->data.name,pos->data.area,pos->data.duration
            ,pos->data.start_data.year,pos->data.start_data.month,pos->data.start_data.day,pos->data.end_date.year,pos->data.end_date.month,pos->data.end_date.day,pos->data.price);
		}

		printf(
				"------- 共:%2d页 ----------------------- 页数 :%2d/%2d ----\n",
				paging.totalRecords, Pageing_CurPage(paging),
				Pageing_TotalPages(paging));
		
        
        
        printf("\n\n\n\n"); 
        
        //��ʾ������ӳ���µĿ�ѡ��
        printf(
				"******************************************************************\n");
		printf(
				"[1]上一页|[2]下一页 | [3]添加新剧目|[4]删除剧目| [5]修改剧目 | [6] 查询剧目 | [7]安排演出 | [0]返回上层");
		printf(
				"\n\n\n\n==================================================================\n");
        printf("请输入您要进行的操作:");//ѡ��
		fflush(stdin);
        setbuf(stdin,NULL);
		scanf("%d", &choice);
		setbuf(stdin,NULL);
		fflush(stdin);


       
		switch (choice) {
		case 3:
            system("clear");
			if (Play_UI_Add()) 
			{
				paging.totalRecords = Play_Srv_FetchAll(head);
				Paging_Locate_LastPage(head, paging, play_node_t);
			}
			break;
		case 4:
            system("clear");
			printf("请输入要删除的剧目ID:");
			scanf("%d", &id);
			if (Play_UI_Delete(id)) {	
				paging.totalRecords = Play_Srv_FetchAll(head);
				List_Paging(head, paging, play_node_t);
			}
			break;
		case 5:
            system("clear");
			printf("请输入要修改的剧目ID");
			scanf("%d", &id);
			if (PLay_UI_Modify(id)) {	
				paging.totalRecords = Play_Srv_FetchAll(head);
				List_Paging(head, paging, play_node_t);
			}
			break;
		case 6:
            system("clear");
			printf("请输入要查询的剧目:");
			scanf("%d", &id);
			play_UI_ask(id);
			paging.totalRecords = Play_Srv_FetchAll(head);
			List_Paging(head, paging, play_node_t);
			break;
		case 7:
			system("clear");
			schedule_UI_MgtENtry();
			paging.totalRecords = Play_Srv_FetchAll(head);
			List_Paging(head, paging, play_node_t);
			break;
		case 1:
            system("clear");
			if (!Pageing_IsFirstPage(paging)) {
				Paging_Locate_OffsetPage(head, paging, -1, play_node_t);
			}
			break;
		case 2:
            system("clear");
			if (!Pageing_IsLastPage(paging)) {
				Paging_Locate_OffsetPage(head, paging, 1, play_node_t);
			}
			break;
		}


	} while (choice != 0);
	//�ͷ������ռ�
	 List_Destroy(head, play_node_t);

}

int Play_UI_Add()
{
	play_t rec;
	int newRecCount = 0;
	int  choice;
// 	typedef struct 
// {
//     int  id; //剧目ID
//     char name[31]; //剧目名称
//     int type; //剧目类型 
//     char area[9]; //出品地区
//     int dating ; //适合年龄
//     int duration ; //时长
//     ttms_data_t start_data;
//     ttms_data_t end_date;
//     int price; //票价
// }play_t;

	do {
		system("clear");
		printf("\n=======================================================\n");
		printf("****************  添加新剧目  ****************\n");
		printf("-------------------------------------------------------\n");
		//ѯ�ʷ�ӳ����Ϣ
		printf("新剧目名称:");
		fflush(stdin);
		setbuf(stdin,NULL);
		gets(rec.name);

		printf("\n剧目类型 [1].影视 | [2].戏剧 | [3].音乐会:");
		setbuf(stdin,NULL);
		scanf("%d", &rec.type);
		while(!(rec.type == 1 || rec.type == 2  || rec.type == 3))
		{
				printf("输入不合法!请重新输入:\n");
				setbuf(stdin,NULL);
				scanf("%d", &rec.type);
		}
		
		
		
		printf("\n出品地区:");
		setbuf(stdin,NULL);
		scanf("%s", &(rec.area));

		printf("\n适合年龄: [1].儿童 | [2].青少年 | [3].成人");
		setbuf(stdin,NULL);
		scanf("%d", &(rec.dating));
		while(!(rec.dating == 1 || rec.dating == 2  || rec.dating == 3))
		{
				printf("输入不合法!请重新输入:");
				setbuf(stdin,NULL);
				scanf("%d", &rec.dating);
		}

		printf("\n时长(分钟):");
		setbuf(stdin,NULL);
		scanf("%d", &(rec.duration));

		printf("\n上映时间 (年/月/日):");
		setbuf(stdin,NULL);
		scanf("%d/%d/%d", &(rec.start_data.year),&(rec.start_data.month),&(rec.start_data.day));

		printf("\n下架时间 (年/月/日):");
		setbuf(stdin,NULL);
		scanf("%d/%d/%d", &(rec.end_date.year),&(rec.end_date.month),&(rec.end_date.day));
		while(!(rec.start_data.year <= rec.end_date.year ))
		{
				printf("输入不合法!请重新输入(下架日期必须晚于上映日期):");
				setbuf(stdin,NULL);
				scanf("%d", &rec.dating);
		}

		printf("\n票价 (元) :");
		setbuf(stdin,NULL);
		scanf("%d", &(rec.price));
		
		printf("=======================================================\n");

		
		if (Play_Srv_Add(&rec))
		 {
			newRecCount += 1;
			printf("成功添加新剧目!\n");
		} else
			printf("新剧目添加失败!\n");

		printf("-------------------------------------------------------\n");
		printf("[1]继续添加, [0]返回上层");
		
		setbuf(stdin,NULL);
		scanf("%d", &choice);
		
	} while (choice != 0);


	system("clear");
	return newRecCount;
}

int Play_UI_Delete(int id)
{
	int rtn = 0;

	if (Play_Srv_DeleteByID(id)) {
		printf(
				"成功删除该剧目!\n按下[Enter] 返回上层!\n");
		rtn = 1;
	} else {
		printf("该剧目不存在!\n按下 [Enter] 返回上层!\n");
	}
	setbuf(stdin,NULL);
	getchar();
	return rtn;

}


int PLay_UI_Modify(id)
{
	play_t rec;
	int rtn = 0;
	int newrow, newcolumn;
	play_list_t list;
	int seatcount;

	/*Load record*/
	if (!Play_Srv_FetchByID(id, &rec)) {
		printf("该剧目不存在!\n按 [Enter] 返回上层!\n");
		setbuf(stdin,NULL);
		getchar();
		return 0;
	}
	else
	{
		printf("该剧目存在!\n");
	}
	

	printf("\n=======================================================\n");
	printf("****************  修改剧目信息  ****************\n");
	printf("-------------------------------------------------------\n");

	printf("剧目名称:");
		fflush(stdin);
		setbuf(stdin,NULL);
		gets(rec.name);

		printf("\n剧目类型 [1].影视 | [2].戏剧 | [3].音乐会:");
		setbuf(stdin,NULL);
		scanf("%d", &rec.type);
		while(!(rec.type == 1 || rec.type == 2  || rec.type == 3))
		{
				printf("输入不合法!请重新输入:\n");
				setbuf(stdin,NULL);
				scanf("%d", &rec.type);
		}
		
		
		
		printf("\n出品地区:");
		setbuf(stdin,NULL);
		scanf("%s", &(rec.area));

		printf("\n适合年龄: [1].儿童 | [2].青少年 | [3].成人");
		setbuf(stdin,NULL);
		scanf("%d", &(rec.dating));
		while(!(rec.dating == 1 || rec.dating == 2  || rec.dating == 3))
		{
				printf("输入不合法!请重新输入:");
				setbuf(stdin,NULL);
				scanf("%d", &rec.dating);
		}

		printf("\n时长(分钟):");
		setbuf(stdin,NULL);
		scanf("%d", &(rec.duration));

		printf("\n上映时间 (年/月/日):");
		setbuf(stdin,NULL);
		scanf("%d/%d/%d", &(rec.start_data.year),&(rec.start_data.month),&(rec.start_data.day));

		printf("\n下架时间 (年/月/日):");
		setbuf(stdin,NULL);
		scanf("%d/%d/%d", &(rec.end_date.year),&(rec.end_date.month),&(rec.end_date.day));
		while(!(rec.start_data.year <= rec.end_date.year ))
		{
				printf("输入不合法!请重新输入(下架日期必须晚于上映日期):");
				setbuf(stdin,NULL);
				scanf("%d", &rec.dating);
		}

		printf("\n票价 (元) :");
		setbuf(stdin,NULL);
		scanf("%d", &(rec.price));

	

	printf("-------------------------------------------------------\n");

	if (Play_Srv_Modify(&rec)) {
		rtn = 1;
		printf(
				"成功修改剧目信息!\n按下 [Enter] 返回上层!\n");
	} else
		printf("修改剧目信息失败!\nPress [Enter]返回上层!\n");

	setbuf(stdin,NULL);
	getchar();
	return rtn;
}

int play_UI_ask(id)
{
	play_t rec;
	if (!Play_Srv_FetchByID(id, &rec)) {
		printf("该剧目不存在!\n按 [Enter] 返回上层!\n");
		setbuf(stdin,NULL);
		getchar();
		system("clear");
		return 0;
	}
	else
	{
		printf(
				"\n==================================================================\n");
		printf(
				"********************** 剧目信息 **********************\n");
		printf("%5s %30s  %9s  %5s  %22s  %5s\n", "ID", "剧目名字", "出品地区",
				"时长", "开始->结束","票价");
		printf(
				"------------------------------------------------------------------\n");

				printf("%5d %15s  %9s  %5d  %d/%d/%d->%d/%d/%d  %5d\n", rec.id,rec.name,rec.area,rec.duration
            ,rec.start_data.year,rec.start_data.month,rec.start_data.day,rec.end_date.year,rec.end_date.month,rec.end_date.day,rec.price);
		printf("该剧目存在!\n按 [Enter] 返回上层!\n");
		setbuf(stdin,NULL);
		getchar();
		system("clear");
	
	}
	return 0;
}