#include <iostream>
//this is the declaration of my class Rational. The objects of this class are fractions
//(numerator/denominator)

class Rational {
        private:
                int numerator;
                int denominator;
        public:
                Rational(double);
                Rational(std::string);
                Rational();
                Rational(int, int);
                void reduce();
                ~Rational();
                Rational add(const Rational&);
                Rational multiply(const Rational&);
                Rational divide(int);
                Rational divide(const Rational&);
                Rational neg();
                void print();
                void to_string(std::string&);
                int get_numerator();
                int get_denominator();
};

