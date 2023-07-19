#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct queue
{
	int qsize;
	int head;
	int tail;
	int *queue_arr;
}Queue;

Queue *create_queue(int qsize)
{
	Queue *que = (Queue*)malloc(sizeof(Queue));

	if(que == NULL)
	{
		printf("Error in memory allocation\n");
	}
	else
	{
		que -> qsize = qsize;
		que -> head = -1;
		que -> tail = -1;

		que -> queue_arr = (int*)malloc(sizeof(int) * qsize);
	}

	return que;
}

bool isfull(Queue *que)
{
	return (que -> tail == (que -> qsize - 1));	
}

bool isempty(Queue *que)
{
	return (que -> head >= que -> tail) || (que -> tail == -1 && que -> head == -1);
}

void enque(Queue *que)
{
	int ele = 0;

	if(isfull(que) == false)
	{
		printf("Enter element of queue : ");
		scanf("%d",&ele);

		que -> tail = que -> tail + 1;

		que -> queue_arr[que -> tail] = ele;
	}
	else
	{
		printf("Queue is full\n");
	}

	return;
}

int deque(Queue *que)
{
	int ele = 0;

	if(isempty(que) == false)
	{
		que -> head = que -> head + 1;

		ele  = que -> queue_arr[que -> head];	
	}
	else
	{
		printf("Queue is empty\n");
	
		que -> head = que -> tail = -1;		

		ele = -1;
	}

	return ele;
}

void print_queue(Queue *que)
{
	int i = 0;

	if(isempty(que) == false)
	{
		i = que -> head + 1;
		while(i <= que -> tail)
		{
			printf("|%d|",que -> queue_arr[i]);
			i = i + 1;
		}

		printf("\n");
	}
	else
	{
		printf("Queue is empty\n");
	}

	return;
}

int main()
{
	int qsize = 0, ele = 0;
	Queue *que = NULL;
	
	printf("Enter size of queue : ");
	scanf("%d",&qsize);

	que = create_queue(qsize);

	char ch = 'y';

	while(ch == 'y')
	{
		enque(que);
		printf("Do you want enque element? [y/n] : ");
		scanf(" %c",&ch);
	}

	print_queue(que);
	
	ch = 'y';
	while(ch == 'y')
	{
		ele = deque(que);
		printf("Deleted element : %d\n",ele);	
	
		printf("Do you want deque element? [y/n] : ");
		scanf(" %c", &ch);
	}

	print_queue(que);

	ch = 'y';
	
	while(ch == 'y')
	{
		enque(que);
		printf("Do you want enque element? [y/n] : ");
		scanf(" %c",&ch);
	}

	print_queue(que);
		
	return 0;
}
