#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <conio.h>

#define TEXTCOLOR(R,G,B) "\033[38;2;"#R";"#G";"#B"m"
#define BACKCOLOR(R,G,B) "\033[48;2;"#R";"#G";"#B"m"
#define RESETCOLOR "\033[0m"

#define REDCOLOR "\033[38;2;200;0;0m"
#define GREENCOLOR "\033[38;2;0;200;0m"

#define GRAD1_COLOR "\033[38;2;255;255;255m"
#define GRAD2_COLOR "\033[38;2;235;235;235m"
#define GRAD3_COLOR "\033[38;2;215;215;215m"
#define GRAD4_COLOR "\033[38;2;195;195;195m"
#define GRAD5_COLOR "\033[38;2;175;175;175m"
#define GRAD6_COLOR "\033[38;2;155;155;155m"
#define GRAD7_COLOR "\033[38;2;135;135;135m"
#define GRAD8_COLOR "\033[38;2;115;115;115m"
#define GRAD9_COLOR "\033[38;2;95;95;95m"
#define GRAD10_COLOR "\033[38;2;75;75;75m"

#define SUCCESS							0x20
#define REALLOC_LIST					0x21
#define EMPTY_LIST_ERROR				0x40
#define OUT_OF_INDEX_ERROR				0x41
#define HAS_LEFT_CHILD_ERROR			0x42
#define HAS_RIGHT_CHILD_ERROR			0x43
#define HAS_CHILD_ERROR					0x44

#define LIST						1
#define		SINGLY_LINKED_LIST		1
#define		DOUBLY_LINKED_LIST		2
#define		STACK					3
#define		QUEUE					4
#define		DEQUE					5
#define TREE						2
#define		BINARY_TREE				1
#define		THREAD_BINARY_TREE		2

#define MIN_SIZE					4
#define MAX_SIZE					255
#define MAX_QUEUE_SIZE				32

#define LEFT						0
#define RIGHT						1

/************************************/

typedef int	DataType;
typedef int MESSAGE_CODE;
typedef int CHILD_POS;

typedef struct o__SLL_Node {
	DataType data;
	struct o__SLL_Node* next;
} SLL_Node, QueueNode;

typedef struct {
	SLL_Node* head;
	unsigned int size;
} SLL, SLL;

typedef struct o__DLL_Node {
	DataType data;
	struct o__DLL_Node* next;
	struct o__DLL_Node* prev;
} DLL_Node;

typedef struct {
	DLL_Node* head;
	DLL_Node* tail;
	unsigned int size;
} DoublyLinkedList, DLL;

typedef struct {
	DataType* data;
	int size;
	int top;
} Stack;

typedef struct o__BT_Node {
	DataType data;
	struct o__BT_Node* left;
	struct o__BT_Node* right;
} BT_Node;

typedef struct {
	BT_Node* head;
} BinaryTree, BT;

typedef struct {
	DataType data[MAX_QUEUE_SIZE];
	int front, rear;
} Queue;

typedef struct o__TBT_Node {
	DataType data;
	struct o__TBT_Node *left, *right;
	boolean isThread;
	// isThread가 TRUE라면 right가 노드 중위 후속자이며 FALSE라면 오른쪽 자식을 가리키는 포인터가 된다
} TBT_Node;

typedef struct {
	TBT_Node *root;
} ThreadBinaryTree, TBT;

/************************************/

void clearBuffer();

void mainView();
void singlyLinkedListView();
void doublyLinkedListView();
void stackView();

SLL* initSLL();
MESSAGE_CODE insertSLL(SLL*, DataType, unsigned int);
int deleteSLL(SLL*, unsigned int);
void showSLL(SLL*);

DLL* initDLL();
MESSAGE_CODE insertDLL(DLL*, DataType, int);
int deleteDLL(DLL*, int);
void showDLL(DLL*, int);

Stack* initStack();
boolean isStackEmpty(Stack* stack);
boolean isStackFull(Stack* stack);
MESSAGE_CODE pushStack(Stack* stack, DataType data);
DataType popStack(Stack* stack);

//Queue* initQueue();

BT* initBT();
BT_Node* newBTNode(DataType data);
unsigned int getHeightBT(BT* tree);
MESSAGE_CODE insertBT(BT_Node* node, CHILD_POS pos, DataType data);
MESSAGE_CODE insertFirstBT(BT* tree, DataType data);
BT_Node* searchBT(BT* tree, DataType key);
MESSAGE_CODE removeBT(BT_Node* node, CHILD_POS pos);
void showBT(BT* tree);

// Thread Binary Tree
/** 다음 순회할 노드(successor) 찾기 */
TBT_Node* findSuccessor(TBT_Node* node);
void inorderThread(ThreadBinaryTree* tree);