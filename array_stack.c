#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct stack
{
	int size;
	int top;
	int *stk_arr;
}Stack;

Stack *create_stack(int stack_size)
{
	Stack *stk = (Stack*)malloc(sizeof(Stack));
	
	if(stk == NULL)
	{
		printf("Error in memory allocation\n");
	}
	else
	{
		stk -> size = stack_size;
		stk -> top = -1;

		stk -> stk_arr = (int*)malloc(sizeof(int) * stack_size);
	}
	
	return stk;
}

bool isfull(Stack *stk)
{
	return (stk -> top == (stk -> size - 1));	
}

bool isempty(Stack *stk)
{
	return (stk -> top == -1);
}

void push(Stack *stk)
{
	int ele = 0;

	if(isfull(stk) == false)
	{
		printf("Enter element to push = ");
		scanf("%d",&ele);
		
		stk -> top = stk -> top + 1;

		stk -> stk_arr[stk->top] = ele;
	}
	else
	{
		printf("Stack is full\n");
	}

	return;
}

int pop(Stack *stk)
{
	int ele = 0;

	if(isempty(stk) == false)
	{
		ele = stk -> stk_arr[stk -> top];

		stk -> top = stk -> top - 1;
	}
	else
	{
		printf("Stack is empty\n");
		ele = -1;
	}

	return ele;
}

void print_stack(Stack *stk)
{
	int i = 0;
	
	while(i <= stk -> top)
	{
		printf("|%d|",stk->stk_arr[i]);
		i = i + 1;
	}

	printf("\n");

	return;
}

int main()
{
	int isize = 0;
	Stack *stk = NULL;	

	printf("Enter size of stack : ");
	scanf("%d",&isize);
	
	stk = create_stack(isize);

	char topush = 'y';
	char topop = 'y';
	while(topush == 'y')
	{
		push(stk);

		printf("Do you want to push an element? [y/n] : ");
		scanf(" %c",&topush);
	}

	print_stack(stk);

	while(topop == 'y')
	{
		int ele = pop(stk);
		
		printf("Poped element is : %d\n", ele);

		printf("Do you wnat to pop an element? [y/n] : ");
		scanf(" %c",&topop);
	}

	print_stack(stk);
	
	free(stk);

	return 0;
}
