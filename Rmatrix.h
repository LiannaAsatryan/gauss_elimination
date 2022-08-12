#include "Rational.h"
//it is my Rmatrix class declaration
//the object of this class is a matrix for which cols=rows+1 

class Rmatrix{
        private:
                int rows;
                Rational** matrix;
        public:
                inline Rational& operator()(int x, int y) {
                        return matrix[x][y];
                }
                Rmatrix(int);
                Rmatrix();
                ~Rmatrix();
                void printm();
                void swap_with_nonzero_row(int);
                bool exists_wrong_row();
                bool exists_zero_row();
                void mull_add(int, int, Rational);
                int get_rows();
};

