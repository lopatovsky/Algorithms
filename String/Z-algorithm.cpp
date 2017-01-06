#include <algorithm>
#include <cmath>
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
#include <vector>

using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define MP make_pair
#define PB push_back
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
void deba(int * a, int n){ cerr << "| "; REP(i,n) cerr << a[i] << " "; cerr << "|" << endl;}

inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }

const int INF = 1<<29;
typedef long long ll;
typedef unsigned long long ull;
/*******************************************************/
/**      Z-alghoritm

    -problem: for every sufix find how many of first characters match to prefix.

    -example ABACABA
             -010301

    -source: http://e-maxx-eng.github.io/basic/z-function.html

    -other uses:
        Search the substring:  create a new string s= pattern + # + oldString. //probably works also woithout #.
        Number of distinct substrings in a string: See the source.

      Find "alan" in "alalan" ->
      s[] = "alan#alalan"
      z[] = "00100304010"

*/

int main() {

    char s[100005];
    int  z[100005];

    scanf("%s", s);
    int n = strlen(s);

    for (int i = 1, l = 0, r = 0; i < n; i++) {

        if (i <= r) z[i] = min(r - i + 1, z[i - l]);   //string medzi indexami r a l, je ten isty ako prefix.
                                                       //Preto mozme pouzit priamo hodnotu z[i-l],
                                                       //pozor nie vzdy je to tak, lebo nevieme co je za indexom r (napr. moze skoncit string).
                                                       //preto vyberame minimalnu hodnotu.

        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) z[i]++;  //brute force part.

        if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1; //ak dojde k nalezeniu noveho najpravejsieho machingu, aktualizujeme indexy l a r.
    }


    /*Do whatever you need with this*/
    DEBA(z,n);

  return 0;
}
