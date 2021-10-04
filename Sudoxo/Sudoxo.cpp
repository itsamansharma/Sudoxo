#include<stdio.h>
#include<conio.h>

char  box[9][9];
/* Hello world */

void changeto0()
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			box[i][j] = 0;
		}
	}
}

bool check(int row, int clm, char p)
{
	int i, j;

	row = row / 3;
	clm = clm / 3;


	for (i = 0; i < 9; i++)
	{
		for (j = 0; j < 9; j++)
		{
			if (i / 3 == row && j / 3 == clm)
			{

				if (box[i][j] == p && box[i + 1][j] == p && box[i + 2][j] == p)
					return true;

				// x _ _
				// x _ _
				// x _ _

				else if (box[i][j] == p && box[i][j + 1] == p && box[i][j + 2] == p)
					return true;

				// x x x
				// _ _ _
				// _ _ _

				else if (box[i][j] == 'x' && box[i + 1][j + 1] == 'x' && box[i + 2][j + 2] == 'x' || box[i][j] == 'o' && box[i + 1][j + 1] == 'o' && box[i + 2][j + 2] == 'o')
					return true;
				// x _ _
				// _ x _
				// _ _ x

			}

			if (i / 3 == (row + 2) && j / 3 == (clm + 2))
			{

				if ((i + 2) / 3 == row && j / 3 == clm)
				{

					if (box[i + 2][j] == 'x' && box[i + 1][j + 1] == 'x' && box[i][j + 2] == 'x' || box[i + 2][j] == 'o' && box[i + 1][j + 1] == 'o' && box[i][j + 2] == 'o')
						return true;
					// _ _ 1
					// _ 1 _
					// 1 _ _
				}
			}
			
		}
	}
	return false;
}

void view()
{
	for (int i = 0; i < 9; i++)
	{
		if (i % 3 == 0 && i > 0)
		{
			printf("\n\n");
		}
		for (int j = 0; j < 9; j++)
		{
			if (j % 3 == 0 && j > 0)
			{
				printf("\t");
			}
			printf("  %c", box[i][j]);

		}
		printf("\n");
	}
}

void initial1()
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			box[i][j] = '1';
		}
	}
}


void changeto1(int row, int clm)
{

	row = row - (row / 3) * 3;
	clm = clm - (clm / 3) * 3;



	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (i / 3 == row && j / 3 == clm)
			{

				if (box[i][j] == '0')
				{

					box[i][j] = '1';
				}
			}
			else
			{
				if (box[i][j] == '1')
					box[i][j] = '0';
			}

		}
	}
}

void main()
{
	int i, j, n, x;
	int row, clm;
	bool won = false;

	char player;

	printf("type X or O to choose player:\n");
	scanf_s("%c", &player);

	for (i = 0; i < 9; i++)
	{
		for (j = 0; j < 9; j++)
		{
			box[i][j] = 1;
		}
	}

	initial1();
	view();

	while (won == false)
	{
		printf("Enter row and column to your turn:\n");
		printf("Enter row:\n");
		scanf_s("%d", &row);
		printf("Enter column:\n");
		scanf_s("%d", &clm);

		if (box[row][clm] == '1')
		{

			box[row][clm] = player;

			won = check(row, clm, player);

			changeto1(row, clm);

			view();

			if (!won)
			{
				player = (player == 'x') ? 'o' : 'x'; // variable =condition true and flase
				printf("chance of player %c\n", player);
			}


		}

	}

	if (won)
	{
		printf("PLAYER: %c WINS", player);
	}

	_getch();
}
