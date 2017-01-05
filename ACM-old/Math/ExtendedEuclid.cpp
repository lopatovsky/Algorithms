// d = gcd( a, b )
// a * x + b * y = d
ll d, x, y;
void egcd( ll a, ll b ) {
  if ( !b ) {
    d = a;
    x = 1;
    y = 0;
    return;
  }
  egcd( b, a % b );
  ll y1 = x - ( a / b ) * y;
  x = y;
  y = y1;
}

// normalizace
xd = b / d;
yd = a / d;
if ( x < 0 ) {
  k  = (y + yd - 1) / yd;
  x += k * xd;
  y -= k * xd;
}
k  = x / xd;
x -= k * xd;
y += k * yd;