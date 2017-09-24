#include <iostream>
#include <algorithm>
#include <iomanip>
#define k first
#define s second
using namespace std;
const int MAX_N=(1e3);
int d,n,t;
pair<int,int> ks[MAX_N];
double ttime[MAX_N];
double mmax;

int main () {
    ios_base::sync_with_stdio(0);
    cin >> t;
    for (int tt=0; tt<t; tt++) {
        cin >> d >> n;
        mmax=0;
        for (int i=0; i<n; i++) {
            cin >> ks[i].k >> ks[i].s;
        }
        sort(ks,ks+n,greater<pair<int,int> >());
        for (int i=0; i<n; i++) {
            ttime[i]=double(d-ks[i].k)/double(ks[i].s);
        }
        for (int i=0; i<n; i++) {
            for (int j=i+1; j<n; j++) {
                if (ttime[j]<ttime[i]) {
                    ttime[j]=ttime[i];
                }
            }
        }
        for (int i=0; i<n; i++) {
            mmax=max(mmax,ttime[i]);
        }
        cout << "Case #" << tt+1 << ": " << setprecision(6) << fixed << d/mmax << endl;
    }
    return 0;
}
