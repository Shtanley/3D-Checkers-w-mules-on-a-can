// Assignment 2 CMPT 128 
// By Daniel. K, Sameer. H, and Eugene. P
// Checkers, Assignment 2 CMPT 128

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>

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

	int myCMCheckersBoard[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE] = { '/0' };

	int xIndicesMove[MAX_PIECES] = { '/0' };
	int xIndicesJup[MAX_PIECES] = { '/0' };
	int yIndicesMove[MAX_PIECES] = { '/0' };
	int yIndicesJump[MAX_PIECES] = { '/0' };

	int numRowsInBoard = 0;
	int squareNumber = -1;
	int squareNumber2 = -1;

	bool gameOver = false;

	for (int i = 0; i < 3; i++)
	{
		cout << "Enter the number of squares along each edge of board\n";

		if (!(cin >> numRowsInBoard))
		{
			numRowsInBoard = 0;
			cin.clear();
			cin.ignore(1000, '\n');
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
			else
			{
				break;
			}
		}

		cout << MIN_ARRAY_SIZE << " <= number of squares <= " << MAX_ARRAY_SIZE << endl;

		if (i == 3 - 1)
		{
			cerr << "ERROR:  Too many errors entering the size of the board";

			return 1;
		}
	}

	InitializeBoard(myCMCheckersBoard, numRowsInBoard);
	DisplayBoard(myCMCheckersBoard, numRowsInBoard);

	while (!gameOver)
	{
		//White Turn
		{
			cout << "White takes a turn." << endl;

			CountJumps(myCMCheckersBoard, numRowsInBoard, player, xLocArray[], yLocArray[]);
			CountMove1Squares(myCMCheckersBoard, numRowsInBoard, player, xLocArray[], yLocArray[]);

			while ()
			{
				cout << "Enter the square number of the checker you want to move" << endl;

				if (!cin >> )
				{
					cerr << "ERROR: You did not enter an integer" << endl << "Try again" << endl;
					continue;
				}
				if ()
				{
					cerr << "ERROR: That square is not on the board" << endl;
					continue;
				}
				if ()
				{
					cerr << "ERROR: That square contains an opponent's checker." << endl << "Try again" << endl;
					continue;
				}
				if ()
				{
					cerr << "ERROR: That square is empty." << endl << "Try again" << endl;
					continue;
				}
				if ()
				{
					cerr << "ERROR: You can jump with another checker, you may not move your chosen checker." << endl;
					cerr << "You can jump using checkers on the following squares: " << << endl;
					cerr << "Try again" << endl;
					continue;
				}
				if ()
				{
					cerr << "ERROR: There is no legal move for this checker." << endl << "Try again" << endl;
					continue;
				}
			}

			while ()
			{
				cout << "Enter the square number of the square you want to move your checker to" << endl;

				if (!cin >> )
				{
					cerr << "ERROR: You did not enter an integer" << endl << "Try again" << endl;
					continue;
				}
				if ()
				{
					cerr << "ERROR: You did not enter an integer." << endl << "Try again" << endl;
					continue;
				}
				if ()
				{
					cerr << "ERROR: It is not possible to move to a square that is not on the board." << endl;
					cerr << "Try again" << endl;
					continue;
				}
				if ()
				{
					cerr << "ERROR: It is not possible to move to a square that is already occupied." << endl;
					cerr << "Try again" << endl;
					continue;
				}
				if ()
				{
					cerr << "ERROR: You can jump with this checker, you must jump not move 1 space." << endl;
					cerr << "Try again" << endl;
				}
			}

			MakeMove(CMCheckersBoard, numRowsInBoard, player, fromSquareNum, toSquareNum, &jumped);

			DisplayBoard(CMCheckersBoard, numRowsInBoard);
			if (MakeMove() == false)
			{
				cerr << "ERROR: Moving to that square is not legal, Try again." << endl;
				//continue? back to e)
			}
			else
			{
				if ()//Another jump true?
				{
					//Make another jump, possible
				}
			}

			IsJump(CMCheckersBoard, numRowsInBoard, )

				if (IsJump() == true)
				{

				}
		}

		//Red Turn
		{
			cout << "Red takes a turn." << endl;
			CountJumps(CMCheckersBoard, numRowsInBoard, player, xLocArray[], yLocArray[]);
			CountMove1Squares(CMCheckersBoard, numRowsInBoard, player, xLocArray[], yLocArray[]);
		}
	}



	if ()
	{
		cout << "White is unable to move.\nGAME OVER, Red has won.\nEnter any character to close the game.\n";
	}


	cout << "Red is unable to move.\nGAME OVER, White has won.\nEnter any character to close the game.\n";


	return 0;
}

}


//Functions
void DisplayBoard(int CMCheckersBoard[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE], int numRowsInBoard)
{
	for (int i = 0; i < numRowsInBoard + 1; i++)
	{
		printf("%02d ", i);
	}
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

int CountJumps(int CMCheckersBoard[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE], int numRowsInBoard, int player, int xLocArray[MAX_PIECES], int yLocArray[MAX_PIECES])
{
	int y = 0;
	int x = 0;
	int possibleJumps = 0;
	int JumpCounter = 0;

	for (int z = 0; z < MAX_PIECES; z++)
	{
		yLocArray[z] = -1;
		xLocArray[z] = -1;
	}
	for (y = 0; y < numRowsInBoard; y++)
	{
		for (x = 0; x < numRowsInBoard; x++)
		{
			if (IsJump())
			{
				JumpCounter++;
				xLocArray[JumpCounter] = y;
				yLocArray[JumpCounter] = x;
			}
		}
	}
	return possibleJumps;
}

bool CheckList(int inArray1[], int inArray2[], int xIndex, int yIndex)
{

}

int CountMove1Squares(int CMCheckersBoard[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE], int numRowsInBoard, int player, int xLocArray[MAX_PIECES], int yLocArray[MAX_PIECES])
{
	int y = 0;
	int x = 0;
	int possibleJumps = 0;
	int JumpCounter = 0;
	for (int z = 0; z < MAX_PIECES; z++)
	{
		yLocArray[z] = -1;
		yLocArray[z] = -1;
	}
	for (y = 0; y < numRowsInBoard; y++)
	{
		for (x = 0; x < numRowsInBoard; x++)
		{
			if (IsMove1Square())
			{
				JumpCounter++;
				xLocArray[JumpCounter] = y;
				yLocArray[JumpCounter] = x;
			}
		}
	}
	return possibleJumps;
}

bool IsMove1Square(int CMCheckersBoard[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE], int numRowsInBoard, int player, int xLoc, int yLoc)
{

}

bool IsJump(int CMCheckersBoard[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE], int numRowsInBoard, int player, int xLoc, int yLoc)
{

}

bool MakeMove(int CMCheckersBoard[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE], int numRowsInBoard, int player, int fromSquareNum, int toSquareNum, bool &jumped)
{

}

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
}


We have the following functions :
InitializeBoard
DisplayBoard
CheckWin
CountJumps
CountMove1Squares

We need :

CheckList
IsMove1Square
IsJump
MakeMove