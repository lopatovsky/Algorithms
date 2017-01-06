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
typedef pair<int,long long> ii;
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
ii a[123456];

bool comp(ii x, ii y){return x.ss < y.ss;}

ll xdist(int p,int q){return ((ll)(a[p].ff-a[q].ff))*((ll)(a[p].ff-a[q].ff));}

ll dist(int p,int q ){
  return xdist(p,q) + (a[p].ss-a[q].ss)*(a[p].ss-a[q].ss);
}

ll xdist2 (int p,int q){return (p-q)*(p-q);}
ll dist2(ii p,ii q ){
  return xdist2(p.ff,q.ff) + xdist2(p.ss,q.ss);
}

ll minDist(int b, int e){

  if ( e - b < 3){
    sort(a+b,a+e,comp);
    return (e - b < 2) ? dist(b,e) : min( dist(b,e) , min(dist(b,b+1), dist(b+1,e)) );
  }
  int b2 = b+ (e-b)/2;
  int e1 = b2 + 1;

  ll mn = min( minDist(b,b2), minDist(e1,e));

  vii r;

  /*FOR(i,b,b2) if( xdist(i,e1) < mn )l.PB(a[i]);
  FOR(i,e1,e) if( xdist(i,b2) < mn )r.PB(a[i]);*/ //staci to robit po mergovani
  int mid = a[e1].ff;
  inplace_merge(a+b,a+e1,a+e,comp);
  FOR(i,b,e) if( xdist2(a[i].ff,mid) < mn )r.PB(a[i]);
  REP(i,r.size()) FOR(j,i+1,min(i+12,(int)r.size()-1)){ mn = min(mn, dist2(r[i],r[j]));}

  return mn;

}

int main() {

  DRI(n);
  REP(i,n)RI(a[i].ff);
  ll s = 0;
  REP(i,n){ s+= a[i].ff; a[i].ss=s; a[i].ff = i;}

  cout << minDist(0,n-1) << endl;


  return 0;
}
