//
// Created by Erik on 3/11/2018.
//
#include <iostream>
#include <cstring>
#include <stdlib.h>
#include "BigInt.h"
using namespace std;
/**
 * Constructor fara parametrii
 * aloc un spatiu de memorie si initializez cu 0.
 */
BigInt::BigInt() {
    vector = new int;
    nr_cifre = 0;
}
/**
 * Constructor cu parametrii ce permite transmiterea ca NR INTREG
 * @param nr - Numarul transmit ca intreg
 * Citesc un long, ii pun cifrele in vector si aloc memorie noua la fiecare pas.
 */
BigInt::BigInt(long long nr) {
    int i = 0;
    this->vector = new int[1];
    while (nr != 0) {
        this->vector = (int*) realloc(this->vector, (i+1) * sizeof(int));
        this->vector[i] = nr % 10;
        nr = nr / 10;
        i++;
    }
    this->nr_cifre = i;
}
/**
 * Constructor fara parametrii ce permite transmiterea ca sir de caractere
 * @param nr - Sirul de caractere
 * Parcurg sirul litera cu litera si il transform in int scazand codul ASCII al lui 0
 */
BigInt::BigInt(char* nr)    {
    int i;
    this->nr_cifre = strlen(nr);
    this->vector = new int[this->nr_cifre + 1];
    for (i=0;i<this->nr_cifre;i++)
        this->vector[this->nr_cifre - 1 - i] = nr[i] - '0';
}
/**
 * Constructor de copiere
 * @param V1 - Nr. copiat
 */
BigInt::BigInt(const BigInt& V1)    {//Constructor de copiere
    int i;
    this->vector = new int[V1.nr_cifre];

    this->nr_cifre = V1.nr_cifre;
    for (i = 0; i < V1.nr_cifre; i++)
        this->vector[i] = V1.vector[i];
}
/**
 * Destructor
 * Dezaloc memoria si reinitializez cu 0
 */
BigInt::~BigInt() {
    vector = NULL;
    delete[] vector;
    this->nr_cifre = 0;
}

/**
 * Operator de citire
 * @param input - Streamul (ex. cin, fisier, etc.)
 * @param V - Sirul
 * @return Sirul citit
 *
 */
istream &operator >>(istream &input, BigInt& V) {
    char* sir; //Iau sir auxiliar
    sir = new char[10000];
    int i, lg_nr_introdus;

    input >> sir;
    V.nr_cifre = strlen(sir);
    //transform caracterele cifre in numere si le retin in ordine inversa
    for(i=V.nr_cifre-1;i>=0;i--)
        V.vector[V.nr_cifre-i-1]= sir[i] - '0';


    return input;
}
/**
 * Operatorul de afisare
 * @param output - Streamul
 * @param V  - Siru;
 * @return - Sirul in ordine inversa, pregatit pentru afisare
 */
ostream &operator <<(ostream &output, const BigInt& V) {
    int i;
    for (i=V.nr_cifre-1;i>=0;i--)
        output << V.vector[i];

    return output;
}
/**
 * Operatorul = care permite egalarea a 2 numere mari
 * @param V1 - Sirul sursa
 * @this - Sirul destinatie
 * @return - BigInt
 * Atribuire de la dreapta spre stanga
 */
BigInt& BigInt::operator=(const BigInt &V1) {
    if (this != &V1) {
        int i;

        delete[] this->vector;

        this->vector = new int[V1.nr_cifre+1];

        this->nr_cifre = V1.nr_cifre;
        for (i = 0; i < V1.nr_cifre; i++)
            this->vector[i] = V1.vector[i];
    }
    return *this;

}
/**Operatorul de adunare a doua numere mari
 *
 * @param V2 - Nr. din dreapta semnului
 * @return - Suma
 * Algoritmul este cel din matematica, adun cifra cu cifra incepand de la coada si unde este nevoie fac transport de valoare adunand 10
 */
BigInt BigInt::operator+(const BigInt &V2)   {
    BigInt H1, H2;
    H1 = *this;
    H2 = V2;
    int i, T=0;
    if (H1.nr_cifre < H2.nr_cifre)  {
        for (i=H1.nr_cifre; i<H2.nr_cifre; i++)
            H1.vector[i] = 0;
        H1.nr_cifre = H2.nr_cifre;
    }
    else
        for (i=H2.nr_cifre; i<H1.nr_cifre; i++)
            H2.vector[i] = 0;

    for (i=0;i<H1.nr_cifre;i++)    {
        H1.vector[i] = H1.vector[i] + H2.vector[i] + T;
        T = H1.vector[i] / 10;
        H1.vector[i] = H1.vector[i] % 10;;
    }
    if (T!=0)
        H1.vector[++H1.nr_cifre-1] = T;

    return H1;
}
/**Operatorul de scadere a doua numere mari
 *
 * @param V2 - Nr. din dreapta
 * @return - Diferenta numerelor
 * Algoritmul este acelasi ca in matematica, scad de la coada si cand este nevoie fac transport de valoare adunand 10
 */
BigInt BigInt::operator-(const BigInt& V2)   {
    BigInt H1, H2, Rez;
    H1 = *this;
    H2 = V2;
    int i, T=0;

    //Pornim de la presupunerea ca H2 < H1
    for (i=H2.nr_cifre; i < H1.nr_cifre; i++)
        H2.vector[i] = 0;
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
/**Operatorul de inmultire
 *
 * @param V2 Nr. din dreapta
 * @return  Numerele inmultite
 * Aplic algoritmul matematic, mergand pe acelasi procedeu de baza ca mai sus.
 */
BigInt BigInt::operator*(const BigInt& V2)  {
    BigInt H1, H2;
    H1 = *this;
    H2 = V2;
    BigInt H3;

    H3.nr_cifre = H1.nr_cifre + H2.nr_cifre;
    H3.vector = new int[H3.nr_cifre+1];

    int i, j, T=0;

    for (i=0;i<H3.nr_cifre; i++)
        H3.vector[i] = 0;

    for (i=0;i<H1.nr_cifre;i++)
        for (j=0;j<H2.nr_cifre;j++)
            H3.vector[i+j] = H3.vector[i+j] + (H1.vector[i] * H2.vector[j]);

    for (i=0;i<H3.nr_cifre;i++)    {
        H3.vector[i] = H3.vector[i] + T;
        T = H3.vector[i] / 10;
        H3.vector[i] %= 10;
    }

    if (T != 0)
        H3.vector[H3.nr_cifre-1] = T;
    while (H3.vector[H3.nr_cifre-1] == 0)
        H3.nr_cifre--;
    return H3;

}
/**Operatorul de impartire
 *
 * @param V2 Nr. din dreapta
 * @return Catul impartirii
 * Spre deosebire de operatiile precedente, impartirea o fac prin scaderi repetate pana cand Deimpartitul se cuprinde in Impartitor, numarand la fiecare pas
 */
BigInt BigInt::operator/(const BigInt V2)  {

    BigInt V1;
    BigInt Rezultat("0");
    V1 = *this;//Deimpartit

    while (V1.comparCu(V2) >= 0) {//comparCu este functie auxiliara, returneaza -1 daca V1 < V2 ; 0 daca V1 = V2 ; 1 daca V1 > V2

        V1 = V1 - V2;
        Rezultat = Rezultat + 1;
        // cout<<"Test"<<"\n";
        //cout << Rezultat << "\n";
        //Rezultat = Rezultat + 1;
    }

    return Rezultat;
}
/**Operatorul de rest suprascris
 *
 * @param V2 - Obiectul din dreapta
 * @return Restul impartirii celor doua obiecte
 * Nu era in cerinte, am facut-o pentru teste.
 */
BigInt BigInt::operator%(const BigInt& V2)  {
    BigInt R;
    R = *this;//Rest
    while (R.comparCu(V2) >= 0)
        R = R - V2;
    return R;
}
/**
 * Functie auxiliara folosita la impartire si impartire cu rest.
 * @param V - Obiectul 2 (parametru)
 * @return : -1 DACA V1 < V2 ;
 *           0 DACA V1=V2 ;
 *           1 DACA V1 > V2
 */
int BigInt::comparCu(const BigInt V)  {
    BigInt V1, V2;

    V1 = *this;
    V2 = V;

    while(V1.vector[V1.nr_cifre-1]==0)
        V1.nr_cifre--; //ma asigur ca nu sunt zerouri nesemnificative
    while(V2.vector[V1.nr_cifre-1]==0)
        V2.nr_cifre--;
    if(V1.nr_cifre != V2.nr_cifre)
        if (V1.nr_cifre < V2.nr_cifre)
            return -1;
        else
            return 1;

    int i = 0;
    while(V1.nr_cifre == V2.nr_cifre && i<V1.nr_cifre)
        i++;
    if(i==V1.nr_cifre-1)
        return 0;
    if ( V1.vector[i] < V2.vector[i] )
        return -1;
    return 1;
}
/** Ridicare la putere
 *
 * @param p - puterea la care se ridica numarul
 * @return - numarul ridicat la puterea p
 * Algoritmul se bazeaza pe inmultiri repetate de p ori
 */
BigInt BigInt::putere(int p) {
    BigInt V = *this;
    BigInt Rez;
    Rez.vector = new int[V.nr_cifre * p];
    int i;
    Rez = V;
    for (i=1;i<p;i++)
        Rez = Rez * V;

    return Rez;
}
/** Verifica paritatea numarului apelant
 *
 * @return 1 = PAR ; 0 = IMPAR
 */
int BigInt::par()   {
    if (this->vector[0] % 2 == 0)
        return 1;//Este par
    else
        return 0;//Este impar
}
/** Suma cifrelor obiectului apelant
 *
 * @return SUMA
 */
long long BigInt::suma_cifre() {
    int i;
    long long s=0;
    for (i=0;i<this->nr_cifre;i++)
        s = s + this->vector[i];
    return s;
}
/** Verifica daca obiectul apelant este palindrom
 *
 * @return 0 = FALS; 1 = ADEVARAT
 * Pornesc de la presupunerea ca numarul este palindrom (pal=1) si daca gasesc cifre pe pozitii simetrice ([i] si [n-i] unde n in program este pozitia de sfarsit din vectorul in care se retin cifrele) pal va deveni 0, adica FALS
 * si opresc executia pentru a nu irosi timp.
 */
int BigInt::palindrom() {
    int i, pal = 1;
    for (i=0;i<this->nr_cifre;i++)
        if (this->vector[i] != this->vector[this->nr_cifre - 1 - i])    {
            pal = 0;
            break;
        }
    return pal;


}
