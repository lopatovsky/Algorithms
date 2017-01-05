const int MAXN = 55;
int  graph[MAXN][MAXN];
int  residual[MAXN][MAXN];
bool visited[MAXN];
int  parent[MAXN];
int  n;
vii  result;

bool bfs( int s, int t ) {
  memset( visited, 0, sizeof( visited ) );
  queue <int> q;

  q.push(s);
  visited[s] = true;
  parent [s] = -1;
  while ( !q.empty( ) ) {
    int u = q.front( );
    q.pop( );

    FOR( v, 1, n ) {
      if ( !visited[v] && residual[u][v] > 0 ) {
        q.push(v);
        parent [v] = u;
        visited[v] = true;
      }
    }
  }
  return visited[t];
}
void dfs( int s ) {
  visited[s] = true;
  FOR( i, 1, n )
    if ( residual[s][i] && !visited[i] )
      dfs( i );
}
void mincut( int s ) {
  result.clear( );
  memset( visited, 0, sizeof( visited ) );
  dfs( s );
  FOR( i, 1, n )
    FOR( j, 1, n )
      if ( visited[i] && !visited[j] && graph[i][j] )
        result.PB( MP( i, j ) );
}
int fordFulkerson( int s, int t ) {
  int u, v;
  int max_flow = 0;  // There is no flow initially

  memcpy( residual, graph, sizeof( graph ) );

  while ( bfs( s, t ) ) {
    int path_flow = INT_MAX;
    for ( v = t; v != s; v = parent[v] ) {
      u = parent[v];
      path_flow = min( path_flow, residual[u][v] );
    }
    for ( v = t; v != s; v = parent[v] ) {
      u = parent[v];
      residual[u][v] -= path_flow;
      residual[v][u] += path_flow;
    }
    max_flow += path_flow;
  }
  return max_flow;
}

int main( ) {
  int m, f, t, c;

  for ( int caseNr = 1; scanf("%d%d", &n, &m) == 2; ++caseNr ) {
    if ( !n && !m )
      break;
    memset( graph, 0, sizeof( graph ) );

    FOR( i, 1, m ) {
      scanf("%d%d%d", &f, &t, &c);
      graph[f][t] += c;
      graph[t][f] += c;
    }
    // solve
    fordFulkerson( 1, 2 );
    mincut( 1 );
    FOR( i, 0, result.size( )-1 )
      printf("%d %d\n", result[i].first, result[i].second);
    printf("\n");
  }
  return 0;
}