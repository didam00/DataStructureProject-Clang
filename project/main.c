#include "ds.h"
int main() {
	BinaryTree* tree = initBT();
	insertFirstBT(tree, 2);
	printf("%d", insertBT(searchBT(tree, 2), LEFT,	3));
	printf("%d", insertBT(searchBT(tree, 2), RIGHT, 4));
	printf("%d", insertBT(searchBT(tree, 3), LEFT,	5));
	printf("%d", insertBT(searchBT(tree, 3), RIGHT, 6));
	printf("%d", insertBT(searchBT(tree, 4), LEFT,	7));
	printf("%d", insertBT(searchBT(tree, 4), RIGHT,	8));

	mainView();
}