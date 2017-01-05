#include <algorithm>
#include <cmath>
#include <climits>
#include <cstdio>
#include <cstring>
#include <iostream>
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
#define DBG(x) cout << ">>> " << #x << " : " << x << endl
#define MP make_pair
#define PB push_back
#define REP(i,b) for (int i = 0; i < int(b); ++i)
#define FOR(i,a,b) for (int i = int(a); i <= int(b); ++i)
#define FORD(i,a,b) for (int i = int(a); i >= int(b); --i)
#define RI(a) scanf("%d", &a)
#define RII(a,b) scanf("%d%d", &a, &b)
#define RIII(a,b,c) scanf("%d%d%d", &a, &b, &c)
#define RIIII(a,b,c,d) scanf("%d%d%d%d", &a, &b, &c, &d)
#define MM(x,b) memset( x, b, sizeof( x ) )
const int INF = 1e9;
typedef long long ll;

const double EPS = 1e-8;

struct point {
    point( ) { x = y = 0; }
    point( double _x, double _y ) { x = _x; y = _y; }
    double x, y;
};

bool circleSegmentIntersection( point center, double radius, point p1, point p2 )
{
    double dx, dy, A, B, C, det, t;

    dx = p2.x - p1.x;
    dy = p2.y - p1.y;

    A = dx * dx + dy * dy;
    B = 2 * (dx * (p1.x - center.x) + dy * (p1.y - center.y));
    C = (p1.x - center.x) * (p1.x - center.x) + (p1.y - center.y) * (p1.y - center.y) - radius * radius;

    det = B * B - 4 * A * C;
    if ( A <= EPS || det < 0 ) {
        // No real solutions.
        return false;
    } else if ( fabs( det ) <= EPS ) {
        // One possible solution.
        t = -B / (2 * A);
        // p1.x + t * dx, p1.y + t * dy
        if ( t >= 0 && t <= 1 )
            return true;
        return false;
    } else {
        // Two possible solutions.
        t = (double) ((-B + sqrt( det )) / (2 * A));
        if ( t >= 0 && t <= 1 )
            return true;
        // p1.x + t * dx, p1.y + t * dy
        t = (double) ((-B - sqrt( det )) / (2 * A));
        if ( t >= 0 && t <= 1 )
            return true;
        return false;
    }
}

int main( ) {
    int t;
    point center, p[3];
    double r;
        
    for ( cin >> t; t--; ) {
        cin >> center.x >> center.y >> r;
        REP( i, 3 )
            cin >> p[i].x >> p[i].y;
        if ( circleSegmentIntersection( center, r, p[0], p[1] ) || circleSegmentIntersection( center, r, p[1], p[2] ) || circleSegmentIntersection( center, r, p[0], p[2] ) )
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
