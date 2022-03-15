//
// Created by Matebook on 11.03.2022.
//

#ifndef LAB2_FLOAT_H
#define LAB2_FLOAT_H
#include <string>

class Float{
public:
        Float() = default;
        Float(double a);
        ~Float() = default;
        Float operator+(Float f) const;
        Float operator+(double a) const;
        Float operator-(Float f) const;
        Float operator-(double a) const;
        Float operator*(Float f) const;
        Float operator*(double a) const;
        Float operator/(Float f) const;
        Float operator/(double a) const;
        Float& operator=(Float f);
        Float& operator=(double a);
        operator double() const;

        friend Float operator+(double a, Float f);
        friend Float operator-(double a, Float f);
        friend Float operator*(double a, Float f);
        friend Float operator/(double a, Float f);
private:
    double value;

};

#endif //LAB2_FLOAT_H
