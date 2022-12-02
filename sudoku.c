/**
 * Simple Sudoku Program Solver
 * 
 * 04-21-2021
 **/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <C:\Users\Patricia Ysabel\Documents\EASY.c>
#include<C:\Users\Patricia Ysabel\Documents\AVERAGE.c>
#include<C:\Users\Patricia Ysabel\Documents\DIFFICULT.c>
void printSudoku(int *sudoku);
void solveSudoku(int *sudoku, int taken[], int toSolve[], int takenN, int toSolveN);
void assignSudoku(int sudoku[3][3], int takenN, int toSolveN);

int main()
{
    // store user input
    int input = 1;
    char response = 'y';

    // menu
    while (input != 4)
    {
        char response2 = 'y';

        // clear screen
        system("cls");

        printf("Sudoku!\n\n");
        printf("Input a number corresponding to Sudoku Problem:\n");
        printf("1. Easy      (3 values missing)\n");
        printf("2. Average   (4 values missing)\n");
        printf("3. Difficult (5 values missing)\n");
        printf("4. Exit\n\n");

        scanf("%d", &input);

        // small programs
        switch (input)
        {
            case 1:
                easy();
                break;

            case 2:
                
                average();
                break;

            case 3:

                difficult();
                break;

            case 4:

                printf("Are you sure you want to exit? (y/n)\n");
                scanf(" %c", &response);

                // that is why re-initialization is done, both input and response to ensure a working program
                if (!(response == 'y'))
                {
                    response = 'y';
                    input = 1;
                }

                break;
        }
    }
}
// print sudoku function
void printSudoku(int *sudoku)
{
 
	// print sudoku puzzle
    // a solution to keep this short and simple as well is to put this
    // algorithm in a function
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
            printf("%d ", *((sudoku + i * 3) + j));
        
        printf("\n");
    }
}

// solve sudoku function
void solveSudoku(int *sudoku, int taken[], int toSolve[], int takenN, int toSolveN)
{
    // value to be used to access solution array
    int x = 0;

    // this algorithm is then used to find solutions for array, that is, numbers from 1 to 9
    // that are not yet used.

    // notice the extra condition in the for loop: (x < toSolveN) to ensure that the array does not go out of bounds (hehe)
    for (int i = 1; i < 10 && x < toSolveN; i++)
    {
        // semi-boolean variable (ugh)
        int solved;

        // this algorithm checks if the taken array values are equal to i
        // if it is, then this small loop terminates and proceeds to next incremented value of i
        for (int j = 0; j < takenN; j++)
        {
            if (i == taken[j])
            {
                solved = 0;
                break;
            }
            
            solved = 1;
        }

        // this ensures that if a solution is found, it is recorded in the toSolve array
        if (solved == 1)
            toSolve[x++] = i;
    }

    // this piece of code then supplies all puzzle pieces that are empty, or equal to 0 in this case,
    // by the found solutions in the previous loop
    x = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            // solution is put on the empty puzzle piece and then x is incremented to next solution
            if (*((sudoku + i * 3) + j) == 0)
                *((sudoku + i * 3) + j) = toSolve[x++];
        }
    }

    printSudoku(sudoku);
}

// assign Sudoku values function
void assignSudoku(int sudoku[3][3], int takenN, int toSolveN)
{
    // clear screen (for Windows)
    system("cls");

    // initialize taken array, which is the already taken numbers in the Sudoku puzzle, to 0
    int taken[takenN];
    for (int i = 0; i < takenN; i++)
        taken[i] = 0;

    // initialize toSolve array, which are the missing numbers in the taken array, to 0.
    int toSolve[toSolveN];
    for (int i = 0; i < toSolveN; i++)
        toSolve[i] = 0;

    // to count already taken values in the loop
    int count = 0;

    // to scan user input
    int index;

    // while the already recorded values are less than 6 (for easy)
    while (count < takenN)
    {
        // initialize row and column variables to place data input
        int row = 0;
        int column = 0;

        printSudoku((int *) sudoku);

        // a do while loop ensures that the loop will do a certain command ONCE before checking.
        // therefore getting the user input before it is checked
        do
        {
            printf("%d - Input index: ", count + 1);
            scanf(" %d", &index);

            // if index inputted is out of bounds
            if (index < 1 || index > 9)
                continue;
            
            // decrement index by one since we count from 0
            index--;

            // algorithm to assign row and column variables

            // if the index is less than 3, then we know that the row is already 0 and that the column
            // should be whatever the user input is

            // let's say the value inputted is 2, then we know that the user wants to input something on
            // row 1 and column 2 of the puzzle, therefore the index is decremented and the result
            // is assigned to column
            if (index < 3)
            {
                row = 0;
                column = index;
            }

            // if it is greater than or equal to 3, let's say, 5; then we know that the user want to input
            // something on row 2 and column 2 of the puzzle, therefore we decrement the index first, which is then 4
            // and row is added by 1. then the index is now decremented by 3, since it lost a row, and then assigned to 
            // the column variable

            // try checking the number 9!
            else
            {
                while (index >= 3)
                {
                    row++;
                    index -= 3;
                    column = index;
                }
            }
        }
        while (sudoku[row][column] != 0);

        // semi-boolean variable (ugh)
        int found = 0;

        // this algorithm is now used to check for data to input, ensuring that the user does not enter values
        // less than 1, or values greater than 9, or already taken values

        // so meaning, if the puzzle already contains the number 9 for instance, then the while loop will take
        // the user back to getting appropriate data.
        do
        {
            // re-initialize semi-boolean variable (ugh) to 0 or false each time
            found = 0;

            // ensures data inputted is not less than 1 or greater than 9
            do
            {
                printf("%d - Input data:  ", count + 1);
                scanf(" %d", &sudoku[row][column]);
            }
            while (sudoku[row][column] < 1 || sudoku[row][column] > 9);

            // checks the taken array if the data being inputted is already used
            for (int i = 0; i < takenN; i++)
            {
                if (taken[i] == sudoku[row][column])
                {
                    found = 1;
                    break;
                }
            }
        }
        while (found == 1);

        system("cls");

        // then if all checks are a success, the taken array is updated with the value used
        taken[count] = sudoku[row][column];

        // count is incremented
        count++;
    }

    // call solve function
    solveSudoku((int *) sudoku, taken, toSolve, takenN, toSolveN);
}

