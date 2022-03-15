//
// Created by Matebook on 11.03.2022.
//

#include "Float.h"

Float::Float(double a) {
    value = a;
}


Float Float::operator+(Float f) const{
    return {value + f.value};
}

Float Float::operator+(double a) const{
    return {value + a};
}

Float Float::operator-(Float f) const{
    return {value - f.value};
}

Float Float::operator-(double a) const{
    return {value - a};
}

Float Float::operator*(Float f) const{
    return {value * f.value};
}

Float Float::operator*(double a) const{
    return {value * a};
}

Float Float::operator/(double a) const{
    return {value / a};
}

Float Float::operator/(Float f) const{
    return {value / f.value};
}

Float& Float::operator=(Float f) {
    value = f.value;
    return *this;
}

Float &Float::operator=(double a) {
    value = a;
    return *this;
}

Float::operator double() const{
    return value;
}

Float operator+(double a, Float f) {
    return {a + f.value};
}

Float operator-(double a, Float f) {
    return {a - f.value};
}

Float operator*(double a, Float f) {
    return {a * f.value};
}

Float operator/(double a, Float f) {
    return {a / f.value};
}
