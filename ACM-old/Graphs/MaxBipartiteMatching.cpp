const int MAXN = 105;
vii blue, red;
int graph[MAXN][MAXN];
int k;

int sqr( int x ) {
  return x * x;
}

int dist( int r, int b ) {
  return ceil( sqrt( sqr( red[r].first - blue[b].first ) + sqr( red[r].second - blue[b].second ) ) );
}

bool bpm( int u, bool seen[], int matchR[], int edge ) {
  FOR( v, red.size( ), red.size( )+blue.size( )-1 ) {// Try every job one by one
    if ( graph[u][v] <= edge && !seen[v] ) {// if applicant u interested in job v and v not visited
      seen[v] = true;
      // If job 'v' is not assigned to an applicant OR
      // previously assigned applicant for job v (which is matchR[v]) 
      // has an alternate job available. 
      // Since v is marked as visited in the above line, matchR[v] 
      // in the following recursive call will not get job 'v' again
      if ( matchR[v] < 0 || bpm( matchR[v], seen, matchR, edge ) ) {
        matchR[v] = u;
        return true;
      }
    }
  }
  return false;
}

int maxBPM( int edge ) {
  int matchR[MAXN]; // array to keep track of assigned, -1 => nobody assigned
  memset( matchR, 0xff, sizeof( matchR ) );// Initially all jobs are available
  int result = 0; // Count of jobs assigned to applicants
  FOR( u, 0, red.size( )-1 ) {
    bool seen[ red.size( )+blue.size( ) ]; // Mark all jobs as not seen for next applicant.
    memset( seen, 0, sizeof(seen) );
    if ( bpm( u, seen, matchR, edge ) ) // Find if the applicant 'u' can get a job
      result++;
  }
  return result;
}

int solve( ) {
  int mini = INT_MAX, maxi = INT_MIN;
  memset( graph, 0, sizeof( graph ) );
  FOR( i, 0, red.size( )-1 )
    FOR( j, 0, blue.size( )-1 ) {
      graph[ i ][ red.size( )+j ] = dist( i, j );
      mini = min( mini, graph[ i ][ red.size( )+j ] );
      maxi = max( maxi, graph[ i ][ red.size( )+j ] );
    }
  int result = INT_MAX;
  while ( maxi > mini + 1 ) {
    int avg = (maxi + mini) / 2;
    int res = maxBPM( avg );
    if ( res < k )
      mini = avg;
    else {
      result = min( avg, result );
      maxi   = avg;
    }
  }
  return result;
}

int main( ) {
  int caseCnt;
  int x, y, p;
  char str[15];

  scanf("%d", &caseCnt);
  FOR( caseNr, 1, caseCnt ) {
    scanf("%d%d", &p, &k);
    blue.clear( ), red.clear( );
    FOR( i, 1, p ) {
      scanf("%d%d%s", &x, &y, str);
      if ( str[0] == 'b' )
        blue.PB( MP( x,  y ) );
      else
        red.PB( MP( x, y ) );
    }
    if ( (int) blue.size( ) < k || (int) red.size( ) < k )
      puts("Impossible");
    else
      printf("%d\n", solve( ));
  }

  return 0;
}