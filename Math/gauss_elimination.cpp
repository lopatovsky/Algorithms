#include <bits/stdc++.h>
#include <unistd.h>

using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define MP make_pair
#define PB push_back
#define ff first
#define ss second
#define TR(it,c) for( typeof(c.begin()) it = c.begin(); it != c.end(); ++it )
#define TRR(it,c) for( typeof(c.rbegin()) it = c.rbegin(); it != c.rend(); ++it
#define REP(i,a) for (int i = 0; i < (a); i++)
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FORD(i,a,b) for (int i = (a); i >= (b); i--)

#define DRI(a) int a; scanf("%d", &a);
#define DRII(a, b) int a, b; scanf("%d %d", &a, &b);
#define DRIII(a, b, c) int a, b, c; scanf("%d %d %d", &a, &b, &c);
#define RI(a) scanf("%d", &a);
#define RII(a, b) scanf("%d %d", &a, &b);
#define RIII(a, b, c) scanf("%d %d %d", &a, &b, &c);
#define MM(arr, num) memset((arr), (num), sizeof((arr)))
#define DEB(x) cerr << ">>> " << (#x) << " -> " << (x) << endl;
#define DEBA(x,n) cerr << (#x) << " "; deba((x),(n));
//#define double float
void deba( double * a, int n){ cerr << "| "; REP(i,n) cerr << a[i] << " "; cerr << "|" << endl;}


inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }

const int INF = 1<<30;
typedef long long ll;
typedef unsigned long long ull;

/*******************************************************/


///expect arrays mat[n][n], b[n], sol[n]; //n^3, numerically unstable.

void gauss(){

 FOR(i, 1, n-1){
        FOR( j, 0, i-1){
            double a = - mat[j][j];
            double d =   mat[i][j];
            FOR(k, j, n-1) mat[i][k] = a * mat[i][k] + d * mat[j][k];
            b[i] = a * b[i] + d * b[j];
        }
    }

    //REP(i,n){ REP(j,n) cout << mat[i][j] << " "; cout << endl; }
    //REP(i,n) cout << b[i] << "-"; cout << endl;

    FORD(i,n-1,0){
        double v = b[i];
        FORD(j,n-1,i+1) v -= sol[j] * mat[i][j];
        sol[i] = v / mat[i][i];
    }

    REP(i,n) cout << sol[i] << " "; cout << endl;

}

int main(){

    return 0;

}
