//
//  main.cpp
//  card
//
//  Created by Marcin Wierzbicki on 13.12.2015.
//  Copyright © 2015 Marcin Wierzbicki. All rights reserved.
//

#include <fstream>
#include <bitset>

const int MAX_N = (1e6);

using namespace std;

fstream plik;
int n,bufor;
int licz;
int wynik;

bitset<MAX_N+1> karty;

int main() {
    plik.open("highcard.in", fstream::in | fstream::out );
    plik >> n;
    for (int i=0; i<n; i++) {
        plik >> bufor;
        karty[bufor]=1;
    }
    plik.close();
    for (int i=n*2; i>=1; i--) {
        if (karty[i]==0) {
            licz++;
        }
        else {
            if (licz>0) {
                licz--;
                wynik++;
            }
        }
    }
    plik.open("highcard.out", fstream::out);
    plik << wynik << endl;
    plik.close();
}
