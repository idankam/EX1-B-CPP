#include<iostream>
#include<string>
#include<vector>
#include"mat.hpp"

using namespace std;

namespace ariel { 
    std::string mat(int mat_length, int mat_breadth, char symbol_1, char symbol_2){

        // exception if number of rows or columns under 1:
        if(mat_length < 1 || mat_breadth < 1){
            throw std::invalid_argument("length / breadth must be at least 1.");
        }

        // exception if number of rows or columns is even:
        if(mat_length%2 == 0 || mat_breadth%2 == 0){
            throw std::invalid_argument("length / breadth odd.");
        }

        // exception if symbol is some space ot illegal char:
        if(symbol_1 == ' ' || symbol_1 == '\t' || symbol_1 == '\n' || symbol_1 == '\r'){
            throw std::invalid_argument("Illegal input at symbol 1, can't be a space or something similar.");
        }
        
        // exception if symbol is some space ot illegal char:
        if(symbol_2 == ' ' || symbol_2 == '\t' || symbol_2 == '\n' || symbol_2 == '\r'){
            throw std::invalid_argument("Illegal input at symbol 2, can't be a space or something similar.");
        }

        if(symbol_1 > up_limit || symbol_1 < down_limit || symbol_2 > up_limit || symbol_2 < down_limit ){
            throw std::invalid_argument("Illegal input - char must be between 33 to 126 in ASCII table");
        }


        // make matrix with the by given size:
        int rows = mat_breadth;
        int cols = mat_length;

        vector<vector<char>> matrix(rows, vector<char> (cols, 0));
        
        // starting symbol (will change every iteration):
        char symbol = symbol_1;

        // starting values for iterate:
        int first_row = 0;
        int last_row = rows-1;
        int first_col = 0;
        int last_col = cols-1;

        // In each iteration we will fill the next frame with the appropriate symbol.
        // The run ends when the pointers of the rows or columns pass each other:
        while (first_row <= last_row && first_col <= last_col)
        {
            // fill up and down rows of the current frame:
            for (int i = first_col; i <= last_col; i++)
            {
                matrix[first_row][i] = symbol;
            }
            for (int i = first_col; i <= last_col; i++)
            {
                matrix[last_row][i] = symbol;
            }

            // fill left and right columns of the current frame: 
            for (int i = first_row+1; i <= last_row-1; i++)
            {
                matrix[i][first_col] = symbol;
            }
            for (int i = first_row+1; i <= last_row-1; i++)
            {
                matrix[i][last_col] = symbol;
            }

            // update values for next iteration
            first_row++; last_row--; first_col++; last_col--;
            if (symbol_1 == symbol){
                symbol = symbol_2;
            }
            else {
                symbol = symbol_1;
            }
        }
        
        // "print" the matrix to string variable:
        std:string answer;
        for (size_t i = 0; i < rows; i++)
        {
            for (size_t j = 0; j < cols; j++)
            {
                answer += matrix[i][j];
            }
            // add \n if there will be next row:
            if (i+1 < rows){
                answer += "\n";  
            }
        }

        return answer;
    };
};