#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *next, *prev;
}Node;

int count = 0;

Node *create_node(int data)
{
	Node *node = (Node*)malloc(sizeof(Node));

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

Node *create_doubly_ll(int size)
{
	int data = 0, i = 0;

	printf("Enter element at node 1 : ");
	scanf("%d",&data);
	
	Node *head = create_node(data);

	if(head != NULL)
	{
		i = 2;
	
		Node *temp = head;
	
		while(i <= size)
		{
			printf("Enter element at node %d : ", i);
			scanf("%d", &data);
			
			temp -> next = create_node(data);

			temp -> next -> prev = temp;
			
			temp = temp -> next;
			
			i = i + 1;
		}

		count = count + size;
	}
	else
	{
		printf("Error in creating linked list\n");
	}

	return head;
}

void insert_at_first(Node **head)
{
	int data = 0;

	printf("Enter data : ");
	scanf("%d",&data);

	if((*head) == NULL)
	{
		(*head) = create_node(data);
	}
	else
	{
		Node *node = create_node(data);

		(*head) -> prev = node;

		node -> next = (*head);
	
		(*head) = node;
	}

	count = count + 1;

	return;
}

void insert_at_last(Node **head)
{
	int data = 0;

	printf("Enter data : ");
	scanf("%d",&data);

	if((*head) == NULL)
	{
		(*head) = create_node(data);
	}
	else
	{
		Node *temp = (*head);

		while(temp -> next != NULL)
		{
			temp = temp -> next;
		}

		temp -> next = create_node(data);

		temp -> next -> prev = temp;
	}

	count = count + 1;

	return;
}

void insert_at_position(Node **head)
{
	int data = 0, pos = 0, i = 1;

	printf("enter position = ");
	scanf("%d",&pos);

	if(pos < 1 || pos > count + 1)
	{
		printf("Enter valid position\n");
	}
	else
	{
		if(pos == 1)
		{
			insert_at_first(head);
		}
		else if(pos == count + 1)
		{
			insert_at_last(head);
		}
		else
		{
			printf("Enter data : ");
			scanf("%d", &data);
		
			Node *temp = (*head);
			Node *node = create_node(data);

			while(i < pos - 1)
			{
				temp = temp -> next;
				i = i + 1;
			}

			node -> next = temp -> next;
			node -> prev = temp;

			temp -> next = node;

			count = count + 1;
		}
	}

	return;
}

int delete_first(Node **head)
{
	int data = 0;

	if((*head) == NULL)
	{
		printf("Doubly ll is empty\n");
		data = -1;
	}
	else if((*head) -> next == NULL)
	{
		data = (*head) -> data;
		free(*head);
		(*head) = NULL;

		count = count - 1;
	}
	else 
	{
		data = (*head) -> data;

		Node *temp = (*head);
		data = temp -> data;

		(*head) = temp -> next;
		(*head) -> prev = NULL;

		free(temp);	

		count = count - 1;
	}

	return data;
}

int delete_last(Node **head)
{
	int data = 0;

	if((*head) == NULL)
	{
		printf("Doubly ll is empty\n");
		data = -1;
	}
	else if((*head) -> next == NULL)
	{
		data = (*head) -> data;
		free(*head);
		(*head) = NULL;

		count = count - 1;
	}
	else
	{
		Node *temp = (*head);

		while(temp -> next -> next != NULL)
		{
			temp = temp -> next;
		}

		data = temp -> next -> data;

		free(temp -> next);

		temp -> next = NULL;

		count = count - 1;
	}
	
	return data;
}

int delete_at_position(Node **head)
{
	int data = 0, i = 1, pos = 0;

	printf("Enter position : ");
	scanf("%d",&pos);

	if(pos < 1 || pos > count)
	{
		printf("Enter valid position\n");
		data = -1;
	}
	else
	{
		if(pos == 1)
		{
			data = delete_first(head);
		}
		else if(pos == count)
		{
			data = delete_last(head);
		}
		else
		{
			Node *temp = (*head);

			while(i < pos - 1)
			{
				temp = temp -> next;
				i = i + 1;
			}
			
			data = temp -> next -> data;
			Node *target = temp -> next;
			temp -> next = target -> next;
			temp -> next -> prev = temp;
			free(target);
		
			count = count - 1;
		}
	}

	return data;
}

void print_dll(Node* head)
{
	Node *temp = head;
	
	if(temp == NULL)
	{
		printf("Doubly ll is empty");
	}
	else
	{
		while(temp != NULL)
		{
			printf("<-|%d|->",temp -> data);
			temp = temp -> next;
		}
	}

	printf("\n");

	return;
}

int main()
{
	Node *head = NULL;
	int size = 0;

	printf("Enter size of doubly ll : ");
	scanf("%d",&size);

	head = create_doubly_ll(size);
	
	print_dll(head);

	insert_at_first(&head);
	insert_at_last(&head);

	print_dll(head);

	int rdata = delete_first(&head);
	printf("Deleted element : %d\n",rdata);
	rdata = delete_last(&head);	
	printf("Deleted element : %d\n",rdata);
	
	print_dll(head);

	insert_at_position(&head);

	print_dll(head);

	rdata = delete_at_position(&head);
	printf("Deleted element : %d\n",rdata);

	print_dll(head);

	free(head);
	
	return 0;
}
