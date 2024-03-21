//Author: Caden LeCluyse
//Filename: main.cpp
//Date: 3/21/24
//Class: EECS348
//Purpose: Get a matrix from a file and do a bunch of things with it

#include <iostream>
#include <cstdlib>
#include <ifstream>
#include <limits>

void create_matrix(int** matrix, const std::size_t size)
{
   matrix = new int*[matrix_size];
   for(std::size_t i = 0; i < matrix_size; ++i) {
      matrix[i] = new int[matrix_size];
   }
   for(std::size_t i = 0; i < size; ++i) {
      for(std::size_t j = 0; j < size; ++j) {
         matrix[i][j] = 0;
      }
   }
}
void parse_input(int** matrix, int** matrix_two, const std::ifstream& file, std::size_t& size)
{
   if(file.is_open()){
      file >> size;
      create_matrix(matrix, size);
      create_matrix(matrix_two, size);
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

void print_matrix(const int** matrix, const std::size_t size)
{
   std::cout << '\n';
   for(std::size_t i = 0; i < size; ++i) {
      std::cout << '|';
      for(std::size_t j = 0; j < size; ++j) {
         if(j == size - 1) {
            std::cout << matrix[i][j];
         } else {
            std::cout << matrix[i][j] << " ";
         }
      }
      std::cout << '|\n';
   }
{

void add_matrices(const int** matrix_one, const int** matrix_two, int** result, const std::size_t size)
{
   for(std::size_t i = 0; i < size; ++i) {
      for(std::size_t j = 0; j < size; ++j) {
         result[i][j] = matrix_one[i][j] + matrix_two[i][j];
      }
   }
}

void multiply_matrices(const int** matrix_one, const int** matrix_two, int** result, const std::size_t size)
{
   for(std::size_t i = 0; i < size; ++i) {
      for(std::size_t j = 0; j < size; ++j) {
         for(std::size_t k = 0; k < size; ++k) {
            result[i][j] += matrix_one[i][k] * matrix_two[k][j];
         }
      }
   }
}

void subtract_matrices(const int** matrix_one, const int** matrix_two, int** result, const std::size_t size)
{
   for(std::size_t i = 0; i < size; ++i) {
      for(std::size_t j = 0; j < size; ++j) {
         result[i][j] = matrix_one[i][j] - matrix_two[i][j];
      }
   }
}

void print_max(const int** matrix, const std::size_t size)
{
   int max = 0;
   for(std::size_t i = 0; i < size; ++i) {
      for(std::size_t j = 0; j < size; ++j) {
         if(matrix[i][j] > max) {
            max = matrix[i][j];
         }
      }
   }
   std::cout << "Max value of the first matrix is: " << max << "\n\n";
}

void update_value(int** matrix, const std::size_t size)
{
   std::size_t row = 0;
   std::size_t col = 0;
   int value = 0;

   std::cout << "Please enter the row of the value you wish to change: ";
   while(!(std::cin >> row) || row >= size) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Incorrect input! Please try again: ";
   }
   std::cout << "\nPlease enter the column of the value you wish to change: ";
   while(!(std::cin >> col) || col >= size) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Incorrect input! Please try again: ";
   }
   std::cout << "\nEnter the new value you wish to insert: ";
   while(!(std::cin >> value)) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Incorrect input! Please try again: ";
   }
   matrix[row][col] = value;
}

int** transpose_matrix(int** matrix, const std::size_t size)
{
   int** return_matrix = nullptr;
   create_matrix(return_matrix, size);

   for(std::size_t i = 0; i < size; ++i) {
      for(std::size_t j = 0; j < size; ++j) {
         return_matrix[i][j] = matrix[j][i]
      }
   }
   for(std::size_t i = 0; i < size; ++i) {
      delete[] matrix[i];
   }
   delete matrix;
   return return_matrix;
}


int main(int argc, char** argv)
{
   std::size_t matrix_size = 0;
   int** matrix = nullptr;
   int** matrix_two = nullptr;
   int** matrix_three = nullptr;
   const std::ifstream inputFile(argv[1]);

   parse_input(matrix, matrix_two, inputFile, matrix_size);
   inputFile.close();
   create_matrix(matrix_three, matrix_size);

   add_matrices(matrix, matrix_two, matrix_three, matrix_size);
   std::cout << "Result of adding the matrices together:\n";
   print_matrix(matrix_three, matrix_size);

   multiply_matrices(matrix, matrix_two, matrix_three, matrix_size);
   std::cout << "Result of multiplying the matrices together:\n";
   print_matrix(matrix_three, matrix_size);

   subtract_matrices(matrix, matrix_two, matrix_three, matrix_size);
   std::cout << "Result of subtracting the second matrix from the first matrix: \n";
   print_matrix(matrix_three, matrix_size);

   update_value(matrix, matrix_size);
   std::cout << "New matrix:\n";
   print_matrix(matrix, matrix_size);

   print_max(matrix, matrix_size);

   matrix = transpose_matrix(matrix, matrix_size);
   std::cout << "Here is the transposed first matrix:\n";
   print_matrix(matrix, matrix_size);

   for(std::size_t i = 0; i < matrix_size; ++i) {
      delete[] matrix[i]
      delete[] matrix_two[i];
      delete[] matrix_three[i];
   }
   delete matrix;
   delete matrix_two;
   delete matrix_three;

   return 0;
}
