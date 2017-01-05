#include <cstdio>
#include <cstring>
#define REP(i,b) for ( int i = 0; i < int(b); ++i )
#define RI(a) scanf("%d", &a)
const int N = 1005;
int  n;
int  gPrefs[N][N], bPrefs[N][N], bMatch[N];
bool gFree[N];

bool bfPreferGf( int bf, int gf, int g ) {
  REP( i, n ) {
    if ( bPrefs[bf][i] == gf )
      return true;
    else if ( bPrefs[bf][i] == g )
      return false;
  }
}
// prefers girls' choices, otherwise swap boys' and girls' array
void stableMarriage( ) {
  int g;
  memset( bMatch, 0xFF, sizeof( bMatch ) );
  memset( gFree, 1, sizeof( gFree ) );

  for ( int freeCount = n; freeCount; ) {
    // find first free girl
    for ( g = 0; g < n && !gFree[g]; ++g );
    // loop through her preferences
    for ( int i = 0; i < n && gFree[g]; ++i ) {
      int b = gPrefs[g][i];
      // preferred boy is single then match him with girl
      if ( bMatch[b] == -1 ) {
        bMatch[b] = g;
        gFree[g]  = 0;
        --freeCount;
      } else {
        // check for stability with his current gf
        int gf = bMatch[b];
        if ( !bfPreferGf( b, gf, g ) ) {
          bMatch[b] = g;
          gFree[gf] = 1;
          gFree[g]  = 0;
        }
      }
    }
  }
  // print boys matched to i-th girl
  REP( i, n ) {
    REP( j, n )
      if ( bMatch[j] == i )
        printf("%d\n", j+1);
  }
  /*cout << "Boy   Girl" << endl;
  REP( i, n )
    cout << " " << i+1 << "\t" << bMatch[i]+1 << endl;*/
}
int main( ) {
  int caseCnt;
  RI( caseCnt );
  REP( caseNr, caseCnt ) {
    if ( caseNr )
      printf("\n");
    RI( n );
    REP( g, n )
      REP( b, n ) {
        RI( gPrefs[g][b] );
        --gPrefs[g][b];
      }
    REP( b, n )
      REP( g, n ) {
        RI( bPrefs[b][g] );
        --bPrefs[b][g];
      }
    stableMarriage( );
  }
  return 0;
}