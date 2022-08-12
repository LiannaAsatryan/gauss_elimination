//here are the declarations of the functions in gauss.cpp
#include <string>
#include "Rmatrix.h"

void read(std::fstream&, Rmatrix&);
bool wrong_data(std::fstream&);
bool is_int(std::string);
bool is_real(std::string);
void set_answer(Rational*, int, std::string&);
void gauss_forward(Rmatrix&);
void gauss_backward(Rmatrix&, Rational*&);
void gauss(Rmatrix&, Rational*&);
