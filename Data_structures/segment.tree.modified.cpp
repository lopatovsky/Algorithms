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
// The segment tree is stored like a heap array
#define RANGE_SUM 0
#define RANGE_MIN 1
#define RANGE_MAX 2
#define BRACKETS 3

vi stOK;
vi stL;
vi stR;

void init_segment_tree(int N) { // if original array size is N,
// the required segment_tree array length is 2*2^(floor(log2(N)) + 1);
    int length = (int)(2 * pow(2.0, floor((log((double)N) / log(2.0)) + 1)));
    stOK.resize(length, 0); // resize this vector and fill with 0
    stL.resize(length, 0); // resize this vector and fill with 0
    stR.resize(length, 0); // resize this vector and fill with 0

}
void build_segment_tree(int code, char A[], int node, int b, int e) {
    if (b == e) { // as b == e, either one is fine
        stOK[node] = 0;
        stL[node] = (A[b] == '(') ? 1 : 0;
        stR[node] = (A[b] == '(') ? 0 : 1;
    }
    else { // recursively compute the values in the left and right subtrees
        int leftIdx = 2 * node, rightIdx = 2 * node + 1;

        build_segment_tree(code, A, leftIdx , b, (b + e) / 2);
        build_segment_tree(code, A, rightIdx, (b + e) / 2 + 1, e);


        stOK[node] = stOK[leftIdx] + stOK[rightIdx] + min(  stL[leftIdx], stR[rightIdx] );
        stL[node] = stL[leftIdx] + stL[rightIdx] - min(  stL[leftIdx], stR[rightIdx] );
        stR[node] = stR[leftIdx] + stR[rightIdx] - min(  stL[leftIdx], stR[rightIdx] );
   }
}

struct T{
    int a,b,c;
};


T query(int code, char A[], int node, int b, int e, int i, int j) {

    T fake;
    fake.a = -1;
    if (i > e || j < b) return fake; // if the current interval does not intersect query interval
    if (b >= i && e <= j) { fake.a = stOK[node]; fake.b = stL[node]; fake.c = stR[node]; return fake;  } // if the current interval is inside query interval
    // compute the minimum position in the left and right part of the interval
    T p1 = query(code, A, 2 * node, b, (b + e) / 2, i, j);
    T p2 = query(code, A, 2 * node + 1, (b + e) / 2 + 1, e, i, j);

    //cout << p1 << " " << p2 << "node: " << node << endl;
    // return the position where the overall minimum is
    if (p1.a == -1) return p2; // can happen if we try to access segment outside query
    if (p2.a == -1) return p1; // same as above

    T Tret;
    Tret.a = p1.a + p2.a + min( p1.b, p2.c);
    Tret.b = p1.b + p2.b - min( p1.b, p2.c);
    Tret.c = p1.c + p2.c - min( p1.b, p2.c);

    return Tret;


}
int main() {
    char A[2000007];

    scanf("%s",A);
   int  len = strlen(A);

    init_segment_tree(len); build_segment_tree(RANGE_SUM, A, 1, 0, len-1);

    int m,x,y;

    /*cout << endl;
    printf("%s\n", A);
    TR(stOK, c) cout << *c << " ";
    cout<<endl;*/

    scanf("%d",&m);

    REP(i,m){
            scanf("%d%d",&x,&y);
            printf("%d\n", 2* query(RANGE_SUM, A, 1, 0, len-1, x-1, y-1 ).a ); // answer is index 2
    }


    return 0;
}
