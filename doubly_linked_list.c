#include<stdio.h>
#include<stdlib.h>


typedef struct Node {
	struct Node *prev;
	int data;
	struct Node *next;
} Node_t;   


Node_t *createList(Node_t *start);
void displayList(Node_t *start);
void countNodes(Node_t *start);
void search(Node_t *start, int x);
Node_t *insertAtBeginning(Node_t *start, int data);
Node_t * insertAtEnd(Node_t *start, int data);
void insertAfter(Node_t *start, int data, int x);
Node_t *insertBefore(Node_t *start, int data, int x);
Node_t *deleteNode(Node_t *start, int data);
Node_t *reverseList(Node_t *start);


int main(int argc, char*argv[]) {

	Node_t *start = NULL;
	
	start = createList(start);

	displayList(start);


	start =	reverseList(start);
	
	printf("Here is the result...\n\n");

	displayList(start);
	
	printf("\n");
	
	return 0;
}


Node_t *createList(Node_t *start)
{
	int i, n, data;

	printf("Enter the no.of nodes : ");
	scanf("%d", &n);

	if (n == 0) {
		return start;
	}

	printf("\nEnter the 1st element to insert : ");
	scanf("%d", &data);
	
	start = insertAtBeginning(start, data);

	for (i = 1; i < n; i++) {
		printf("\nEnter the next element to insert : ");
		scanf("%d", &data);
		insertAtEnd(start, data);
	}

	printf("\n");

	return start;
}



void displayList(Node_t *start)
{
	Node_t *temp;
	if (start == NULL) {
		printf("List is empty\n");
		return;
	}

	printf("NULL <--> ");

	for (temp = start; temp != NULL; temp = temp->next) {
		printf("%d ", temp->data);
		printf("<--> ");
	}

	printf("NULL\n\n");
}


void countNodes(Node_t *start)
{
	int count = 0;
	Node_t *temp = start;

	while (temp) {
		count++;
		temp = temp->next;
	}

	printf("No.of nodes = %d\n", count); 

}


void search(Node_t *start, int x)
{
	int pos = 1;
	Node_t *temp = start;
	
	while (temp && temp->data != x) {
		pos++;
		temp = temp->next;

	}

	if (temp == NULL) {
		printf("%d not found\n", x);
	}

	else {
		printf("%d is at %d\n", x, pos);
	}
}





Node_t *insertAtBeginning(Node_t *start, int data)
{

	Node_t *temp = (Node_t *)malloc(sizeof(Node_t));
	
	temp->data = data;

	temp->next = start;

	temp->prev = NULL;

	if (start != NULL) {
		start->prev = temp;
	}

	start = temp;

	return start;
}
	




Node_t *insertAtEnd(Node_t *start, int data)
{
	Node_t *temp = (Node_t *)malloc(sizeof(Node_t));
	
	temp->data = data;

	temp->next = NULL;
   	
	if (start == NULL) {

		temp->prev = start;
		
		start = temp;

		return start;
	}

	
	Node_t *p = start;
	
	while (p->next != NULL) {
		p = p->next;
	}
	
	p->next = temp;
	temp->prev = p;

	return start;
}


void insertAfter(Node_t *start, int data, int x)
{
	
	Node_t *p = start;

	while (p != NULL && p->data != x) {
		p = p->next;
	}

	if (p == NULL) {
		printf("Node not found\n");
	}

	else {
		Node_t *temp = (Node_t *)malloc(sizeof(Node_t));
		temp->data = data;
		temp->next = p->next;
		temp->prev = p;
		if (p->next != NULL) {
			p->next->prev = temp;
		}
		p->next = temp;
	}

}


Node_t *insertBefore(Node_t *start, int data, int x)
{
	Node_t *temp, *p = start;

	while (p != NULL && p->data != x) {
		p = p->next;
	}


	if (p == NULL) {
		printf("Node not found\n");
		return start;
	}
	
	temp = (Node_t *)malloc(sizeof(Node_t));
	temp->data = data;
	temp->next = p;
	temp->prev = p->prev;
	
	if (p == start) {
		start = temp;
	} else {
		p->prev->next = temp;
	}

	p->prev = temp;

	return start;
}



Node_t *deleteNode(Node_t *start, int data)
{

	Node_t *p;

	if (start == NULL) {
		printf("Empty List\n");
		return start;
	}

	p = start;

	while (p != NULL && p->data != data) {
		p = p->next;
	}

	if (p == NULL) {
		printf("Node not found\n");
		return start;
	}

	if (p->prev == NULL) {
		start = p->next;
	} else {
		p->prev->next = p->next;
	}

	if (p->next != NULL) {
		p->next->prev = p->prev;
	}

	free(p);
	
	return start;

}





Node_t *reverseList(Node_t *start)
{

	Node_t *p, *temp;

	p = start;

	while (p) {
		
		temp = p->next;
		p->next = p->prev;
		p->prev = temp;

		if (temp == NULL) {
			start = p;
			break;
		}

		p = temp;
	}
	
	return start;
}
