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
		printf("\n==================================================================\n");
		printf("**************** Theater Ticket Management System ****************\n");
		printf("[S]tudio Management.\n");
		printf("[P]lay Management.\n");
		printf("[T]icket Sale.\n");
		printf("[R]efound Ticket.\n");
		printf("[Q]ueries\n");
		printf("Stat[i]stical Sales.\n"); // 统计销售额 
		printf("Ra[n]king and Statistics.\n"); //统计票房 
		printf("[M]aintenance of Personal Accounts.\n"); //维护个人资料 
		printf("[A]ccount Management.\n"); //系统用户管理 
		printf("[E]xist.\n");
		printf("\n==================================================================\n");
		printf("Please input your choice:");
		fflush(stdin);
		choice = getchar();
		switch (choice) {
		case 'S':
		case 's':
			Studio_UI_MgtEntry();
			break;
 		case 'P':
		case 'p':
			Play_UI_MgtEntry();
			break;
		case 'Q':
		case 'q':
			Schedule_UI_ListAll();
			break;
		case 'T':
		case 't':
			Sale_UI_MgtEntry();
			break;
		case 'R':
		case 'r':
			Sale_UI_RetfundTicket();
			break;
		case 'I':
		case 'i':
			StaSales_UI_MgtEntry();
			break;
		case 'N':
		case 'n':
			SalesAnalysis_UI_MgtEntry ();
			break;
		case 'M':
		case 'm':
			MaiAccount_UI_MgtEntry ();
			break;
		case 'A':
		case 'a':
			Account_UI_MgtEntry();
			break;
		}
	} while ('E' != choice && 'e' != choice);
}

