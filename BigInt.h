//
// Created by Erik on 3/11/2018.
//
#include <iostream>
using namespace std;
#ifndef POO_TEMA1_BIGINT_H
#define POO_TEMA1_BIGINT_H


class BigInt {
    public:
        BigInt();
        BigInt(int);
        ~BigInt();
        friend ostream &operator <<(ostream&, const BigInt&);
        friend istream &operator >>(istream&, BigInt&);
        BigInt operator+(const BigInt&);
        BigInt operator-(const BigInt&);
        BigInt operator*(const BigInt&);
        BigInt operator/(const BigInt&);
        BigInt& operator=(const BigInt&);


        BigInt powerUp(int);
        int par();
        int palindrom();
        long long suma_cifre();
    public:
        int *vector;
        char *vector_char;
        int nr_cifre;


};


#endif //POO_TEMA1_BIGINT_H
