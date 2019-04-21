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
		 //cout << matrix[i] << endl;
	 }

	 output();
}

bool Board::isSolvable() // checks if the given matrix table is solvable using some linear algebra
{
	int list[9];
	int inversions = 0;
	int gridWidth = 9;
	int row = 0;
	int blankRow = 0;
	int result;

	for (int i = 0; i < (9); i++)
	{
		list[i] = matrix[i];
		//cout << list[i] << endl;
	}

	__asm
	{
		mov esi, 0							;initialize i to 0 (in this code segment, i = esi, and j = ecx)
		/* This code segment is meant to initialize list with values from matrix. It's currently non functional, so it's been omitted.
		for1:
			cmp esi, 9*4
			jl next1
			jmp endfor1

			next1:
				mov eax, matrix[esi]
				mov list[esi], eax
				add esi, 4
				jmp for1

		endfor1:
			mov esi, 0
		*/
		for2:
			cmp esi, 9*4					;loop condition
			jl next2						;if i < 36, jump to next2
			jmp endfor2						;else, jump to endfor2

			next2:
				mov eax, esi				;move i into eax
				xor edx, edx				;clear edx
				idiv gridWidth				;divide i by gridWidth

			if1:
				cmp edx, 0					;check remainder
				je then1					;if i % gridWidth == 0, jump to then1
				jmp endif1					;else, jump to endif1

				then1:
					inc row					;increment row

			endif1:

			if_2:							;find which row contains the blank element
				cmp list[esi], 0			;compare list[i] and 0
				je then2					;if list[i] == 0, jump to then2
				jmp endif2					;else, jump to endif2

				then2:
					mov eax, row			;move row into eax
					mov blankRow, eax		;move eax into blankRow

			endif2:
				mov ecx, esi				;move i into j
				add ecx, 4					;increment j by 4

			for3:
				cmp ecx, 9*4				;loop condition
				jl if3						;if j < 36, jump to if3
				jmp endfor3					;else, jump to endfor3

				if3:						;find the total number of inversions in list
					mov eax, list[ecx]		;move list[j] into eax
					cmp list[esi], eax		;compare list[i] to list[j]
					jle endif3				;if list[i] <= list[j], jump to endif3

				elseif3:
					cmp list[ecx], 0		;compare list[j] to 0
					jne then3				;if list[j] != 0, jump to then3
					jmp endif3				;else, jump to endif3

					then3:
						inc inversions		;increment inversions

				endif3:
					add ecx, 4				;increment j by 4
					jmp for3				;jump to for3

			endfor3:
				add esi, 4					;increment i by 4
				jmp for2					;jump to for2

		endfor2:
			mov eax, gridWidth				;move gridWidth into eax
			xor edx, edx					;clear edx
			mov ebx, 2						;move 2 into ebx
			idiv ebx						;divide gridWidth by 2

		if4:								;check if number of rows is even (with the 3x3 game board, this will never be true, but this is left in for future purposes)
			cmp edx, 0						;check for remainder
			je then4						;if gridWidth % 2 == 0, jump to then4
			jmp else4						;else, jump to else4

			then4:
				mov eax, blankRow			;move blankRow into eax
				xor edx, edx				;clear edx
				mov ebx, 2					;move 2 into ebx
				idiv ebx					;divide blankRow by 2

			if5:
				cmp edx, 0					;check for remainder
				je then5					;if blankRow % 2 == 0, jump to then5
				jmp else5					;else, jump to else5

				then5:
					mov eax, inversions		;move inversions into eax
					xor edx, edx			;clear edx
					mov ebx, 2				;move 2 into ebx
					idiv ebx				;divide inversions by 2
								
				if6:
					cmp edx, 0				;check for remainder
					je then6				;if inversions % 2 == 0, jump to then6
					jmp else6				;else, jump to else6
							
					then6:
						mov result, 0		;move 0 (true) into result
						jmp endif6			;jump to endif6

					else6:
						mov result, 1		;move 1 (false) into result

				endif6:
					jmp endif4				;jump to endif4

			else5:
				mov eax, inversions			;move inversions into eax
				xor edx, edx				;clear edx
				mov ebx, 2					;move 2 into ebx
				idiv ebx					;divide inversions by 2

				if7:
					cmp edx, 0				;check for remainder
					jne then7				;if inversions % 2 != 0, jump to then7
					jmp else7				;else, jump to else7

					then7:
						mov result, 0		;move 0 (true) into result
						jmp endif7			;jump to endif7

					else7:
						mov result, 1		;move 1 (false) into result

				endif7:
					jmp endif4				;jump to endif4

		else4:								;check if number of rows is odd (with a 3x3 board, should always be the case)
			mov eax, inversions				;move inversions into eax
			xor edx, edx					;clear edx
			mov ebx, 2						;move 2 into ebx
			idiv ebx						;divide inversions by 2

			if8:
				cmp edx, 0					;check for remainder
				je then8					;if inversions % 2 == 0, jump to then8
				jmp else8					;else, jump to else8

				then8:
					mov result, 0			;move 0 (true) into result
					jmp endif8				;jump to endif8

				else8:
					mov result, 1			;move 1 (false) into result

			endif8:

		endif4:
	};
	//cout << inversions << endl;
	return result % 2 == 0;
	/* This code segment is the C++ variation of the above assembly code.
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
     }*/
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