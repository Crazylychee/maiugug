#pragma once
#include<stdio.h>
#include<time.h>

//符号的定义
#define ROW 3
#define COL 3

//函数的声明
void menu();
void game();

void InitBoard(char board[ROW][COL], int row, int col);

//打印棋盘的函数
void Displayed(char board[ROW][COL], int row,int col);

void Playermove(char board[ROW][COL], int row, int col);

void Computermove(char board[ROW][COL], int row, int col);

//1. 玩家赢了 - *
//2.电脑赢了 - #
//3.平局 - Q
//4.游戏继续 - C

//判断游戏是否有输赢
char IsWin(char board[ROW][COL], int row, int col);
