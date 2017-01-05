for ( unsigned i = 1; i < vertX.size( ); i++ )
{
  result += vertX[i-1] * vertY[i];
  result -= vertY[i-1] * vertX[i];
}
result = abs(result / 2);