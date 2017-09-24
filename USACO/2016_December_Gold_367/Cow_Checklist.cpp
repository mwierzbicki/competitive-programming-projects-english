#include <cstdio>
#include <algorithm>
#define x first
#define y second
using namespace std;
const int MAX_N=(1e3)+2;
const long long INF=1000000000000000001;
int lh,lg;
long long aa,bb,dyn[MAX_N][MAX_N];
pair<long long,long long> h[MAX_N],g[MAX_N];
char hlg[MAX_N][MAX_N];

long long podl(pair<long long,long long> a, pair<long long,long long> b) {
    return (abs((b.x-a.x)*(b.x-a.x)))+(abs((b.y-a.y)*abs(b.y-a.y)));
}

void gdyn() {
    hlg[1][1]='h';
    hlg[2][1]='g';
    dyn[2][1]=podl(h[1],g[2]);
    for (int i=3; i<=lg+1; i++) {
        dyn[i][1]=dyn[i-1][1]+podl(g[i],g[i-1]);
        hlg[i][1]='g';
    }
    for (int i=2; i<lh; i++) {
        dyn[1][i]=dyn[1][i-1]+podl(h[i],h[i-1]);
        hlg[1][i]='h';
    }
    for (int i=2; i<=lg+1; i++) {
        for (int j=2; j<lh; j++) {
            aa=INF;
            bb=INF;
            if(dyn[i][j-1]!='g') {
                aa=min(aa,dyn[i][j-1]+podl(h[i],h[i-1]));
            }
            else if(dyn[i][j-1]!='h'){
                aa=min(aa,dyn[i][j-1]+podl(h[i],g[i-1]));
            }
            if(dyn[i-1][j]!='g') {
                bb=min(bb,dyn[i-1][j]+podl(g[i],h[i-1]));
            }
            else if(dyn[i-1][j]!='h') {
                bb=min(bb,dyn[i-1][j]+podl(g[i],g[i-1]));
            }
            if (aa==bb) {
                hlg[i][j]='c';
                dyn[i][j]=aa;
            }
            else if (aa>bb) {
                hlg[i][j]='h';
                dyn[i][j]=aa;
            }
            else {
                hlg[i][j]='g';
                dyn[i][j]=bb;
            }
        }
    }
}

int main () {
    freopen("checklist.in","r",stdin);
    scanf("%d%d",&lh,&lg);
    for (int i=1; i<=lh; i++) {
        scanf("%lld%lld",&h[i].x,&h[i].y);
    }
    for (int i=2; i<=lg+1; i++) {
        scanf("%lld%lld",&g[i].x,&g[i].y);
    }
    fclose(stdin);
    gdyn();
    freopen("checklist.out","w",stdout);
    /*for (int i=0; i<=lg+1; i++) {
        for (int j=0; j<lh; j++) {
            printf("%lld ",dyn[i][j]);
        }
        printf("\n");
    }
    for (int i=0; i<=lg+1; i++) {
        for (int j=0; j<lh; j++) {
            printf("%c ",hlg[i][j]);
        }
        printf("\n");
    }*/
    aa=INF;
    //if(hlg[lg+1][lh-1]!='g') {
        aa=min(aa,podl(h[lh],h[lh-1]));
    //}
    //else if (hlg[lg+1][lh-1]!='h') {
        aa=min(aa,podl(h[lh],g[lg+1]));
    //}
    printf("%lld",dyn[lg+1][lh-1]+aa);
    fclose(stdout);
    return 0;
}
