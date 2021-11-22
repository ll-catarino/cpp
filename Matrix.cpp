#include "Matrix.h"
#include <iostream>

Matrix::Matrix(int rows, int cols, int** matrix) {
        this->matrix = matrix;
        this->rows = rows;
        this->cols = cols;
}

int Matrix::GetRows() {
   return rows;
}

int Matrix::GetCols() {
    return cols;
}

int Matrix::GetElement(int row, int col) {
    return matrix[row-1][col-1];
}

void Matrix::SetElement(int row, int col, int element) {
    matrix[row-1][col-1] = element;
}

int** Matrix::ToArray()
{
    return matrix;
}

bool Matrix::IsSquare() { return rows == cols; }

bool Matrix::IsIdentity()
{
    if (!this->IsSquare())
    {
        return false;
    }
    
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {   
            if (i == j && matrix[i][j] != 1)
            {
                return false;
            }

            if (i != j && matrix[i][j] != 0)
            {
                return false;
            }
            
        }
    } 
    return true;
}

bool Matrix::IsScalar()
{
    if (!this->IsSquare())
    {
        return false;
    }

    int scalar = matrix[0][0];
    
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {   
            if (i == j && matrix[i][j] != scalar)
            {
                return false;
            }

            if (i != j && matrix[i][j] != 0)
            {
                return false;
            }
        }
    } 
    return true;
}

bool Matrix::IsNull()
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {   
            if (matrix[i][j] != 0)
            {
                return false;
            }
        }
    }
    return true;
}

bool Matrix::IsRow() { return rows == 1; }

bool Matrix::IsColumn() { return cols == 1; }

bool Matrix::IsSymmetric()
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {   
            if (matrix[i][j] != matrix[j][i])
            {
                return false;
            }
        }
    }
    return true; 
}

bool Matrix::IsSkewSymmetric()
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {   
            if (matrix[i][j] + matrix[j][i] != 0)
            {
                return false;
            }
        }
    }
    return true;  
}

void Matrix::Scale(float scalar)
{
   for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {   
            matrix[i][j] = matrix[i][j] * scalar;
        }
    } 
}

Matrix* Matrix::Sum(Matrix* a, Matrix* b)
{
    int rows = a->GetRows();
    int cols = a->GetCols();
    int **matrix = new int*[rows];

    for (int i = 0; i < rows; i++)
    {
        matrix[i] = new int[cols];

        for (int j = 0; j < cols; j++)
        {
            matrix[i][j] = a->ToArray()[i][j] + b->ToArray()[i][j];
        }
    }

    Matrix* m = new Matrix(rows, cols, matrix);

    return m;
}

Matrix* Matrix::Subtract(Matrix* a, Matrix* b)
{
    int rows = a->GetRows();
    int cols = a->GetCols();
    int **matrix = new int*[rows];

    for (int i = 0; i < rows; i++)
    {
        matrix[i] = new int[cols];

        for (int j = 0; j < cols; j++)
        {
            matrix[i][j] = a->ToArray()[i][j] - b->ToArray()[i][j];
        }
    }

    Matrix* m = new Matrix(rows, cols, matrix);

    return m;
}

int Matrix::GetLongestElement(){
    int longest = matrix[0][0];

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {   
            if (std::to_string(matrix[i][j]).size() > std::to_string(longest).size())
            {
                longest = matrix[i][j];
            }
            
        }
    }

    return longest;
}

std::string Matrix::ToString() {

    int longest = GetLongestElement();
    std::string str = "";

    for (int i = 0; i < rows; i++) {

        str.append("[ ");

        for (int j = 0; j < cols; j++) {

            int current = matrix[i][j];

            //spacing utility
            for (
                int k = 0;
                k < (std::to_string(longest).size() - std::to_string(current).size()); 
                k++
            )
            {
                str.append(" ");
            }
            
            str.append(std::to_string(current) + " ");
        }

        str.append("]\n");
    }
    return str;
}

Matrix::~Matrix()
{
   for (int i = 0; i < rows; i++) {
       delete[] matrix[i];
   } 

   delete[] matrix;
}