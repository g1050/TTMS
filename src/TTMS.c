/*
* Copyright(C), 2007-2008, XUPT Univ.	 
* File name: TTMS.c			  
* Description : Main in C, Ansi-style	
* Author:   XUPT  		 
* Version:  v.1 	 
* Date: 	2015��4��22��	
*/
#include "./Service/Account.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <sys/io.h>
#include "./View/Main_Menu.h"

extern account_t gl_CurUser;


int main(void) {
	setvbuf(stdout, NULL, _IONBF, 0);
	system("clear");
	SysLogin();//用户登录

	// printf(" type = %d\n",gl_CurUser.type);
	if(gl_CurUser.type == 0 || gl_CurUser.type == 9)//系统管理员
	{
		puts("菜单1");
		Main_Menu();
	}
	else if(gl_CurUser.type == 1 )//售票员
	{
		puts("菜单2");
		Main_Menu1();
	}
	else if(gl_CurUser.type == 2)//经理
	{
		puts("菜单3");
		Main_Menu2();
	}

	return EXIT_SUCCESS;
}
