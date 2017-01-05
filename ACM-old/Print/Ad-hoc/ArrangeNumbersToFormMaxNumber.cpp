// Given an array of numbers, program to arrange the numbers to form the
// largest number
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
 
bool compare( const unsigned & a, const unsigned & b )
{
  unsigned long long x = a * pow( 10, floor(log10( b )) + 1 ) + b;
  unsigned long long y = b * pow( 10, floor(log10( a )) + 1 ) + a;
  // cout << a << " " << b << " " << x << " " << (x < y) << " " << y << endl;
  return x < y;
}

void printLargest( vector<unsigned> & v )
{
  sort( v.rbegin( ), v.rend( ), compare );
  for ( vector<unsigned>::const_iterator it = v.begin( ); it != v.end( ); ++it )
    cout << *it;
  cout << endl;
}

int main( )
{
  vector<unsigned> arr;

  //output should be 6054854654
  arr.push_back(54);
  arr.push_back(546);
  arr.push_back(548);
  arr.push_back(60);
  printLargest( arr );

  // output should be 777776
  arr.clear( );
  arr.push_back(7);
  arr.push_back(7);
  arr.push_back(776);
  arr.push_back(7);
  printLargest( arr );

  //output should be 998764543431
  arr.clear( );
  arr.push_back(1);
  arr.push_back(34);
  arr.push_back(3);
  arr.push_back(98);
  arr.push_back(9);
  arr.push_back(76);
  arr.push_back(45);
  arr.push_back(4);
  printLargest( arr );
  return 0;
}