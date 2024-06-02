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
			printf("\t 1. �������� \n");
			printf("\t 2. Ʈ�� \n");
			printf("\n");
			printf("\n");
			printf("\n");
			printf("\n");

			printf("\n\n");
			printf("\t �ڷᱸ���� �����ϼ���: ");
			scanf_s("%d", &sel);

			continue;
		}

		if (sel == LIST) {
			printf("\t 0. ���ư���			\n");
			printf("\t 1. ���� ���Ḯ��Ʈ		\n");
			printf("\t 2. ���� ���Ḯ��Ʈ		\n");
			printf("\t 3. ����				\n");
			printf("\t 4. ť					\n");
			printf("\t 5. ��					\n");

			printf("\n\n");
			printf("\t ���� �ڷᱸ���� �����ϼ���: ");
			scanf_s("%d", &sub_sel);

			switch (sub_sel) {
				case 0: sel = 0; break;
				case SINGLY_LINKED_LIST	: singlyLinkedListView(); break;
				case DOUBLY_LINKED_LIST	: doublyLinkedListView(); break;
				case STACK				: stackView(); break;
			}
		} else if (sel == TREE) {
			printf("\t 0. ���ư���			\n");
			printf("\t 1. ���� Ʈ��			\n");
			printf("\t 2. ������ ���� Ʈ��		\n");
			printf("\n");
			printf("\n");
			printf("\n");

			printf("\n\n");
			printf("\t ���� �ڷᱸ���� �����ϼ���: ");
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