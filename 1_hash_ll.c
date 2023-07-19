#include<stdio.h>
#include<stdlib.h>

// Structure of node.
typedef struct node
{
	int data;
	struct node *next;
}Node;

// Structure of hash table
typedef struct hash
{
	int size;
	Node **hash_array;
}Hash;

// Function to create node
Node *create_node(int data)
{
	Node *node = (Node*)malloc(sizeof(Node));
	
	if(node != NULL)
	{
		node -> data = data;
		node -> next = NULL;	
	}
	else
	{
		printf("Error in memory allcation of node\n");
	}

	return node;
}

// Function to allocate memory for Hash structure.
Hash *create_hashtable(int size)
{
	Hash *hashptr = (Hash*)malloc(sizeof(Hash));
	
	if(hashptr != NULL)
	{
		hashptr -> size = size;
		hashptr -> hash_array = (Node**)calloc(size, sizeof(Node*));
	}
	else
	{
		printf("Error in memory allocation of hash function\n");
	}	

	return hashptr;
}

// Function to insert node at last in linked list.
// Linked list is used to resolve collisions. 
void insert_last(Node **head, int data)
{
	Node *temp = (*head);

	if((*head) != NULL)
	{
		while(temp -> next != NULL)
		{
			temp = temp -> next;
		}
		temp -> next = create_node(data);
	}
	else
	{
		(*head) = create_node(data);
	}
	
	return;
}

// Basic hash function.
int hash_function(int data, int size)
{
	return data % size;
}

// Function to insert data in hash table.
void insert_in_hashtable(int data, Hash *hashptr)
{
	int hashvalue = 0;

	hashvalue = hash_function(data, hashptr -> size);

	insert_last(hashptr -> hash_array + hashvalue, data);

	return;
}

// Function to print linked list.
void print_ll(Node *head)
{
	while(head != NULL)
	{
		printf("|%d|->",head -> data);
		head = head -> next;
	}

	printf("\n");
	
	return;
}

// Function to print hash table.
void print_hash_structure(Hash *hashptr)
{
	int i = 0;

	if(hashptr != NULL)
	{
		printf("Hash array size = %d\n", hashptr -> size);
	
		printf("Printing hash table :\n");
		while(i < hashptr -> size)
		{
			printf("%d => ",i);
			print_ll(hashptr -> hash_array[i]);
			i = i + 1;
		}
	}
	else
	{
		printf("There is no memory for hash structure\n");
	}

	return;
}

// Main function.
int main()
{
	int size = 10, i = 0, data = 0;

	Hash *hashptr = create_hashtable(size);

	while(i < 10)
	{
		printf("Enter data : ");
		scanf("%d", &data);

		insert_in_hashtable(data, hashptr);
		
		i = i + 1;	
	}
	
	print_hash_structure(hashptr);	

	return 0;

}
