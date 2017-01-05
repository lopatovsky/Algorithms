// b - number, p - power, m - modulo
ll bigmod( ll b, ll p, ll m ) {
  if ( !p )
    return 1;
  if ( p & 1 )
    return ( b * bigmod( b, p-1, m ) ) % m;
  b = bigmod( b, p / 2, m );
  return ( b * b ) % m;
}
// iterativni
ll modpow( ll b, ll e, ll m ) {
  b %= m;
  ll r = 1;
  while ( e > 0 ) {
    if ( e & 1 )
      r = ( r * b ) % m;
    b = (b * b) % m
    e >>= 1;
  }
  return r;
}