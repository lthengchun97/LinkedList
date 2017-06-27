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

void listRemove(LinkedList *list,char *name	 )
{
	if (list->len == 1)					// IF THERE IS ONLY ONE PEOPLE
	{
		list->head = NULL;
		list->tail = NULL;
	}
	
	else if (list->len > 1)				// IF THERE IS MORE THAN ONE PEOPLE
	{
		list->head = list->head->next;
		list->len -= 1;
		
	}
	else								// IF THERE IS NEGATIVE VALUE ON LENGTH
	{	
		printf("ERROR there is no negative people");
	}
}