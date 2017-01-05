#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <limits>
#include <set>
#include <stack>
#include <queue>
#include <vector>
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef set<int> si;
typedef set<ii> sii;
#define MP make_pair
#define PB push_back
#define REP(i, a, b) for ( int i = int(a); i <= int(b); ++i )
#define REPR(i, a, b) for ( int i = int(a); i >= int(b); --i )
#define TR(c,it) for( typeof(c.begin()) it = c.begin(); it != c.end(); ++it )
#define TRR(c,it) for( typeof(c.rbegin()) it = c.rbegin(); it != c.rend(); ++it )

const int INF = 1000000000;

struct vertex
{
       vertex    ( double _x, double _y ) { x = _x; y = _y; };
  void addEdge   ( int v, int w ) { adj.PB( v ); wei.PB( w ); };
  void removeEdge( int v );
  vi     adj;  // adjacent vertices
  vi     wei;  // edge weight
  double x, y; // coordinates of vertex
};
void vertex::removeEdge( int v )
{
  int pos = find( adj.begin( ), adj.end( ), v ) - adj.begin( );
  vi::iterator it1 = adj.begin( );
  vi::iterator it2 = wei.begin( );
  advance( it1, pos );
  advance( it2, pos );
  adj.erase( it1 );
  wei.erase( it2 );
}

struct edge
{
  edge( int f, int t, double w = 0.0 ) { from = f, to = t; wei = w; };
  bool   operator<( const edge & e ) const { return wei > e.wei; }; // invertovany operator kvuli priority_queue
  double wei;
  int    from, to;
};
// matice sousednosti (na vahy hran) a seznamy sousednosti
struct graph
{
  vector<vertex> vert;
  double distance     ( double x1, double y1, double x2, double y2 ) { return sqrt( (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1) ); };
  double distVert     ( vertex & v1, vertex & v2 ) { return distance( v1.x, v1.y, v2.x, v2.y ); };
  void   addVertex    ( double x = 0, double y = 0 ) { vert.PB( vertex( x, y ) ); };
  void   addEdge      ( int v1, int v2, int w = 0 ) { vert[v1].addEdge( v2, w ); }; // undirected
  void   removeEdge   ( int v1, int v2 ) { vert[v1].removeEdge( v2 ); };

  si     articulations;
  sii    bridges;
  vi     low, pre;
  int    cnt;
  void   artbrid      ( ); // find articulations and bridges
  void   dfsAB        ( int u, int v );

  vi     topsorted, colors;
  void   topsort      ( );
  void   dfsTop       ( int n );

  vi     group;
  int    findGrp      ( int v ) { if ( group[v] != v ) group[v] = findGrp( group[v] ); return group[v]; }
  void   linkGrps     ( int v1, int v2 ) { group[ findGrp( v2 ) ] = findGrp( v1 ); };
  double kruskal      ( );
  double prim         ( );

  vector<bool> visited;
  int    components   ( );
  void   compDFS      ( int v );

  vector<vi> matrix, path;
  void   adjMatrix    ( );
  void   initPath     ( );
  void   showPath     ( int i, int j );
  void   floydWarshall( );
  //vector<bool> visited;
  stack<int> vertices;
  vector<vi> SCClist;
  void   invertMatrix ( );
  void   SCCDFS       ( int v, bool firstDFS );
  void   kosarajuSCC  ( ); // strongly connected components

  void   dijkstra     ( );
  void   bellmanFord  ( );
  void   johnson      ( );

  void   edmondKarp   ( );
  void   maxMatching  ( );

  // vector< vector<double> > matrix; // matice sousednosti, pri inicializaci pro konkretni pocet vrcholu
};

void   graph::artbrid      ( )
{
  articulations.clear( ), bridges.clear( );
  low = pre = vi( vert.size( ), -1 );
  cnt = 0;
  REP( i, 0, vert.size( ) - 1 )
    if ( pre[i] == -1 )
      dfsAB( i, i );
}
void   graph::dfsAB        ( int u, int v )
{
  int children = 0;
  low[v] = pre[v] = ++cnt;
  TR( vert[v].adj, w )
  {
    if ( pre[*w] == -1 )
    {
      ++children;
      dfsAB( v, *w );
      // update low number
      low[v] = min( low[v], low[*w] );
      // bridge found, save it that first number is less or equal
      if ( low[*w] == pre[*w] )
        bridges.insert( MP( min( v, *w ), max( *w, v ) ) );
      // non-root of DFS is an articulation point if low[w] >= pre[v]
      if ( low[*w] >= pre[v] && u != v )
        articulations.insert( v );
    }
    // update low number - ignore reverse of edge leading to v
    else if ( *w != u )
      low[v] = min( low[v], pre[*w] );
  }
  // root of DFS is an articulation point if it has more than 1 child
  if ( u == v && children > 1 )
    articulations.insert( v );
}

void   graph::topsort      ( )
{
  colors = vi( vert.size( ), 0 );
  REP( i, 0, vert.size( )-1 )
    if ( !colors[i] )
      dfsTop( i );
}
void   graph::dfsTop       ( int n )
{
  colors[n] = 1;
  REP( i, 0, vert[n].adj.size( )-1 )
    if ( !colors[ vert[n].adj[i] ] )
      dfsTop( vert[n].adj[i] );
  topsorted.PB( n );
}

double graph::kruskal      ( )
{
  double spanningTree = 0.0;
  priority_queue<edge> pq;
  group.resize( vert.size( ) );
  REP( i, 0, vert.size( )-1 )
    group[i] = i;

  // pridani existujich hran
  // REP( i, 0, vert.size( ) - 1 )
  //   REP( j, 0, vert[i].adj.size( ) - 1 )
  //     pq.push( edge( i, vert[i].adj[j], vert[i].wei[j] ) );

  // pridani vsech moznych hran na zaklade souradnic
  REP( i, 0, vert.size( )-1 )
    REP( j, i + 1, vert.size( )-1 )
      pq.push( edge( i, j, distVert( vert[i], vert[j] ) ) );

  while ( !pq.empty( ) )
  {
    edge e = pq.top( );
    pq.pop( );
    if ( findGrp( e.from ) == findGrp( e.to ) )
      continue;
    linkGrps( e.from, e.to );
    spanningTree += e.wei;
  }
  return spanningTree;
}
double graph::prim         ( )
{
  double spanningTree = 0.0;
  priority_queue<edge> pq;
  group = vi( vert.size( ), 0 );

  // pridani existujicich hran
  // group[0] = 1;
  // REP( i, 0, vert[0].adj.size( )-1 )
  //   pq.push( edge( 0, vert[0].adj[i], vert[0].wei[i] ) );

  // pridani vsech moznych hran na zaklade souradnic
  group[0] = 1;
  REP( i, 1, vert.size( )-1 )
    pq.push( edge( 0, i, distVert( vert[0], vert[i] ) ) );

  while ( !pq.empty( ) )
  {
    edge e = pq.top( );
    pq.pop( );
    if ( group[e.to] )
      continue;
    group[e.to]    = 1;
    spanningTree += e.wei;
    // pridani existujicich hran
    // REP( i, 0, vert[e.to].adj.size( )-1 )
    //   pq.push( edge( e.to, vert[e.to].adj[i], vert[e.to].wei[i] ) );

    // pridani vsech moznych hran na zaklade souradnic
    REP( i, 0, vert.size( )-1 )
      if ( !group[i] )
        pq.push( edge( e.to, i, distVert( vert[e.to], vert[i] ) ) );
  }
  return spanningTree;
}

int    graph::components   ( )
{
  int compCnt = 0;
  visited = vector<bool> ( vert.size( ), 0 );

  REP( i, 0, vert.size( )-1 )
    if ( !visited[i] )
    {
      ++compCnt;
      compDFS( i );
    }
  return compCnt;
}
void   graph::compDFS      ( int v )
{
  visited[v] = 1;
  REP( i, 0, vert[v].adj.size( )-1 )
    if ( !visited[ vert[v].adj[i] ] )
      compDFS( vert[v].adj[i] );
}

void   graph::adjMatrix    ( )
{
  matrix = vector<vi> ( vert.size( ), vi( vert.size( ), INF ) );
  REP( i, 0, vert.size( )-1 )
    REP( j, 0, vert[i].adj.size( )-1 )
      matrix[i][j] = vert[i].wei[j];
  REP( i, 0, vert.size( )-1 )
    matrix[i][i] = 0;
}
void   graph::initPath     ( )
{
  path = vector<vi> ( vert.size( ), vi( vert.size( ), -1 ) );
  REP( i, 0, vert.size( )-1 )
    REP( j, 0, vert.size( )-1 )
      if( matrix[i][j] != INF )
        path[i][j] = j;
}
void   graph::showPath     ( int i, int j )
{
  if ( i == j )
  {
    printf("->%d", i);
    return;
  }
  printf("->%d", i);
  showPath( path[i][j], j );
}
void   graph::floydWarshall( )
{
  initPath( );
  REP( k, 0, vert.size( )-1 )
    REP( i, 0, vert.size( )-1 )
      REP( j, 0, vert.size( )-1 )
        if ( matrix[i][k] != INF && matrix[k][j] != INF && matrix[i][k] + matrix[k][j] < matrix[i][j] )
        {
          matrix[i][j] = matrix[i][k] + matrix[k][j];
          path  [i][j] = path  [i][k];
        }
}
void   graph::invertMatrix ( )
{
  REP( i, 0, matrix.size( )/2 )
    REP( j, 0, matrix.size( )/2 )
      swap( matrix[i][j], matrix[j][i] );
}
void   graph::SCCDFS       ( int v, bool firstDFS )
{
  visited[v] = true;
  if ( !firstDFS )
    SCClist.rbegin( )->PB( v );
  // Recur for all the vertices adjacent to this vertex
  REP( i, 0, vert.size( )-1 )
    if ( matrix[v][i] != INF && matrix[v][i] && !visited[i] )
      SCCDFS( i, firstDFS );
  // All vertices reachable from v are processed by now, push v to Stack
  if ( firstDFS )
    vertices.push( v );
}
void   graph::kosarajuSCC  ( )
{
  adjMatrix( );
  vertices = stack<int> ( );
  visited  = vector<bool> ( vert.size( ), 0 );
  SCClist.clear( );

  // Fill vertices in stack according to their finishing times
  REP( i, 0, vert.size( )-1 )
    if( !visited[i] )
      SCCDFS( i, true );
  // Create a reversed graph
  invertMatrix( );
  // Mark all the vertices as not visited (For second DFS)
  visited = vector<bool> ( vert.size( ), 0 );
  // Now process all vertices in order defined by Stack
  while ( !vertices.empty( ) )
  {
    int v = vertices.top( );
    vertices.pop( );
    // Print Strongly connected component of the popped vertex
    if ( visited[v] == false )
    {
      SCClist.PB( vi( ) );
      SCCDFS( v, false );
    }
  }
}

void   graph::edmondKarp   ( )
{
  map<int, int> p; // parent map to reconstruct path
  int f, s, t;     // global variables
  int max_flow = 0;
  while ( true )
  { // this will be run max O(VE) times
  f = 0;
  queue<int> q; map<int, int> dist; // O(E) BFS and record path p
  q.push(s); dist[s] = 0; // start from source
  while (!q.empty()) {
  int u = q.front(); q.pop(); // queue: layer by layer!
  if (u == t) break; // modification 1: reach sink t, stop BFS
  TRvii (AdjList[u], v) // for each neighbours of u
  // modification 2: also check AdjMat as edges may disappear
  if (AdjMat[u][v->first] > 0 && !dist.count(v->first)) {
  dist[v->first] = dist[u] + 1; // then v is reachable from u
  q.push(v->first); // enqueue v for next steps
  p[v->first] = u; // modification 3: parent of v->first is u
  }
  }
  augmentPath(t, INF); // path augmentation in O(V)
  if (f == 0) break; // seems that we cannot pass any more flow
  max_flow += f;
  }
  printf("Max flow = %d\n", max_flow);

  void augmentPath(int v, int minEdge) {
if (v == s) { // managed to get back to source
f = minEdge; // minEdge of the path
return;
}
else if (p.count(v)) { // augment if there is a path
// we need AdjMat for fast lookup here
augmentPath(p[v], min(minEdge, AdjMat[p[v]][v]));
AdjMat[p[v]][v] -= f; // forward edges -> decrease
AdjMat[v][p[v]] += f; // backward edges -> increase
} } // for more details why we must do that, consult references!
}

int main( )
{
  graph g;

  REP( i, 0, 4 )
    g.addVertex( );
  g.addEdge( 0, 2, 1 );
  g.addEdge( 2, 1, 1 );
  g.addEdge( 1, 0, 1 );
  g.addEdge( 0, 3, 1 );
  g.addEdge( 3, 4, 1 );
  // g.kosarajuSCC( );
  g.adjMatrix( );
  REP( i, 0, g.vert.size( )-1 )
  {
    REP( j, 0, g.vert.size( )-1 )
      printf("%10d ", g.matrix[i][j] );
    printf("\n");
  }

  // REP( i, 0, g.SCClist.size( )-1 )
  // {
  //   REP( j, 0, g.SCClist[i].size( )-1 )
  //     printf("%d ", g.SCClist[i][j]);
  //   printf("\n");
  // }

  return 0;
}
