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
/** GENERIC SEGMENT TREE LIBRARY **/
/*******************************************************/

/// SEGMENT TREE SUM
/// - in most basic cases T == S.
/// - T needs implement operator +.
/// - T needs implement operator = object S.
/// - segment_tree stores the same type of data as underlaying array.

template <class T,class S>  //
struct ST_SUM{

  vector<S> segment_tree;
  vector<T> arr;

    ST_SUM( T * a, int sz ){
        int len = (int)(2 * pow(2.0, floor((log((double) sz ) / log(2.0)) + 1)));
        segment_tree.resize(len);
        REP(i,sz)arr.PB( a[i] );
        build( 1 ,0, sz-1 );
    }

    void build( int node, int b, int e) { //node is actual position in segment tree (root is 1!)
        if (b == e) { // as b == e, either one is fine
            /*** Store value in segment tree leaf ***/
            segment_tree[node] = arr[b]; // store value of this cell
            /***/
        }
        else { // recursively compute the values in the left and right subtrees
            int leftIdx = 2 * node, rightIdx = 2 * node + 1;
            build(  leftIdx , b, (b + e) / 2);
            build(  rightIdx, (b + e) / 2 + 1, e);

            /***Joining  branches operation ***/
            segment_tree[node] = segment_tree[leftIdx] + segment_tree[rightIdx];
            /***/
       }
   }


   S que( int node, int b, int e, int i, int j) { //Begin End of whole tree, <i,j> - wanted interval.

        if (i > e || j < b) return 0; /***/ ///change to 0 equivalent in S or return pair<S,bool>
        if (b >= i && e <= j) return segment_tree[node]; // if the current interval is inside query interval
        // compute the minimum position in the left and right part of the interval
        S p1 = que(  2 * node, b, (b + e) / 2, i, j);
        S p2 = que(  2 * node + 1, (b + e) / 2 + 1, e, i, j);

        if (p1 == 0) return p2; // can happen if we try to access segment outside query
        if (p2 == 0) return p1; // same as above

        /***Joining  branches operation ***/
        return p1 + p2;
        /***/
    }
    S query( int i, int j) {  /// interval <i,j>
        if(i < 0 || j >= arr.size() || i > j) cerr <<"Out of bounds error" << endl;
        que( 1, 0, arr.size()-1,i,j);
    }

    S up( int node, int b, int e, int i){

         if (b>e || b>i || e<i ) return segment_tree[node];
         if (b==e) //at leaf node
         {
             segment_tree[node] = arr[i];/***/
         }
         else{

            segment_tree[node] =  up(  node*2 , b , (b+e)/2 , i )
                                + up(  node*2 + 1 , (b+e)/2 + 1 , e , i );/***/
         }
         return segment_tree[node];

    }

    void update( int i, int val){
       if(i < 0 || i >= arr.size()) cerr <<"Out of bounds error" << endl;
       arr[i] = val;
       up(1,0, arr.size()-1 ,i);
    }


};


/// SEGMENT TREE MAX
/// - T needs implement operator <
/// - segment_tree stores the integer pointing to the underlaying array of type T.
/// - easily transformed to MIN. (3 changes) without need to reimplement operator < of basic types.

template <class T>
struct ST_MAX{

  vector<int> segment_tree;
  vector<T> arr;

    ST_MAX( T * a, int sz ){
        int len = (int)(2 * pow(2.0, floor((log((double) sz ) / log(2.0)) + 1)));
        segment_tree.resize(len, 0);
        REP(i,sz)arr.PB( a[i] );
        build( 1 ,0, sz-1 );
    }

    void build( int node, int b, int e) { //node is actual position in segment tree (root is 1!)
        if (b == e) { // as b == e, either one is fine
            /*** Store index in segment tree leaf ***/
            segment_tree[node] = b;
            /***/
        }
        else { // recursively compute the values in the left and right subtrees
            int leftIdx = 2 * node, rightIdx = 2 * node + 1;
            build(  leftIdx , b, (b + e) / 2);
            build(  rightIdx, (b + e) / 2 + 1, e);

            /***Joining  branches operation ***/
            int lContent = segment_tree[leftIdx], rContent = segment_tree[rightIdx];
            T lValue = arr[lContent], rValue = arr[rContent];
          ///* MIN */    segment_tree[node] =  !(rValue < lValue) ? lContent : rContent;
            /* MAX */    segment_tree[node] =  !(lValue < rValue) ? lContent : rContent;
            /***/
       }
   }


   int que( int node, int b, int e, int i, int j) { //Begin End of whole tree, <i,j> - wanted interval.

        if (i > e || j < b) return -1; // if the current interval does not intersect query interval
        if (b >= i && e <= j) return segment_tree[node]; // if the current interval is inside query interval
        // compute the minimum position in the left and right part of the interval
        int p1 = que(  2 * node, b, (b + e) / 2, i, j);
        int p2 = que(  2 * node + 1, (b + e) / 2 + 1, e, i, j);
        // return the position where the overall minimum is
        if (p1 == -1) return p2; // can happen if we try to access segment outside query
        if (p2 == -1) return p1; // same as above

        /***Joining  branches operation ***/
        ///*MIN*/ return !(arr[p2] < arr[p1]) ? p1 : p2;
        /*MAX*/   return !(arr[p1] < arr[p2]) ? p1 : p2; //RANGE_MAX
        /***/
    }
    int query( int i, int j) {  /// interval <i,j>
        que( 1, 0, arr.size()-1,i,j);
    }

    int up( int node, int b, int e, int i){

         if (b>e || b>i || e<i ) return segment_tree[node];
         if (b==e) //at leaf node
         {
           segment_tree[node] = i; /***/
         }
         else{

         int p1 = up(  node*2 , b , (b+e)/2 , i ); /***/
         int p2 = up(  node*2 + 1 , (b+e)/2 + 1 , e , i );/***/

         /***Joining  branches operation ***/
        ///*MIN*/ segment_tree[node] =  !(arr[p2] < arr[p1]) ? p1 : p2;
        /*MAX*/   segment_tree[node] =  !(arr[p1] < arr[p2]) ? p1 : p2; //RANGE_MAX
        /***/
        }
        return segment_tree[node];
    }



    void update( int i, int val){
       arr[i] = val;
       up(1,0, arr.size()-1 ,i);
    }


};


int main() {

    //int A[] = {8,7,3,9,5,1,10};
    double A[] = {8.01,7.01,3.01,9.02,5.03,1.001,10.02};
    int len = 7;

    ST_SUM<double,int> st( A, len ); ///take the array of doubles, but count their integer sum.

    printf("%d\n", st.query( 1, 1 )); //7
    printf("%d\n", st.query( 1, 3 )); //19
    printf("%d\n", st.query( 0, 6 )); //43
    printf("%d\n", st.query( 3, 4 )); //14
    printf("%d\n", st.query( 2, 5 )); //18

    st.update(3,A[3]+10);
    st.update(1,A[1]+10);

    printf("%d\n", st.query( 1, 3 )); //39
    printf("%d\n", st.query( 0, 6 )); //63
    printf("%d\n", st.query( 3, 4 )); //24
    printf("%d\n", st.query( 2, 5 )); //28

    ST_MAX<double> st_max( A , len);

    printf("%d\n", st_max.query( 1, 1 )); //1
    printf("%d\n", st_max.query( 1, 3 )); //3
    printf("%d\n", st_max.query( 0, 6 )); //10
    printf("%d\n", st_max.query( 3, 4 )); //9
    printf("%d\n", st_max.query( 2, 5 )); //9

    st.update(3,A[3]-10);
    st.update(1,A[1]+10);

    printf("%d\n", st_max.query( 1, 3 )); //39
    printf("%d\n", st_max.query( 0, 6 )); //63
    printf("%d\n", st_max.query( 3, 4 )); //24
    printf("%d\n", st_max.query( 2, 5 )); //28




    return 0;
}
