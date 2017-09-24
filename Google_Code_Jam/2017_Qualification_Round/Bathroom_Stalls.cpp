//
//  main.cpp
//  QC
//
//  Created by Marcin Wierzbicki on 08.04.2017.
//

#include <iostream>
using namespace std;
int tt;
long long n,k,z,zmj,lz,lzmj,cnt,h,tlz,tlzmj,sol,buf;

int main() {
    ios_base::sync_with_stdio(0);
    cin >>tt;
    for (int t=1; t<=tt; t++) {
        cnt=3; h=2;
        cin >>n >>k;
        
        if (k==1) {
            sol=n;
            cout << "Case #" << t << ": " << sol/2 << " " << (sol/2)-((sol+1)%2) << endl;
        }
        else {
            if (n%2) {
                lz=2;
                lzmj=0;
            }
            else {
                lz=1;
                lzmj=1;
            }
            z=n/2;
            zmj=(n/2)-1;
            
            while(cnt<k) {
                
                tlz=0; tlzmj=0;
                if (z%2) {
                    //jezeli z jest nieparzyste -> z-1 jest parzyste
                    //nowa liczba z +=2*obecna liczba z
                    //nowa liczba z-1 += 0
                    //nowa liczba z +=obecna liczba z-1
                    //nowa liczba z-1 +=obecna liczba z-1
                    tlz=(lz*2)+lzmj;
                    tlzmj=lzmj;
                }
                else {
                    //jezeli z jest parzyste -> z-1 jest nieparzyste
                    //nowa liczba z += obecna liczba z
                    //nowa liczba z-1 += obecna liczba z
                    //nowa liczba z += 0
                    //nowa liczba z-1 += 2*obecna liczba z-1
                    tlz=lz;
                    tlzmj=(lzmj*2)+lz;
                }
                buf=z/2;
                z=buf;
                zmj=buf-1;
                lz=tlz;
                lzmj=tlzmj;
                h=h*2;
                cnt=cnt+h;
            }
            k=k-(cnt-h);
            if (k>lz) {
                sol=zmj;
            }
            else {
                sol=z;
            }
            cout << "Case #" << t << ": " << sol/2 << " " << (sol/2)-((sol+1)%2) << endl;
        }
    }
    return 0;
}
