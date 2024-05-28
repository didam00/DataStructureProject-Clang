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

#define EMPTY_LIST_ERROR				0x00
#define SUCCESS							0x01
#define REALLOC_LIST					0x02
#define OUT_OF_INDEX_ERROR				0x0F

#define LIST						1
#define		SINGLY_LINKED_LIST		1
#define		DOUBLY_LINKED_LIST		2
#define		STACK					3
#define		QUEUE					4
#define		DEQUE					5

#define MIN_SIZE					4
#define MAX_SIZE					255

/************************************/

typedef int	DataType;


typedef struct o__SLL_Node {
	DataType data;
	struct o__SLL_Node* next;
} SLL_Node;

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

/************************************/

void clearBuffer();

void mainView();
void singlyLinkedListView();
void doublyLinkedListView();
void stackView();

SLL* initSLL();
int insertSLL(SLL*, DataType, unsigned int);
int deleteSLL(SLL*, unsigned int);
void showSLL(SLL*);

DLL* initDLL();
int insertDLL(DLL*, DataType, int);
int deleteDLL(DLL*, int);
void showDLL(DLL*, int);

Stack* initStack();
int isEmpty(Stack* stack);
int isFull(Stack* stack);
int push(Stack* stack, DataType data);
DataType pop(Stack* stack);