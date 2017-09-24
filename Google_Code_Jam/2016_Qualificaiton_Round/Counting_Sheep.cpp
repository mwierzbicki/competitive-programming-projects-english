//
//  main.cpp
//  counting
//

#include <iostream>
using namespace std;

int t,n,nn,b,lel;
bool bylo[10];
bool stop;

int main() {
    ios_base::sync_with_stdio(0);
    cin >> t;
    for (int i=0; i<t; i++) {
        cin >> n;
        if (n==0) {
            cout << "Case #" << i+1 << ": INSOMNIA\n";
        }
        else {
            b=n;
            stop=false;
            lel=0;
            while(!stop) {
                nn=b;
                while (nn!=0) {
                    if (bylo[nn%10]==0) {
                        lel++;
                        bylo[nn%10]=1;
                    }
                    nn=nn/10;
                }
                if (lel==10) {
                    cout << "Case #" << i+1 << ": " << b << endl;
                    stop=true;
                }
                b=b+n;
            }
            for (int j=0; j<10; j++) {
                bylo[j]=0;
            }
        }
    }
    return 0;
}
