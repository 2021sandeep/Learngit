#include <stdio.h>
#include "fun.h"
#ifndef LOG
#define LOG printf
#endif

//static int value = 11;
extern cll_node *head;


void add()
{
	int add_choice;
	int ch=1;
	
	while(ch==1)
	{
		printf("\n 1. Add_Beginning\t 2. Add_End \t Your choice? : ");
		//printf("\n Add as per choice :");
		scanf("%d",&add_choice);

		switch(add_choice)
		{
			case 1:	add_at_beg();
				break;
			case 2:	add_at_end();
				break;
			default:
				break;
		}
		printf("\n Exit (0) or Add another (1) : ");
		scanf("%d",&ch); 
		printf("\n %d : ",ch);
	}
	return;
}

void add_at_beg()
{
  cll_node *temp=head,*new_node;  
  
   int data;  
   new_node = (cll_node *)malloc(sizeof(cll_node));  
    printf("\nEnter value");  
    scanf("%d",&data);  
    new_node->data=data; 
   if(head==NULL)  
       {  
           head=new_node; 
           new_node->next = head;
       }  
   else   
       {  
           temp=head;
           new_node->next = temp;
           while(temp->next != head)  
            {  
                temp=temp->next;  
            } 
            temp->next=new_node;
            
           head=new_node;  
       }
    	NODE_COUNT++; 

   printf("\nNode added in beginning\n"); 
  
}
void add_at_end()
{
    cll_node *temp = head;
	int value;

	cll_node *new_node = (cll_node *)malloc(sizeof(cll_node));
	if(new_node == NULL)
	{
		printf("Unable to allocate memory");
		return;
	}
	printf("\nEnter data in the node : ");
	scanf("%d",&value);
	new_node->data = value;
	

    	if(head == NULL)
    	{
    		head = new_node;	
    		new_node->next = head;
    		
    	}
    	else
    	{
    		while(temp->next!=head)
    			temp = temp->next;
    		temp->next = new_node;
    		new_node->next=head;
    			
    	}
	NODE_COUNT++;
	printf("\n node added at end.");
	
	return;

}