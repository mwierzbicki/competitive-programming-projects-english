#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;
int t;
int n,r,o,y,g,b,v,cmax,ogn;
char last,first,nlast;
string sol;

int main () {
    //brute
    ios_base::sync_with_stdio(0);
    cin >> t;
    for (int tt=0; tt<t; tt++) {
        cin >>n >>r >>o >>y >>g >>b >>v;
        ogn=n; sol=""; last='N'; first='N';
        if ((r>(ogn/2)) || (y>(ogn/2)) || (b>(ogn/2))) {
            sol="IMPOSSIBLE";
        }
        else {
            while (n>0) {
                cmax=0;
                if (r>cmax && last!='R') {
                    cmax=r;
                    nlast='R';
                }
                if (y>cmax && last!='Y') {
                    cmax=y;
                    nlast='Y';
                }
                if (b>cmax && last!='B') {
                    cmax=b;
                    nlast='B';
                }
                last=nlast;
                if (last=='R') {
                    r--;
                }
                else if (last=='Y') {
                    y--;
                }
                else if (last=='B') {
                    b--;
                }
                sol+=last;
                --n;
            }
            --ogn;
            if (sol[0]==sol[ogn]) {
                if (ogn>0) {
                    swap(sol[ogn],sol[ogn-1]);
                }
            }
        }
        cout << "Case #" << tt+1 << ": " << sol << endl;
    }
    return 0;
}
