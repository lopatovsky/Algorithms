const int MAXN = 1000005;
struct node {
	double x, y;
	int parent, rank;
};
struct edge {
	bool operator<( const edge & e ) const { return w < e.w; }
	int f, t;
	double w;
};
vector<node> nodes;
vector<edge> edges;

int find( int n ) {
	if ( nodes[n].parent != n )
		nodes[n].parent = find( nodes[n].parent );
	return nodes[n].parent;
}
void link ( int n1, int n2 ) {
	int x = find( n1 );
	int y = find( n2 );
	if ( nodes[x].rank < nodes[y].rank )
		nodes[x].parent = y;
	else if ( nodes[y].rank < nodes[x].rank )
		nodes[y].parent = x;
	else {
		nodes[y].parent = x;
		++nodes[x].rank;
	}
}
int kruskal( ) {
	double spanTree = 0;

	sort( edges.begin( ), edges.end( ) );
	FOR( i, 0, edges.size( )-1 ) {
		if ( find( edges[i].f ) == find( edges[i].t ) )
			continue;
		link( edges[i].f, edges[i].t );
		spanTree += edges[i].w;
	}
	return spanTree;
}