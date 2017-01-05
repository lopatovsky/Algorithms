// vraci mensi rozdil uhlu !!! vraci ho se znamenkem !!!
double res = hangle - mangle;
if ( res > 180 )
  res -= 360;
if ( res < -180 )
  res += 360;
// res = abs( res );