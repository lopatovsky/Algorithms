unsigned int gcd(unsigned int a, unsigned int b)
{
  return ( b == 0 ) ? a : gcd( b, a % b );
}

int lcm(int a, int b)
{
  return a*b/gcd(a,b);
}