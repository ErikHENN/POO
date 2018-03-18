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
    BigInt(long long);
    BigInt(char*);
    BigInt(const BigInt&);//constructor de copiere
    ~BigInt();
    friend ostream &operator <<(ostream&, const BigInt&);
    friend istream &operator >>(istream&, BigInt&);
    BigInt operator+(const BigInt&);
    BigInt operator-(const BigInt&);
    BigInt operator*(const BigInt&);
    BigInt operator/(const BigInt);
    BigInt operator%(const BigInt&);
    BigInt& operator=(const BigInt&);


    BigInt putere(int);
    int par();
    int comparCu(const BigInt);
    int palindrom();
    long long suma_cifre();
private:
    int *vector;
    int nr_cifre;


};


#endif //POO_TEMA1_BIGINT_H
