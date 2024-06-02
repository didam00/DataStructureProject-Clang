#include "ds.h"

TBT_Node* findSuccessor(TBT_Node* node) {
	TBT_Node* sNode = node->right;
	if (sNode == NULL || node->isThread) {
		return sNode;
	}

	while (sNode->left) {
		sNode = sNode->left;
	}

	return sNode;
}

void inorderThread(TBT* tree) {
	TBT_Node* cur = tree->root;
	// ���� �������� �̵��Ѵ�
	while (cur->left) cur = cur->left;

	do {
		printf("%d -> ", cur->data);
		cur = findSuccessor(cur);
	} while (cur);
}