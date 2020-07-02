#include<stdio.h>
#include<stdlib.h>


typedef struct Node {
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
Node_t *insertAtPosition(Node_t *start, int data, int index);
Node_t *deleteNode(Node_t *start, int data);
Node_t *reverseList(Node_t *start);
void bubble_sort_xchg_data(Node_t *start);
Node_t *bubble_sort_xchg_link(Node_t *start);
Node_t *merge_sort(Node_t *start);
Node_t *mid_node(Node_t *start);
Node_t *divide(Node_t *start);
Node_t *merge(Node_t *p1, Node_t *p2);
Node_t *find_cycle(Node_t *start);
void remove_cycle(Node_t *start, Node_t *intersect_node);



int main() {

	Node_t *start = NULL;
	
	start = createList(start);

	displayList(start);
	
#if 1
	
	Node_t * p = start;
	while (p->next) {
		p = p->next;
	}

	p->next = start->next->next;

#endif

	printf("Here is the result...\n");

	Node_t *temp = find_cycle(start);
	
	if (temp) {
		printf("There is a cycle at %d...\n", temp->data);
	} else {
		printf("No cycle\n");
	}

	printf("Now removing cycle...\n");

	remove_cycle(start, temp);
	
	printf("Removal succesful...The latest list is...\n");

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

	for (temp = start; temp != NULL; temp = temp->next) {
		printf("%d ", temp->data);
		printf("--> ");
	}

	printf("NULL\n");
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

	start = temp;

	return start;
}
	




Node_t *insertAtEnd(Node_t *start, int data)
{
	Node_t *temp = (Node_t *)malloc(sizeof(Node_t));
	
	temp->data = data;

	temp->next = NULL;
   	
	if (start == NULL) {
		start = temp;
		return start;
	}

	
	Node_t *p = start;
	
	while (p->next != NULL) {
		p = p->next;
	}
	
	p->next = temp;

	return start;
}


void insertAfter(Node_t *start, int data, int x)
{
	
	Node_t *p = start;

	while (p) {
		if (p->data == x) {
			break;
		}
		p = p->next;
	}

	if (p == NULL) {
		printf("Node not found\n");
	}

	else {
		Node_t *temp = (Node_t *)malloc(sizeof(Node_t));
		temp->data = data;
		temp->next = p->next;
		p->next = temp;
	}

}


Node_t *insertBefore(Node_t *start, int data, int x)
{
	Node_t *temp, *p;

	if (start == NULL) {
		printf("List is empty\n");
		return start;
	}

	if (start->data == x) {
		temp = (Node_t *)malloc(sizeof(Node_t));
		temp->data = data;
		temp->next = start;
		start = temp;
		return start;
	}

	p = start;

	while (p->next) {
		if (p->next->data == x) {
			break;
		}
		p = p->next;
	}

	if (p->next == NULL) {
		printf("Node not found\n");
	}
	else {
		temp = (Node_t *)malloc(sizeof(Node_t));
		temp->data = data;
		temp->next = p->next;
		p->next = temp;
	}
	return start;
}


Node_t *insertAtPosition(Node_t *start, int data, int index)
{

	Node_t *temp, *p; 

	int i;

	if (index == 1) {
		temp = (Node_t *)malloc(sizeof(Node_t));
		temp->data = data;
		temp->next = start;
		start = temp;
		return start;
	}	
	
	p = start;
	
	for (i = 1; i < (index - 1) && p != NULL; i++) {
		p = p->next;
	}

	if (p == NULL) {
		printf("Position not found\n");
	}

	else {
		temp = (Node_t *)malloc(sizeof(Node_t));
		temp->data = data;
		temp->next = p->next;
		p->next = temp;
	}
	
	return start;

}




Node_t *deleteNode(Node_t *start, int data)
{

	Node_t *p, *del_node_ptr;

	if (start == NULL) {
		printf("Empty List\n");
		return start;
	}

	if (start->data == data) {
		del_node_ptr = start;
		start = start->next;
		free(del_node_ptr);
		return start;
	}

	p = start;

	while (p->next) {
		if (p->next->data == data) {
			break;
		}
		p = p->next;
	}

	if (p->next == NULL) {
		printf("Node not found\n");
	}

	else {
		del_node_ptr = p->next;
		p->next = del_node_ptr->next;
		free(del_node_ptr);
	}
	
	return start;

}





Node_t *reverseList(Node_t *start)
{

	Node_t *addr, *p, *next_node;

	p = start;

	addr = NULL;

	while (p) {
		next_node = p->next;
		p->next = addr;
		addr = p;
		p = next_node;
	}
	start = addr;
	return start;
}



void bubble_sort_xchg_data(Node_t *start)
{
	Node_t *p, *end;

	if (start == NULL) {
		return;
	}

	end = NULL;

	while (end != start->next) {
		p = start;
		while (p->next != end) {
			if (p->data > p->next->data) {
				int temp = p->data;
				p->data = p->next->data;
				p->next->data = temp;
			}
			p = p->next;
		}
		end = p;
	}

}



Node_t *bubble_sort_xchg_link(Node_t *start)
{
	Node_t *p, *q, *r, *end, *temp;

	if (start == NULL) {
		return NULL;
	}

	end = NULL;

	while (end != start->next) {
		r = p = start;
		while (p->next != end) {
			q = p->next;
			if (p->data > q->data) {
				p->next = q->next;
				q->next = p;
				if (p != start) {
					r->next = q;
				} else {
					start = q;
				}
				temp = p;
				p = q;
				q = temp;
			}
			r = p;
			p = p->next;
		}
		end = p;
	}

	return start;
}



Node_t *mid_node(Node_t *start)
{
	if (start == NULL) {
		return NULL;
	}

	Node_t *slow_ptr = start;
	Node_t *fast_ptr = start;

	while (fast_ptr && fast_ptr->next) {
		slow_ptr = slow_ptr->next;
		fast_ptr = fast_ptr->next->next;
	}

	return slow_ptr;
}




Node_t *divide(Node_t *start)
{

    if (start == NULL) {
        return NULL;
    }   

	Node_t *start2;
    Node_t *slow_ptr = start;
    Node_t *fast_ptr;


    if (start->next != NULL) {
        fast_ptr = start->next->next;
    } else {
        fast_ptr = start->next;
    }   

    while (fast_ptr && fast_ptr->next) {
        slow_ptr = slow_ptr->next;
        fast_ptr = fast_ptr->next->next;
    }   
	
	start2 = slow_ptr->next;
	slow_ptr->next = NULL;

    return start2;
}




Node_t *merge_sort(Node_t *start)
{
	Node_t *mid;

	if (start==NULL || start->next == NULL) {
		return start;
	}
	
	mid = divide(start);
	start = merge_sort(start);
	mid = merge_sort(mid);
	
	return merge(start, mid);

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



Node_t *find_cycle(Node_t *start)
{
	if (start == NULL || start->next == NULL) {
		return NULL;
	}

	Node_t *slow_ptr = start;
	Node_t *fast_ptr = start;

	while (fast_ptr && fast_ptr->next) {
		slow_ptr = slow_ptr->next;
		fast_ptr = fast_ptr->next->next;
		if (slow_ptr == fast_ptr) {
			return slow_ptr;
		}
	}

	return NULL;
}



void remove_cycle(Node_t *start, Node_t *intersect_node)
{
	Node_t *p = intersect_node;

	Node_t *q = start;
	
	//Find out the starting node
	while (p != q) {
		p = p->next;
		q = q->next; 
	}

	//Move to the actual last node
	while (q->next != p) {
		q = q->next;
	}	
	
	q->next = NULL;
}
















