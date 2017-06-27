#include <stdio.h>
#include "linkedlist.h"


void listInit ( LinkedList *list)
{
  list->head = NULL;
  list->tail = NULL;
  list->len = 0;
}

void listAdd(LinkedList *list, Item*item)
{
  if(list->len == 0)
  {
  list->head =item;
  list->tail =item;
  }
  else
  {
    list->tail = item;
  }
  list->len += 1 ;
  item->next = NULL;
}

void listRemove(LinkedList *list,char *name	)      //BY USING LENGTH OF THE LIST
{
	
	if (list->len == 1)					// IF THERE IS ONLY ONE PEOPLE
	{
		list->head = NULL;
		list->tail = NULL;
	}
	
	else if (list->len > 1)				// IF THERE IS MORE THAN ONE PEOPLE
	{									// Hence, we need to compare to the name
		Item* before = NULL;
		Item* now = list->head;
		
		if(now == NULL)
			return NULL;
		else
		while(strcmp(((Student*)now->data)->name,name)! = 0)
		{
		before = now;
		now = now->next;
		}
		if(now == list ->head)
		{
			if(list->head == list->tail)
			{
				listInit(list);
			}
			else
			{
				list->head = list->head->next;
				list->len -= 1;
			}
		}
		else if(now =- list->tail)
		{
			list->tail = before;
			before->next = NULL;
			list ->len -=1;
		}
		else
		{
			before->next = now ->next;
			list -> len -= 1;
		}
		
		
	}
	else								// IF THERE IS NEGATIVE VALUE ON LENGTH
	{	
		printf("ERROR there is no negative people");
	}
}

