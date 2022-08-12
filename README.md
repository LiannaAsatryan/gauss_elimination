#What this project does
 This project solves the given system of linear equations using Gauss-elimination method

#files
 in this directory there are following files
* input.txt __ it is the file where our matrix examples are arranged in the following order
	        size1
		________
               |       |
               |matrix1|
               |_______|
 		
		size2
                _______
               |       |
               |matrix2|
               |_______|
	       ...
* golden.txt __ it is the file where our correct answers are located
* Rational.h __ it is a header file which contains the declaration of class Rational. The objects of this class are fractions
* Rational.cpp __ the implementations of the Rational class methods
* Rmatrix.h __  it is a header file which contains the declaration of class Rmatrix. The objects of this class are matrixes, whiches elements are Rational objects
* Rmatrix.cpp __ the implementations of the Rmatrix class methods
* Makefile
* gauss.cpp __ this .cpp file contains the functions which solve our main problem (gauss_ forward, gauss_backward, gauss and other related functions) 
* gauss.h __ this file contains the declarations of the functions in gauss.cpp
* gauss_test.cpp __ this .cpp file contains the operation of the testing 

#description
My project solves the system of linear equations using matrixes
If the system doesn't have solution or the system is linearly dependent the answer is "no solution"
If a letter is typed in place of number, the answer is "something is wrong with your file"
If wrong size is typed the answer is "wrong size, cannot continue the process"
And finally, when our system has solution the answer is written like this   "sol1 sol2 sol3 ... soln"

#to run the main program type
 make 
to clean the generated files type
 make clean 

#to run the test you type
 make test
to clean the generated files type 
 make clean
