//
//  main.cpp
//  senators
//
//  Created by Marcin Wierzbicki on 08.05.2016.
//  Copyright © 2016 Marcin Wierzbicki. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;

int t,n,maxx=0,jmaxx=0,kek=0;
int tab[26];
bool stop;

int main() {
    ios_base::sync_with_stdio(0);
    cin >> t;
    for (int i=0; i<t; i++) {
        cin >> n;
        for (int j=0; j<n; j++) {
            cin >> tab[j];
        }
        cout << "Case #" << i+1 << ": ";
        if (n==1) {
            for (int j=0; j<n; j++) {
                cout << "A ";
            }
        }
        else if (n==2) {
            while (tab[0]>tab[1]) {
                tab[0]--;
                cout << "A ";
            }
            while (tab[1]>tab[0]) {
                tab[1]--;
                cout << "B ";
            }
            while (tab[0]>0) {
                tab[0]--;
                cout << "AB ";
            }
        }
        else {
            stop=false;
            while (!stop) {
                for (int j=0; j<n; j++) {
                    if (tab[j]>maxx) {
                        maxx=tab[j];
                        jmaxx=j;
                    }
                }
                if (maxx==0) {
                    stop=true;
                }
                else if (maxx==1) {
                    if (n%2==1) {
                        cout << "A ";
                        for (int j=1; j<n; j+=2) {
                            cout << char(j+65) << char(j+1+65) << " ";
                        }
                    }
                    else {
                        for (int j=0; j<n-1; j+=2) {
                            cout << char(j+65) << char(j+1+65) << " ";
                        }
                    }
                    stop=true;
                }
                else {
                    tab[jmaxx]--;
                    cout << char(jmaxx+65);
                    maxx=0;
                    jmaxx=0;
                    for (int j=0; j<n; j++) {
                        if (tab[j]>maxx) {
                            maxx=tab[j];
                            jmaxx=j;
                        }
                    }
                    if (maxx==1) {
                        if (n%2==1) {
                            cout << "A ";
                            for (int j=1; j<n; j+=2) {
                                cout << char(j+65) << char(j+1+65) << " ";
                            }
                        }
                        else {
                            cout << " ";
                            for (int j=0; j<n-1; j+=2) {
                                cout << char(j+65) << char(j+1+65) << " ";
                            }
                        }
                        stop=true;
                    }
                    else {
                        tab[jmaxx]--;
                        cout << char(jmaxx+65) << " ";
                        maxx=0;
                        jmaxx=0;
                    }
                }

            }
        }
        cout << endl;
    }
    return 0;
}
