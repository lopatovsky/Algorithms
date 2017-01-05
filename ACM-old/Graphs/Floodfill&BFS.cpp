int  neigh[8][2] = {
	{-1,0},
	{0,1},
	{1,0},
	{0,-1},
	{-1,-1},
	{-1,1},
	{1,1},
	{1,-1}
};
int  rows, cols;
char image[55][55];

void floodFill( int r, int c )
{
	queue<ii> q;

	q.push( MP( r, c ) );
	while ( !q.empty( ) )
	{
		ii p = q.front( );
		q.pop( );
		if ( image[ p.first ][ p.second ] != 'X' )
			continue;
		image[ p.first ][ p.second ] = '*';
		FOR( i, 0, 3 )
			q.push( MP( p.first + neigh[i][0], p.second + neigh[i][1] ) );
	}
}
int bfs( int r, int c )
{
	int count = 0;

	queue<ii> q;

	q.push( MP( r, c ) );
	while ( !q.empty( ) )
	{
		ii p = q.front( );
		q.pop( );
		if ( image[ p.first ][ p.second ] == '.' )
			continue;
		if ( image[ p.first ][ p.second ] == 'X' )
		{
			++count;
			floodFill( p.first, p.second );
		}
		image[ p.first ][ p.second ] = '.';
		FOR( i, 0, 3 )
			q.push( MP( p.first + neigh[i][0], p.second + neigh[i][1] ) );
	}
	return count;
}
void solve( vi & res )
{
	FOR( i, 1, rows )
		FOR( j, 1, cols )
			if ( image[i][j] != '.' )
				res.PB( bfs( i, j ) );
}
int main( )
{
	vi result;

	for ( int caseNr = 1; scanf("%d%d ", &cols, &rows) == 2; ++caseNr )
	{
		if ( !rows && !cols )
			break;
		result.clear( );
		FOR( i, 1, rows )
			gets( image[i]+1 );
		FOR( i, 0, cols+1 )
			image[0][i] = image[rows+1][i] = '.';
		FOR( i, 0, rows+1 )
			image[i][0] = image[i][cols+1] = '.';
		solve( result );
		sort( result.begin( ), result.end( ) );
		printf("Throw %d\n", caseNr);
		FOR( i, 0, result.size( )-1 )
			printf("%d%c", result[i], (i == result.size( )-1) ? '\n' : ' ');
		printf("\n");
	}

	return 0;
}