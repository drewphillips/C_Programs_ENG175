// https://www.codesdope.com/c-introduction/
// https://www.codesdope.com/blog/article/linked-lists-in-c-singly-linked-list/

#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node* next;
};

void display(struct node* head) {
	struct node* tmp;
	tmp = head;
	while (tmp != NULL) {
		printf("%d\n", tmp->data);
		tmp = tmp->next;
	}
    return;
}

struct node* front(struct node* head, int value) {
	struct node* p;

	p = malloc(sizeof(struct node));
	p->data = value;
	p->next = head;
	return p;
}

int end(struct node* head, int value) {
	struct node* p, * q;

	p = malloc(sizeof(struct node));
	p->data = value;
	p->next = NULL;
	q = head;

	while (q->next != NULL) {
		q = q->next;
	}
	q->next = p;
}

int del(struct node* before_del) {
	struct node* temp;

	temp = before_del->next;
	before_del->next = temp->next;
	free(temp);
}

int insert(struct node* head) {

	struct node* current, * p;
	int position;

	p = malloc(sizeof(struct node));
	printf("Enter data value: ");
	scanf("%d", &p->data);
	p->next = NULL;

	printf("Postions in list: ");
	scanf("%d", &position);

	current = head;

	for (int i = 0; i < position - 2; i++) {
		current = current->next;
	}

	p->next = current->next;
	current->next = p;

}

int main(void)
{
	struct node* prev = NULL, * head, * p;
	int n, i;

	printf("number of elements: ");
	scanf("%d", &n);

	head = NULL;
	for (i = 0; i < n; i++) {
		p = malloc(sizeof(struct node));
		printf("Enter data for each node %d: ", i + 1);
		scanf("%d", &p->data);
		p->next = NULL;

		if (head == NULL)
			head = p;
		else
			prev->next = p;

		prev = p;
	}

	printf("Original List\n\n");
	display(head);

	printf("List after front\n");
	head = front(head, 100);
	display(head);

	printf("List ater end\n");
	end(head, 2000);
	display(head);

	printf("List after del\n");
	del(head->next);
	display(head);

	//insert a new node
	printf("List after user position insert \n");
	insert(head);
	display(head);

	return 0;
}