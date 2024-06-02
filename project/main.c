#include "ds.h"
int main() {
			TBT_Node b1 = { 1, NULL, NULL, TRUE };
			TBT_Node b2 = { 2, NULL, NULL, TRUE };
		TBT_Node b3 = { 3, &b1, &b2, FALSE };
			TBT_Node b4 = { 4, NULL, NULL, TRUE };
			TBT_Node b5 = { 5, NULL, NULL, FALSE };
		TBT_Node b6 = { 6, &b4, &b5, FALSE };
	TBT_Node b7 = { 7, &b3, &b6, FALSE };
	TBT tree = { &b7 };

	b4.right = &b6;
	b2.right = &b7;
	b1.right = &b3;

	inorderThread(&tree);

	//mainView();
}