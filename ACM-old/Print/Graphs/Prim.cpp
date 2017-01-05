struct edge
{
  edge( int f, int t, double w = 0.0 ) { from = f, to = t; wei = w; };
  bool   operator<( const edge & e ) const { return wei > e.wei; }; // invertovany operator kvuli priority_queue
  double wei;
  int    from, to;
};

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