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

///decreasing sort. stl ->   sort(intVec.begin(), intVec.end(), greater<int>());

struct T{
  int a, b;


};

bool operator< (const T & i,const T & j) { return (i.b<j.b);}
bool fcia (const T & i,const T & j){ return (i.b<j.b);}

T pole[14];

bool fcia (const T & x, const T & y){


    if (x.a < y.a) return true;
    else if (x.a > y.a) return false;
    return x.b < y.b;
}


void print(){
 REP(i,14){  cout << "[" << pole[i].a << "," << pole[i].b << "]" ;   } cout <<endl;
}

int main() {

	int arr[] = { 1,5,4,5,46,8,5,6,4,2,3,5,4,9,4,4,75,3,5,4,6,8,7,9,9,5,2,4 };

	REP(i,14){
        pole[i].a = arr[i*2];
        pole[i].b = arr[i*2 + 1];
	}

	print();

	sort (pole, pole+14, fcia);

    print();

    sort(pole,pole+14);

    print();

  return 0;
}
