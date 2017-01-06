#include <algorithm>
#include <cctype>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef set<int> si;
typedef set<ii> sii;
#define MP make_pair
#define PB push_back
#define TR(c,it) for( typeof(c.begin()) it = c.begin(); it != c.end(); ++it )
#define TRR(c,it) for( typeof(c.rbegin()) it = c.rbegin(); it != c.rend(); ++it
#define REP(i,a) for (int i = 0; i < (a); i++)
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FORD(i,a,b) for (int i = (a); i >= (b); i--)
inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }

const int INF = 1<<29;
typedef long long int lli;
/*******************************************************/


// Segment Tree Library
// The segment tree is stored like a heap array and count the sum of the segment.
/*** SUM specific operation ***/
vi segment_tree;
int FROM, TO;

void init_segment_tree() { // if original array size is N,
// the required segment_tree array length is 2*2^(floor(log2(N)) + 1);
    int length = (int)(2 * pow(2.0, floor((log((double)7) / log(2.0)) + 1)));
    segment_tree.resize(length, 0);  // resize this vector and fill with 0

}

void bst( int A[], int node, int b, int e) { //node is actual position in segment tree (root is 1!)
    if (b == e) { // as b == e, either one is fine
        /*** Store value in segment tree leaf ***/
        segment_tree[node] = A[b]; // store value of this cell
        // MIN/MAX segment_tree[node] = b; // if RANGE_MIN/MAXIMUM, store index
        /***/
    }
    else { // recursively compute the values in the left and right subtrees
        int leftIdx = 2 * node, rightIdx = 2 * node + 1;

        bst( A, leftIdx , b, (b + e) / 2);
        bst( A, rightIdx, (b + e) / 2 + 1, e);

        /***Joining  branches operation ***/

        segment_tree[node] = segment_tree[leftIdx] + segment_tree[rightIdx];

        // MIN/MAX int lContent = segment_tree[leftIdx], rContent = segment_tree[rightIdx];
        // MIN/MAX lValue = A[lContent], rValue = A[rContent];
        // MIN     segment_tree[node] = (lValue <= rValue) ? lContent : rContent;
        // MAX     segment_tree[node] = (lValue >= rValue) ? lContent : rContent;

        /***/
   }
}
inline void build_segment_tree( int A[] ){
  bst(A,1,FROM,TO);
}


int que( int A[], int node, int b, int e, int i, int j) { //Begin End of whole tree, <i,j> - wanted interval.

    if (i > e || j < b) return -1; // if the current interval does not intersect query interval
    if (b >= i && e <= j) return segment_tree[node]; // if the current interval is inside query interval
    // compute the minimum position in the left and right part of the interval
    int p1 = que( A, 2 * node, b, (b + e) / 2, i, j);
    int p2 = que( A, 2 * node + 1, (b + e) / 2 + 1, e, i, j);
    // return the position where the overall minimum is
    if (p1 == -1) return p2; // can happen if we try to access segment outside query
    if (p2 == -1) return p1; // same as above

    /***Joining  branches operation ***/
    return p1 + p2;
    //MIN return (A[p1] <= A[p2]) ? p1 : p2;
    //MAX return (A[p1] >= A[p2]) ? p1 : p2; //RANGE_MAX
    /***/
}
inline int query( int A[], int i, int j) {
  que(A,1,FROM,TO,i,j);
}

/*void up( int A[], int node) {
  if (node < 1)return;

  int leftIdx = 2 * node, rightIdx = 2 * node + 1;

  segment_tree[node] = segment_tree[leftIdx] + segment_tree[rightIdx];

  up(A,node/2);
}*/



int up(int A[], int node, int b, int e, int i)
{
 if (b>e || b>i || e<i ) return segment_tree[node];
 if (b==e) //at leaf node
 {
  return segment_tree[node] = A[i];/***/
 }

 segment_tree[node] =  up( A, node*2 , b , (b+e)/2 , i )
                       + up( A, node*2 + 1 , (b+e)/2 + 1 , e , i );/***/

 //now some change might have been made in either of the child nodes.

 //segment_tree[node] =  segment_tree[node*2]  +  segment_tree[node*2 + 1];

}


inline void update( int A[], int i, int val){
  A[i] = val;
  up(A,1,FROM,TO,i);
}

int main() {

    int A[] = {8,7,3,9,5,1,10};
    FROM = 0;
    TO = 6;
    init_segment_tree(); build_segment_tree( A );

      REP(ii,16) cout << "|" << segment_tree[ii] << "|";
    cout << endl;

    printf("%d\n", query( A, 1, 3 )); //19
    printf("%d\n", query( A, 0, 6 )); //43
    printf("%d\n", query( A, 3, 4 )); //14
    printf("%d\n", query( A, 2, 5 )); //18

    update(A,3,A[3]+10);
    update(A,1,A[1]+10);

    REP(i,7)cout << "." << A[i] << ".";
    cout << endl;

    printf("%d\n", query( A, 1, 3 )); //39
    printf("%d\n", query( A, 0, 6 )); //63
    printf("%d\n", query( A, 3, 4 )); //24
    printf("%d\n", query( A, 2, 5 )); //28


    return 0;
}
