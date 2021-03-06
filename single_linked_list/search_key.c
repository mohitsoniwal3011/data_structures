#include <stdio.h>
#include <stdlib.h>
struct node {
	int data;
	struct node * next;
};
struct node * create_list()
{
	int i,n;
	printf("enter the number of nodes you want to create \n");
	scanf("%d",&n);
	if(n==0){
		struct node *head=NULL;
		return head;
	}	
	struct node *head,*newnode,*temp;
	/*we will use newnode for creating any new node in the list.
	head to store the address of the first node so that we can return it to the main function
	temp to traverse through the list so that any other links in the list do not get Damaged. */
	//creating  the head node
	newnode=(struct node *)malloc(sizeof(struct node));
	i=1;
	head=NULL;
	printf("enter the data for node %d :\n",i);
	scanf("%d",&newnode->data);
	newnode->next=NULL;
	head=newnode;
	temp=head; 
	//creating other nodes 
	for(i=2;i<=n;i++){
		newnode=(struct node *)malloc(sizeof(struct node));
		printf("enter the data for node %d:\n",i);
		scanf("%d",&newnode->data);
		newnode->next=NULL;
		temp->next=newnode;
		temp=newnode;
	}
	return head;
}
void search_key(int key,struct node *start)
{
	struct  node *p;
	p=start;
	int position=1;
	while(p != NULL){
		if(p->data == key){
			printf("key found at position %d",position);
			return ;
		}
		else{
			p=p->next;
			position++ ;
		}
	}
	printf("key not found in the list");
}	
int main ()
{
	struct node *head=(struct node *)malloc(sizeof(struct node ));
	head=create_list();
	printf("enter the key you want to search");
	int n;
	scanf("%d",&n);
	search_key(n,head);
	return 0;
}	