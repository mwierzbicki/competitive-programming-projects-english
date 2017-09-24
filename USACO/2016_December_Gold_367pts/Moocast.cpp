#include <cstdio>
#include <algorithm>
#define x first
#define y second
#define w first
#define ind1 second.first
#define ind2 second.second
#define LL long long
#define PII pair<int,int>
#define PLL pair<LL,LL>
using namespace std;
const int MAX_N=1001;
const int MAX_NS=MAX_N*MAX_N;
bool halt;
int n,tab[MAX_N],roz[MAX_N];
long long wsko;
PLL c[MAX_N];
pair<long long, pair<int,int> > odl[MAX_NS];

long long podl(PLL a, PLL b) {
    return (abs((b.x-a.x)*(b.x-a.x)))+(abs((b.y-a.y)*abs(b.y-a.y)));
}

int Find(int x) {
    if (tab[x]==x) {
        return x;
    }
    tab[x]=Find(tab[x]);
    return tab[x];
}

void Union (int a, int b) {
    a=Find(a);
    b=Find(b);
    if (roz[a]<roz[b]) {
        tab[a]=b;
        roz[b]+=roz[a];
    }
    else {
        tab[b]=a;
        roz[a]+=roz[b];
    }
    if (roz[a]==n || roz[b]==n) {
        halt=1;
    }
    return;
}

int main () {
    freopen("moocast.in","r",stdin);
    scanf("%d",&n);
    for (int i=1; i<=n; i++) {
        tab[i]=i;
        roz[i]=1;
    }
    for (int i=1; i<=n; i++) {
        scanf("%lld%lld",&c[i].x,&c[i].y);
    }
    fclose(stdin);
    freopen("moocast.out","w",stdout);
    for (int i=1; i<=n; i++) {
        for (int j=i+1; j<=n; j++) {
            odl[wsko].w=podl(c[i],c[j]);
            odl[wsko].ind1=i;
            odl[wsko].ind2=j;
            wsko++;
        }
    }
    sort(odl,odl+wsko);
    for (int i=0; i<wsko; i++) {
        //cout << odl[i].w << " " << odl[i].i1 << " " << odl[i].i2 << endl;
        if (Find(odl[i].ind1)!=Find(odl[i].ind2)) {
            Union(odl[i].ind1,odl[i].ind2);
        }
        //cout << tab[odl[i].i1] << " " << tab[odl[i].i2] << endl;
        if (halt) {
            printf("%lld",odl[i].w);
            fclose(stdout);
            return 0;
        }
    }
}
