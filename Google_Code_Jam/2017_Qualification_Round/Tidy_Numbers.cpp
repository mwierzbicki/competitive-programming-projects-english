//
//  main.cpp
//  QB
//
//  Created by Marcin Wierzbicki on 08.04.2017.
//

#include <iostream>
using namespace std;
int tt;
string s;

int main() {
    ios_base::sync_with_stdio(0);
    cin >>tt;
    for (int t=1; t<=tt; t++) {
        cin >>s;
        for (int i=0; i<s.size()-1; i++) {
            if (s[i]>s[i+1]) {
                s[i]--;
                for (int j=i+1; j<s.size(); j++) {
                    s[j]='9';
                }
                i=-1;
            }
        }
        if (s[0]=='0') {
            s.erase(s.begin());
        }
        cout << "Case #" << t << ": " <<s <<endl;
    }
    return 0;
}
