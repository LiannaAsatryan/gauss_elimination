#include "gauss.h"
#include <fstream>

void solving( std::fstream &i_file, std::fstream &o_file)
{
	i_file.open("input.txt", std::ios::in);
        int rows;
        bool wrong = false;
        while(!i_file.eof()) {
        	std::string answer, str;
                i_file >> str;
                if(i_file.eof()) {
                	break;
                }
                if(!is_int(str)) {
                	answer = "wrong size, cannot continue the process";
                        wrong = true;
                } else {
                	rows = std::stoi(str);
                        Rmatrix matrix(rows);
                        read(i_file, matrix);
                        Rational* x = new Rational[rows];
                        gauss(matrix, x);
                        set_answer(x, rows, answer);
                        delete[] x;
                }
                o_file << answer << std::endl;
                if(wrong) {
                	break;
                }
        }
}

int main()
{
        std::fstream i_file;
        std::fstream o_file;
        i_file.open("input.txt", std::ios::in);
        o_file.open("output.txt", std::ios::out);
        if(wrong_data(i_file)) {
                o_file << "something is wrong with your file" << std::endl;
        }else {
       		solving(i_file, o_file);
        }
        i_file.close();
        o_file.close();
}


