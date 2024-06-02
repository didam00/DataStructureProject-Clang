#include "ds.h"

void mainView() {
	int sel = 0;
	int sub_sel = 0;

	while (1) {
		system("cls");

		printf("\n\n===============================================================================");

		printf("\n\n\n");

		printf("%s\t,------.            ,--.				%s\n", GRAD1_COLOR, RESETCOLOR);
		printf("%s\t|  .-.  \\  ,--,--.,-'  '-. ,--,--.		%s\n", GRAD2_COLOR, RESETCOLOR);
		printf("%s\t|  |  \\  :' ,-.  |'-.  .-'' ,-.  |		%s\n", GRAD3_COLOR, RESETCOLOR);
		printf("%s\t|  '--'  /\\ '-'  |  |  |  \\ '-'  |	%s\n", GRAD4_COLOR, RESETCOLOR);
		printf("%s\t`-------'  `--`--'  `--'   `--`--'		%s\n", GRAD5_COLOR, RESETCOLOR);
		printf("%s\t ,---.   ,--.                         ,--.								%s\n", GRAD6_COLOR, RESETCOLOR);
		printf("%s\t'   .-',-'  '-.,--.--.,--.,--. ,---.,-'  '-.,--.,--.,--.--. ,---.		%s\n", GRAD7_COLOR, RESETCOLOR);
		printf("%s\t`.  `-.'-.  .-'|  .--'|  ||  || .--''-.  .-'|  ||  ||  .--'| .-. :		%s\n", GRAD8_COLOR, RESETCOLOR);
		printf("%s\t.-'    | |  |  |  |   '  ''  '\\ `--.  |  |  '  ''  '|  |   \\   --.	%s\n", GRAD9_COLOR, RESETCOLOR);
		printf("%s\t`-----'  `--'  `--'    `----'  `---'  `--'   `----' `--'    `----'		%s\n", GRAD10_COLOR, RESETCOLOR);
		printf("\n\n\n");

		if (sel <= 0 || sel >= 4) {
			printf("\t 1. 선형구조 \n");
			printf("\t 2. 트리 \n");
			printf("\n");
			printf("\n");
			printf("\n");
			printf("\n");

			printf("\n\n");
			printf("\t 자료구조를 선택하세요: ");
			scanf_s("%d", &sel);

			continue;
		}

		if (sel == LIST) {
			printf("\t 0. 돌아가기			\n");
			printf("\t 1. 단일 연결리스트		\n");
			printf("\t 2. 이중 연결리스트		\n");
			printf("\t 3. 스택				\n");
			printf("\t 4. 큐					\n");
			printf("\t 5. 덱					\n");

			printf("\n\n");
			printf("\t 하위 자료구조를 선택하세요: ");
			scanf_s("%d", &sub_sel);

			switch (sub_sel) {
				case 0: sel = 0; break;
				case SINGLY_LINKED_LIST	: singlyLinkedListView(); break;
				case DOUBLY_LINKED_LIST	: doublyLinkedListView(); break;
				case STACK				: stackView(); break;
			}
		} else if (sel == TREE) {
			printf("\t 0. 돌아가기			\n");
			printf("\t 1. 이진 트리			\n");
			printf("\t 2. 스레드 이진 트리		\n");
			printf("\n");
			printf("\n");
			printf("\n");

			printf("\n\n");
			printf("\t 하위 자료구조를 선택하세요: ");
			scanf_s("%d", &sub_sel);

			switch (sub_sel) {
				case 0: sel = 0; break;
				case SINGLY_LINKED_LIST	: singlyLinkedListView(); break;
				case DOUBLY_LINKED_LIST	: doublyLinkedListView(); break;
				case STACK				: stackView(); break;
			}
		}
	}
}