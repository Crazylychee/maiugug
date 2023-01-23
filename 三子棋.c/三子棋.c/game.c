#include"game.h"
void menu()
{
	printf("************************************\n");
	printf("**********  1. ��ʼ��Ϸ  ***********\n");
	printf("**********  0. �˳���Ϸ  ***********\n");
	printf("************************************\n");
}
void game()
{
	//�洢���� - ��ά����
	char board[ROW][COL];
	//��ʼ������ - ��ʼ���ո�
	InitBoard(board, ROW, COL);

	//��ӡһ������ - �����Ǵ�ӡ���������
	Displayed(board, ROW, COL);
	char ret = 0;//������Ϸ״̬
	while (1)
	{
		//�������
		Playermove(board, ROW, COL);
		Displayed(board, ROW, COL);
		//�ж�����Ƿ�Ӯ����Ϸ
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
			break;
		//��������
		Computermove(board, ROW, COL);
		Displayed(board, ROW, COL);

		//�жϵ����Ƿ�Ӯ����Ϸ
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
			break;
	}
	if (ret == '*')
	{
		printf("���Ӯ��\n");
	}
	else if (ret == '#')
	{
		printf("����Ӯ��\n");
	}
	else
	{
		printf("ƽ��\n");
	}
	Displayed(board, ROW, COL);
}
void InitBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)//ԭ���Ǵ�ӡ��ά����
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

	printf("�����:>\n");

	while (1)
	{
		printf("����������λ�ã�\n");
		scanf("%d %d", &x, &y);
		//�ж�����Ϸ���
		if (x <= ROW&&x > 0 && y <= COL&&y > 0)
		{
			//����
			//�����Ƿ�ռ��
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("���걻ռ�ã�����������\n");
			}
		}
		else
		{
			printf("����Ƿ�������������\n");
		}
	}
}
void Computermove(char board[ROW][COL], int row, int col)
{
	printf("�����ߣ�>\n");

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
				return 0;//����û��
			}
		}
	}
	return 1;
}
char IsWin(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)//�ж������
	{
		if (board[0][i] == board[1][i] && board[1][i]==board[2][i] && board[0][i] != ' ')
		{
			return board[0][i]; 
		}
	}
	for (i = 0; i < col; i++)//�ж������
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][2] != ' ')
		{
			return board[i][0];
		}
	}
	//for (i = 0; i < row; i++)//�ж϶Խ������
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
	
	//�ж�ƽ��
	//����������˷���1����������0
	int ret = IsFull(board, row, col);
	if (ret == 1)
	{
		return 'Q';
	}

	//����
	return 'C';
}