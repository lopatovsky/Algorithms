#include <cstdio>
#include <ctime>

int main( ) {
  int f, d, m, y;
  while ( scanf("%d%d%d%d", &f, &d, &m, &y) == 4 ) {
    if ( !f && !d && !m && !y )
      break;
    tm now       = { 0 };
    now.tm_mday  = d;
    now.tm_mon   = m - 1;
    now.tm_year  = y - 1900;
    now.tm_mday += f;
    mktime( &now );
    printf("%d %d %d\n", now.tm_mday, now.tm_mon+1, now.tm_year+1900);
  }
  return 0;
}