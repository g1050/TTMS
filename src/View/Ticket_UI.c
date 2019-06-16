#include "Ticket_UI.h"
#include "Schedule_UI.h"
#include "stdio.h"

int Ticket_UI_Mgtent(id)
{
	schedule_t rec;
	if (!Schedule_Srv_FetchByID(id, &rec)) {
		printf("该演出计划不存在!\n按 [Enter] 返回上层!\n");
		setbuf(stdin,NULL);
		getchar();
		return 0;
	}
	else
	{//演出计划存在
        int choice;
        do
        {
            printf(
				"\n==================================================================\n");
            printf(
                    "********************** 演出计划信息 **********************\n");
            printf("%8s %8s  %8s  %8s  %8s %8s\n", "演出计划ID", "上映剧目ID", "演出厅ID",
                    "放映日期", "放映时间","座位数");
            printf(
                    "------------------------------------------------------------------\n");
            
                printf("%8d %8d  %8d  %d/%d/%d  %d/%d/%d %8d \n", rec.id,
                        rec.play_id, rec.studio_id, rec.date.year,
                        rec.date.month,rec.date.day,rec.time.hour,
                        rec.time.minute,rec.time.second,rec.seat_count);
                        printf(
                    "******************************************************************\n");
            printf(
                    "==================================================================\n");
        
                printf("请输入演出厅ID:");
                int roomID;
                scanf("%d",&roomID);
                printf(
                        "[1]生成演出票 | [2]重新生成票 | [0]返回上层\n");
                printf("请输入您要进行的操作:");
                setbuf(stdin,NULL);
                scanf("%d",&choice);
                system("clear");
                int flag = 0;
            switch(choice)
            {
                case 1:
                    flag = Ticket_Srv_GenBatch(&rec,roomID);
                    break;
                case 2:
                 flag = Ticket_Srv_DeleteBatch(id);
                 flag = Ticket_Srv_GenBatch(&rec,roomID);
                    break;
            }
            
            if(flag > 0)
            {
                    printf("操作成功!\n");
            }
            else
            {
                    printf("操作失败!\n");
            }
            printf(
                        "按 [0]返回上层\n");
                setbuf(stdin,NULL);
                scanf("%d",&choice);
                system("clear");
        } while (choice != 0);

		
        }
		
}