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

inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }

const int INF = 1<<29;
typedef long long ll;
typedef unsigned long long ull;
/*******************************************************/

vi pset(1000);
void initSet( int size ){ pset.resize( size ); REP(i,size) pset[i] = i; }
int findSet ( int i ){ return (pset[i] == i) ? i : (pset[i] = findSet( pset[i] )); }
void unionSet ( int i, int j){   pset[findSet(i)] = findSet(j); }
bool isSameSet ( int i, int j){ return findSet(i) == findSet(j); }


int main() {

     initSet(2000);
    unionSet(1,10);//
    unionSet(3,8);//
    unionSet(2,9);//
    unionSet(2,5);//
    unionSet(5,6);//
    unionSet(4,7);//
    unionSet(3,7);//
    unionSet(1,5);//
    unionSet(7,5);//
    unionSet(1,10);//
    unionSet(4,2);//

    cout << isSameSet(1,10) << endl;
    cout << isSameSet(7,3) << endl;
    cout << isSameSet(1,4) << endl;
    cout << isSameSet(1,11) << endl;

  return 0;
}
