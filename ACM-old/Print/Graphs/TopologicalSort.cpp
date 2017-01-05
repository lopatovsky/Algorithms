const int MAXN = 105;
int  n;
bool visited[MAXN];
vi   adj[MAXN];
vi   topsorted;

void dfsTop( int v )
{
	visited[v] = 1;
	FOR( i, 0, adj[v].size( )-1 )
		if ( !visited[ adj[v][i] ] )
			dfsTop( adj[v][i] );
	topsorted.PB( v );
}
void topsort( )
{
	topsorted.clear( );
	memset( visited, 0, sizeof( visited ) );

	FOR( i, 1, n )
		if ( !visited[i] )
			dfsTop( i );
}