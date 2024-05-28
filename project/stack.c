#include "ds.h"

#define QUIT_OP			0
#define PUSH_OP			1
#define POP_OP			2

Stack* initStack() {
	Stack* newStack = (Stack*)malloc(sizeof(Stack));
	newStack->top = -1;
	newStack->size = MIN_SIZE;
	newStack->data = (DataType*)malloc(newStack->size * sizeof(DataType));

	return newStack;
}

boolean isStackEmpty(Stack* stack) {
	return stack->top == -1;
}

boolean isStackFull(Stack* stack) {
	return stack->top == (stack->size - 1);
}

int pushStack(Stack* stack, DataType data) {
	int res = SUCCESS;
	if (isStackFull(stack)) {
		stack->size *= 2;
		stack->data = (DataType*)realloc(stack->data, stack->size * sizeof(DataType));
		res = REALLOC_LIST;
	}
	stack->data[++(stack->top)] = data;
	return res;
}

int popStack(Stack* stack) {
	if (isStackEmpty(stack)) {
		return;
	}

	return stack->data[(stack->top)--];
}

int peekStack(Stack* stack) {
	if (isStackEmpty(stack)) {
		return;
	}

	return stack->data[(stack->top)];
}

void showStack(Stack* stack) {
	printf("\n");
	for (int i = 0; i < stack->size - stack->top - 1; i++) {
		printf("\t┃     ┃ \n");
	}
	for (int i = stack->top; i >= 0; i--) {
		printf("\t┃ %3d ┃ \n", stack->data[i]);
	}
	printf("\t┗━━━━━┛\n");
}

void stackView() {
	int viewQuit = 0;

	int op = 0;
	int val = 0;

	Stack* stack = initStack();
	int res = SUCCESS;

	while (1) {
		if (viewQuit) return;

		system("cls");

		switch (res) {
			case REALLOC_LIST: {
					printf("\n%s REALLOC DATA ARRAY. %s\n", GREENCOLOR, RESETCOLOR);
					break;
				};
			default:
				printf("\n\n");
		}

		printf("===============================================================================");

		printf("\n\n");

		printf("    ");
		showStack(stack);
		printf("\n\n");

		printf("  0. quit		\n");
		printf("  1. push		\n");
		printf("  2. pop		\n");

		printf("\n\n");

		printf(" 연산을 선택하세요: ");
		scanf_s("%d", &op);

		switch (op) {
			case QUIT_OP: viewQuit = 1; break;

			case PUSH_OP: {
					printf("\n PUSH할 값을 입력하세요 (INT): ");
					scanf_s("%d", &val);

					res = pushStack(stack, val);
					break;
				};

			case POP_OP: {
					res = popStack(stack);
					break;
				};
		}
	}
}

