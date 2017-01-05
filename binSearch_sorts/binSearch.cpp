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






int main() {

	//lower_bound, upper_bound, binary_search and equal_range
    int A[] = {1,2,4, 5 , 8 , 11, 15, 35, 48, 98, 105};



    int target = 68;

/***********BASIC*******************/  //funguje len na presne vyhladanie. ak sa cislo v poli nenachadza vrati, nenasiel.

   int mid, lo = 1, hi = 11;
   while (lo <= hi){
      mid = lo + (hi-lo)/2;
      if (A[mid] == target){
         cout << mid << " -> " << A[mid] <<  endl; break;} // vypis index + hodnotu na nom.
      else if (A[mid] < target)
         lo = mid+1;
      else
         hi = mid-1;
   }

/*******hladanie najvascieho prvku, pre ktory vracia funkcia true************/
l=0;
r= //posledny mozny index;

//pole typu->  // { true, true, true, false, false};   ...najdi posledne true; //! POZOR:   true, false, false   aj false false false      vrati nulu!!!!!!

while (l<r)
{
 m=l+r+1;
 m/=2;
 if (check(m) ) l=m; else r=m-1;
}

//v l || r je max index.

////// false false true true ... najdi prve true.
diff:
!check(m)
v l+1 je hladany index.


/**** #include <algorithm> *****/

 int arr[] = {-3,1,2,2,4,4, 5 , 8 , 11, 15, 35, 37, 48, 98, 105};


 int que[] = {-5,-3,0,2,3,4,5,6,105,108};
 int qLen = 10;
 int len = 14;
 int * p;

/// custom comparator fcion ::>   bool cmp(int a, int b){  return a[a] < a[b];}

//The lower_bound() function returns an iterator to the first position where a value could be inserted without violating the order;
// i.e. the first element equal to the element you want, or the place where it would be inserted.


  ///  int *ptr = std::lower_bound(array, array+len, what); // a custom comparator can be given as fourth arg

    REP(i,qLen){
        p = lower_bound(arr, arr + len, que[i]);
        //cout << "Query: " << que[i] << "  ->  value: " << *p << " at position: " << p - arr << endl;
    }
    //! Najde cislo z najnizsim indexom, vacsie rovne hladanemu.      //ak neexistuje vacsie rovne, vrati posledne

      /**    Query: -5  ->  value: -3 at position: 0
            Query: -3  ->  value: -3 at position: 0
            Query: 0  ->  value: 1 at position: 1
            Query: 2  ->  value: 2 at position: 2
            Query: 3  ->  value: 4 at position: 4
            Query: 4  ->  value: 4 at position: 4
            Query: 5  ->  value: 5 at position: 6
            Query: 6  ->  value: 8 at position: 7
            Query: 105  ->  value: 105 at position: 14
            Query: 108  ->  value: 105 at position: 14
    */

        //
        //
        //

//The upper_bound() function returns an iterator to the last position where a value could be inserted without violating the order;
//i.e. one past the last element equal to the element you want, or the place where it would be inserted.

   /// int *ptr = std::upper_bound(array, array+len, what); // a custom comparator can be given as fourth arg

   REP(i,qLen){
        p = upper_bound(arr, arr + len, que[i]);
       // cout << "Query: " << que[i] << "  ->  value: " << *p << " at position: " << p - arr << endl;
    }

    //! Najde cislo z najnizsim indexom, vacsie ako hladane.      //ak neexistuje vacsie, vrati posledne

    /**  Query: -5  ->  value: -3 at position: 0
        Query: -3  ->  value: 1 at position: 1
        Query: 0  ->  value: 1 at position: 1
        Query: 2  ->  value: 4 at position: 4
        Query: 3  ->  value: 4 at position: 4
        Query: 4  ->  value: 5 at position: 6
        Query: 5  ->  value: 8 at position: 7
        Query: 6  ->  value: 8 at position: 7
        Query: 105  ->  value: 105 at position: 14
        Query: 108  ->  value: 105 at position: 14
    **/




//The equal_range() function returns a pair of the results of lower_bound() and upper_bound().


    ///std::pair<int *, int *> bounds = std::equal_range(array, array+len, what); // a custom comparator can be given as fourth arg
    //int arr[] = {-3,1,2,2,4,4, 5 , 8 , 11, 15, 35, 37, 48, 98, 105};
    pair<int *, int *> bounds;

    REP(i,qLen){
       bounds = equal_range(arr, arr + len, que[i]);
      // cout << "Query: " << que[i] << "  ->  from : " << *bounds.first << " at position: " << bounds.first - arr << endl;
       //cout << "       " <<  "  "  << "  ->  to   : " << *bounds.second << " at position: " << bounds.second - arr << endl;
    }

    //! first -> lower_bound, second -> upper_bound;

      /**    Query: -5  ->  from : -3 at position: 0
                       ->  to   : -3 at position: 0
            Query: -3  ->  from : -3 at position: 0
                       ->  to   : 1 at position: 1
            Query: 0  ->  from : 1 at position: 1
                       ->  to   : 1 at position: 1
            Query: 2  ->  from : 2 at position: 2
                       ->  to   : 4 at position: 4
            Query: 3  ->  from : 4 at position: 4
                       ->  to   : 4 at position: 4
            Query: 4  ->  from : 4 at position: 4
                       ->  to   : 5 at position: 6
            Query: 5  ->  from : 5 at position: 6
                       ->  to   : 8 at position: 7
            Query: 6  ->  from : 8 at position: 7
                       ->  to   : 8 at position: 7
            Query: 105  ->  from : 105 at position: 14
                       ->  to   : 105 at position: 14
            Query: 108  ->  from : 105 at position: 14
                       ->  to   : 105 at position: 14


*/

//Note that the difference between the bounds is the number of elements equal to the element you want.
//The binary_search() function returns true or false for whether an element equal to the one you want exists in the array.
//It does not give you any information as to where it is.


    ///bool found = std::binary_search(array, array+len, what); // a custom comparator can be given as fourth arg
    //int arr[] = {-3,1,2,2,4,4, 5 , 8 , 11, 15, 35, 37, 48, 98, 105};
    bool b;

    REP(i,qLen){
        b = binary_search(arr, arr + len, que[i]);
        cout << "Query: " << que[i] << " -> " <<   ( b ? "found ": "not found" )  << endl;
    }
    //!  jednoduche found, not found...
    /**

            Query: -5 -> not found
            Query: -3 -> found
            Query: 0 -> not found
            Query: 2 -> found
            Query: 3 -> not found
            Query: 4 -> found
            Query: 5 -> found
            Query: 6 -> not found
            Query: 105 -> not found
            Query: 108 -> not found
*/





  return 0;
}
