//
//  main.cpp
//  fence
//
//  Created by Marcin Wierzbicki on 12.12.2015.
//  Copyright © 2015 Marcin Wierzbicki. All rights reserved.
//

#include <fstream>
#include <bitset>

std::bitset<101> bylo;

int main() {
    std::fstream plik;
    int a,b,c,d,wynik;
    plik.open("paint.in",std::ios::in | std::ios::out);
    plik >> a >> b >> c >> d;
    plik.close();
    for (int i=a; i<b; i++) {
        bylo[i]=true;
    }
    for (int i=c; i<d; i++) {
        bylo[i]=true;
    }
    for (int i=0; i<=100; i++) {
        if (bylo[i]==true) {
            wynik++;
        }
    }
    plik.open("paint.out", std::fstream::out);
    plik << wynik << std::endl;
    plik.close();
    return 0;
}
