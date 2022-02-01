#include <iostream>
/*
CS317 Programming Assignment 2 - N-Queens Algorithm
Author - Brandon
Date - November 17th, 2021
Fall 2021
*/

// declare functions
void print(int** array, int input); //print array
void printTotal (int input, int& count); // printnumber of solutions
bool safe(int** array, int testRow, int testColumn, int input); // check if spot is safe in array
void initialize(int** array, int input); //initialize a dynamically allocated array
void solve(int** array, int row, int input, int& count); // fill in array with backtracking

using namespace std;

// temp variable to keep track of number of solutions
int tmp = 0;

// start program
int main(void)
{
    // initialize user input for size of chess board
    int input = 0;
    
    // create pointer of the address of the counter for # of solutions so that function can alter it
    int* count = &tmp;
    
    // prompt user for input and get input
    cout << "Enter a number 1 - 9" << endl;
    cin >> input;
    
    // check if user input is within the specified range
    while (input < 1 || input > 9)
    {
        // get new user input if invalid
        cout << "Number too large or small. Please enter a number from 1 - 9" << endl;
        cin >> input;
    }
    
    // create a dynamically allocated array of size input
    int** array = new int* [input];
    
    // initialize the two dimensional array
    initialize(array, input);
    
    // solve calling on the n-queens backtracking algorithm
    solve(array, 0, input, *count);
    
    // display how many solutions that are possible
    printTotal(input, *count);
    
    // end program
    return 0;
}



    // define functions
    // print out an array
void print(int** array, int input)
{
    // increment through rows
    for (int row = 0; row < input; row++)
    {
        // increment through columns
        for (int column = 0; column < input; column++)
        {
            // print array element
            cout << array[row][column] << " ";
        }
        // skip to next line at end of each row
            cout << endl;
    }
    // skip line at end of array
    cout << endl;
}


// print out the number of solutions for the specific NxN board
void printTotal(int input, int& count)
{
    // if there are no solutions
    if (count == 0)
    {
        cout << "Solution does not exist." << endl;
    }
    // if there are solutions tell the total number
    else {
        cout << "The number of solutions for a " << input << "x" << input << "board: " << count << endl;
    }
}


// initialize a dynamically allocated array
void initialize(int** array, int input)
{
    // increment through rows
    for (int row = 0; row < input; row++)
    {
        array[row] = new int[input];
        
        // increment through columns
        for (int column = 0; column < input; column++)
        {
            // set element to 0
            array[row][column] = 0;
        }
    }
}


// check if a spot is safe from a queen
bool safe(int** array, int testRow, int testColumn, int input)
{
    // initialize column
    int column = testColumn;
    
    // increment through rows
    for (int row = 0; row < testRow; row++)
    {
        // if there is a queen in the row / column
        if (array[row][column] == 1)
        {
            // declare not safe
            return false;
        }
    }
    // reinitialize row
    int row = testRow;
    
    // while the rows and columns are not zero
    while (row >= 0 && column >= 0)
    {
        // if the element has a queen in its / diagonal
        if (array[row][column] == 1)
        {
            // declare not safe
            return false;
        }
        // decrement row and column
        row--;
        column--;
    }
    
    // reinitialize row and column
    row = testRow;
    column = testColumn;
    
    // while the rows are not zero and the columns are less than the user input size
    while (row >= 0 && column < input)
    {
        // if the element has a queen in the other \ diagonal
        if (array[row][column] == 1)
        {
            // declare not safe
            return false;
        }
        // decrement row
            row--;
            // increment columns
            column++;
    }
    // otherwise return as safe
    return true;
}


// fills out the solution array through backtracking
void solve(int** array, int row, int input, int& count)
{
    // if there are the correct number of queens (same size as board) i.e. on the last row
    if (row == input)
    {
        // increment solution counter
        count++;
        // if its the first solution
        if (count == 1) {
            // print out only one solutions
            print(array, input);
        }
        // exit function
        return;
    }
    
    // increment through current row
       for (int column = 0; column < input; column++)
    {
        // if the spot is safe
        if (safe(array, row, column, input))
        {
            // place queen
            array[row][column] = 1;
            
            // move on to next row with recurrence to allow for backtracking
            solve(array, row + 1, input, count);
            
            // if no solution in next row, remove queen from previous spot and move to next
            array[row][column] = 0;
        }
    }
}
