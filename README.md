# N-Queens
This was an assignment for my CS317 class. We were to print out a solution to an N-Queens problem after typing in the NxN size. THe total number of solutions are then printed.

Completed: 11-21-21

## Assignment

This problem is to find an arrangement of N queens on a chessboard, such that no queen can attack any other queens on the board.

The chess queens can attack in a horizontal, vertical, horizontal, and diagonal way.

A binary matrix is used to display the positions of N Queens, where no queens can attack other queens.

Your program should include comments.

### Input and Output:

In the output, the value 1 indicates the correct place for the queens. The 0 denotes the blank spaces on the chessboard.

Do not use char 'Q' in the output. Use 0's and 1's. If Q's are used, you will not be given points. 

Users should be given an option to enter the number for N (1 to 9): 

If the solution does not exist, it will print a message "Solution does not exist".

If more than one solution exists, then print one possible solution and give the number of possible solutions as a statement.

<br>

For example:

> Let us assume the user enter N = 4:

> The size of a chessboard is 4 and can be interpreted as 4 x 4 size chessboard.

> The possible outcomes are 2 combinations.

> Print just one possible combination of a solution, and in a statement, say the number of all combinations possible(if exists).
<br>

Sample Output:
```
Test 1:

N = 2

The solution does not exist for N = 2
```
 

Test 2: (Do not print more than one combination)
```
N = 4

0 1 0 0 

0 0 0 1

1 0 0 0

0 0 1 0

The solution for N = 4 can produce two different solutions.
```
