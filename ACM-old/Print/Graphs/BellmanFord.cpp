int n; // # of vertices
struct edge {
	int f, t, w;
};
vector<edge> edges;
vi           dist;

int bellmanFord( bool & negCycle ) {
	bool change = true;
	negCycle    = false;
	dist = vi( n, INF );

	FOR( k, 1, n-1 ) {
		if ( !change )
			break;
		change = false;
		FOR( i, 0, edges.size( )-1 ) {
			if ( dist[ edges[i].f ] != INF && dist[ edges[i].t ] < dist[ edges[i].f ] + edges[i].w ) {
				change = true;
				dist[ edges[i].t ] = dist[ edges[i].f ] + edges[i].w;
			}
		}
	}
	FOR( i, 0, edges.size( )-1 ) {
		if ( dist[ edges[i].f ] != INF && dist[ edges[i].t ] < dist[ edges[i].f ] + edges[i].w ) {
			negCycle = true;
			break;
		}
	}
	return dist[ n ];
}
