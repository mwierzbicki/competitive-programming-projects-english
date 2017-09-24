//
//  main.cpp
//  limit
//
//  Created by Marcin Wierzbicki on 12.12.2015.
//  Copyright © 2015 Marcin Wierzbicki. All rights reserved.
//

#include <fstream>
#include <iostream>

using namespace std;

std::fstream plik;
int sl[101];
int sp[101];
int last=1;
int maxx=0;
int roznica;

int main() {
    int a,b,c,d;
    plik.open("speeding.in", std::fstream::in | std::fstream::out );
    plik >> a >> b;
    for (int i=0; i<a; i++) {
        plik >> c >> d;
        for (int j=last; j<=last+c; j++) {
            sl[j]=d;
        }
        last=last+c;
    }
    last=1;
    for (int i=0; i<b; i++) {
        plik >> c >> d;
        for (int j=last; j<=last+c; j++) {
            sp[j]=d;
        }
        last=last+c;
    }
    plik.close();
    for (int i=0; i<=100; i++) {
        if (sp[i]>sl[i]) {
            if (sp[i]-sl[i]>maxx) {
                maxx=sp[i]-sl[i];
            }
        }
    }
    plik.open("speeding.out", std::fstream::out);
    plik << maxx << std::endl;
    plik.close();
    return 0;
}

