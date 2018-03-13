//
// Created by Erik on 3/11/2018.
//
#include <iostream>
#include <cstring>
#include "BigInt.h"
using namespace std;

BigInt::BigInt() {
    vector = new int;
    //&nr_cifre = new int;
    nr_cifre = 0;
}

BigInt::BigInt(int nr_cifre) {
    this->nr_cifre = nr_cifre;
    vector = new int[nr_cifre];
}

BigInt::~BigInt() {
    delete[] vector;
    delete &nr_cifre;
}

istream &operator >>(istream &input, BigInt& V) {
    char* sir; //Iau sir auxiliar
    sir = new char[V.nr_cifre + 1];
    int i, lg_nr_introdus;

    input >> sir;
    lg_nr_introdus = strlen(sir);
    //transform caracterele cifre in numere si le retin in ordine inversa
    for(i=V.nr_cifre-1;i>=0;i--)
        V.vector[V.nr_cifre-i-1]= sir[i] - '0';

    if (lg_nr_introdus < V.nr_cifre) {
        cout << "Exceptie: ati declarat " << V.nr_cifre << " cifre, dar ati introdus doar " << lg_nr_introdus << "\n";
       // delete input;
        delete[] V.vector;
        delete &V.nr_cifre;
    }

    return input;
}

ostream &operator <<(ostream &output, const BigInt& V) {
    int i;
    for (i=V.nr_cifre-1;i>=0;i--)
        output << V.vector[i];

    return output;
}
BigInt& BigInt::operator=(const BigInt &V1) {
    if (this != &V1) {
        int i;

        delete[] this->vector;
        delete &this->nr_cifre;

        this->vector = new int[V1.nr_cifre];

        this->nr_cifre = V1.nr_cifre;
        for (i = 0; i < V1.nr_cifre; i++)
            this->vector[i] = V1.vector[i];
    }
        return *this;

}

BigInt BigInt::operator+(const BigInt &V2)   {
    BigInt H1, H2;
    H1 = *this;
    H2 = V2;
    int i, T=0;
    //cout << "H1: "<< H1 << "\t" << "H2: " << H2 << "T:\t" << T << "\n";
    if (H1.nr_cifre < H2.nr_cifre)  {
        for (i=H1.nr_cifre+1; i<=H2.nr_cifre; i++)
            H1.vector[i++] = 0;
        H1.nr_cifre = H2.nr_cifre;
    }
    else
        for (i=H2.nr_cifre+1; i<=H1.nr_cifre; i++)
            H2.vector[i++] = 0;

    for (i=0;i<H1.nr_cifre;i++)    {
        H1.vector[i] = H1.vector[i] + H2.vector[i] + T;
        T = H1.vector[i] / 10;
        H1.vector[i] = H1.vector[i] % 10;;
    }
    //cout << "H1: "<< H1 << "\t" << "H2: " << H2 << "T:\t" << T << "\n";
    if (T!=0)
        H1.vector[++H1.nr_cifre] = T;

    return H1;
}

BigInt BigInt::operator-(const BigInt &V2)   {
    BigInt H1, H2;
    H1 = *this;
    H2 = V2;
    int i, T=0;
    //Pornim de la presupunerea ca H2 < H1
    for (i=H2.nr_cifre + 1; i <= H1.nr_cifre; i++)
        H1.vector[i++] = 0;
    for (i=0;i<H1.nr_cifre;i++) {
        H1.vector[i] = H1.vector[i] - (H2.vector[i] + T);
        if (H1.vector[i] < 0)
            T = 1;
        else
            T = 0;
        if (T != 0)
            H1.vector[i] = H1.vector[i] + 10;
    }
    while ( H1.vector[H1.nr_cifre-1] == 0 )
        H1.nr_cifre--;
    return H1;
}

BigInt BigInt::operator*(const BigInt& V2)  {
    BigInt H1, H2;
    H1 = *this;
    H2 = V2;
    BigInt H3;

    //H3 = H1 * H2
   // H3.nr_cifre = new int;
    H3.nr_cifre = H1.nr_cifre + H2.nr_cifre - 1;
    H3.vector = new int[H3.nr_cifre+1];

    int i, j, T=0;

    cout << "\nH1: "<< H1 << "\t" << "H2: " << H2 << "\t" << "H3: " << H3 << "\tT: " << T << "\n";
    for (i=0;i<H1.nr_cifre + H2.nr_cifre; i++)
        H3.vector[i] = 0;
    cout << "H1: "<< H1 << "\t" << "H2: " << H2 << "\t" << "H3: " << H3 << "\tT: " << T << "\n";
    for (i=0;i<H1.nr_cifre;i++)
        for (j=0;j<H2.nr_cifre;j++)
                H3.vector[i+j] = H3.vector[i+j] + (H1.vector[i] * H2.vector[j]);
    cout << "H1: "<< H1 << "\t" << "H2: " << H2 << "\t" << "H3: " << H3 << "\tT: " << T << "\n";
    for (i=0;i<H3.nr_cifre;i++)    {
        T = (H3.vector[i] += T) / 10;
        H3.vector[i] %= 10;
    }
    cout << "H1: "<< H1 << "\t" << "H2: " << H2 << "\t" << "H3: " << H3 << "\tT: " << T << "\n";
    if (T != 0)
        H3.vector[H3.nr_cifre-1] = T;

    //cout << "Test: " << H1.nr_cifre-1 + H2.nr_cifre-1 - 1;
    return H3;

}

BigInt BigInt::operator/(const BigInt& V2)  {
    BigInt H1, H2;
    H1 = *this;
    H2 = V2;
    BigInt H3;

    //H3 = H1 * H2
    // H3.nr_cifre = new int;
    H3.nr_cifre = H1.nr_cifre + H2.nr_cifre - 1;
    H3.vector = new int[H3.nr_cifre+1];

    int i, j, T=0;

    cout << "\nH1: "<< H1 << "\t" << "H2: " << H2 << "\t" << "H3: " << H3 << "\tT: " << T << "\n";
    for (i=0;i<H1.nr_cifre + H2.nr_cifre; i++)
        H3.vector[i] = 0;
    cout << "H1: "<< H1 << "\t" << "H2: " << H2 << "\t" << "H3: " << H3 << "\tT: " << T << "\n";
    for (i=0;i<H1.nr_cifre;i++)
        for (j=0;j<H2.nr_cifre;j++)
            H3.vector[i+j] = H3.vector[i+j] + (H1.vector[i] * H2.vector[j]);
    cout << "H1: "<< H1 << "\t" << "H2: " << H2 << "\t" << "H3: " << H3 << "\tT: " << T << "\n";
    for (i=0;i<H3.nr_cifre;i++)    {
        T = (H3.vector[i] += T) / 10;
        H3.vector[i] %= 10;
    }
    cout << "H1: "<< H1 << "\t" << "H2: " << H2 << "\t" << "H3: " << H3 << "\tT: " << T << "\n";
    if (T != 0)
        H3.vector[H3.nr_cifre-1] = T;

    //cout << "Test: " << H1.nr_cifre-1 + H2.nr_cifre-1 - 1;
    return H3;

}

BigInt BigInt::powerUp(int p) {
    BigInt V = *this;
    BigInt Rez;
    Rez.vector = new int[V.nr_cifre * p];
    int i;
    Rez = V;
    for (i=1;i<p;i++) {
        cout<<"Before:" <<i<<"||";
        Rez = Rez * V;
        cout<<"After:" <<i<<"||";
    }
    cout<<"Test";
    return Rez;
}

int BigInt::par()   {
    if (this->vector[0] % 2 == 0)
        return 1;//Este par
    else
        return 0;//Este impar
}

long long BigInt::suma_cifre() {
    int i;
    long long s=0;
    for (i=0;i<this->nr_cifre;i++)
        s = s + this->vector[i];
    return s;
}

int BigInt::palindrom() {
    int i, pal = 1;
    for (i=0;i<this->nr_cifre;i++)
        if (this->vector[i] != this->vector[this->nr_cifre - 1 - i])    {
            pal = 0;
            break;
        }
    return pal;


}
