#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <limits.h>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef set<int> si;
typedef set<ii> sii;
#define MP make_pair
#define PB push_back
#define REP(i,a) for (int i = 0; i < int(a); i++)
#define FOR(i,a,b) for ( int i = int(a); i <= int(b); ++i )
#define FORD(i,a,b) for ( int i = int(a); i >= int(b); --i )
#define TR(c,it) for( typeof(c.begin()) it = c.begin(); it != c.end(); ++it )
#define TRR(c,it) for( typeof(c.rbegin()) it = c.rbegin(); it != c.rend(); ++it )

const int INF = 1<<29;
typedef long long int lli;

const int MAXN = 100;
int  graph[MAXN+1][MAXN+1];
int  residual[MAXN+1][MAXN+1];
bool visited[MAXN+1];
int  parent[MAXN+1];
int  n;

bool bfs( int s, int t )
{
  memset( visited, 0, sizeof( visited ) );
  queue <int> q;
  q.push(s);
  visited[s] = true;
  parent [s] = -1;
  while ( !q.empty( ) )
  {
    int u = q.front();
    q.pop();

    FOR( v, 1, n )
    {
      if ( !visited[v] && residual[u][v] > 0 )
      {
        q.push(v);
        parent [v] = u;
        visited[v] = true;
      }
    }
  }
  return visited[t];
}

int fordFulkerson( int s, int t )
{
  int u, v;

  FOR( u, 1, n )
    FOR( v, 1, n )
      residual[u][v] = graph[u][v];

  int max_flow = 0;  // There is no flow initially
  while ( bfs( s, t ) )
  {
    int path_flow = INT_MAX;
    for ( v = t; v != s; v = parent[v] )
    {
      u = parent[v];
      path_flow = min( path_flow, residual[u][v] );
    }
    for ( v = t; v != s; v = parent[v] )
    {
      u = parent[v];
      residual[u][v] -= path_flow;
      residual[v][u] += path_flow;
    }
    max_flow += path_flow;
  }
  return max_flow;
}

int main( )
{
    int s, t, c, n1, n2, ca;

    for ( int caseNr = 1; scanf("%d", &n) == 1 && n; ++caseNr )
    {
        scanf("%d%d%d", &s, &t, &c);
        // reset
        FOR( i, 1, n )
            FOR( j, 1, n )
                graph[i][j] = residual[i][j] = 0;
        // input
        FOR( j, 0, c-1 )
        {
            scanf("%d%d%d", &n1, &n2, &ca);
            graph[n1][n2] += ca;
            graph[n2][n1] += ca;
        }
        // solve
        printf("Network %d\n", caseNr);
        printf("The bandwidth is %d.\n\n", fordFulkerson( s, t ));
    }
    return 0;
}
