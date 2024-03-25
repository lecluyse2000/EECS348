//Author: Caden LeCluyse
//Filename: main.cpp
//Date: 3/21/24
//Class: EECS348
//Purpose: Get two matrices from a file and do a bunch of things with them 

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <limits>
#include <iomanip>

//Extremely verbose so i decided to make a typedef
typedef const int* const* const& const_2d_array_ref;


int** create_matrix(const std::size_t size)
{
   int** matrix = new int*[size];
   for(std::size_t i = 0; i < size; ++i) {
      matrix[i] = new int[size];
   }
   for(std::size_t i = 0; i < size; ++i) {
      for(std::size_t j = 0; j < size; ++j) {
         matrix[i][j] = 0;
      }
   }
   return matrix;
}

void parse_input(int**& matrix, int**& matrix_two, std::ifstream& file, std::size_t& size)
{
   if(file.is_open()){
      file >> size; 
      matrix = create_matrix(size);
      matrix_two = create_matrix(size);
      for(std::size_t i = 0; i < size * 2; ++i) {
         for(std::size_t j = 0; j < size; ++j) {
            if(i < size) {
               file >> matrix[i][j];
            } else {
               file >> matrix_two[i - size][j];
            }
         }
      }
   } else {
      std::cerr << "The given file could not be opened!\n";
      std::exit(EXIT_FAILURE);
   }
}

//Took me forever to figure out why "const int**&" wasnt compiling
void print_matrix(const_2d_array_ref matrix, const std::size_t size)
{
   std::cout << '\n';
   for(std::size_t i = 0; i < size; ++i) {
      std::cout << '|';
      for(std::size_t j = 0; j < size; ++j) {
         std::cout << std::setw(3) << matrix[i][j]; // Set width to 3 for each element
            if (j != size - 1) {
                std::cout << " ";
            }
      }
      std::cout << "|\n";
   }
}

void add_matrices(const_2d_array_ref matrix_one, const_2d_array_ref matrix_two, int**& result, const std::size_t size)
{
   for(std::size_t i = 0; i < size; ++i) {
      for(std::size_t j = 0; j < size; ++j) {
         result[i][j] = matrix_one[i][j] + matrix_two[i][j];
      }
   }
}

void multiply_matrices(const_2d_array_ref matrix_one, const_2d_array_ref matrix_two, int**& result, const std::size_t size)
{
   for(std::size_t i = 0; i < size; ++i) {
      for(std::size_t j = 0; j < size; ++j) {
         result[i][j] = 0;
         for(std::size_t k = 0; k < size; ++k) {
            result[i][j] += matrix_one[i][k] * matrix_two[k][j];
         }
      }
   }
}

void subtract_matrices(const_2d_array_ref matrix_one, const_2d_array_ref matrix_two, int**& result, const std::size_t size)
{
   for(std::size_t i = 0; i < size; ++i) {
      for(std::size_t j = 0; j < size; ++j) {
         result[i][j] = matrix_one[i][j] - matrix_two[i][j];
      }
   }
}

void print_max(const_2d_array_ref matrix, const std::size_t size)
{
   int max = 0;
   for(std::size_t i = 0; i < size; ++i) {
      for(std::size_t j = 0; j < size; ++j) {
         if(matrix[i][j] > max) {
            max = matrix[i][j];
         }
      }
   }
   std::cout << "\n\nMax value of the first matrix is: " << max << "\n\n";
}

void update_value(int**& matrix, const std::size_t size)
{
   std::size_t row = 0;
   std::size_t col = 0;
   int value = 0;

   std::cout << "\nPlease enter the row of the value you wish to change: ";
   while(!(std::cin >> row) || row >= size) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Incorrect input! Please try again: ";
   }
   std::cout << "Please enter the column of the value you wish to change: ";
   while(!(std::cin >> col) || col >= size) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Incorrect input! Please try again: ";
   }
   std::cout << "Enter the new value you wish to insert: ";
   while(!(std::cin >> value)) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Incorrect input! Please try again: ";
   }
   matrix[row][col] = value;
}

int** transpose_matrix(int**& matrix, const std::size_t size)
{
   int** return_matrix = create_matrix(size);

   for(std::size_t i = 0; i < size; ++i) {
      for(std::size_t j = 0; j < size; ++j) {
         return_matrix[i][j] = matrix[j][i];
      }
   }
   for(std::size_t i = 0; i < size; ++i) {
      delete[] matrix[i];
   }
   delete[] matrix;
   return return_matrix;
}

int main(int argc, char** argv)
{
   std::size_t matrix_size = 0;
   int** matrix = nullptr;
   int** matrix_two = nullptr;
   int** matrix_three = nullptr;
   std::ifstream inputFile(argv[1], std::ifstream::in);

   parse_input(matrix, matrix_two, inputFile, matrix_size);
   inputFile.close();
   matrix_three = create_matrix(matrix_size);
   
   add_matrices(matrix, matrix_two, matrix_three, matrix_size);
   std::cout << "\nResult of adding the matrices together:\n";
   print_matrix(matrix_three, matrix_size);
   
   multiply_matrices(matrix, matrix_two, matrix_three, matrix_size);
   std::cout << "\nResult of multiplying the matrices together:\n";
   print_matrix(matrix_three, matrix_size);

   subtract_matrices(matrix, matrix_two, matrix_three, matrix_size);
   std::cout << "\nResult of subtracting the second matrix from the first matrix: \n";
   print_matrix(matrix_three, matrix_size);

   update_value(matrix, matrix_size);
   std::cout << "New matrix:\n";
   print_matrix(matrix, matrix_size);

   print_max(matrix, matrix_size);

   matrix = transpose_matrix(matrix, matrix_size);
   std::cout << "\nHere is the transposed first matrix:\n";
   print_matrix(matrix, matrix_size);
   
   for(std::size_t i = 0; i < matrix_size; ++i) {
      delete[] matrix[i];
      delete[] matrix_two[i];
      delete[] matrix_three[i];
   }
   delete[] matrix;
   delete[] matrix_two;
   delete[] matrix_three;

   return 0;
}
