#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "maze3.h"
#define MAX_STACK_SIZE 10000
#define MAX_QUEUE_SIZE 10000
#define MAX_PQ_SIZE 10000

struct element {
	short int row;
	short int col;
	short int dir;
	element* parent;
	int dist;
};

typedef struct {
	short int x;
	short int y;
}offsets;

offsets move[8] = {
	{-1,0},
	{-1,1},
	{0,1},
	{1,1},
	{1,0},
	{1,-1},
	{0,-1},
	{-1,-1},
};

#pragma region BFS/DFS/Best_FS
void DFS();
void BFS();
void Best_FS();
void DFSPrintNode(bool found);
void BFSPrintNode(element* Dest);
void Best_FSPrintNode(element* Dest);
#pragma endregion

#pragma region 스택
element stack[MAX_STACK_SIZE];
int s_top;
void S_Push(element value);
element S_Pop();
#pragma endregion

#pragma region 큐
element queue[MAX_QUEUE_SIZE];
int front, rear, pointer;
void Q_Push(element value);
element* Q_Pop();
bool Q_empty();
bool Q_full();
#pragma endregion

#pragma region 우선순위 큐
struct Heap {
	element Open[MAX_PQ_SIZE];
	element Closed[MAX_PQ_SIZE];
	int pq_size;
};
Heap heap;
int closed_top = 0;
void PQ_Insert();
element PQ_Pop();
bool PQ_empty();
bool PQ_Full();
#pragma endregion

#pragma region 스택 구현부
void S_Push(element value) {
	if (s_top == MAX_STACK_SIZE - 1)
		return;
	stack[++s_top] = value;
}
element S_Pop() {
	if (s_top == -1) {
		fprintf(stderr, "Error : stack is empty");
		exit(1);
	}
	return stack[s_top--];
}
#pragma endregion

#pragma region 큐 구현부
void Q_Push(element value) {
	if (!Q_full()) {
		queue[rear] = value;
		rear += 1;
	}
	else {
		fprintf(stderr, "Error : Queue is Full");
		exit(1);
	}
}
element* Q_Pop() {
	if (!Q_empty()) {
		return &queue[front++];
	}
	else {
		fprintf(stderr, "Error : Queue is Empty");
		exit(1);
	}
}
bool Q_empty() {
	return front == rear;
}
bool Q_full() {
	if (rear == MAX_QUEUE_SIZE) {
		return true;
	}
	else
		return false;
}
int Q_Size() {
	return front > rear ? front - rear : rear - front;
}
#pragma endregion

#pragma region 우선순위 큐 구현부
void PQ_Insert(element value) {
	int i = ++(heap.pq_size);//pq[1]부터 추가
	if (!PQ_Full()) {
		while ((i != 1) && (value.dist < heap.Open[i].dist)) {
			heap.Open[i] = heap.Open[i / 2];
			i /= 2;
		}
		heap.Open[i] = value;
	}
	else {
		fprintf(stderr, "Error : Priority Queue is Full");
		exit(1);
	}
}
element PQ_Pop() {
	element value, temp;
	int parent, child;

	if (!PQ_empty()) {
		value = heap.Open[1];
		temp = heap.Open[heap.pq_size--];
		parent = 1;
		child = 2;
		while (child <= heap.pq_size) {
			if ((child < heap.pq_size) && ((heap.Open[child].dist > heap.Open[child + 1].dist))) {
				child++;
			}

			if (temp.dist <= heap.Open[child].dist)
				break;

			heap.Open[parent] = heap.Open[child];
			parent = child;
			child *= 2;
		}
	}
	else {
		fprintf(stderr, "Error : Priority Queue is Empty");
		exit(1);
	}

	heap.Open[parent] = temp;
	return value;
}
bool PQ_empty() {
	if (heap.pq_size == 0)
		return true;
	else
		return false;
}
bool PQ_Full() {
	if (heap.pq_size == MAX_PQ_SIZE)
		return true;
	else
		return false;
}

#pragma endregion

void DFS()
{
	// 미로를 통과하는 경로가 존재할 경우, 이를 출력
	int  row, col, next_row, next_col, dir;
	int  found = false;
	element  position;

	// 미로의 입구좌표와 E 방향으로 stack 초기화
	mark[START_ROW][START_COL] = 1;
	s_top = 0;
	stack[0].row = 1;
	stack[0].col = 1;
	stack[0].dir = 0;
	while (s_top > -1 && !found) { // stack이 empty가 아니고, 아직
						   // 경로를 발견 못할 때까지 실행
		position = S_Pop();	 // top의 위치로 이동
		row = position.row;
		col = position.col;
		dir = position.dir;

		while (dir < 8 && !found) { // 8방향을 차례대로 검사
			next_row = row + move[dir].x;
			next_col = col + move[dir].y;
			if (next_row == EXIT_ROW && next_col == EXIT_COL) {
				position.row = row;
				position.col = col;
				position.dir = ++dir;
				S_Push(position);
				mark[next_row][next_col] = 1;
				found = true;
			}
			else if (!maze[next_row][next_col] && !mark[next_row][next_col]) {
				position.row = row;
				position.col = col;
				position.dir = ++dir;
				S_Push(position);  // 현재 좌표와 방향을 stack 저장
				row = next_row;  // 안 가본 길로 전진. 방향은 북쪽
				col = next_col;
				mark[next_row][next_col] = 1;
				dir = 0;
			}
			else  ++dir;
		}
	}

	DFSPrintNode(found);
}

void DFSPrintNode(bool found) {
	if (found) {
		/*
		printf(" The path is: \n ");
		printf("row  col \n");
		for (i = 0; i <= top; i++)
			printf(" %2d %5d \n", stack[i].row, stack[i].col);
		printf(" %2d %5d \n", row, col);
		printf(" %2d %5d \n", EXIT_ROW, EXIT_COL);*/
		int VN = 0;
		int i;
		char printer[ROWS][COLS];
		for (i = 0; i < ROWS; i++) {
			for (int j = 0; j < COLS; j++) {
				if (maze[i][j] == 1)
					printer[i][j] = '|';
				else if (mark[i][j] == 1) {
					printer[i][j] = '.';
					VN++;
				}
				else
					printer[i][j] = ' ';
			}
		}
		for (int k = 0; k <= s_top; k++) {
			int row = stack[k].row;
			int col = stack[k].col;
			printer[row][col] = 'o';
		}
		printer[START_ROW][START_COL] = 'S';
		printer[EXIT_ROW][EXIT_COL] = 'G';


		printf("DFS : \n");
		for (i = 0; i < ROWS; i++) {
			for (int j = 0; j < COLS; j++) {
				printf("%2c", printer[i][j]);
			}
			printf("\n");
		}
		printf("DFS : \n");
		printf("  No. of Visited Nodes : %d\n", VN);
		printf("  Length of Goal Path : %d\n", s_top + 1);
	}
	else printf(" The maze does not have a path \n ");
}

void BFS() {
	// 1. 시작 위치에서 가능한 모든 곳들을 queue에 저장(parent : 현재노드)
	// 2. 1에서 queue에 저장한 노드 수만큼 꺼내서 하나씩 확인, 각각의 노드에 대해 1번 반복
	// 3. 도착지점에 도착한 경우 이 노드의 부모를 타고 출력 

	front = 0, rear = 1;
	bool found = false;
	element* Dest = nullptr;

	queue[0].row = START_ROW;
	queue[0].col = START_COL;
	queue[0].parent = nullptr;

	while (!Q_empty()) {
		element* nowPos = Q_Pop();
		int row = (*nowPos).row;
		int col = (*nowPos).col;

		element* parent = nowPos;

		if (row == EXIT_ROW && col == EXIT_COL) {
			found = true;
			Dest = nowPos;
			break;
		}
		for (int dir = 0; dir < 8; dir++) {
			int next_row = row + move[dir].x;
			int next_col = col + move[dir].y;
			if (!maze[next_row][next_col] && !mark[next_row][next_col]) {
				element position;
				position.row = next_row;
				position.col = next_col;
				position.parent = parent;
				Q_Push(position);  // 현재 좌표와 방향을 queue 저장
				mark[next_row][next_col] = 1;
			}
		}
	}

	if (found) {
		BFSPrintNode(Dest);
	}
	else {
		printf(" The maze does not have a path \n ");
	}
}

void BFSPrintNode(element* Dest) {
	int VN = 0, GN = 0;
	int i;
	char printer[ROWS][COLS];
	for (i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			if (maze[i][j] == 1)
				printer[i][j] = '|';
			else if (mark[i][j] == 1) {
				printer[i][j] = '.';
				VN++;
			}
			else {
				printer[i][j] = ' ';
			}
		}
	}
	for (element* position = Dest; (*position).parent != nullptr; position = (*position).parent) {
		int row = (*position).row;
		int col = (*position).col;
		printer[row][col] = 'o';
		GN++;
	}
	printer[START_ROW][START_COL] = 'S';
	printer[EXIT_ROW][EXIT_COL] = 'G';


	printf("BFS : \n");
	for (i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			printf("%2c", printer[i][j]);
		}
		printf("\n");
	}
	printf("BFS : \n");
	printf("  No. of Visited Nodes : %d\n", VN);
	printf("  Length of Goal Path : %d\n", GN);
}

void Best_FS() {
	bool found = false;
	element* Dest = nullptr;
	element position;
	position.row = START_ROW;
	position.col = START_COL;
	position.dist = (EXIT_ROW - position.row) + (EXIT_COL - position.col);
	position.parent = nullptr;
	PQ_Insert(position);

	while (!PQ_empty()) {
		element nowPos = PQ_Pop();
		int row = nowPos.row;
		int col = nowPos.col;
		int dist = nowPos.dist;

		heap.Closed[closed_top] = nowPos;

		element* parent = &heap.Closed[closed_top];

		if (row == EXIT_ROW && col == EXIT_COL) {
			found = true;
			Dest = parent;
			break;
		}

		for (int dir = 0; dir < 8; dir++) {
			int next_row = row + move[dir].x;
			int next_col = col + move[dir].y;
			int next_dist = (EXIT_ROW - next_row) + (EXIT_COL - next_col);
			if (!maze[next_row][next_col] && !mark[next_row][next_col]) {
				element position;
				position.row = next_row;
				position.col = next_col;
				position.dist = next_dist;
				position.parent = parent;
				PQ_Insert(position);
				mark[next_row][next_col] = 1;
			}
		}

		closed_top++;
	}

	if (found) {
		Best_FSPrintNode(Dest);
	}
	else {
		printf(" The maze does not have a path \n ");
	}
}

void Best_FSPrintNode(element* Dest) {
	int VN = 0, GN = 0;
	int i;
	char printer[ROWS][COLS];
	for (i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			if (maze[i][j] == 1)
				printer[i][j] = '|';
			else if (mark[i][j] == 1) {
				printer[i][j] = '.';
				VN++;
			}
			else {
				printer[i][j] = ' ';
			}
		}
	}
	for (element* position = Dest; (*position).parent != nullptr; position = (*position).parent) {
		int row = (*position).row;
		int col = (*position).col;
		printer[row][col] = 'o';
		GN++;
	}
	printer[START_ROW][START_COL] = 'S';
	printer[EXIT_ROW][EXIT_COL] = 'G';


	printf("BestFS : \n");
	for (i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			printf("%2c", printer[i][j]);
		}
		printf("\n");
	}
	printf("BestFS : \n");
	printf("  No. of Visited Nodes : %d\n", VN);
	printf("  Length of Goal Path : %d\n", GN);
}



int main() {

	DFS();
	memset(mark, 0, sizeof(mark));
	printf("\n-------------------------------------------------\n");
	BFS();
	memset(mark, 0, sizeof(mark));
	printf("\n-------------------------------------------------\n");
	Best_FS();

	return 0;
}
