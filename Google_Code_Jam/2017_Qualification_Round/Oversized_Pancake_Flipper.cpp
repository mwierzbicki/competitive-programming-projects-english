//
//  main.cpp
//  QA_brute
//
//  Created by Marcin Wierzbicki on 08.04.2017.
//

#include <iostream>
using namespace std;
int tt,k,sol;
bool stop=0;
string s;

int main() {
    ios_base::sync_with_stdio(0);
    cin >>tt;
    for (int t=1; t<=tt; t++) {
        cin >>s >>k;
        stop=0; sol=0;
        for (int i=0; i<s.size(); i++) {
            if (s[i]=='-') {
                sol++;
                for (int j=i; j<i+k; j++) {
                    if (j==s.size()) {
                        stop=1;
                        break;
                    }
                    if (s[j]=='-') {
                        s[j]='+';
                    }
                    else {
                        s[j]='-';
                    }
                }
            }
            if (stop) {
                break;
            }
        }
        cout <<"Case #" <<t <<": ";
        if (stop) {
            cout <<"IMPOSSIBLE\n";
        }
        else {
            cout <<sol <<endl;
        }
    }
    return 0;
}
