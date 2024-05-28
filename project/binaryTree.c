#include "ds.h"

BT* initBT() {
	BinaryTree* newTree = (BT*)malloc(sizeof(BT));
	newTree->head = NULL;

	return 0;
}

BT_Node* searchBT(BT_Node* node, DataType data) {

}

BT_Node* newBTNode(DataType data) {
	BT_Node* newNode = (BT_Node*)malloc(sizeof(BT_Node));
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;

	return newNode;
}

int insertBT(BT_Node* node, CHILD_POS pos, DataType data) {
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