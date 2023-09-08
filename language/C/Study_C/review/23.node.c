#include <stdio.h>
#include <stdlib.h>

struct Node* CreateNode(int data);

struct Node {
	int data;
	struct Node* nextNode;
};


struct Node* CreateNode(int data) {
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

	(*newNode).data = data;
	newNode->nextNode = NULL;

	return newNode;
}

struct Node* InsertNode(struct Node* current, int data) {
/*
	struct Node* after = current->nextNode;
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

	newNode->data = data;
	newNode->nextNode = after;

	current->nextNode = newNode;

	return newNode;
*/
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

	newNode->data = data;
	newNode->nextNode = current->nextNode; // 관계 없다?????

	current->nextNode = newNode;

	return newNode;
}

void DestroyNode(struct Node* destroy, struct Node* head) {
	struct Node* next = head;
	if (destroy == head) {
		free(destroy);
		return;
	}
	while (next) {
		if (next->nextNode == destroy) {
			next->nextNode = destroy->nextNode;
		}
		next = next->nextNode;
	}
	free(destroy);
}