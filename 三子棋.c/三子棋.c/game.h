#pragma once
#include<stdio.h>
#include<time.h>

//���ŵĶ���
#define ROW 3
#define COL 3

//����������
void menu();
void game();

void InitBoard(char board[ROW][COL], int row, int col);

//��ӡ���̵ĺ���
void Displayed(char board[ROW][COL], int row,int col);

void Playermove(char board[ROW][COL], int row, int col);

void Computermove(char board[ROW][COL], int row, int col);

//1. ���Ӯ�� - *
//2.����Ӯ�� - #
//3.ƽ�� - Q
//4.��Ϸ���� - C

//�ж���Ϸ�Ƿ�����Ӯ
char IsWin(char board[ROW][COL], int row, int col);
