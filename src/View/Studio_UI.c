/*
* Copyright(C), 2007-2008, XUPT Univ.	
* ������ţ�TTMS_UC_01	 
* File name: Studio_UI.c			  
* Description : �ݳ������������	
* Author:   XUPT  		 
* Version:  v.1 	 
* Date: 	2015��4��22��	
*/

#include "../View/Studio_UI.h"

#include "../Common/List.h"
#include "../Service/Studio.h"
#include "../Service/Seat.h"


static const int STUDIO_PAGE_SIZE = 5;

#include <stdio.h>
#include <stdlib.h>

/*
��ʶ����TTMS_SCU_Studio_UI_MgtEnt 
�������ܣ����������ݳ�������ں�������ʾ��ǰ���ݳ������ݣ����ṩ�ݳ����������ӡ��޸ļ�ɾ�����ܲ�������ڡ�
����˵�����ޡ�
�� �� ֵ���ޡ�
*/
void Studio_UI_MgtEntry(void) {
	int i, id;
	int choice;

	studio_list_t head;
	studio_node_t *pos;
	Pagination_t paging;

	List_Init(head, studio_node_t);
	paging.offset = 0;
	paging.pageSize = STUDIO_PAGE_SIZE;

	//��������
	paging.totalRecords = Studio_Srv_FetchAll(head);
	Paging_Locate_FirstPage(head, paging);
    
    /* int cnt = 0; */
	do {
        //��ӡ��ӳ���Ļ�����Ϣ
		printf(
				"\n==================================================================\n");
		printf(
				"********************** 演出厅信息 **********************\n");
		printf("%5s  %18s  %10s  %10s  %10s\n", "ID", "名字", "行",
				"列", "座位数量");
		printf(
				"------------------------------------------------------------------\n");
		    //��ʾ����
		Paging_ViewPage_ForEach(head, paging, studio_node_t, pos, i){
			printf("%5d  %18s  %10d  %10d  %10d\n", pos->data.id,
					pos->data.name, pos->data.rowsCount, pos->data.colsCount,
					pos->data.seatsCount);
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
				"[1]上一页|[2]下一页 | [3]添加演出厅|[4]删除演出厅|[5]修改演出厅 | [6]座位管理 | [0]返回上层");
		printf(
				"\n\n\n\n==================================================================\n");
        printf("请输入您要进行的操作:");//ѡ��
		fflush(stdin);
        setbuf(stdin,NULL);
		scanf("%d", &choice);
		setbuf(stdin,NULL);
        printf("choice = %c",choice);
		fflush(stdin);


        //����ѡ�������Ӧ�ĺ���
		switch (choice) {
		case 3:
            system("clear");
			if (Studio_UI_Add()) //�����ӳɹ����������һҳ��ʾ
			{
				paging.totalRecords = Studio_Srv_FetchAll(head);
				Paging_Locate_LastPage(head, paging, studio_node_t);
			}
			break;
		case 4:
            system("clear");
			printf("请输入要删除的演出厅ID:");
			scanf("%d", &id);
			if (Studio_UI_Delete(id)) {	//������������
				paging.totalRecords = Studio_Srv_FetchAll(head);
				List_Paging(head, paging, studio_node_t);
			}
			break;
		case 5:
            system("clear");
			printf("请输入要修改的演出厅ID");
			scanf("%d", &id);
			if (Studio_UI_Modify(id)) {	//������������
				paging.totalRecords = Studio_Srv_FetchAll(head);
				List_Paging(head, paging, studio_node_t);
			}
			break;
		case 6:
            system("clear");
			printf("请输入要管理座位的演出厅:");
			scanf("%d", &id);
			Seat_UI_MgtEntry(id);
			paging.totalRecords = Studio_Srv_FetchAll(head);
			List_Paging(head, paging, studio_node_t)
			;
			break;
		case 1:
            system("clear");
			if (!Pageing_IsFirstPage(paging)) {
				Paging_Locate_OffsetPage(head, paging, -1, studio_node_t);
			}
			break;
		case 2:
            system("clear");
			if (!Pageing_IsLastPage(paging)) {
				Paging_Locate_OffsetPage(head, paging, 1, studio_node_t);
			}
			break;
		}
	} while (choice != 0);
	//�ͷ������ռ�
	List_Destroy(head, studio_node_t);
}

/*
��ʶ����TTMS_SCU_Studio_UI_Add 
�������ܣ�������ϵͳ������һ�����ݳ������ݡ�
����˵�����ޡ�
�� �� ֵ�����ͣ��ɹ��������ݳ����ĸ�����
*/
int Studio_UI_Add(void) {
	studio_t rec;
	int newRecCount = 0;
	char choice;

	do {
		system("clear");
		printf("\n=======================================================\n");
		printf("****************  Add New Projection Room  ****************\n");
		printf("-------------------------------------------------------\n");
		//ѯ�ʷ�ӳ����Ϣ
		printf("Room Name:");
		fflush(stdin);
		setbuf(stdin,NULL);
		gets(rec.name);

		printf("Row Count of Seats:");
		scanf("%d", &(rec.rowsCount));
		
		printf("Column Count of Seats:");
		scanf("%d", &(rec.colsCount));
		
		rec.seatsCount = 0;
		printf("=======================================================\n");

		if (Studio_Srv_Add(&rec)) {
			newRecCount += 1;
			printf("The new room added successfully!\n");

		} else
			printf("The new room added failed!\n");

		printf("-------------------------------------------------------\n");
		printf("[A]dd more, [R]eturn:");
		fflush(stdin);

		while (getchar() != '\n');
		
		scanf("%c", &choice);
	} while ('a' == choice || 'A' == choice);
	system("clear");
	return newRecCount;
}

/*
��ʶ����TTMS_SCU_Studio_UI_Mod
�������ܣ������޸�ϵͳ���ִ��һ���ݳ������ݡ�
����˵����idΪ���ͣ�����Ҫ�޸ĵ��ݳ���ID��
�� �� ֵ�����ͣ���ʾ�Ƿ�ɹ��޸����ݳ����ı�־��
*/
int Studio_UI_Modify(int id) {
	studio_t rec;
	int rtn = 0;
	int newrow, newcolumn;
	seat_list_t list;
	int seatcount;

	/*Load record*/
	if (!Studio_Srv_FetchByID(id, &rec)) {
		printf("The room does not exist!\nPress [Enter] key to return!\n");
		getchar();
		return 0;
	}

	printf("\n=======================================================\n");
	printf("****************  Update Projection Room  ****************\n");
	printf("-------------------------------------------------------\n");
	printf("Room ID:%d\n", rec.id);
	printf("Room Name[%s]:", rec.name);
	fflush(stdin);
	gets(rec.name);

	List_Init(list, seat_node_t);
	seatcount = Seat_Srv_FetchByRoomID(list, rec.id);
	if (seatcount) {
		do {			//�����λ�ļ���������λ��Ϣ������µ����б������ǰ�󣬷�����������
			printf("Row Count of Seats should >= [%d]:", rec.rowsCount);
			scanf("%d", &(newrow));
			printf("Column Count of Seats should >= [%d]:", rec.colsCount);
			scanf("%d", &(newcolumn));
		} while (newrow < rec.rowsCount || newcolumn < rec.colsCount);
		rec.rowsCount = newrow;
		rec.colsCount = newcolumn;
		rec.seatsCount = seatcount;
	} else {
		printf("Row Count of Seats:");
		scanf("%d", &rec.rowsCount);
		printf("Column Count of Seats:");
		scanf("%d", &rec.colsCount);
		rec.seatsCount = 0;
	}

	printf("-------------------------------------------------------\n");

	if (Studio_Srv_Modify(&rec)) {
		rtn = 1;
		printf(
				"The room data updated successfully!\nPress [Enter] key to return!\n");
	} else
		printf("The room data updated failed!\nPress [Enter] key to return!\n");

	getchar();
	return rtn;
}

/*
��ʶ����TTMS_SCU_Studio_UI_Del
�������ܣ�����ɾ��ϵͳ���ִ��һ���ݳ������ݡ�
����˵����idΪ���ͣ�����Ҫɾ�����ݳ���ID��
�� �� ֵ�����ͣ���ʾ�Ƿ�ɹ�ɾ�����ݳ����ı�־��
*/
int Studio_UI_Delete(int id) {

	int rtn = 0;

	if (Studio_Srv_DeleteByID(id)) {
		//��ɾ����ӳ��ʱ��ͬʱ���ݷ�ӳ��idɾ����λ�ļ��е���λ
		if (Seat_Srv_DeleteAllByRoomID(id))
			printf("成功删除该演出厅座位!!\n");
		printf(
				"成功删除该演出厅!\n按下[Enter] 返回上层!\n");
		rtn = 1;
	} else {
		printf("该演出厅不存在!\n按下 [Enter] 返回上层!\n");
	}
	setbuf(stdin,NULL);
	getchar();
	return rtn;
}

