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

struct flow_network {
	int n;
	struct edge { int v; ll c; int rev; };
	vector< vector<edge> > G;
	flow_network(int _n) : n(_n), G(_n) {}
	void add_edge(int u, int v, ll c) {
		edge e = {v, c, G[v].size()}, _e = {u, 0, G[u].size()};
		G[u].push_back(e); G[v].push_back(_e);
	}
	ll dfs(int u, int t, ll f, vector<bool>& vis) {
		if (u == t) return f;
		vis[u] = true;
		for (int i = 0; i < G[u].size(); i++) {
			edge& e = G[u][i];
			if (vis[e.v] || e.c == 0) continue;
			ll d = min(e.c, dfs(e.v, t, min(f, e.c), vis));
			if (d == 0) continue;
			e.c -= d;
			G[e.v][e.rev].c += d;
			return d;
		}
		return 0;
	}
	ll max_flow(int s, int t) {
		ll res = 0;
		for (;;) {
			vector<bool> vis(n);
			ll f = dfs(s, t, INF, vis);
			if (f == 0) return res;
			res += f;
		}
	}
};



int main() {

  flow_network fn(4);
  fn.add_edge(0,1,10);
  fn.add_edge(0,2,20);
  fn.add_edge(1,3,20);
  fn.add_edge(2,3,10);
  fn.add_edge(2,1,5);
  DEB( fn.max_flow( 0, 3) );

  for (int u = 0; u < 4; u++)
		for (int k = 0; k < fn.G[u].size(); k++) {
			flow_network::edge e = fn.G[u][k];
			cout << u << ": " << e.v << " free capacity=" << e.c << endl;
		}


  return 0;
}

