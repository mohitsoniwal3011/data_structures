#include <stdio.h>
#include <stdlib.h>
struct node {
	int data;
	struct node *next;
} ;
struct node *create_list()
{
	printf("enter the number of nodes you want to create:\n");
	int n,i=1;
	scanf("%d",&n);
	if(n==0){
		struct node *last=NULL;
		printf("created an empty list \n");
		return last;
	}	
	struct node *newnode,*last,*temp;
	struct node *head=NULL;
	if(n==1){
		newnode=(struct node *)malloc(sizeof(struct node));
		printf("enter the data for node %d:\n",i);
		scanf("%d",&newnode->data);
		last=newnode;
		last->next=last;
		return last;
	}
	newnode=(struct node *)malloc(sizeof(struct node));
	printf("enter the data for node %d:\n",i);
	scanf("%d",&newnode->data);
	head=newnode;
	temp=head;
	for(i=2;i<=n;i++){
		if(i == n){
			newnode=(struct node *)malloc(sizeof(struct node ));
			printf("enter the data for node %d:\n",i);
			scanf("%d",&newnode->data);
			newnode->next=head;
			temp->next=newnode;
			last=newnode;
			return last;
		}		
		newnode=(struct node *)malloc(sizeof(struct node ));
		printf("enter the data for node %d:\n",i);
		scanf("%d",&newnode->data);
		newnode->next=NULL;
		temp->next=newnode;
		temp=newnode;
	}
	return head;	
	
}
struct node *insert_after(struct node *last)
{
	if(last ==NULL){
		printf("the list is empty\n");
		return last;
	}
	struct node *p,*temp,*newnode;
	newnode=(struct node *)malloc(sizeof(struct node));
	printf("enter the element to be inserted:\n ");
	scanf("%d",&newnode->data);
	int element;
	printf("enter the element after which you want to insert the data:\n");
	scanf("%d",&element);
	p=last->next;
	do{
		if(p->data == element && p==last){
			temp=p->next;
			p->next=newnode;
			newnode->next=temp;
			last=last->next;
			return last;
		}
		if(p->data == element && p != last){
			temp=p->next;
			p->next=newnode;
			newnode->next=temp;
			return last;
		}
	}while(p != last->next);	
	
}
void display(struct node *last)
{
	struct node *p;//for traversing through the list
	int i=1;
	if(last == NULL){
		printf("the list is empty\n");
		return ;
	}
	p=last->next;
	do{
		printf("\ndata of the node %d :\n",i++);
		printf("%d",p->data);
		p=p->next;
	}while(p != last->next);
	//if we use while loop then in very first iteration codition of the while loop will be violated.
	//and nothing will be printed.
	return ;
}	
int main ()
{
	struct node *tail=(struct node *)malloc(sizeof(struct node ));
	tail=create_list();
	struct node *new_tail=(struct node *)malloc(sizeof(struct node ) );
	new_tail=insert_after(tail);
	display(new_tail);
	return 0;
}	
		