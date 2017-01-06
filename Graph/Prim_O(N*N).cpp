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
void deba(int * a, int n){ cerr << "| "; REP(i,n) cerr << a[i] << " "; cerr << "|" << endl;}


inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }

const int INF = 1<<30;
typedef long long ll;
typedef unsigned long long ull;
/*******************************************************/
//char a[1002][11][11];
int mat[1002][1002];
int len[1002];
int lenI[1002];

int main() {

  DRII(n,m);
  DRII(l,z);

  /*int sum = n*m;

  REP(k,l){
      REP(i,n) scanf("%s", a[k][i]);
  }
  REP(x1,l)FOR(x2,x1+1,l-1){
    int s = 0;
    REP(i,n)REP(j,m) if(a[x1][i][j] != a[x2][i][j]) s++;
    mat[x1][x2] = mat[x2][x1] = min(s*z, n*m);
  }*/


  /// Here start the Prim, at the graf represented by matrix mat.

  REP(i,l)len[i] = INF;
  vii kostra;
  int act = 0;

  REP(i,l-1){
    int mn = INF, mnJ;
    FOR(j,1,l-1){
        if( len[j] < 0  ) continue;

        if (len[j] > mat[act][j]){
          len[j] = mat[act][j];
          lenI[j] = act;
        }

        if( mn > len[j]) { mn = len[j]; mnJ = j; }
    }
    kostra.PB( MP(mnJ,lenI[mnJ]) );
    sum += len[mnJ];
    len[mnJ] = -1;
    act = mnJ;
  }

  printf("%d\n", sum); ///lenghht of the spanning tree
  //printf("1 0\n");
  REP(i,kostra.size()){ ///all edges
    /*if (mat[kostra[i].ff][kostra[i].ss] == n*m)*/ printf("%d %d\n",kostra[i].ff+1, 0);
    /*else printf("%d %d\n",kostra[i].ff+1, kostra[i].ss+1);*/
  }



  return 0;
}
