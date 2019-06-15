/*Author : Linux_sky */


#include "../View/Play_UI.h"

#include "../Common/List.h"
//#include "../Service/Studio.h"
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
	//paging.totalRecords = Studio_Srv_FetchAll(head); printf("进入!\n");
	Paging_Locate_FirstPage(head, paging);
   
    /* int cnt = 0; */
	do {
     
		printf(
				"\n==================================================================\n");
		printf(
				"********************** 剧目信息 **********************\n");
		printf("%5s %30s  %9s  %5d  %22s  %5d\n", "ID", "剧目名字", "出品地区",
				"时长", "开始->结束","票价");
		printf(
				"------------------------------------------------------------------\n");
		    //��ʾ����
		Paging_ViewPage_ForEach(head, paging, play_node_t, pos, i)
        {
			printf("%5d %30s  %9s  %5d  %10d->%10d  %5d\n", pos->data.id,pos->data.name,pos->data.area,pos->data.duration
            ,pos->data.start_data,pos->data.end_date,pos->data.price);
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
				"[1]上一页|[2]下一页 | [3]添加新剧目|[4]删除剧目|[5]查询剧目 | [6]安排演出 | [0]返回上层");
		printf(
				"\n\n\n\n==================================================================\n");
        printf("请输入您要进行的操作:");//ѡ��
		fflush(stdin);
        setbuf(stdin,NULL);
		scanf("%d", &choice);
		setbuf(stdin,NULL);
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
	// List_Destroy(head, studio_node_t);

}