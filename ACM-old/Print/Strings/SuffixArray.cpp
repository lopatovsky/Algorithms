// suffix array

char str[1002];
int  strLen, vmax;
vi   suffix, lcp;

inline bool compare( const int & a, const int & b )
{
  return ( strcmp( str+a, str+b ) < 0 );
}
int prefixLen( char * a, char * b )
{
  int len;
  for ( len = 0; *a && *b && *a == *b; ++a, ++b, ++len );
  return len;
}
void suffixArray( )
{
  suffix.clear( );
  char * tmp = str;
  FOR( i, 0, strLen - 1 )
    suffix.PB( i );
  sort( suffix.begin( ), suffix.end( ), compare );
  // TR( suffix, it )
  //   printf("%10s %d\n", str+*it, *it);
}
void lcpArray( )
{
  lcp.clear( );
  lcp.PB( 0 );
  FOR( i, 1, strLen - 1 )
    lcp.PB( prefixLen( str+suffix[i-1], str+suffix[i] ) );
  // TR( lcp, it )
  //   printf("%d ", *it);
  // printf("\n");
}
void solve( )
{
  vmax = 0;
  FOR( i, 1, lcp.size( ) - 1 )
    if ( lcp[vmax] < lcp[i] )
      vmax = i;
}

int main( )
{
  int caseCnt;

  scanf("%d", &caseCnt);
  for ( int caseNr = 1; caseNr <= caseCnt; ++caseNr )
  {
    scanf("\n%s", str);
    strLen = strlen( str );
    str[ strLen ] = '$';
    str[++strLen] = '\0';
    suffixArray( );
    lcpArray   ( );
    solve      ( );
    if ( lcp[vmax] == 0 )
      puts("No repetitions found!");
    else
    {
      FOR( i, suffix[vmax], suffix[vmax]+lcp[vmax]-1 )
        printf("%c", str[i]);
      int cnt = 0;
      FOR( i, 0, strLen - 1 )
        if ( strncmp( str+suffix[vmax], str+i, lcp[vmax] ) == 0 )
          ++cnt;
      printf(" %d\n", cnt);
    }
  }
  return 0;
}