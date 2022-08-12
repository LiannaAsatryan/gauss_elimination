#include "Rmatrix.h"


Rmatrix::Rmatrix(int row) 
{
        rows = row;
        //create the matrix
        int cols = rows + 1;
        matrix = new Rational*[rows];
        for(int i = 0; i < rows; i++) {
                matrix[i]=new Rational[cols];
        }
        //fill with zeroes by default
        for(int i = 0; i < rows; i++) {
                for(int j = 0; j < cols; j++) {
                        Rational p(0);
                        matrix[i][j] = p;
                }
        }
}

Rmatrix::Rmatrix()
{
        rows = 0;
        matrix = nullptr;
}

Rmatrix::~Rmatrix()
{
        for(int i = 0; i < rows; i++) {
                delete[] matrix[i];
        }
        delete[] matrix;
}

void Rmatrix::printm()
{
        int cols = rows + 1;
        for(int i = 0; i < rows; i++) {
                for(int j = 0; j < cols; j++) {
                        matrix[i][j].print();
                        std::cout << " ";
                }
                std::cout << std::endl;
        }
}

void Rmatrix::swap_with_nonzero_row(int i)
{
        int cols = rows + 1;
        for (int j = i+1; j < rows; j++)
        {
                if (matrix[j][i].get_numerator() != 0)
                {
                        for (int k = 0; k < cols; k++)
                        {
                                Rational temp = matrix[i][k];
                                matrix[i][k] = matrix[j][k];
                                matrix[j][k] = temp;
                        }
                        break;
                }
        }
}

//this function returns true if there is a row in the matrix like this- (0, 0, ..., 0, t) where t is nonzero
bool Rmatrix::exists_wrong_row()
{
        int cols = rows + 1;
        for(int i = 0; i < rows; i++){
                bool zero = true;
                for(int j = 0; j < cols - 1; j++) {
                        if(matrix[i][j].get_numerator() != 0) {
                                zero = false;
                                break;
                        }
                }
                if(zero && matrix[i][cols - 1].get_numerator() != 0) {
                        return true;
                }
        }
        return false;
}

//this function returns true if there is a row in the matrix like this- (0, 0, ..., 0) 
bool Rmatrix::exists_zero_row()
{
        int cols = rows + 1;
        for(int i = 0; i < rows; i++){
                bool zero = true;
                for(int j = 0; j < cols; j++) {
                        if(matrix[i][j].get_numerator() != 0) {
                                zero = false;
                                break;
                        }
                }
                if(zero) {
                        return true;
                }
        }
        return false;
}

//this function adds the i-th row with d*(j-th row)
void Rmatrix::mull_add(int i, int j, Rational d)
{
        int cols = rows + 1;
        for (int k = 0; k < cols; k++) {
                Rational t = d.multiply(matrix[j][k]);
                matrix[i][k] = matrix[i][k].add(t);
       }

}

int Rmatrix::get_rows()
{
        return rows;
}





















