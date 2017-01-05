ull nCr( ull n, ull k ) {
  if ( k > n )
    return 0;
  k = min( k, n - k );
  ull r = 1;
  for ( ull d = 1; d <= k; ++d ) {
    r *= n--;
    r /= d;
  }
  return r;
}

// s modulenim

ll degree(ll a, ll k, ll p) {
  ll res = 1;
  ll cur = a;

  while (k) {
    if ( k % 2 )
      res = (res * cur)%p;
    k /= 2;
    cur = (cur * cur) % p;
  }
  return res;
}

int get_degree(ll n, ll p) { // returns the degree with which p is in n!
  int degree_num = 0;
  ll u = p;
  ll temp = n;
  while (u <= temp) {
    degree_num += temp/u;
    u *= p;
  }
  return degree_num;
}

ll nCr(int n, int k, ll p) {
  if ( !k || n == k )
    return 1;
  if ( !n || n < k )
    return 0;
  int num_degree = get_degree(n,p) - get_degree(n- k,p);
  int den_degree = get_degree(k,p);
  if (num_degree > den_degree) {
    return 0;
  }
  ll res = 1;
  for (ll i = n; i > n- k; --i) {
    ll ti = i;
    while(ti % p == 0) {
      ti /= p;
    }
    res = (res *ti)%p;
  }
  ll denom = 1;
  for (ll i = 1; i <= k; ++i) {
    ll ti = i;
    while(ti % p == 0) {
      ti /= p;
    }
    denom = (denom * ti)%p;
  }
  res = (res * degree(denom, p-2, p)) % p;
  return res;
}

// backup mene optimalni verze
long long nCr(int n, int k, long long p) {
  int num_degree = get_degree(n,p) - get_degree(n- k,p);
  int den_degree = get_degree(k,p);
  if (num_degree > den_degree) {
    return 0;
  }
  long long res = 1;
  for (long long i = n; i > n- k; --i) {
    long long ti = i;
    while(ti % p == 0) {
      ti /= p;
    }
    res = (res *ti)%p;
  }
  for (long long i = 1; i <= k; ++i) {
    long long ti = i;
    while(ti % p == 0) {
      ti /= p;
    }
    res = (res * degree(ti, p-2, p))%p;
  }
  return res;
}