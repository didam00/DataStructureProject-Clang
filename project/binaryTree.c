#include "ds.h"

BT* initBT() {
	BinaryTree* newTree = (BT*)malloc(sizeof(BT));
	newTree->head = NULL;

	return newTree;
}

BT_Node* searchBT(BT* tree, DataType key) {
	BT_Node* head = tree->head;
	Stack* stack = initStack();
	BT_Node* cur = NULL;

	pushStack(stack, head);

	while (!isStackEmpty(stack)) {
		cur = (BT_Node*)stack->data[stack->top];
		if (cur->data == key) break;

		if (cur->left) pushStack(stack, (int)cur->left);
		if (cur->right) pushStack(stack, (int)cur->right);
	}
	
	return cur;
}

BT_Node* newBTNode(DataType data) {
	BT_Node* newNode = (BT_Node*)malloc(sizeof(BT_Node));
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;

	return newNode;
}

MESSAGE_CODE insertFirstBT(BT* tree, DataType data) {
	BT_Node* newNode = newBTNode(data);
	tree->head = newNode;

	return SUCCESS;
}

MESSAGE_CODE insertBT(BT_Node* node, CHILD_POS pos, DataType data) {
	BT_Node* newNode = newBTNode(data);
	if (pos == LEFT) {
		if (node->left != NULL) {
			free(newNode);
			return HAS_LEFT_CHILD_ERROR;
		}
		node->left = newNode;
	}
	else if (pos == RIGHT) {
		if (node->right != NULL) {
			free(newNode);
			return HAS_RIGHT_CHILD_ERROR;
		}
		node->right = newNode;
	}
	return SUCCESS;
}

MESSAGE_CODE removeBT(BT_Node* node, CHILD_POS pos) {
	if (pos == LEFT) {
		if (node->left != NULL) {
			return HAS_LEFT_CHILD_ERROR;
		}
		free(node->left);
		node->left = NULL;
	} else if (pos == RIGHT) {
		if (node->right != NULL) {
			return HAS_RIGHT_CHILD_ERROR;
		}
		free(node->left);
		node->right = NULL;
	}
	return SUCCESS;
}

//void showBT(BT* tree) {
//	BT_Node* head = tree->head;
//}