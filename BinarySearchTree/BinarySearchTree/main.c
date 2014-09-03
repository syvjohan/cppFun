#include <stdio.h>
#include <stdlib.h>
#include <time.h>


typedef struct treeNode {
	struct treeNode *leftPtr; //pointer left subtree
	int data;
	struct treeNode *rightPtr; // pointer right subtree
}TreeNode;

typedef TreeNode *TreeNodePtr;

void insertNode(TreeNodePtr *treePtr, int value);
void inOrder(TreeNodePtr treePtr);
void postOrder(TreeNodePtr treePtr);
void preOrder(TreeNodePtr treePtr);

int main(void) {
	int i;
	int item;
	TreeNodePtr rootPtr = NULL;

	srand(time(NULL));
	printf("inserted values in the tree");

	//Insert random values in the tree.
	for (i = 0; i <= 10; i++) {
		item = rand() % 15;
		printf("%3d", item);
		insertNode(&rootPtr, item);
	}

	printf("\n\nThe preOrder traversal is:\n");
	preOrder(rootPtr);

	printf("\n\nThe inOrder traversal is:\n");
	inOrder(rootPtr);

	printf("\n\nThe postOrder traversal is:\n");
	postOrder(rootPtr);

	system("pause");
	return 0;
}

void insertNode(TreeNodePtr *treePtr, int value) {
	if (*treePtr == NULL) {
		*treePtr = malloc(sizeof(TreeNode));

		if (*treePtr != NULL) {
			(*treePtr)->data = value;
			(*treePtr)->leftPtr = NULL;
			(*treePtr)->rightPtr = NULL;
		} else {
			printf("%dNot inserted, No memory available\n", value);
		}
	} else {
		if (value < (*treePtr)->data) {
			insertNode(&((*treePtr)->leftPtr), value);
		}
		else if (value >(*treePtr)->data) {
			insertNode(&((*treePtr)->rightPtr), value);
		} else {
			printf(" duplicated data values is ignored for now!"); //Fixa!!!.
		}
	}
}

void inOrder(TreeNodePtr treePtr) {
	if (treePtr != NULL) {
		inOrder(treePtr->leftPtr);
		printf("%3d", treePtr->data);
		inOrder(treePtr->rightPtr);
	}
}

void postOrder(TreeNodePtr treePtr) {
	if (treePtr != NULL) {
		postOrder(treePtr->leftPtr);
		postOrder(treePtr->rightPtr);
		printf("%3d", treePtr->data);
	}
}

void preOrder(TreeNodePtr treePtr) {
	if (treePtr != NULL) {
		printf("%3d", treePtr->data);
		preOrder(treePtr->leftPtr);
		preOrder(treePtr->rightPtr);
	}
}