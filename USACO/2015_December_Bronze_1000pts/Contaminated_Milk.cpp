//
//  main.cpp
//  milk
//
//  Created by Marcin Wierzbicki on 12.12.2015.
//  Copyright © 2015 Marcin Wierzbicki. All rights reserved.
//

#include <fstream>
#include <bitset>
#include <algorithm>

std::fstream plik;

std::pair<int, std::pair<int, int> > tab[1001];
std::pair<int, int> tab2[51];
std::bitset<51> usper;
std::bitset<51> bylo;
int tab3[51];
int n,m,d,s,iter;
unsigned long maxx;

int main() {
    plik.open("badmilk.in", std::fstream::in | std::fstream::out );
    plik >> n >> m >> d >> s;
    for (int i=0; i<d; i++) {
        plik >> tab[i].second.first >> tab[i].second.second >> tab[i].first;
    }
    sort(tab, tab+d);
    for (int i=0; i<s; i++) {
        plik >> tab2[i].first >> tab2[i].second;
        iter=0;
        while ((tab[iter].first<tab2[i].second) && iter+1<=d) {
            if (tab2[i].first==tab[iter].second.first) {
                if (bylo[tab[iter].second.second]==0) {
                    tab3[tab[iter].second.second]++;
                    bylo[tab[iter].second.second]=true;
                }
            }
            iter++;
        }
        for (int i=1; i<51; i++) {
            bylo=false;
        }
    }
    plik.close();
    for (int i=1; i<51; i++) {
        if (tab3[i]==s) {
            for (int j=0; j<d; j++) {
                if (tab[j].second.second==i) {
                    usper[tab[j].second.first]=true;
                }
            }
            if (usper.count()>maxx) {
                maxx=usper.count();
            }
            for (int j=1; j<51; j++) {
                usper[j]=false;
            }
        }
    }
    plik.open("badmilk.out", std::fstream::out);
    plik << maxx << std::endl;
    plik.close();
    return 0;
}

