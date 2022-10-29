#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node {
	int data;
	struct node *next;
};

struct node *head = NULL;
struct node *createNode(void);
void insertAtFirst(void);
void insertAtEnd(void);
void displayList(void);
void reverseList(void);
void searchKey(void);
void deleteNode(void);
void swapNodesByKeys(int key1, int key2);
int swapNodesByPos(int key1, int key2);
void insertBeforeAKeyNode(int key1);
void insertAfterAKeyNode(int key1);

int main(int argc, char *argv[])
{
	int option, key1, key2;

	while (1)
	{
		printf("*************************\n");
		printf("1) Insert at first\n");
		printf("2) Insert at last\n");
		printf("3) Display List\n");
		printf("4) Reverse list with copy\n");
		printf("5) Search a key\n");
		printf("6) Delete a node\n");
		printf("7) Swap nodes by key\n");
		printf("8) Swap nodes by positions\n");
		printf("9) Insert node before key\n");
		printf("10) Insert node after key\n");
		printf("11) Exit\n");
		printf("Select the option:");
		scanf("%d", &option);

		switch(option)
		{
			case 1:
				insertAtFirst();
				break;	       
			case 2:
				insertAtEnd();
				break;	       
			case 3:
				displayList();
				break;	       
			case 4:
				reverseList();
				break;	       
			case 5:
				searchKey();
				break;	       
			case 6:
				deleteNode();
				break;	       
			case 7:
				printf("\nEnter keys of nodes to swap\n");
				printf("\nKey1: ");
				scanf("%d", &key1);
				printf("\nKey2: ");
				scanf("%d", &key2);

				swapNodesByKeys(key1, key2);
				break;	       
			case 8:
				printf("\nEnter position of nodes to swap\n");
				printf("\nPos 1: ");
				scanf("%d", &key1);
				printf("\nPos 2: ");
				scanf("%d", &key2);

				swapNodesByPos(key1, key2);
				break;	       
			case 9:
				printf("\nEnter key info\n");
				printf("\nkey: ");
				scanf("%d", &key1);

				insertBeforeAKeyNode(key1);
				break;	       
			case 10:
				printf("\nEnter key info\n");
				printf("\nkey: ");
				scanf("%d", &key1);

				insertAfterAKeyNode(key1);
				break;	       

			case 11:
				exit(0);
			default:
				printf("Please select proper option!!!!\n");
				break;	       
		}


	}
}


struct node *createNode(void)
{
	struct node *newNode;
	int data;
	newNode = (struct node *)malloc(sizeof(struct node));
	if(newNode == NULL)
	{
		printf("malloc: Failed to allocate memory\n");
		return NULL;
	}

	printf("Enter data for node: ");
	scanf("%d", &data);
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}

void insertAtFirst(void)
{
	struct node *newNode;
	newNode = createNode();
	if(newNode == NULL)
	{
		return;
	}

	newNode->next = head;
	head = newNode;
}


void insertAtEnd(void)
{
	struct node *newNode, *temp;
	newNode = createNode();
	if(newNode == NULL)
	{
		return;
	}

	if(head == NULL)
	{
		head = newNode;
		return;
	}

	temp = head;

	while(temp->next != NULL)
	{
		temp = temp->next;
	}

	temp->next = newNode;
}

void displayList(void)
{
	struct node *temp;

	temp = head;
	printf("\n");
	while(temp != NULL)
	{
		printf("%d ->", temp->data);
		temp = temp->next;
	}
	printf(" NULL\n\n");

}


void reverseList(void)
{
	struct node *temp = NULL, *prev = NULL;

	if((head == NULL) || (head->next == NULL))
		return;

	prev = head;
	head = head->next;
	temp = head;
	prev->next = NULL;

	while(temp != NULL)
	{
		head = head->next;
		temp->next = prev;
		prev = temp;
		temp = head;
	}

	head = prev;
}

void searchKey(void)
{
	int key;
	struct node *temp;

	if(head == NULL)
	{
		printf("List is empty\n");
		return;
	}

	printf("Enter key to be searched: ");
	scanf("%d", &key);
	temp = head;

	while(temp != NULL)
	{
		if(temp->data == key)
		{
			printf("Key found\n");
			break;
		}
		temp = temp->next;
	}

	if(temp == NULL)
		printf("Key not found.\n");

}

void deleteNode(void)
{
	int key;
	struct node *temp = NULL, *prev = NULL;

	if(head == NULL)
	{
		printf("List is empty\n");
		return;
	}
	printf("Enter key to be deleted: ");
	scanf("%d", &key);

	if(head->data ==  key)
	{
		temp = head;
		head = head->next;
		free(temp);	
		return;
	}

	temp = head;

	while(temp != NULL)
	{
		prev = temp;
		temp = temp->next;
		if(temp->data == key)
		{
			break;
		}
	}

	if(temp == NULL)
	{
		printf("Key not found\n");
		return;
	}

	prev->next = temp->next;

	free(temp);
}

void swapNodesByKeys(int key1, int key2)
{
	struct node *prev1 = NULL, *prev2 = NULL, *node1 = NULL, *node2 = NULL, *temp;

	bool isFirstNodeFound, isSecNodeFound;

	if(head == NULL)
		return;

	temp = head;

	while((temp != NULL) && ((isFirstNodeFound != true) || (isSecNodeFound != true)))
	{


		if(temp->data == key1)
		{
			node1 = temp;
			isFirstNodeFound = true;
		}
		else if(temp->data == key2)
		{
			node2 = temp;
			isSecNodeFound = true;
		}

		if(isFirstNodeFound != true)
		{
			prev1 = temp;
		}

		if(isSecNodeFound != true)
		{
			prev2 = temp;
		}

		temp = temp->next;
	}



	if(isFirstNodeFound != true)
	{
		printf("Key1 not found\n");
		return;	
	}

	if(isSecNodeFound != true)
	{
		printf("Key2 not found\n");
		return;	
	}

	if(prev1 != NULL)
	{
		prev1->next = node2;
	}

	if(prev2 != NULL)
	{
		prev2->next = node1;
	}

	temp = node1->next;
	node1->next = node2->next;
	node2->next = temp;

	if(prev1 == NULL)
	{
		head = node2;
	}

	if(prev2 == NULL)
	{
		head = node1;
	}


}

int count(struct node *list)
{
	int nodes = 0;

	while (list != NULL)
	{
		nodes++;
		list = list->next;
	}

	return nodes;
}

int swapNodesByPos(int pos1, int pos2)
{
	struct node *node1, *node2, *prev1, *prev2, *temp;
	int i;

	// Get the far position among both
	const int maxPos = (pos1 > pos2) ? pos1 : pos2;

	// Get total nodes in the list
	const int totalNodes = count(head);

	// Validate swap positions
	if ((pos1 <= 0 || pos1 > totalNodes) || (pos2 <= 0 || pos2 > totalNodes))
	{
		return -1;
	}

	// If both positions are same then no swapping required
	if (pos1 == pos2)
	{
		return 1;
	}


	// Identify both nodes to swap
	i = 1;
	temp  = head;
	prev1 = NULL;
	prev2 = NULL;

	// Find nodes to swap
	while (temp != NULL && (i <= maxPos))
	{
		if (i == pos1 - 1)
			prev1 = temp;
		if (i == pos1)
			node1 = temp;

		if (i == pos2 - 1)
			prev2 = temp;
		if (i == pos2)
			node2 = temp;

		temp = temp->next;
		i++;
	}

	// If both nodes to swap are found.
	if (node1 != NULL && node2 != NULL)
	{
		// Link previous of node1 with node2
		if (prev1 != NULL)
			prev1->next = node2;

		// Link previous of node2 with node1
		if (prev2 != NULL)
			prev2->next = node1;

		// Swap node1 and node2 by swapping their
		// next node links
		temp        = node1->next;
		node1->next = node2->next;
		node2->next = temp;

		// Make sure to swap head node when swapping
		// first element.
		if (prev1 == NULL)
			head = node2;
		else if (prev2 == NULL)
			head = node1;
	}

	return 1;
}

void insertBeforeAKeyNode(int key)
{
	struct node *temp, *prev = NULL, *newNode;
	if(head == NULL)
		return;

	temp = head;

	while(temp != NULL)
	{
		if(temp->data == key)
		{
			break;	
		}
		prev = temp;
		temp = temp->next;	
	}	

	if(temp == NULL)
	{
		printf("Key not found\n");
		return;
	}
	
	newNode = createNode();
	if(newNode == NULL)
		return;

	if(prev == NULL)
	{
		newNode->next = temp;
		head = newNode;
		return;
	}

	prev->next = newNode;
	newNode->next = temp;
}

void insertAfterAKeyNode(int key)
{
	struct node *temp, *nextNode = NULL, *newNode;
	if(head == NULL)
		return;

	temp = head;

	while(temp != NULL)
	{
		if(temp->data == key)
		{
			break;	
		}
		temp = temp->next;	
	}	

	if(temp == NULL)
	{
		printf("Key not found\n");
		return;
	}
	
	newNode = createNode();
	if(newNode == NULL)
		return;
		
	nextNode = temp->next;

	temp->next = newNode;
	if(nextNode != NULL)
		newNode->next = nextNode;

}
