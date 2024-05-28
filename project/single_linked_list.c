#include "ds.h"

#define QUIT_OP			0
#define INSERT_OP		1
#define DELETE_OP		2

SLL* initSLL() {
	SLL* newList = (SLL*)malloc(sizeof(SLL));
	newList->head = NULL;
	newList->size = 0;
	return newList;
}

int insertSLL(SLL* list, DataType data, unsigned int idx) {
	if (list->size < idx) {
		printf("OUT OF INDEX ERROR!: %d -> [%d] length: %d \n", data, idx, list->size);
		return OUT_OF_INDEX_ERROR;
	}

	int curIdx = idx;
	SLL_Node* prevNode = list->head; // index를 가리킴
	SLL_Node* newNode = (SLL_Node*)malloc(sizeof(SLL_Node));
	newNode->data = data;

	if (list->size == 0) {
		//if (curIdx != 0) {
		//	free(newNode);
		//	printf("OUT OF INDEX ERROR!: %d -> [%d]\n", data, idx);
		//	return OUT_OF_INDEX_ERROR;
		//}
		list->head = newNode;
		list->size = 1;
		newNode->next = NULL;
		return SUCCESS;
	}

	if (idx == 0) {
		newNode->next = list->head;
		list->head = newNode;
		list->size++;
		return SUCCESS;
	}

	//while (--curIdx && prevNode != NULL) {
	while (curIdx-- > 1) {
		prevNode = prevNode->next;
	}

	//if (prevNode == NULL) {
	//	free(newNode);
	//	printf("OUT OF INDEX ERROR!: %d -> [%d]\n", data, idx);
	//	return OUT_OF_INDEX_ERROR;
	//}

	newNode->next = prevNode->next;
	prevNode->next = newNode;
	list->size++;

	return SUCCESS;
}

int deleteSLL(SLL* list, unsigned int idx) {
	if (list->size == 0) {
		return EMPTY_LIST_ERROR;
	}

	if (list->size < idx) {
		printf("OUT OF INDEX ERROR! \n");
		return OUT_OF_INDEX_ERROR;
	}

	int curIdx = idx;
	SLL_Node* prevNode = list->head;

	if (idx == 0) {
		list->head = prevNode->next;
		list->size--;
		free(prevNode);
		return SUCCESS;
	}

	while (--curIdx > 0) {
		prevNode = prevNode->next;
	}

	SLL_Node* target = prevNode->next;

	if (list->head == target) {
		list->head = target->next;
	}

	prevNode->next = target->next;
	free(target);

	list->size--;

	return SUCCESS;
}

void showSLL(SLL* list) {
	printf("    ");
	for (int i = 0; i < list->size; i++) {
		printf("┌──────┬┐ ");
	}
	printf("\n");
	SLL_Node* cur = list->head;
	printf("    ");
	while (cur) {
		printf("│ %-4d │┼→", cur->data);
		cur = cur->next;
	}
	printf(" NULL ");
	printf("\n");
	printf("    ");
	for (int i = 0; i < list->size; i++) {
		printf("└──────┴┘ ");
	}
	printf("\n");
}

void singlyLinkedListView() {
	int viewQuit = 0;

	int op = 0;
	int val = 0;

	unsigned int idx = 0;

	SLL* list = initSLL();
	int res = SUCCESS;

	while (1) {
		if (viewQuit) return;

		system("cls");

		switch (res) {
			case OUT_OF_INDEX_ERROR: {
				printf("\n%s OUT OF INDEX! %s\n", REDCOLOR, RESETCOLOR);
				break;
			};
			default:
				printf("\n\n");
		}

		printf("===============================================================================");

		printf("\n\n");

		showSLL(list);
		printf("\n\n");

		printf("  0. quit		\n");
		printf("  1. insert		\n");
		printf("  2. delete		\n");

		printf("\n\n");

		printf(" 연산을 선택하세요: ");
		scanf_s("%d", &op);

		switch (op) {
			case QUIT_OP: viewQuit = 1; break;

			case INSERT_OP: {
				printf("\n 삽입할 위치를 입력하세요 (INDEX): ");
				scanf_s("%d", &idx);
				printf("\n 삽입할 값을 입력하세요 (INT): ");
				scanf_s("%d", &val);

				res = insertSLL(list, val, idx);
				break;
			}

			case DELETE_OP: {
				printf("\n 삭제할 위치를 입력하세요 (INDEX): ");
				scanf_s("%d", &idx);

				res = deleteSLL(list, idx);
				break;
			};
		}
	}
}