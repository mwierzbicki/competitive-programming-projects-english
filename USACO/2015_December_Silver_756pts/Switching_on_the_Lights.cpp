//
//  main.cpp
//  light
//
//  Created by Marcin Wierzbicki on 13.12.2015.
//  Copyright © 2015 Marcin Wierzbicki. All rights reserved.
//

#include <algorithm>
#include <bitset>
#include <vector>
#include <fstream>

using namespace std;

unsigned long wyn;

fstream plik;
int n,m,a,b,c,d;
//pair<pair<int,int>,pair<int,int> > lista[20000];
vector<pair<int,int> > polaczenia[101][101];
bitset<101> bylo[101];

void dfs(int x, int y) {
    bylo[x][y]=1;
    for (int i=0; i<polaczenia[x][y].size(); i++) {
        if (!bylo[polaczenia[x][y][i].first][polaczenia[x][y][i].second]) {
            dfs(polaczenia[x][y][i].first,polaczenia[x][y][i].second);
        }
    }
}

int main() {
    plik.open("lightson.in", fstream::in | fstream::out );
    plik >> n >> m;
    for (int i=0; i<m; i++) {
        //cin >> lista[i].first.first >> lista[i].first.second >> lista[i].second.first >> lista[i].second.second;
        plik >> a >> b >> c >> d;
        polaczenia[a][b].push_back(make_pair(c,d));
    }
    plik.close();
    dfs(1,1);
    //sort(lista, lista+m);
    /*for (int i=0; i<m; i++) {
        //cout << lista[i].first.first << " " << lista[i].first.second << " " << lista[i].second.first << " " << lista[i].second.second << endl;
    }*/
    for (int i=0; i<=101; i++) {
        wyn=wyn+bylo[i].count();
    }
    plik.open("lightson.out", fstream::out);
    plik << wyn << endl;
    plik.close();
    return 0;
}

