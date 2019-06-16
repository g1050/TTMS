#include "Ticket_Persist.h"
#include "./EntityKey_Persist.h"
#include <stdio.h>
#include "../Common/List.h"

static const char TICKET_DATA_FILE[] = "ticket.dat"; 
static const char TICKET_DATA_TEMP_FILE[] = "ticketmp.dat"; 
static const char TICKET_KEY_NAME[] = "ticket";

int  Ticket_Perst_Insert(ticket_list_t list)
{
    
	ticket_node_t *p;
	int len = 0;
	int rtn  = 0;
	assert(NULL!=list);
	List_ForEach(list,p)
	{
		len++;
	}

    //printf("len = %d",len);
	int key = EntKey_Perst_GetNewKeys(TICKET_KEY_NAME,len);
	if(key <= 0)
	{
		printf("key <= 0 \n");
		return 0;
	} 
	else
	{
		
		FILE *fp = fopen(TICKET_DATA_FILE,"ab");
		if(fp == NULL) 
		{
			printf("TICKET_DATA_FILE打开文件失败!\n");
			return 0;
		}
        
        ticket_t tmp;
		List_ForEach(list,p)
		{
				
				p->data.id = key++;
				rtn++;
                tmp = p->data;
				fwrite(&tmp,sizeof(ticket_t),1,fp);
		}
		fclose(fp);
		
		}
	
	return rtn;
}

int Ticket_Perst_Rem(int id)
{
    
	
	if(rename(TICKET_DATA_FILE, TICKET_DATA_TEMP_FILE)<0){
		printf("Cannot open file %s!\n", TICKET_DATA_FILE);
		return 0;
	}

	FILE *fpSour, *fpTarg;
	fpSour = fopen(TICKET_DATA_TEMP_FILE, "rb");
	if (NULL == fpSour ){
		printf("Cannot open file %s!\n",TICKET_DATA_FILE);
		return 0;
	}


	fpTarg = fopen(TICKET_DATA_FILE, "wb");
	if ( NULL == fpTarg ) {
		printf("Cannot open file %s!\n", TICKET_DATA_TEMP_FILE);
		return 0;
	}


	ticket_t buf;

	int found = 0;
	while (!feof(fpSour)) {
		if (fread(&buf, sizeof(ticket_t), 1, fpSour)) {
			if (id == buf.schedule_id) {
				found = 1;
				continue;
			}
			fwrite(&buf, sizeof(ticket_t), 1, fpTarg);
		}
	}

	fclose(fpTarg);
	fclose(fpSour);

	
	remove(TICKET_DATA_TEMP_FILE);
    //printf("found = %d",found);
	return found;
}