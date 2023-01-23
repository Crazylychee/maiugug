#include"game.h"
void menu()
{
	printf("************************************\n");
	printf("**********  1. 开始游戏  ***********\n");
	printf("**********  0. 退出游戏  ***********\n");
	printf("************************************\n");
}
void game()
{
	//存储数据 - 二维数组
	char board[ROW][COL];
	//初始化棋盘 - 初始化空格
	InitBoard(board, ROW, COL);

	//打印一下棋盘 - 本质是打印数组的内容
	Displayed(board, ROW, COL);
	char ret = 0;//接受游戏状态
	while (1)
	{
		//玩家下棋
		Playermove(board, ROW, COL);
		Displayed(board, ROW, COL);
		//判断玩家是否赢得游戏
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
			break;
		//电脑下棋
		Computermove(board, ROW, COL);
		Displayed(board, ROW, COL);

		//判断电脑是否赢得游戏
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
			break;
	}
	if (ret == '*')
	{
		printf("玩家赢了\n");
	}
	else if (ret == '#')
	{
		printf("电脑赢了\n");
	}
	else
	{
		printf("平局\n");
	}
	Displayed(board, ROW, COL);
}
void InitBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)//原理是打印二维数组
	{
		for (j = 0;j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}

void Displayed(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)
				printf("|");
			else
				printf("\n");
		}
		for (j = 0; j < col; j++)
		{
			printf("---");
			if (j < col - 1)
				printf("|");
		}
		printf("\n");
	}
}
void Playermove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;

	printf("玩家走:>\n");

	while (1)
	{
		printf("请输入下棋位置：\n");
		scanf("%d %d", &x, &y);
		//判断坐标合法性
		if (x <= ROW&&x > 0 && y <= COL&&y > 0)
		{
			//下棋
			//坐标是否被占用
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("坐标被占用，请重新输入\n");
			}
		}
		else
		{
			printf("坐标非法，请重新输入\n");
		}
	}
}
void Computermove(char board[ROW][COL], int row, int col)
{
	printf("电脑走：>\n");

	while (1)
	{
		int x = rand() % row;
		int y = rand() % col;

		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}
}
int IsFull(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
			{
				return 0;//棋盘没满
			}
		}
	}
	return 1;
}
char IsWin(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)//判断列相等
	{
		if (board[0][i] == board[1][i] && board[1][i]==board[2][i] && board[0][i] != ' ')
		{
			return board[0][i]; 
		}
	}
	for (i = 0; i < col; i++)//判断行相等
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][2] != ' ')
		{
			return board[i][0];
		}
	}
	//for (i = 0; i < row; i++)//判断对角线相等
	//{
	//	if ()
	//}
	if (board[0][0] == board[1][1] && board[2][2] == board[1][1] && board[0][0] != ' ')
	{
		return board[1][1];
	}
	if (board[2][0] == board[1][1] && board[0][2] == board[1][1] && board[1][1] != ' ')
	{
		return board[2][0];
	}
	
	//判断平局
	//如果棋盘满了返回1，不满返回0
	int ret = IsFull(board, row, col);
	if (ret == 1)
	{
		return 'Q';
	}

	//继续
	return 'C';
}