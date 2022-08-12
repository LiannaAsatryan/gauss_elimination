#include "gauss.h"
#include <fstream>

//this function reads the numbers from the input file,
//turns them into doubles and stores them in the matrix of double numbers
//if one of the numbers isn't a real number, the function sets mistake=true;
void read(std::fstream &i_file, Rmatrix &matrix)
{
        int rows = matrix.get_rows();
        int cols = rows + 1;
        std::string str;
        for(int i = 0; i < rows; i++) {
                for(int j = 0; j < cols; j++) {
                        i_file >> str;
                        Rational temp(str);
                        matrix(i, j) = temp;
                }
        }
}

//this function receives a file as a parameter and returns true if 
//there is an element which isn't a real number and returns false otherwise
bool wrong_data(std::fstream &file)
{
        std::string str;
        while(!file.eof()) {
                file >> str;
                if(file.eof()) {
                        break;
                }
                if(!is_real(str)) {
                        file.close();
                        return true;
                }
        }
        file.close();
        return false;
}


//this function checks whether the given string is a positive integer number
bool is_int(std::string str)
{
        for(int i = 0; i < str.length(); i++) {
                if(str[i] < '1' || str[i] > '9') {
                        return false;
                }
        }
        return true;
}

//this function checks whether the string is a real number or not
bool is_real(std::string str)
{
        int countDots = 0;
        if(str[0] == '.' || str[str.length() - 1] == '.') {
                return false;
        }
        for(int i = 0; i < str.length(); i++) {
                if(str[i] == '-' && i == 0) {
                        continue;
                }
                if(str[i] < '0' || str[i] > '9') {
                        if(str[i] == '.') {
                                countDots++;
                        }
                        else{
                                return false;
                        }
                }
        }
        return countDots <= 1;
}

//this function receives an array, the size of it and the 
//reference of a string <answer>
//if the array is nullptr, sets the <answer> = "no solution"
//otherwise makes the array as a string and assignes it to the <answer>
void set_answer(Rational* x, int n, std::string &answer)
{
        if(x == nullptr) {
                answer = "no solution";
        }else{
                std::string str;
                for(int i = 0; i < n; i++) {
             		x[i].to_string(str);
                        if(i < n-1) {
                                answer += str + ' ';
                        }else {
                                answer += str;
                        }
                }
        }
}



//this function receives the matrix as a parameter and performs gauss forward elimination
void gauss_forward(Rmatrix &matrix)
{
	int rows = matrix.get_rows();
        for (int  j = 0; j < rows-1; j++)
        {       
                if (matrix(j, j).get_numerator() != 0)
                {
                        for (int i = j+1; i < rows; i++)
                        {
                                Rational m = matrix(i, j).neg();
                                Rational d = m.divide( matrix(j, j));
                                matrix.mull_add(i, j, d);
                        }
                }
                else {
                        matrix.swap_with_nonzero_row(j);
                }
        }
}

//this function receives the matrix and an array, performs gauss backward elimination and stores the solutions in the given array
void gauss_backward(Rmatrix &matrix, Rational*& solutions)
{
	int rows = matrix.get_rows();
	int cols = rows + 1;
	for (int i = 0; i < rows; i++){
	        Rational a(0);
	        solutions[i] = a;
	}
	for (int i = rows - 1; i >= 0; i--)
	{
	        Rational sum(0, 1);
	        for (int j = i + 1; j < cols - 1; j++)
	        {
	                sum = sum.add(matrix(i, j).multiply( solutions[j]) );
	        }
	        Rational p = matrix(i, cols - 1).add(sum.neg());
	        solutions[i] = p.divide(matrix(i, i));

	}
}

//this function receives a matrix, ofstream file and an array, performs gauss elinimation with the given matrix,
//stores the solutions in the given array
//in critical cases, writes the appropriate message in the output file
void gauss(Rmatrix &matrix, Rational*& solutions)
{
	 gauss_forward(matrix); //FORWARD
	 if(matrix.exists_wrong_row() || matrix.exists_zero_row()) {
         	solutions = nullptr;
		return;
         } 
         gauss_backward(matrix, solutions); //BACKWARD
}


