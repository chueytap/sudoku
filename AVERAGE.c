//AVERAGE
#include<stdio.h>
#include <stdlib.h>
#include <ctype.h>
void average ()
{
	
void printSudoku(int *sudoku);
void solveSudoku(int *sudoku, int taken[], int toSolve[], int takenN, int toSolveN);
void assignSudoku(int sudoku[3][3], int takenN, int toSolveN);

	// store user input
    int input = 1;
    char response = 'y';

while (response == 'y')
                {
                   // will run as long as user agrees to run
                while (response == 'y')
                {
                    
					int sudoku[3][3] = {0};

                    // use assign sudoku function, which also calls solveSudoku function
                    assignSudoku(sudoku, 5, 4);

                    printf("\nWould you like to try the average level again? (y/n)\n");
                    scanf(" %c", &response);
                }
                }
                

}
