#include <stdlib.h>
#include <stdio.h>


typedef struct stackNode {
	int data;
	struct stackNode *nextPtr;
}StackNode;

typedef StackNode *StackNodePtr;

void instructions(void);
void push(int item, StackNodePtr *sPtr);
int pop(StackNodePtr *topPtr);
int isEmpty(StackNodePtr topPtr);
void printStack(StackNodePtr currentPtr);

int main(void) {

	StackNodePtr stackPtr = NULL;
	int choice;
	int value;

	instructions();
	scanf("%d", &choice);

	while (choice != 3) {

		switch (choice) {
		case 1:
			printf("Enter a integer: ");
			scanf(" %d", &value);
			push(value, &stackPtr);
			printStack(stackPtr);
			instructions();
			break;
		case 2:
			if (!isEmpty( stackPtr)) {
				printf("The popped value is %d: \n", pop(&stackPtr));
			}
			printStack(stackPtr);
			instructions();
			break;
		default:
			printf("Invalid choice \n\n");
			instructions();
			break;
		}
		
		scanf(" %d", &choice);
	}
	printf("End");

	return 0;
}

void instructions(void) {
	printf("Press 1 to push to stack\n"
		"Press 2 to pop the stack\n"
		"Press 3 to quit program\n");
}

void push(int item, StackNodePtr *topPtr) {
	StackNodePtr newPtr;
	newPtr = malloc(sizeof(StackNode));

	//insert node at stack top.
	if (newPtr != NULL) {
		newPtr->data = item;
		newPtr->nextPtr = *topPtr;
		*topPtr = newPtr;
	} else {
		printf("%d not inserted. No memory available", item);
	}
}

int pop(StackNodePtr *topPtr) {
	StackNodePtr tempPtr;
	int popValue;

	tempPtr = *topPtr;
	popValue = (*topPtr)->data;
	*topPtr = (*topPtr)->nextPtr;
	free(tempPtr);
	return popValue;

}

int isEmpty(StackNodePtr topPtr) {
	return topPtr == NULL;
}

void printStack(StackNodePtr currentPtr) {
	if (currentPtr == NULL) {
		printf("The stack is empty");
	} else {
		printf("The stack is: \n");
		while (currentPtr != NULL) {
			printf("%d --> ", currentPtr->data);
			currentPtr = currentPtr->nextPtr;
		}
		printf("NULL \n\n");
	}
}