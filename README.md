# EECS348 - Software Engineering

## Lab5

### Program1

Simply generates a sales report based on an input file  
The input file must be passed in in the terminal  
The input file must have 12 lines of numbers in order to function correctly, nothing else  
The program assumes these numbers are formatted corectly from Jan-Dec  
```bash
./SalesReport data.txt    
```

### Program2

Generates all the possible scoring plays given a score  
The program will continue to prompt until a value of 0 or 1 is passed in  
Very large values over 300 and negative values will not be accepted   

## Lab6    

Takes in two matrices from an input file and does a bunch of things with them as specified in the program requirements.   

> Problem Description
> You are tasked with implementing a C++ program that performs various operations on square matrices using functions and arrays (no classes or objects yet). Your program should read matrix data from a file, perform matrix operations, and output the results. You need to read the matrix size from the first line of data. For this assignment, you will write the following functions:
> 1. Read values from a file into a matrix:
> Create a function to read matrix data from a specified file and store it in a 2D array.
> 2. Print a matrix:
> Implement a function to display a matrix in a user-friendly format. The matrix values should nicely align in a column.
> 3. Add two matrices and place the result in a third matrix; print the result:
> Create a function that adds two matrices of the same size and stores the result in a third matrix. Display the resulting matrix.
> 4. Multiply two matrices and place the result in a third matrix; print the result:
> Implement a function for matrix multiplication (matrix1 * matrix2 = result_matrix). Display the resulting matrix.
> 5. Subtract the second matrix from the first matrix and place the result in a third matrix; print the result:
> Develop a function to subtract one matrix from another and store the result in a third matrix. Display the resulting matrix.
> 6. Update an element of the first matrix; print the result:
> Develop a function to accept the row, column, and a new value. Update the first matrix with the given data. You must check the validity of the row and column. Display the resulting matrix.
> 7. Get the max value of the first matrix:
> Develop a function to find and print the max value of the first matrix.
> 8. Transpose the first matrix; print the result:
> Develop a function to transpose and print the first matrix.
> Constraints
> The matrices are square matrices (NxN), where N is a static constant. The input matrices are read from a file named "matrix_input.txt." The output matrices are displayed on the console.
> Please align your output.
> Sample Input (matrix_input.txt):   
>
> 3   
> 1 2 3   
> 4 5 6   
> 7 8 9   
> 2 3 4   
> 5 6 7   
> 8 9 10   

Requires a file to be passed in at runtime:
```bash
./Lab6 matrix_input.txt
```
