#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
}Node;

Node *create_node(int data)
{
	Node *node = (Node*)malloc(sizeof(Node));
	
	node -> data = data;
	node -> next = NULL;

	return node;
}

Node *create_linked_list(int size)
{
	int data = 0, i = 0;
	
	printf("Enter data of node 1 : ");
	scanf("%d",&data);
	Node *first = create_node(data);

	Node *temp = first;

	i = 2;
	while(i <= size)
	{
		printf("Enter data of node %d : ",i);
		scanf("%d",&data);
		temp -> next = create_node(data);
		temp = temp -> next;
		i = i + 1;	
	}

	return first;
}

void insert_at_first(Node **head)
{
	int data = 0;

	printf("Enter data : ");
	scanf("%d",&data);

	Node *node = create_node(data);

	if((*head) == NULL)
	{
		(*head) = node;
	}
	else
	{
		node -> next = (*head);
		(*head) = node;
	}

	return;
}

void insert_at_last(Node **head)
{
	int data = 0;

	printf("Enter data : ");
	scanf("%d",&data);

	Node *node = create_node(data);

	if((*head) != NULL)
	{
		Node *temp = (*head);
	
		while(temp -> next != NULL)
		{
			temp = temp -> next;
		}

		temp -> next = node;
	}
	else
	{
		(*head) = node;
	}

	return;
}

void insert_at_position(Node **head)
{
	int data = 0, i = 0, pos = 0;
	Node *temp = (*head);


	printf("Enter position : ");
	scanf("%d",&pos);

	if(pos <= 0)
	{
		printf("Enter valid position\n");
		return;
	}

	if(pos == 1)
	{
		insert_at_first(head);
	}
	else
	{
		printf("Enter data : ");
		scanf("%d",&data);
		Node *node = create_node(data);

		while(i < (pos - 2))
		{
			if(temp != NULL)
			{
				temp = temp -> next;
			}
	
			i = i + 1;
		}
	
		if(temp != NULL)
		{
			node -> next = temp -> next;
			temp -> next = node; 
		}
		else
		{
			printf("Enter valid position\n");
		}

	}
	
	return;
}

int delete_first(Node **head)
{
	int data = 0;

	if((*head) == NULL)
	{
		data = -1;
	}
	else
	{	
		data = (*head) -> data;

		Node *temp = (*head);

		(*head) = (*head) -> next;

		free(temp);
	}

	return data;
}

int delete_last(Node **head)
{
	int data = 0;

	if((*head) == NULL)
	{
		data = -1;
	}
	else
	{
		Node *temp = (*head);

		if(temp -> next == NULL)
		{
			data = temp -> data;
			free(temp);	
		}
		else
		{
			while(temp -> next -> next != NULL)
			{
				temp = temp -> next;
			}
		
			data = temp -> next -> data;
			free(temp -> next);
			temp -> next = NULL;
		}
	}

	return data;
}

int delete_at_position(Node **head)
{

	int data = 0, i = 0, pos = 0;

	printf("Enter position : ");
	scanf("%d",&pos);

	if(pos <= 0)
	{
		printf("Enter valid position\n");
		data = -1;
	}
	else if((*head) == NULL)
	{
		printf("Linked list is empty\n");
		data = -1; 
	}
	else if(pos == 1)
	{
		data = delete_first(head);
	}
	else
	{
		Node *temp = (*head);
		
		while(i < (pos - 2))
		{
			if(temp != NULL)
			{
				temp = temp -> next;
			}
			
			i = i + 1;
		}

		if(temp -> next != NULL)
		{
			Node *tofree = temp -> next;
		
			temp -> next = tofree -> next;
		
			data = tofree -> data;
			free(tofree);
		}
		else
		{
			printf("Enter valid position\n");
			data = -1;
		}
	}
	
	
	return data;
	
}

void print_ll(Node *head)
{
	Node *temp = head;

	while(temp != NULL)
	{
		printf("|%d|->",temp -> data);
		temp = temp -> next;
	}

	printf("\n");

	return;
}

int main()
{
	int size = 0;
	Node *head = NULL;
	
	printf("Enter size of linked list : ");
	scanf("%d",&size);
	head = create_linked_list(size);
		
	insert_at_first(&head);
	insert_at_last(&head);

	print_ll(head);

	int rdata = delete_first(&head);	
	printf("Deleted Node is : %d\n",rdata);
	
	print_ll(head);

	rdata = delete_last(&head);
	printf("Deleted Node is : %d\n",rdata);

	print_ll(head);

	insert_at_position(&head);
	print_ll(head);
	
	while(1)
	{
		rdata = delete_at_position(&head);
		printf("Deleted element is %d\n",rdata);

		print_ll(head);
	}

	return 0;
}
