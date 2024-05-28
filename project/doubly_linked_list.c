#include "ds.h"

#define QUIT_OP			0
#define INSERT_OP		1
#define DELETE_OP		2

DLL* initDLL() {
	DLL* newList = (DLL*)malloc(sizeof(DLL));
	newList->head = NULL;
	newList->tail = NULL;
	newList->size = 0;
	return newList;
}

int insertDLL(DLL* list, DataType data, int idx) {
	if ((int)(list->size) < idx || (int)(list->size) < -idx) {
		printf("OUT OF INDEX ERROR!: %d -> [%d] length: %d \n", data, idx, list->size);
		return OUT_OF_INDEX_ERROR;
	}

	DLL_Node* newNode = (DLL_Node*)malloc(sizeof(DLL_Node));
	newNode->data = data;

	// first insert
	if (list->size == 0) {
		list->size = 1;

		list->head = newNode;
		list->tail = newNode;

		newNode->next = newNode;
		newNode->prev = newNode;

		return SUCCESS;
	}

	if (idx < 0) {
		negativeInsertDLL(list, newNode, -idx);
	} else {
		positiveInsertDLL(list, newNode, idx);
	}

	list->size++;

	return SUCCESS;
}

int positiveInsertDLL(DLL* list, DLL_Node* newNode, int idx) {
	int curIdx = idx;
	DLL_Node* prevNode = list->head;

	if (idx == 0) {
		newNode->next = list->head;
		newNode->prev = list->tail;

		list->head->prev = newNode;
		list->tail->next = newNode;

		list->head = newNode;
		return SUCCESS;
	}

	if (idx == list->size) {
		newNode->next = list->head;
		newNode->prev = list->tail;

		list->head->prev = newNode;
		list->tail->next = newNode;

		list->tail = newNode;
		return SUCCESS;
	}

	while (curIdx-- > 1) {
		prevNode = prevNode->next;
	}

	newNode->next = prevNode->next;
	newNode->prev = prevNode;
	prevNode->next->prev = newNode;
	prevNode->next = newNode;

	return SUCCESS;
}

int negativeInsertDLL(DLL* list, DLL_Node* newNode, int idx) {
	int curIdx = idx;
	DLL_Node* prevNode = list->tail;

	while (curIdx-- > 0) {
		prevNode = prevNode->prev;
	}

	newNode->next = prevNode->next;
	newNode->prev = prevNode;
	prevNode->next->prev = newNode;
	prevNode->next = newNode;
	list->size++;
}

int deleteDLL(DLL* list, int idx) {
	if (list->size == 0) {
		return EMPTY_LIST_ERROR;
	}

	if ((int)(list->size) < idx || (int)(list->size) < -idx) {
		printf("OUT OF INDEX ERROR! \n");
		return OUT_OF_INDEX_ERROR;
	}

	if (list->size == 1) {
		DLL_Node* target = list->head;

		list->head = NULL;
		list->tail = NULL;

		free(target);
		list->size--;

		return SUCCESS;
	}

	if (idx < 0) {
		negativeDeleteDLL(list, -idx);
	} else {
		positiveDeleteDLL(list, idx);
	}

	return SUCCESS;
}

int positiveDeleteDLL(DLL* list, int idx) {
	int curIdx = idx;
	DLL_Node* prevNode = list->head;

	while (--curIdx) {
		prevNode = prevNode->next;
	}

	DLL_Node* target = prevNode->next;

	if (list->head == target) {
		list->head = target->next;
	}

	if (list->tail == target) {
		list->tail = target->prev;
	}

	target->next->prev = prevNode;
	prevNode->next = target->next;
	
	free(target);

	list->size--;
}

int negativeDeleteDLL(DLL* list, int idx) {
	int curIdx = idx;
	DLL_Node* prevNode = list->tail;

	while (--curIdx > -1) {
		prevNode = prevNode->prev;
	}

	DLL_Node* target = prevNode->next;

	if (list->head == target) {
		list->head = target->next;
	}

	if (list->tail == target) {
		list->tail = target->prev;
	}

	target->next->prev = prevNode;
	prevNode->next = target->next;

	free(target);

	list->size--;
}

void showDLL(DLL* list, int step) {
	if (list->size == 0) {
		printf("NULL \n");
		return;
	}

	if (step > 0) {
		DLL_Node* cur = list->head;

		do {
			printf("%d ", cur->data);
			cur = cur->next;
			if (cur != list->head) {
				printf("-> ");
			}
		} while (cur != list->head);

		printf("\n");
	} else if (step < 0) {
		DLL_Node* cur = list->tail;

		do {
			printf("%d ", cur->data);
			cur = cur->prev;
			if (cur != list->tail) {
				printf("<- ");
			}
		} while (cur != list->tail);

		printf("\n");
	}
}

void doublyLinkedListView() {
	int viewQuit = 0;

	int op = 0;
	int val = 0;

	int idx = 0;

	DLL* list = initDLL();
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

		printf("    ");
		if (op == 3) {
			showDLL(list, -1);
		} else {
			showDLL(list, 1);
		}
		printf("\n");

		printf("  0. quit		\n");
		printf("  1. insert		\n");
		printf("  2. delete		\n");
		printf("  3. reverse	\n");
		printf("  9. pass		\n");

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

					res = insertDLL(list, val, idx);
					break;
				};

			case DELETE_OP: {
					printf("\n 삭제할 위치를 입력하세요 (INDEX): ");
					scanf_s("%d", &idx);

					res = deleteDLL(list, idx);
					break;
				};
		}
	}
}