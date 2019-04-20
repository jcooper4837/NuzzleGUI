#include "Board.h"
#include <time.h>      
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <chrono>
using namespace std;
using namespace std::chrono;


Board::Board() {
     mTimer = Timer::Instance();
	 mInput = InputManager::Instance();

     listX = new float[9];
     listX[0] = 340.0f;
     listX[1] = 500.0f;
     listX[2] = 660.0f;
	 listX[3] = 340.0f;
	 listX[4] = 500.0f;
	 listX[5] = 660.0f;
	 listX[6] = 340.0f;
	 listX[7] = 500.0f;
	 listX[8] = 660.0f;

     listY = new float[9];
     listY[0] = 220.0f;
     listY[3] = 420.0f;
     listY[6] = 600.0f;
	 listY[1] = 220.0f;
	 listY[4] = 420.0f;
	 listY[7] = 600.0f;
	 listY[2] = 220.0f;
	 listY[5] = 420.0f;
	 listY[8] = 600.0f;

	 matrix = new int[9];
	 moves = 0;
	 
	 for (int i = 0; i < 9; i++)
	 {
		 /*if (i < 8)
		 {
			 matrix[i] = i + 1;
		 }
		 else
		 {
			 matrix[i] = 0;
		 }*/
		 matrix[i] = 0;
	 }

     mOne = new Texture("1.png");
     mOne->Parent(this);
     mOne->Pos(Vector2(listX[0], listY[0]));
     mOne->setter(1);
     mOne->Scale(Vector2(0.2f, 0.2f));

     mTwo = new Texture("2.png");
     mTwo->Parent(this);
     mTwo->setter(2);
     mTwo->Pos(Vector2(listX[1], listY[1]));
     mTwo->Scale(Vector2(0.2f, 0.2f));

     mThree = new Texture("3.png");
     mThree->Parent(this);
     mThree->setter(3);
     mThree->Pos(Vector2(listX[2], listY[2]));
     mThree->Scale(Vector2(0.1f, 0.1f));

     mFour = new Texture("4.png");
     mFour->Parent(this);
     mFour->setter(4);
     mFour->Pos(Vector2(listX[3], listY[3]));
     mFour->Scale(Vector2(0.1f, 0.1f));

     mFive = new Texture("5.png");
     mFive->Parent(this);
     mFive->setter(5);
     mFive->Pos(Vector2(listX[4], listY[4]));
     mFive->Scale(Vector2(0.1f, 0.1f));

     mSix = new Texture("6.png");
     mSix->Parent(this);
     mSix->setter(6);
     mSix->Pos(Vector2(listX[5], listY[5]));
     mSix->Scale(Vector2(0.1f, 0.1f));

     mSeven = new Texture("7.png");
     mSeven->Parent(this);
     mSeven->setter(7);
     mSeven->Pos(Vector2(listX[6], listY[6]));
     mSeven->Scale(Vector2(0.1f, 0.1f));

     mEight = new Texture("8.png");
     mEight->Parent(this);
     mEight->setter(8);
     mEight->Pos(Vector2(listX[7], listY[7]));
     mEight->Scale(Vector2(0.1f, 0.1f));

     mEmpty = new Texture("9.png");
     mEmpty->Parent(this);
     mEmpty->setter(9);
     mEmpty->Pos(Vector2(listX[8], listY[8]));
     mEmpty->Scale(Vector2(0.0f, 0.0f));

}

Board::~Board() {
     mTimer = NULL;
	 mInput = NULL;

     delete mOne;
     mOne = NULL;

     delete mTwo;
     mTwo = NULL;

     delete mThree;
     mThree = NULL;

     delete mFour;
     mFour = NULL;

     delete mFive;
     mFive = NULL;

     delete mSix;
     mSix = NULL;

     delete mSeven;
     mSeven = NULL;

     delete mEight;
     mEight = NULL;

     delete mEmpty;
     mEmpty = NULL;

}
void Board::Shuffle() {
     do
     {
          vector<int> list;
          int value;
          srand((unsigned)time(0));

          for (int i = 0; i < (9); i++)
          {
               do
               {
                    value = rand() % ((9));
               } while (containsValue(list, value)); // fill unique numbers only, no duplicates

               matrix[i] = value;
               list.push_back(value);
          }
     } while (!isSolvable()); // if given matrix is an unsolvable solution, loop back and try again

	 for (int i = 0; i < 9; i++)
	 {
		 cout << matrix[i] << endl;
	 }

	 output();
}

bool Board::isSolvable() // checks if the given matrix table is solvable using some linear algebra
{
     int *list = new int[9];
     int count = 0;

     for (int i = 0; i < (9); i++)
     {
          list[count] = matrix[i];
          count++;
     }

     int parity = 0;
     int gridWidth = 9;
     int row = 0;
     int blankRow = 0;

     for (int i = 0; i < (9); i++)
     {
          if (i % gridWidth == 0)
          {
               row++;
          }
          if (list[i] == 0)
          {
               blankRow = row;
               continue;
          }
          for (int j = i + 1; j < (9); j++)
          {
               if (list[i] > list[j] && list[j] != 0)
               {
                    parity++;
               }
          }
     }

     if (gridWidth % 2 == 0)
     {
          if (blankRow % 2 == 0)
          {
               return parity % 2 == 0;
          }
          else
          {
               return parity % 2 != 0;
          }
     }
     else
     {
          return parity % 2 == 0;
     }
}


bool Board::containsValue(vector<int> list, int value) // checks if the value is already used to prevent duplicates
{
     int count = 0;

     if (list.size() != 0)
     {
          for (size_t i = 0; i < list.size(); i++)
          {
               if (list.at(i) == value)
               {
                    return true;
               }
          }
     }

     return false;
}

void Board::output()
{

	for (int i = 0; i < 9; i++)
	{
		switch (matrix[i])
		{
			case 1:
			{
				mOne->Pos(Vector2(listX[i], listY[i]));
				break;
			}
			case 2:
			{
				mTwo->Pos(Vector2(listX[i], listY[i]));
				break;
			}
			case 3:
			{
				mThree->Pos(Vector2(listX[i], listY[i]));
				break;
			}
			case 4:
			{
				mFour->Pos(Vector2(listX[i], listY[i]));
				break;
			}
			case 5:
			{
				mFive->Pos(Vector2(listX[i], listY[i]));
				break;
			}
			case 6:
			{
				mSix->Pos(Vector2(listX[i], listY[i]));
				break;
			}
			case 7:
			{
				mSeven->Pos(Vector2(listX[i], listY[i]));
				break;
			}
			case 8:
			{
				mEight->Pos(Vector2(listX[i], listY[i]));
				break;
			}
			case 0:
			{
				mEmpty->Pos(Vector2(listX[i], listY[i]));
				break;
			}
		}
	}
}

void Board::shift(char m) // take in user input and shift the proper number into the blank spot
{
	int temp;

	if (m == 'w') // move number up into blank spot
	{
		for (int i = 0; i < 6; i++)
		{
			if (matrix[i] == 0)
			{
				temp = matrix[i + 3];
				matrix[i + 3] = matrix[i];
				matrix[i] = temp;
				return;
			}
		}
	}
	if (m == 's') // move number down into blank spot
	{
		for (int i = 3; i < 9; i++)
		{
			if (matrix[i] == 0)
			{
				temp = matrix[i - 3];
				matrix[i - 3] = matrix[i];
				matrix[i] = temp;
				return;
			}
		}
	}
	if (m == 'a') // move number left into blank spot
	{
		for (int i = 0; i < 9; i++)
		{
			if (matrix[i] == 0 && (i + 1) % 3 != 0)
			{
				temp = matrix[i + 1];
				matrix[i + 1] = matrix[i];
				matrix[i] = temp;
				return;
			}
		}
	}
	if (m == 'd') // move number right into blank spot
	{
		for (int i = 0; i < 9; i++)
		{
			if (matrix[i] == 0 && i % 3 != 0)
			{
				temp = matrix[i - 1];
				matrix[i - 1] = matrix[i];
				matrix[i] = temp;
				return;
			}
		}
	}
}

bool Board::isValid() {

     for (int i = 0; i < 9; i++)
     {
          if (i == (9 - 1))
          {
               return true;
          }
          else if (i + 1 != matrix[i])
          {
               return false;
          }

     }

     return true;
}

bool Board::newGame()
{
	for (int i = 0; i < 9; i++)
	{
		if (matrix[i] != 0)
		{
			return false;
		}
	}

	return true;
}

int Board::getMoves()
{
	return moves;
}

void Board::Update() {
	if (mInput->KeyPressed(SDL_SCANCODE_DOWN) && !isValid())
	{
		shift('s');
		output();
		moves++;
	}
		
	else if (mInput->KeyPressed(SDL_SCANCODE_UP) && !isValid())
	{
		shift('w');
		output();
		moves++;
	}

	else if (mInput->KeyPressed(SDL_SCANCODE_LEFT) && !isValid())
	{
		shift('a');
		output();
		moves++;
	}

	else if (mInput->KeyPressed(SDL_SCANCODE_RIGHT) && !isValid())
	{
		shift('d');
		output();
		moves++;
	}
}

void Board::Render() {
     mOne->Render();
     mTwo->Render();
     mThree->Render();
     mFour->Render();
     mFive->Render();
     mSix->Render();
     mSeven->Render();
     mEight->Render();
     mEmpty->Render();
}