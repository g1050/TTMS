/*
 *  Seat_UI.c
 *
 *  Created on: 2015��5��23��
 *  Author: lc
 */
#include "Seat_UI.h"

#include "../Service/Seat.h"
#include "../Service/Studio.h"
#include "../Common/List.h"
#include <stdio.h>

//����״̬���ض�Ӧ��ʾ״̬����
inline char Seat_UI_Status2Char(seat_status_t status) {

	return "#";
}

//����״̬���ŷ�����λ״̬
inline seat_status_t Seat_UI_Char2Status(char statusChar) {
	return SEAT_NONE;
}

void Seat_UI_MgtEntry(int roomID) {

}

int Seat_UI_Add(seat_list_t list, int roomID, int row, int column) {  //����һ����λ

	return 0;
}

int Seat_UI_Modify(seat_list_t list, int row, int column) {

	return 0;

}

int Seat_UI_Delete(seat_list_t list, int row, int column) {

	return 0;

}

