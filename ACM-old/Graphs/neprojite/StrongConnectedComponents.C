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
#define REP(i,a) for (int i = 0; i < (a); i++)
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FORD(i,a,b) for (int i = (a); i >= (b); i--)
inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }

const int INF = 1<<29;
typedef long long int lli;
/*******************************************************/

int gc[10002];
int gn[10002][10002];
int color[10002];
int rgc[10002];
int rgn[10002][10002];

stack<int > f;


void dfs(int u){

        color[u] = 1;
        REP(i,gc[u]){
            if (color[ gn[u][i] ] == 0) dfs( gn[u][i] );
        }

        f.push( u );

}

void dfsr(int u){

        color[u] = 0;

        cout << u << " ";

        REP(i,rgc[u]){
            if (color[ rgn[u][i] ] == 1) dfsr( rgn[u][i] );
        }

}


int main() {
    int cs,n,m,x,y;
	scanf("%d",&cs);
	FOR(ii,1,cs){
            scanf("%d%d",&n,&m);
            memset(gc,0,sizeof(int) *  (n+2));
            memset(rgc,0,sizeof(int) *  (n+2));
            memset(color,0,sizeof(int) *  (n+2));
            REP(i,m){
                    scanf("%d%d",&x,&y);
                    gn[x][gc[x]++]= y;
                    rgn[y][rgc[y]++]= x;
            }

            FOR(i,1,n) if (color[i] == 0) dfs(i);

            while( !f.empty()  ){
                   if (color[f.top()]){
                       cout<< "SSC " << f.top() << ": ";
                       dfsr(f.top() );
                       cout << endl;
                   }
                      f.pop();


            }


            //printf("Case %d: %d\n",ii,out);
	}

  return 0;
}
