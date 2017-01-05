si     articulations;
sii    bridges;
vi     low, pre;

void   graph::artbrid( )
{
  articulations.clear( ), bridges.clear( );
  low = pre = vi( vert.size( ), -1 );
  cnt = 0;
  REP( i, 0, vert.size( ) - 1 )
    if ( pre[i] == -1 )
      dfsAB( i, i );
}
void   graph::dfsAB( int u, int v )
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