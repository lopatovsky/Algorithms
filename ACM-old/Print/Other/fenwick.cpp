#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <limits.h>
#include <map>
#include <bitset>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef set<int> si;
typedef set<ii> sii;
#define MP make_pair
#define PB push_back
#define REP(i,a) for (int i = 0; i < int(a); i++)
#define FOR(i,a,b) for ( int i = int(a); i <= int(b); ++i )
#define FORS(i,a,b,s) for ( int i = int(a); i<=int(b); i+=s )
#define FORD(i,a,b) for ( int i = int(a); i >= int(b); --i )

const int INF = 1<<29;
typedef long long int lli;

const int MAX =200002;
int ft[MAX];

//prida na index rozdil oproti puvodni hodnote
void add( int index, int diff, int n) {
  while (index<=n) {
    ft[index] += diff;
    index = index + (index & -index);   // bitový and
  }
}

//vrati sum 1..index
int prefixSum(int index) {
  int sum = 0;
  while (index>0) {
    sum = sum + ft[index];
    index = index & (index-1);
  }
  return sum;
}

// 2D varianta
const int MAXX = 2002;
const int MAXY = 2002;
int       ft[MAXX][MAXY];

void add( int x, int y, int diff, int max_x, int max_y ) {
  for ( ; x <= max_x; x += (x & -x) ){
    for ( int y1 = y; y1 <= max_y; y1 += (y1 & -y1) ){
      ft[x][y1] += diff;
    }
  }
}
int sum( int x, int y ) {
  int sum = 0;
  for ( ; x > 0; x = x & (x-1) ) {
    for ( int y1 = y; y1 > 0; y1 = y1 & (y1-1) ) {
      sum += ft[x][y1];
    }
  }
  return sum;
}
