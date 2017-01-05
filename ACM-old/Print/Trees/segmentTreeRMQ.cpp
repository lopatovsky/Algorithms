#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <limits.h>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define DEBUG(x) cout << ">>> " << #x << " : " << x << endl;
#define MP make_pair
#define PB push_back
#define REP(i,b) for ( int i = 0; i < int(b); ++i )
#define FOR(i,a,b) for ( int i = int(a); i <= int(b); ++i )
#define FORD(i,a,b) for ( int i = int(a); i >= int(b); --i )

const int INF = 1<<29;
typedef long long ll;

const int MAXN = 100000;
const int MAXS = 262143; // 2 * pow( 2, ceil( log2( MAXN ) ) ) - 1
int arr[MAXN];
int st [MAXS];
int n;
 
/*  A recursive function to get the minimum value in a given range of array
    indexes. The following are parameters for this function.
 
    st    --> Pointer to segment tree
    index --> Index of current node in the segment tree. Initially 0 is
             passed as root is always at index 0
    ss & se  --> Starting and ending indexes of the segment represented by
                 current node, i.e., st[index]
    qs & qe  --> Starting and ending indexes of query range */
int RMQUtil( int ss, int se, int qs, int qe, int index ) {
  // If segment of this node is a part of given range, then return the min of the segment
  if (qs <= ss && qe >= se)
      return st[index];
  // If segment of this node is outside the given range
  if ( se < qs || ss > qe )
    return INT_MAX;
  // If a part of this segment overlaps with the given range
  int mid = ss + (se-ss) / 2 ;
  return min( RMQUtil( ss, mid, qs, qe, 2*index+1 ), RMQUtil( mid+1, se, qs, qe, 2*index+2 ) );
}
 
// Return minimum of elements in range from index qs (quey start) to
// qe (query end).  It mainly uses RMQUtil()
int RMQ( int qs, int qe ) {
  if (qs < 0 || qe > n-1 || qs > qe) {
      cerr << "Invalid Input" << endl;;
      return -1;
  }
  return RMQUtil( 0, n-1, qs, qe, 0 );
}

int constructST( int ss, int se, int si ) {
  // If there is one element in array, store it in current node of segment tree and return
  if ( ss == se ) {
    st[si] = arr[ss];
    return arr[ss];
  }
  // If there are more than one elements, then recur for left and
  // right subtrees and store the minimum of two values in this node
  int mid = ss + (se-ss) / 2;
  st[si]  = min( constructST( ss, mid, si*2+1 ), constructST( mid+1, se, si*2+2 ) );
  return st[si];
}

void updateValueUtil(int *st, int ss, int se, int i, int diff, int index)
{
    // Base Case: If the input index lies outside the range of this segment
    if (i < ss || i > se)
        return;
 
    // If the input index is in range of this node, then update the value
    // of the node and its children
    st[index] = st[index] + diff;
    if (se != ss)
    {
        int mid = ss + ( se - ss ) / 2 ;
        updateValueUtil(st, ss, mid, i, diff, 2*index + 1);
        updateValueUtil(st, mid+1, se, i, diff, 2*index + 2);
    }
}
 
// The function to update a value in input array and segment tree.
// It uses updateValueUtil() to update the value in segment tree
void updateValue(int arr[], int *st, int n, int i, int new_val)
{
    // Check for erroneous input index
    if (i < 0 || i > n-1)
    {
        printf("Invalid Input");
        return;
    }
 
    // Get the difference between new value and old value
    int diff = new_val - arr[i];
 
    // Update the value in array
    arr[i] = new_val;
 
    // Update the values of nodes in segment tree
    updateValueUtil(st, 0, n-1, i, diff, 0);
}
 
int main( ) {
  int qs, qe, t;
  ios::sync_with_stdio( 0 );
  cin >> n >> t;
  REP( i, n )
    cin >> arr[i];
  // Build segment tree from given array O(n)
  constructST( 0, n-1, 0 );
  // queries [qs..qe] O(log n)
  REP( i, t ) {
    cin >> qs >> qe;
    cout << RMQ( qs, qe ) << endl;
  }
  return 0;
}