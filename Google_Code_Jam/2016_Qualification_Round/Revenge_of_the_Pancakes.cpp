//
//  main.cpp
//  pancakes
//

#include <iostream>
#include <string>
using namespace std;

int t,wyn;
string tekst;

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin >> t;
    for (int i=0; i<t; i++) {
        wyn=0;
        cin >> tekst;
        for (int i=1; i<tekst.length(); i++) {
            if (tekst[i]!=tekst[i-1]) {
                wyn++;
            }
        }
        if (tekst[tekst.length()-1]=='-') {
            wyn++;
        }
        cout << "Case #" << i+1 << ": " << wyn << endl;
    }
    return 0;
}
