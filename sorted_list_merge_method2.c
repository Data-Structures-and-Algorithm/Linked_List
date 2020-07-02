//In place algorithm...Alter 1st and 2nd list posiions... 

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
Node_t *merge(Node_t *start1, Node_t *start2);

int main(void) 
{

	int n;

	char choice = 'n';

	Node_t *start1 = NULL;
	Node_t *start2 = NULL;

#if 1

	do {
		printf("Enter a node: ");
		scanf("%d", &n);
		start1 = insertInOrder(start1, n);
		while (getchar() != '\n');
		printf("Enter more?(y or n): ");
		scanf("%c",&choice);
	} while (toupper(choice) == 'Y');

#endif


#if 1
	do {
		printf("Enter a node: ");
		scanf("%d", &n);
		start2 = insertInOrder(start2, n);
		while (getchar() != '\n');
		printf("Enter more?(y or n): ");
		scanf("%c",&choice);
	} while (toupper(choice) == 'Y');
	
#endif

	Node_t *start3 = merge(start1, start2);

	displayList(start3);

	//search(start, atoi(argv[1]));	

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


Node_t *merge(Node_t *p1, Node_t *p2)
{
	Node_t *start3, *p3;

	if (p1 == NULL && p2 == NULL){
		return NULL;
	}

	if (p1 == NULL) {
		return p2;
	} 

	if (p2 == NULL) {
		return p1;
	}

	if (p1->data <= p2->data) {
		p3 = p1;
		p1 = p1->next;
	} else {
		p3 = p2;
		p2 = p2->next;
	}

	start3 = p3;


	while (p1 && p2) {

		if (p1->data <= p2->data) {
			p3->next = p1;
			p3 = p1;	
			p1 = p1->next;
		} else {
			p3->next = p2;
			p3 = p2;
			p2 = p2->next;
		}
	}

	if (p1 == NULL) {
		p3->next = p2;
	} else {
		p3->next = p1;
	}

	return start3;
}


















