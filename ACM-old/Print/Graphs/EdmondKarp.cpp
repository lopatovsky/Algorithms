const int MAXN = 105;

int n, f, s, t; // # of nodes, flow, source, tank

vi  AdjList[MAXN];
int AdjMat[MAXN][MAXN];
int dist[MAXN];
int parent[MAXN];

void augmentPath( int v, int minEdge ) {
  if ( v == s ) { // managed to get back to source
    f = minEdge; // minEdge of the path
    return;
  }
  else if ( parent[v] != -1 ) { // augment if there is a path
    // we need AdjMat for fast lookup here
    augmentPath( parent[v], min( minEdge, AdjMat[parent[v]][v] ) );
    AdjMat[parent[v]][v] -= f; // forward edges -> decrease
    AdjMat[v][parent[v]] += f; // backward edges -> increase
  }
} // for more details why we must do that, consult references!
int edmondKarp( ) {
  int max_flow = 0;
  while ( 1 ) { // this will be run max O(VE) times
    f = 0;
    queue<int> q;
    // map<int, int> dist; // O(E) BFS and record path p
    q.push(s);
    FOR( i, 1, n )
      dist[i] = parent[i] = -1;
    dist[s] = 0; // start from source
    while ( !q.empty( ) ) {
      int u = q.front( );
      q.pop( ); // queue: layer by layer!
      if ( u == t )
        break; // modification 1: reach sink t, stop BFS
      FOR( i, 0, AdjList[u].size( )-1 ) {
        int v = AdjList[u][i];
        if ( AdjMat[u][v] > 0 && dist[v] == -1 ) {
          dist[v] = dist[u] + 1; // then v is reachable from u
          q.push(v); // enqueue v for next steps
          parent[v] = u; // modification 3: parent of v->first is u
        }
      }
    }
    augmentPath( t, INF ); // path augmentation in O(V)
    if ( f == 0 )
      break; // seems that we cannot pass any more flow
    max_flow += f;
  }
  return max_flow;
}
int main( ) {
  int c, n1, n2, ca;
  for ( int caseNr = 1; scanf("%d", &n) == 1 && n; ++caseNr ) {
    scanf("%d%d%d", &s, &t, &c);
    // reset
    memset( AdjMat, 0, sizeof( AdjMat ) );
    FOR( i, 0, MAXN-1 )
      AdjList[i].clear( );
    // input
    FOR( j, 0, c-1 )
    {
      scanf("%d%d%d", &n1, &n2, &ca);
      AdjList[n1].PB( n2 );
      AdjList[n2].PB( n1 );
      AdjMat[n1][n2] += ca;
      AdjMat[n2][n1] += ca;
    }
    // edmondKarp
    printf("Network %d\n", caseNr);
    printf("The bandwidth is %d.\n\n", edmondKarp( ));
  }
  return 0;
}
