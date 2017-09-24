//
//  main.cpp
//  Getting_the_D
//
//  Created by Marcin Wierzbicki on 30.04.2016.
//

#include <iostream>
#include <vector>
#include <algorithm>
#define t(a) lit[int(a)-65]
using namespace std;

int n;
string tekst;
string slownik[10]={"ZERO", "TWO", "SIX", "EIGHT", "THREE", "SEVEN", "FOUR", "FIVE", "NINE", "ONE"};
int topush[10]={0, 2, 6, 8, 3, 7, 4, 5, 9, 1};
vector<int> wyn;
int lit[26];
bool ok;

void resolve() {
    for (int i=0; i<tekst.length(); i++) {
        lit[int(tekst[i]-65)]++;
    }
    for (int i=0; i<10; i++) {
        ok=true;
        for (int j=0; j<slownik[i].length(); j++) {
            if (t(slownik[i][j])<1) {
                ok=false;
            }
        }
        if (ok) {
            for (int j=0; j<slownik[i].length(); j++) {
                t(slownik[i][j])--;
            }
            wyn.push_back(topush[i]);
            i--;
        }
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> tekst;
        resolve();
        sort(wyn.begin(), wyn.end());
        cout << "Case #" << i+1 << ": ";
        for (int t=0; t<wyn.size(); t++) {
            cout << wyn[t];
        }
        cout << endl;
        wyn.clear();
        for (int i=0; i<26; i++) {
            lit[i]=0;
        }
    }
    return 0;
}
