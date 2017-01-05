// P - pocet uzlu
const int MAXN = 1005;
int             P;
stack<int>      st;
bool            visited[MAXN];
vi              adj[MAXN], adjinv[MAXN];
vector<vi>      result;
map<string,int> people;

void dfsSCC( int v, bool first )
{
	visited[v] = true;
	if ( !first )
		result[ result.size()-1 ].PB( v );
	FOR( i, 0, adj[v].size()-1 )
		if ( !visited[ adj[v][i] ] )
			dfsSCC( adj[v][i], first );
	if ( first )
		st.push( v );
}
void SCC( )
{
	memset( visited, 0, sizeof(visited) );
	result.clear( );
	st = stack<int> ( );
	// first dfs
	FOR( i, 0, P-1 )
		if( !visited[i] )
			dfsSCC( i, true );
	// invert
	FOR( i, 0, P-1 )
		FOR( j, 0, adj[i].size( )-1 )
			adjinv[ adj[i][j] ].PB( i );
	swap( adj, adjinv );
	memset( visited, 0, sizeof(visited) );
	// second dfs
	while ( !st.empty( ) )
	{
		int v = st.top( );
		st.pop( );
		if ( !visited[v] )
		{
			result.PB( vi( ) );
			dfsSCC( v, false );
		}
	}
}