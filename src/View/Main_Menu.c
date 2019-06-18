#include "Main_Menu.h"
#include "Schedule_UI.h"
#include "Studio_UI.h"
#include "Play_UI.h"
#include "Sale_UI.h"
#include "Account_UI.h"
#include "MaiAccount_UI.h"
#include "SalesAnalysis_UI.h"
#include "StaSales_UI.h"
#include <stdio.h>

#include "../View/Studio_UI.h"
void Main_Menu(void) {
	char choice;
	do { 
		system("clear");
		printf("\n==================================================================\n");
		printf("      **************** 剧院票务管理系统 ****************\n\n");
		printf("                       [S]演出厅管理界面\n");
		printf("                       [P]剧目管理界面\n");
		printf("                       [T]售票管理界面\n");
		printf("                       [C]查询演出票\n");
		printf("                       [R]退票界面\n");
		printf("                       [Q]查询演出界面\n");
		printf("                       [N]统计销售额界面\n");
		printf("                       [A]统计票房界面\n");
		printf("                       [F]维护个人资料\n");
		printf("                       [F]管理系统用户\n");
		printf("\n");
		printf("                       [E]退出系统\n");
		printf("\n==================================================================\n");
		printf("\n请输入您要进行的操作");
		
		fflush(stdin);//������뻺������ֹӰ���´�����,����linux��û�취��
		setbuf(stdin,NULL);
		choice = getchar();
		setbuf(stdin,NULL);
        fflush(stdin);
		switch (choice)
		 {
		case 'S':
		case 's':
            system("clear");
			Studio_UI_MgtEntry();
			break;
         case 'P': 
		 case 'p':
		 		system("clear");
			 Play_UI_MgtEntry(); 
			 break; 
		//  case 'Q': 
		// case 'q': 
		// 	system("clear");
		// 	 Schedule_UI_ListAll(); 
		// 	 break; 
		// case 'T': 
		// case 't': 
		// 	system("clear");
		// 	Sale_UI_MgtEntry(); 
		// 	break; 
		/* case 'R': */
		/* case 'r': */
			/* Sale_UI_ReturnTicket(); */
			/* break; */
		/* case 'N': */
		/* case 'n': */
			/* SalesAanalysis_UI_MgtEntry(); */
			/* break; */
		/* case 'A': */
		/* case 'a': */
			/* Account_UI_MgtEntry(); */
			/* break; */
		}
	} while ('E' != choice && 'e' != choice);
}

