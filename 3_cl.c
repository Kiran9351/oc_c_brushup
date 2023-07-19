#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *next, *prev;
}Node;

Node *create_node(int data)
{
	Node *node = NULL;

	node = (Node*)malloc(sizeof(Node));

	if(node == NULL)
	{
		printf("Error in memory allocation\n");
	}
	else
	{
		node -> data = data;
		node -> next = NULL;
		node -> prev = NULL;
	}

	return node;
}

Node *create_circular_ll(int size)
{
	int data = 0, i = 0;

	printf("Enter data of node 1 : ");
	scanf("%d",&data);

	Node *head = create_node(data);

	if(head != NULL)
	{
		Node *temp = head;
		
		i = 2;
		while(i <= size)
		{
			printf("Enter data of node %d : ",i);
			scanf("%d",&data);

			Node *node = create_node(data);
			temp -> next = node;
			node -> prev = temp;
			node -> next = head;
			temp = temp -> next;
			head -> prev = temp;

			i = i + 1;
		}
	}

	return head;
}

void insert_first(Node **head)
{
	int data = 0;

	printf("Enter data : ");
	scanf("%d",&data);
	
	Node *node = create_node(data);

	node -> next = (*head);
	node -> prev = (*head) -> prev;
	(*head) -> prev -> next = node;
	(*head) -> prev = node;

	(*head) = node;

	return;
}

void insert_last(Node **head)
{
	int data = 0;

	if((*head) != NULL)
	{
		printf("Enter data : ");
		scanf("%d",&data);

		Node *node = create_node(data);
	
		node -> next = (*head);
		node -> prev = (*head) -> prev;
		(*head) -> prev -> next = node;
		(*head) -> prev = node;
	}
	else
	{
		printf("Circular ll is empty\n");
	}


	return;
}

int delete_first(Node **head)
{
	int data = 0;
	
	if((*head) != NULL)
	{
		data = (*head) -> data;

		Node *temp = (*head);

		(*head) = temp -> next;
		(*head) -> prev = temp -> prev;
		(*head) -> prev -> next = (*head);

		free(temp);	
	}
	else
	{
		printf("Circular ll is empty\n");
		data = -1;
	}

	return data;
}

int delete_last(Node **head)
{
	int data = 0;
	
	if((*head) != NULL)
	{
		data = (*head) -> prev -> data;
	
		Node *temp = (*head) -> prev;
		temp -> prev -> next = (*head);
		(*head) -> prev = temp -> prev;

		free(temp);	
	}
	else
	{
		printf("Circular ll is empty\n");
		data = -1;
	}

	return data;
}

void print_ll(Node *head)
{

	if(head != NULL)
	{
		Node *temp = head -> next;

		printf("<-|%d|->",head -> data);

		while(temp != head)
		{
			printf("<-|%d|->",temp -> data);
			temp = temp -> next;
		}
	}	
	else
	{
		printf("Circular ll is empty");
	}
	printf("\n");
	
	return;
}

int main()
{
	Node *head = NULL;
	int size = 0;

	printf("Enter size of linked list : ");
	scanf("%d",&size);	

	head = create_circular_ll(size);
	insert_first(&head);
	insert_last(&head);
	print_ll(head);

	printf("Deleted element = %d\n",delete_first(&head));
	print_ll(head);
	
	printf("Deleted element = %d\n", delete_last(&head));
	print_ll(head);
	
	return 0;
}
