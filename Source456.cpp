#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <stdio.h>

using namespace std;

//Initializing Global Constants
const int MAX_ARRAY_SIZE = 18;
const int MIN_ARRAY_SIZE = 8;
const int MAX_PIECES = 72;
const int NOPLAYER = 0;
const int WHITEWINS = 1;
const int REDWINS = 2;
const int NOONEWINS = 0;
const int WHITESOLDIER = 1;
const int WHITEMULE = 2;
const int WHITEKING = 3;
const int REDSOLDIER = 4;
const int REDMULE = 5;
const int REDKING = 6;
const int WHITEPLAYER = 1;
const int REDPLAYER = 2;

//Prototype funcitons
void InitializeBoard(int CMCheckersBoard[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE],
	int numRowsInBoard);

void DisplayBoard(int CMCheckersBoard[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE],
	int numRowsInBoard);

int CountJumps(int CMCheckersBoard[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE],
	int numRowsInBoard, int player, int xLocArray[], int yLocArray[]);

bool CheckList(int inArray1[], int inArray2[], int xIndex, int yIndex);

int CountMove1Squares(int CMCheckersBoard[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE],
	int numRowsInBoard, int player, int xLocArray[], int yLocArray[]);

bool IsMove1Square(int CMCheckersBoard[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE],
	int numRowsInBoard, int player, int xLoc, int yLoc);

bool IsJump(int CMCheckersBoard[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE],
	int numRowsInBoard, int player, int xLoc, int yLoc);

bool MakeMove(int CMCheckersBoard[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE],
	int numRowsInBoard, int player, int fromSquareNum,
	int toSquareNum, bool &jumped);

bool CheckWin(int CMCheckersBoard[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE], int numRowsInBoard);

const int ODD_EVE = 2;
const int ODD = 1;
const int EVEN = 0;

int main()
{
	//Counters
	int Count1 = 0;
	int Count2 = 0;

	int myCMCheckersBoard[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE] = { 0 };

	int xIndicesMove[MAX_PIECES] = { 0 };
	int xIndicesJump[MAX_PIECES] = { 0 };
	int yIndicesMove[MAX_PIECES] = { 0 };
	int yIndicesJump[MAX_PIECES] = { 0 };
	int yArr[MAX_PIECES] = { 0 };
	int xArr[MAX_PIECES] = { 0 };

	int y = 0;
	int x = 0;
	int numRowsInBoard = 0;
	int squareNumber = -1;
	int squareNumber2 = -1;
	int player = 1;
	int currentSquare = 0;

	bool gameOver = false;
	bool input = true;
	bool jump = true;

	for (int i = 0; i < 3; i++)
	{
		cout << "Enter the number of squares along each edge of board\n";

		if (!(cin >> numRowsInBoard))
		{
			numRowsInBoard = 0;
			cin.clear();
			cin.ignore(1024, '\n');
			cout << "ERROR:  Board size is not an integer\n";
			continue;
		}
		else
		{
			if (numRowsInBoard < MIN_ARRAY_SIZE)
			{
				cerr << "ERROR: Board size too small" << endl;
				continue;
			}
			else if (numRowsInBoard > MAX_ARRAY_SIZE)
			{
				cerr << "ERROR: Board size too large" << endl;
				continue;
			}
			else if ((numRowsInBoard%ODD_EVE) == ODD)
			{
				cerr << "ERROR: Board size odd" << endl;
				continue;
			}
			else { break; }
		}
		cout << MIN_ARRAY_SIZE << " <= number of squares <= " << MAX_ARRAY_SIZE << endl;

		if (i == 3 - 1)
		{
			cerr << "ERROR:  Too many errors entering the size of the board" << endl;

			return 1;
		}
	}

	InitializeBoard(myCMCheckersBoard, numRowsInBoard);
	DisplayBoard(myCMCheckersBoard, numRowsInBoard);
	int maxSquares = numRowsInBoard * numRowsInBoard - 1;

	while (!gameOver)
	{
		if (player == WHITEPLAYER && CountJumps(myCMCheckersBoard, numRowsInBoard, 1, xIndicesJump, yIndicesJump) <= 0 && CountMove1Squares(myCMCheckersBoard, numRowsInBoard, 1, xIndicesMove, yIndicesMove) <= 0)
		{
			
			cout << "White is unable to move." << endl;
			cout << "GAME OVER, Red has won." << endl;
			cout << "Enter any character to close the game." << endl;
			
			return 0;

		}
		else
		{
			cout << "nRed is unable to move." << endl;
			cout << "GAME OVER, White has won." << endl;
			cout << "Enter any character to close the game." << endl;
			
			return 0;
		}

		if (player == WHITEPLAYER) 
		{
			cout << "White takes a turn." << endl;
		}
		else if (player == REDPLAYER)
		{
			cout << "Red takes a turn." << endl;
		}

		for (int turns; turns < 9999; turns++)
		{
			cout << "Enter the square number of the checker you want to move" << endl;
			cin >> currentSquare;

			if (cin.fail())
			{
				squareNumber = -1;
				cin.clear();
				cin.ignore(1024, '\n');
				cerr << "ERROR: You did not enter an integer" << endl;
				cout << "Try again" << endl;
				continue;
			}
			if (currentSquare > maxSquares || currentSquare < 0)
			{
				cerr << "ERROR: That square is not on the board." << endl;
				cout << "Try again" << endl;
				continue;
			}
			yArr = 

		}

	}

	void InitializeBoard(int CMCheckersBoard[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE], int numRowsInBoard)
	{
		for (int i = 0; i < numRowsInBoard / 2; i++)
		{
			CMCheckersBoard[i * 2][0] = WHITEMULE;
			CMCheckersBoard[i * 2 + 1][1] = WHITESOLDIER;
			CMCheckersBoard[i * 2][2] = WHITESOLDIER;

			CMCheckersBoard[i * 2][MAX_ARRAY_SIZE - 1] = WHITEMULE;
			CMCheckersBoard[i * 2 + 1][MAX_ARRAY_SIZE - 2] = WHITESOLDIER;
			CMCheckersBoard[i * 2][MAX_ARRAY_SIZE - 3] = WHITESOLDIER;
		}
	}

	void DisplayBoard(int CMCheckersBoard[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE],
		int numRowsInBoard)
	{
		for (int i = 0; i < numRowsInBoard + 1; i++)
			printf("%02d ", i);
		printf("\n\n");

		for (int i = 0; i < numRowsInBoard; i++)
		{
			printf("%02d ", i);
			for (int j = 0; j < numRowsInBoard; j++)
			{
				printf("%02d ", j);
			}
			printf("\n\n");
		}
	}
	/*
	int CountJumps(int CMCheckersBoard[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE],
		int numRowsInBoard, int player, int xLocArray[], int yLocArray[])
	{

	}

	bool CheckList(int inArray1[], int inArray2[], int xIndex, int yIndex)
	{

	}

	int CountMove1Squares(int CMCheckersBoard[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE],
		int numRowsInBoard, int player, int xLocArray[], int yLocArray[])
	{

	}
	*/
	bool CheckWin(int CMCheckersBoard[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE], int numRowsInBoard)
	{
		int wmulesProm = 0;
		int rmulesProm = 0;
		int rmules = 0;
		int wmules = 0;
		int rpiece = 0;
		int wpiece = 0;


		for (int i = 0; i < numRowsInBoard; i++)
		{
			for (int j = 0; j < numRowsInBoard; i++)
			{
				if (i == 0 && CMCheckersBoard[i][j] == REDMULE)
				{
					rmulesProm++;
				}
				if (i == numRowsInBoard - 1 && CMCheckersBoard[i][j] == WHITEMULE)
				{
					wmulesProm++;
				}
				switch (CMCheckersBoard[i][j])
				{
				case WHITEMULE:
					wmules++;
					break;
				case WHITESOLDIER:
					wpiece++;
					break;
				case WHITEKING:
					wpiece++;
					break;
				case REDMULE:
					rmules++;
					break;
				case REDSOLDIER:
					rpiece++;
					break;
				case REDKING:
					rpiece++;
					break;
				}
			}
		}
		if (rmules == 1 && rmulesProm)
		{
			cout << "The Red Player has won the game by losing all of the Red Mules";
		}
		else if (wmules == 1 && wmulesProm)
		{
			cout << "The White Player has won the game by losing all of the White Mules";
		}
		else if (wmules == 0)
		{
			cout << "The White Player has won the game by losing all of the White Mules";
		}
		else  if (rmules == 0)
		{
			cout << "The Red Player has won the game by losing all of the Red Mules";
		}
		else if (wpiece == 0)
		{
			cout << "The Red Player has won by capturing all of the white players soldiers and kings";
		}
		else if (rpiece == 0)
		{
			cout << "The White Player has won by capturing all of the red players soldiers and kings";
		}
		else if (rmulesProm == 1)
		{
			cout << "Red has created a Mule King,  White wins the game";
		}
		else if (wmulesProm == 1)
		{
			cout << "White has created a Mule King,  Red wins the game";
		}
		cout << endl;
	}

	return 0;
}
