/*
* Copyright(C), 2007-2008, XUPT Univ.	 
* ������ţ�TTMS_UC_02
* File name: Seat_UI.c			  
* Description : ������λ���������	
* Author:   XUPT  		 
* Version:  v.1 	 
* Date: 	2015��4��22��	
*/

#include "Seat_UI.h"
#include "../Service/Seat.h"

#include "../Service/Studio.h"
#include "../Common/List.h"
#include <stdio.h>

/*
��ʶ����TTMS_SCU_Seat_UI_S2C 
�������ܣ�������λ״̬��ȡ������ʾ���š�
����˵����statusΪseat_status_t���ͣ���ʾ��λ״̬��
�� �� ֵ���ַ��ͣ���ʾ��λ�Ľ�����ʾ���š�
*/
inline char Seat_UI_Status2Char(seat_status_t status) {

	return "#";
}

/*
��ʶ����TTMS_SCU_Seat_UI_C2S
�������ܣ�����������Ż�ȡ��λ״̬��
����˵����statusCharΪ�ַ��ͣ���ʾ������λ��������š�
�� �� ֵ��seat_status_t���ͣ���ʾ��λ��״̬��
*/
inline seat_status_t Seat_UI_Char2Status(char statusChar) {
	return SEAT_NONE;
}

/*
��ʶ����TTMS_SCU_Seat_UI_MgtEnt
�������ܣ�����������λ����ں�������ʾ��ǰ����λ���ݣ����ṩ��λ�������ӡ��޸ġ�ɾ�����ܲ�������ڡ�
����˵����roomIDΪ���ͣ�����Ҫ������λ���ݳ���ID��
�� �� ֵ���ޡ�
*/ 
void Seat_UI_MgtEntry(int roomID) {
	studio_t buf;
	if(Studio_Srv_FetchByID(roomID,&buf))
	{
		//printf("演出厅存在!\n");
				seat_list_t list;
				List_Init(list,seat_node_t);
				
				if( Seat_Srv_FetchByRoomID(list,roomID)== 0)//list用于存放座位信息
				{//不存在座位
					Seat_Srv_RoomInit(list,roomID,buf.rowsCount,buf.colsCount);
					buf.seatsCount = buf.colsCount*buf.rowsCount;
					Studio_Srv_Modify(&buf);
					printf("座位初始化完成!\n");
					printf("按[ENTER]继续\n");
					setbuf(stdin,NULL);
					getchar();
				}
				else
				{
						seat_list_t p;
						char map[buf.rowsCount+5][buf.colsCount+5];
						Seat_Srv_map(list,(char*)map,buf.colsCount);
						//printf("输出座位!\n");
						for(int  i =1;i<=buf.rowsCount;i++)
						{
							printf("第%d行 ",i);
							for(int j = 1;j<=buf.colsCount;j++)
							{
								printf("%c ",*((char *)map+i*buf.colsCount+j));
							}
							printf("\n");
						}
						//printf("map[2][2] = %c",map[2][2]);
						
						int choice ;             
						do
						{
							printf(
									"******************************************************************\n");
							printf(
									"[1]添加座位 | [2]删除座位 |  [3]修改座位 | [0]返回上层");
							printf(
									"\n\n\n\n==================================================================\n");
							printf("请输入您要进行的操作:");
							setbuf(stdin,NULL);
							scanf("%d",&choice);


							switch (choice)
							{
										case 1:
												{
															int row,col;
															printf("请输入要添加的座位坐标:\n");
															printf("行号:");
																scanf("%d",&row);
															printf("列号:");
																scanf("%d",&col);

															Seat_UI_Add(list,row,col);//int Seat_UI_Modify(seat_list_t list, int row, int column)
															char map[buf.rowsCount+5][buf.colsCount+5];
															Seat_Srv_map(list,(char*)map,buf.colsCount);
															//printf("输出座位!\n");
															for(int  i =1;i<=buf.rowsCount;i++)
															{
																printf("第%d行 ",i);
																for(int j = 1;j<=buf.colsCount;j++)
																{
																	printf("%c ",*((char *)map+i*buf.colsCount+j));
																}
																printf("\n");
															}
															//system("clear");
															break;
												}


									case 2:
								
												{
															int row,col;
															printf("请输入要删除的座位坐标:\n");
															printf("行号:");
																scanf("%d",&row);
															printf("列号:");
																scanf("%d",&col);

															Seat_UI_Delete(list,row,col);//int Seat_UI_Modify(seat_list_t list, int row, int column)
															char map[buf.rowsCount+5][buf.colsCount+5];
															Seat_Srv_map(list,(char*)map,buf.colsCount);
															//printf("输出座位!\n");
															for(int  i =1;i<=buf.rowsCount;i++)
															{
																printf("第%d行 ",i);
																for(int j = 1;j<=buf.colsCount;j++)
																{
																	printf("%c ",*((char *)map+i*buf.colsCount+j));
																}
																printf("\n");
															}
															//system("clear");
															break;
												}
										


									case 3:
										{
											int row,col;
											printf("请输入要管理的座位坐标:\n");
											printf("行号:");
												scanf("%d",&row);
											printf("列号:");
												scanf("%d",&col);

											Seat_UI_Modify(list,row,col);//int Seat_UI_Modify(seat_list_t list, int row, int column)
											char map[buf.rowsCount+5][buf.colsCount+5];
											Seat_Srv_map(list,(char*)map,buf.colsCount);
											//printf("输出座位!\n");
											for(int  i =1;i<=buf.rowsCount;i++)
											{
												printf("第%d行 ",i);
												for(int j = 1;j<=buf.colsCount;j++)
												{
													printf("%c ",*((char *)map+i*buf.colsCount+j));
												}
												printf("\n");
											}
											//system("clear");
											break;
										}
										



									default:
										printf("输入有误，请重新输入!\n");
										break;
							}
									
						}while(choice != 0);
						system("clear");
							
				}
		
	}
	else
	{
		printf("演出厅不存在!\n");
		return ;
	}
	
	//展示菜单
}

/*
ʶ����TTMS_SCU_Seat_UI_Add
�������ܣ���������һ���µ���λ���ݡ�
����˵������һ������listΪseat_list_t����ָ�룬ָ����λ����ͷָ�룬
         �ڶ�������rowsCountΪ���ͣ���ʾ��λ�����кţ�����������colsCountΪ���ͣ���ʾ��λ�����кš�
�� �� ֵ�����ͣ���ʾ�Ƿ�ɹ���������λ�ı�־��
*/
int Seat_UI_Add(seat_list_t list, int row, int column) {  //����һ����λ

	seat_list_t p;
	List_ForEach(list,p)
	{
		if(p->data.row == row && p->data.column ==column && p->data.status == 4)
		{
			p->data.status = 1;//4删除
		}
		else if(p->data.row == row && p->data.column ==column && p->data.status == 2)
		{
			printf("座位损坏，不可添加!\n");
		}
		else if(p->data.row == row && p->data.column ==column && p->data.status == 3)
		{
			printf("该位置是过道，不可添加!\n");
		}
	}
	return 0;
}

/*
��ʶ����TTMS_SCU_Seat_UI_Mod 
�������ܣ������޸�һ����λ���ݡ�
����˵������һ������listΪseat_list_t����ָ�룬ָ����λ����ͷָ�룬�ڶ�������rowsCountΪ���ͣ���ʾ��λ�����кţ�����������colsCountΪ���ͣ���ʾ��λ�����кš�
�� �� ֵ�����ͣ���ʾ�Ƿ�ɹ��޸�����λ�ı�־��
*/
int Seat_UI_Modify(seat_list_t list, int row, int column) {
	int flag = 0;
	seat_list_t p = Seat_Srv_FindByRowCol(list, row, column);
	if( p == NULL)
	{
		printf("该座位不存在!\n");
	}
	else
	{
		do
		{
				int status = 0;
				printf("该座位存在!\n");
				//printf("row = %d col = %d\n",p->data.row,p->data.column);
				printf("请输入您要修改的座位状态:\n");
				printf("[1] 好 | [2] 坏 | [3]过道 \n");
				setbuf(stdout,NULL);
				setbuf(stdin,NULL);
				scanf("%d",&status);
				//printf("status = %d\n",status);
				if(status >= 1 && status <= 3)
				{
					//printf("进入!\n");
						p->data.status = status;
						Seat_Srv_Modify(p);//Seat_Srv_Modify(const seat_list_t *data)
						return 0;
				}
				printf("输入有误!请重新输入!\n");

		} while (1);
		
		
		
	}
	
	return 0;

}

/*
��ʶ����TTMS_SCU_Seat_UI_Del
�������ܣ�����ɾ��һ����λ�����ݡ�
����˵������һ������listΪseat_list_t����ָ�룬ָ����λ����ͷָ�룬�ڶ�������rowsCountΪ���ͣ���ʾ��λ�����кţ�����������colsCountΪ���ͣ���ʾ��λ�����кš�
�� �� ֵ�����ͣ���ʾ�Ƿ�ɹ�ɾ������λ�ı�־��
*/
int Seat_UI_Delete(seat_list_t list, int row, int column) {
	
	int flag = 0;
	seat_list_t p;
	List_ForEach(list,p)
	{
		if(p->data.row == row && p->data.column ==column)
		{
			p->data.status = 4;//4删除
		}
	}
	
	return 0;

}

