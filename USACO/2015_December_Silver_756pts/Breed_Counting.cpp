//
//  main.cpp
//  breed
//
//  Created by Marcin Wierzbicki on 13.12.2015.
//  Copyright © 2015 Marcin Wierzbicki. All rights reserved.
//

#include <fstream>
#include <iostream>

const int MAX_N=131072;

using namespace std;

int drzewo[(MAX_N*2)+2][3];

int r=1;
int wyn[MAX_N+1][3];

void maxpotega(int n) {
    while (n > r) {
        r<<=1;
    }
}

void buildtree(int r) {
    for (int i=r-1; i>0; i--) {
        for (int j=0; j<3; j++) {
            drzewo[i][j]=drzewo[i][j]+drzewo[2*i][j]+drzewo[(2*i)+1][j];
        }
    }
}

void zapytanie(int a, int b, int k) {
    for (int i=0; i<3; i++) {
        wyn[k][i]=0;
    }
    a=a+r-1;
    b=b+r-1;
    for (int i=0; i<3; i++) {
        wyn[k][i]=wyn[k][i]+drzewo[a][i];
    }
    if (a!=b) {
        for (int i=0; i<3; i++) {
            wyn[k][i]=wyn[k][i]+drzewo[b][i];
        }
    }
    while (a/2 != b/2) {
        if (a%2==0) {
            for (int i=0; i<3; i++) {
                wyn[k][i]=wyn[k][i]+drzewo[a+1][i];
            }
        }
        if (b%2==1) {
            for (int i=0; i<3; i++) {
                wyn[k][i]=wyn[k][i]+drzewo[b-1][i];
            }
        }
        a=a/2;
        b=b/2;
    }
}

int main() {
    int n,q,a,b;
    ifstream inp;
    inp.open("bcount.in");
    inp >> n >> q;
    maxpotega(n);
    for (int i=r; i<r+n; i++) {
        inp >> a;
        drzewo[i][a-1]=1;
    }
    buildtree(r);
    for (int i=0; i<q; i++) {
        inp >> a >> b;
        zapytanie(a,b,i);
    }
    inp.close();
    ofstream outp;
    outp.open("bcount.out", fstream::out );
    for (int i=0; i<q; i++) {
        outp << wyn[i][0] << " " << wyn[i][1] << " " << wyn[i][2] << endl;
    }
    outp.close();
    return 0;
}

