#include <iostream>
#include "BigInt.h"
using namespace std;

int main() {
    BigInt V, H, Rez;
    int x;
    V = "1234";
    H = 111;
    //cout << "Introduceti numarul 1 (V)";cin>>V;
    //cout<< "Introduceti numarul al 2-lea (H)";cin>>H;

    cout<<V<<"\n";
    cout<<H;
    cout<<"\nRezultat adunare: " << V+H;
    cout << "\nRezultat scadere: ";cout<<V-H;
    cout << "\nRezultat inmultire: ";cout<<V*H<<"\n";

    cout<<"Putere: "<<V.putere(2) << "\n";
    cout<<"Palindrom: "<<V.palindrom() << "\n";
    cout<<"Paritate: "<<V.par() << "\n";
    cout<<"Suma cifre: "<<V.suma_cifre() << "\n";

   // cout << "\nRezultat impartire: ";cout<<V/H;

    return 0;
}
