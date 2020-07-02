#include<stdio.h>
#include<stdlib.h>


typedef struct Node {
   int data;
   struct Node *next;
} Node_t;   


Node_t *createList(Node_t *tail);
void displayList(Node_t *tail);
Node_t *insertAtBeginning(Node_t *tail, int data);
Node_t *insertAtEnd(Node_t *tail, int data);
Node_t *insertAfter(Node_t *tail, int data, int x);
Node_t *deleteNode(Node_t *tail, int data);


int main(int argc, char*argv[]) {

	Node_t *tail = NULL;
	
	tail = createList(tail);

	displayList(tail);

	tail = deleteNode(tail, 128);
	
	printf("Here is the result...\n");

	displayList(tail);
	
	printf("\n");
	
	return 0;
}


Node_t *createList(Node_t *tail)
{
	int i, n, data;

	printf("Enter the no.of nodes : ");
	scanf("%d", &n);

	if (n == 0) {
		return tail;
	}

	printf("\nEnter the 1st element to insert : ");
	scanf("%d", &data);
	
	tail = insertAtBeginning(tail, data);

	for (i = 1; i < n; i++) {
		printf("\nEnter the next element to insert : ");
		scanf("%d", &data);
		tail = insertAtEnd(tail, data);
	}

	printf("\n");

	return tail;
}



void displayList(Node_t *tail)
{
	Node_t *p;

	if (tail == NULL) {
		printf("List is empty\n");
		return;
	}

	p = tail->next;

	do {
		printf("%d --> ", p->data);
		p = p->next;
	} while (p != tail->next);

	printf("\n");
}



Node_t *insertAtBeginning(Node_t *tail, int data)
{

	Node_t *temp = (Node_t *)malloc(sizeof(Node_t));
	
	temp->data = data;

	if (tail == NULL) {
		tail = temp;
		tail->next = tail;
		return tail;
	}

	temp->next = tail->next;
	tail->next = temp;

	return tail;
}
	




Node_t *insertAtEnd(Node_t *tail, int data)
{
	Node_t *temp = (Node_t *)malloc(sizeof(Node_t));
	
	temp->data = data;
	
	if (tail == NULL) {
		tail = temp;
		tail->next = tail;
		return tail;
	}
	
	temp->next = tail->next;
	tail->next = temp;
	tail = temp;

	return tail;
}


Node_t *insertAfter(Node_t *tail, int data, int x)
{
	if (tail == NULL) {
		printf("List is empty\n");
		return tail;
	}

	Node_t *p = tail->next;

	do {
		if (p->data == x) {
			break;
		}
		p = p->next;
	} while (p != tail->next);

	if (p == tail->next && p->data != x) {
		printf("Node not found\n");
	} else {
		Node_t *temp = (Node_t *)malloc(sizeof(Node_t));
		temp->data = data;
		temp->next = p->next;
		p->next = temp;
		if (p == tail) {
			tail = temp;
		}
	}
	
	return tail;
}



Node_t *deleteNode(Node_t *tail, int data)
{

	Node_t *p, *del_node_ptr;

	if (tail == NULL) {
		printf("Empty List\n");
		return tail;
	}
	
	if (tail->next == tail && tail->data == data) {
		free(tail);
		tail = NULL;
		return tail;
	}
		
	p = tail->next;

	do {
		if (p->next->data == data) {
			break;
		}
		p = p->next;
	} while (p != tail->next);

	if (p == tail->next && p->next->data != data) {
		printf("\nNode not found\n");
	} else {
		del_node_ptr = p->next;
		p->next = del_node_ptr->next;
		if (del_node_ptr == tail) {
			tail = p;
		}
		free(del_node_ptr);
	}

	return tail;

}





