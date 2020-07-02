#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

typedef struct Node {
   int data;
   struct Node *next;
} Node_t;   


void displayList(Node_t *start);
void search(Node_t *start, int data);
Node_t *insertInOrder(Node_t *start, int data);


int main(int argc, char *argv[]) 
{

	int n;

	char choice = 'n';

	Node_t *start = NULL;
	
	do {
		printf("Enter a node: ");
		scanf("%d", &n);
		start = insertInOrder(start, n);
		while (getchar() != '\n');
		printf("Enter more?(y or n): ");
		scanf("%c",&choice);
	} while (toupper(choice) == 'Y');

	displayList(start);

	search(start, atoi(argv[1]));	

	//printf("Here is the result...\n");

	//displayList(start);
	
	printf("\n");
	
	return 0;
}



void displayList(Node_t *start)
{
	Node_t *p;

	if (start == NULL) {
		printf("List is empty\n");
		return;
	}

	p = start;

	while (p) {
		printf("%d --> ", p->data);
		p = p->next;
	}

	printf("NULL\n");
}


void search(Node_t *start, int data)
{
	Node_t *p = start;

	int pos = 1;

	while (p != NULL && p->data <= data) {
		if (p->data == data) {
			break;
		}
		pos++;
		p = p->next;
	}

	if (p == NULL || p->data != data) {
		printf("Node not found\n");
	} else {
		printf("Found at %d\n", pos);
	}


}

Node_t *insertInOrder(Node_t *start, int data)
{
	Node_t *temp = (Node_t *)malloc(sizeof(Node_t));

	temp->data = data;

	Node_t *p;

	if (start == NULL || (start->data > data)) {
		temp->next = start;
		start = temp;
		return start;
	}

	p = start;

	while (p->next != NULL && p->next->data <= data) {
		p = p->next;
	}

	temp->next = p->next;
	p->next = temp;
	
	return start;
}


