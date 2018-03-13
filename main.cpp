#include <iostream>
#include "BigInt.h"
using namespace std;

int main() {
    BigInt V(4);
    int x;
    cout << "Introduceti numarul 1 (V)";
    cin>>V;
   // cout<< "Introduceti numarul al 2-lea (H)";
   // cin>>H;
    //cout << "V.nr_cfr = " << V.nr_cifre;
 //   cout<<V+H;
    //cout << "\n" << V*H;
   // cout<<V.powerUp(2);
    cout<<V.palindrom();
    return 0;
}