/**************************************************************************************************/
/* Copyright (C) mc2lab.com, SSE@USTC, 2014-2015                                                  */
/*                                                                                                */
/*  FILE NAME             :  menu.c                                                               */
/*  PRINCIPAL AUTHOR      :  Saki Chuang                                                          */
/*  SUBSYSTEM NAME        :  menu                                                                 */
/*  MODULE NAME           :  menu                                                                 */
/*  LANGUAGE              :  C                                                                    */
/*  TARGET ENVIRONMENT    :  ANY                                                                  */
/*  DATE OF FIRST RELEASE :  2014/08/31                                                           */
/*  DESCRIPTION           :  This is a menu program                                               */
/**************************************************************************************************/

/*
 * Revision log:
 *
 * Created by Mengning, 2014/09/10
 *
 */

// menu.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int Help();

#define CMD_MAX_LEN 128
#define DESC_LEN    1024
#define CMD_NUM     10

typedef struct DataNode			//define node
{
    char   cmd[CMD_MAX_LEN];
    char   desc[DESC_LEN];
    struct  DataNode *next;
} tDataNode;

tDataNode *head;

void main()						//main
{
	tDataNode *head = NULL;
	/*Init cmd list*/
	int CmdNum;
	tDataNode *p = NULL;
	tDataNode *r = NULL;
	head=(tDataNode*)malloc(sizeof(tDataNode));
	head->next = NULL;
	r=head;
	for(CmdNum=0;CmdNum<CMD_NUM;CmdNum++)
	{		
		p=(tDataNode*)malloc(sizeof(tDataNode));
		sprintf(p->cmd,"cmd%d",CmdNum);
		sprintf(p->desc,"this is %d cmd!",CmdNum);
		r->next = p;
		r=r->next;
		//p=(tDataNode*)malloc(sizeof(tDataNode));
		//head = p;
	}
	r->next=NULL;
	printf("menu list:\n");
	p = head->next;
	while(p !=NULL)					//show all cmd
	{
		printf("%s - %s\n",p->cmd,p->desc);
		p=p->next;
	}

   /* cmd line begins */
    while(1)
    {
        char cmd[CMD_MAX_LEN];
        int i;
		int CmdLen;
		printf("Input a cmd number > ");
        scanf("%s", cmd);
		CmdLen = strlen(cmd);
		//for(i=0;i<CmdLen;i++)
		//{
		//	cmd[i];
		//}
		tDataNode *p = head->next;
        while(p != NULL)
        {
			//if(p->cmd==cmd)
			if(strcmp(cmd,p->cmd)==0)
			{	
				printf("%s - %s\n", p->cmd, p->desc);
				break;	
			}
			p=p->next;
        }
		if(p == NULL) 
		{
			printf("This is a wrong cmd!\n ");
			continue;
		}
    }

}


//int Help()
//{
//    printf("Menu List:\n");
//    tDataNode *p = head;
//    while(p != NULL)
//    {
//        printf("%s - %s\n", p->cmd, p->desc);
//        p = p->next;
//    }
//    return 0; 
//}

