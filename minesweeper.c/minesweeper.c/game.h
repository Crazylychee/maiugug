#define CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#pragma once
#include<stdlib.h>
#include<time.h>

#define COL 9
#define ROW 9
#define EASY_COUNT 10

#define COLS COL + 2
#define ROWS ROW + 2

//��ʼ�����̵�
void InitBoard(char board[ROWS][COLS], int rows, int cols, char set);

//��ӡ����
void DisplayBoard(char board[ROWS][COLS], int row, int col);

//�����׵�λ��
void SetMine(char mine[ROWS][COLS], int row, int col);

//�Ų���
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);
