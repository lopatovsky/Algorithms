#include <algorithm>
#include <cctype>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef set<int> si;
typedef set<ii> sii;
#define MP make_pair
#define PB push_back
#define TR(c,it) for( typeof(c.begin()) it = c.begin(); it != c.end(); ++it )
#define TRR(c,it) for( typeof(c.rbegin()) it = c.rbegin(); it != c.rend(); ++it
#define REP(i,a) for (int i = 0; i < (a); i++)
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FORD(i,a,b) for (int i = (a); i >= (b); i--)
inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }

const int INF = 1<<29;
typedef long long int lli;
/*******************************************************/
int MOD = 1000000009;

struct Mat{
    lli m[3][3];

    Mat square(){
        Mat ret;
        REP(i,3)REP(j,3){
            ret.m[i][j] = 0;
            REP(k,3) ret.m[i][j] += m[i][k] * m[k][j];
            ret.m[i][j] %= MOD;
        }
        return ret;
    }

    void print(){
        REP(i,3){
        REP(j,3){
            cout << m[i][j] << ", ";
        }
        cout << endl;
        }
    }
};

struct Vec{
    lli m[3];

    Vec multiply( Mat x){
        Vec ret;
        REP(i,3){
            ret.m[i] = 0;
            REP(k,3) ret.m[i] += x.m[i][k] * m[k];
            ret.m[i] %= MOD;
        }
        return ret;
    }


};

Mat arr[55];



int main() {
    lli n;
    arr[1].m[0][0] = 1;
    arr[1].m[0][1] = 1;
    arr[1].m[0][2] = 1;
    arr[1].m[1][0] = 1;
    arr[1].m[1][1] = 0;
    arr[1].m[1][2] = 0;
    arr[1].m[2][0] = 0;
    arr[1].m[2][1] = 1;
    arr[1].m[2][2] = 0;

    FOR(i,2,54){
        arr[i] = arr[i-1].square();
    }

    while(scanf("%lld", &n)  && n ){
        if(n <= 3 ){ printf("%lld\n", n-1); continue;}
        n -= 3;
        int i = 1;
        Vec out;
        out.m[0] =  2;
        out.m[1] =  1;
        out.m[2] =  0;

        while ( n ){
            if ( n & 1) {
                out = out. multiply( arr[i] );
            }
            n >>= 1;
            i++;
        }
        printf("%lld\n", out.m[0] );

    }
  return 0;
}
