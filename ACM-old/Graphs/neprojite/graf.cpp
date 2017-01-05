 /** Floyd Warshall **/

        FOR(m,1,u )FOR(n,1,u ) mat[m][n] = INF; // inicializacia
	    FOR(m,1,u) mat[m][m] = 0;

	    REP(m,h){  //citanie vstupov a znamych dlzok
	        scanf("%d%d%d",&a,&b,&len);
	        mat[a][b] = mat[b][a] = len;
	    }

        FOR(k,1,u)FOR(i,1,u)FOR(j,1,u){ //cyklus
            if ( mat[i][j] > mat[i][k] + mat[k][j] )
                mat[i][j] = mat[i][k] + mat[k][j];
        }



/**BFS -> najkratsia cesta z  x -> y**/
int gn[1200][1200];
int gc[1200];
bool black[1200];

int bfs(int x, int y){

    int u,nn;
    queue<int> q;
    queue<int> num;

    q.push(x);
    num.push(0);

    memset(black,0,sizeof black);

    black[x] = 1;

    while(!q.empty()){

        u = q.front(); q.pop();
        black[u] = 1;
        nn = num.front(); num.pop();
        if (u == y) return nn;

        for (int i = 0; i < gc[u]; i++){
            if ( black[gn[u][i]] == 0 ){
                q.push(gn[u][i]);
                num.push(nn+1);
            }
        }
    }
    return -1;
}
/** Haunting graneyard**/ //lepsi Bel-Ford??
int w,h,stones,holes, tx, ty, uz;

int hX[1000], hY[1000], hLen[1000];
int yard[33][33], cnt[33][33], hod[33][33];
queue<int> qx, qy;

void relax(int neu, int ax, int ay){
    if (yard[ax][ay] == -1 )return;
    if( hod[ax][ay] > neu ){
            hod[ax][ay] = neu;
            qx.push(ax);
            qy.push(ay);
    }
}
int solve(){
    int ax,ay;
    while( !qx.empty() ){ qx.pop(); qy.pop(); }
    qx.push(1);
    qy.push(1);
    hod[1][1] = 0;

    while( !qx.empty() ){
            ax = qx.front(); qx.pop();
            ay = qy.front(); qy.pop();
            if ( ++cnt[ax][ay] > uz) return 0;
            if( ax == w && ay == h)continue;

            if ( yard[ax][ay] == 0){
                relax( hod[ax][ay] + 1, ax, ay+1  );
                relax( hod[ax][ay] + 1, ax, ay-1  );
                relax( hod[ax][ay] + 1, ax+1, ay  );
                relax( hod[ax][ay] + 1, ax-1, ay  );
            }
            else{
               relax( hod[ax][ay] + hLen[ yard[ax][ay] ], hX[ yard[ax][ay] ] , hY[ yard[ax][ay] ]  );
            }
    }
    if ( cnt[w][h] == 0 ) return -1;
    return 1;
}
int main() {

	while(scanf("%d%d",&w,&h) && w){

	    REP(i, w+2)REP(j, h+2){
            if( i == 0 || j == 0 || i == w+1 || j == h+1 ) yard[i][j] = -1;
            else { yard[i][j] = cnt[i][j] = 0; hod[i][j] = INF;}
	    }
	    scanf("%d", &stones);
	    REP(i,stones){
               scanf("%d%d",&tx,&ty);
               yard[tx+1][ty+1] = -1;
	    }
	    scanf("%d", &holes);
	    FOR(i,1,holes){
               scanf("%d%d",&tx,&ty);
               yard[tx+1][ty+1] = i;
               scanf("%d%d",&hX[i],&hY[i]);
               hX[i]++;hY[i]++;
               scanf("%d",&hLen[i]);
	    }
	    uz = w * h - stones;

	    int s = solve();
        if (s == 0) printf("Never\n");
        else if (s < 0) printf("Impossible\n");
        else printf("%d\n",hod[w][h]);
	}
  return 0;
}
/**Najmensia kostra (prepojenie bodov spojnicou) Prim **/

inline lli cLen(lli x, lli y){
    return x*x + y*y;
}
int prim(){
        int cnt = 0, act = 0,mnJ;
         lli length, mn;
        FOR(i,1,n-1) len[i] = INF;

        REP(i,n-1){
            mn = INF;
            FOR(j,1,n-1){
                if( !len[j]  ) continue;
                length = cLen (x[act] - x[j], y[act] - y[j] );
                if( len[j] > length )len[j] = length;
                if( mn > len[j]) { mn = len[j]; mnJ = j; }
            }
            out[cnt++] = len[mnJ];
            len[mnJ] = 0;
            act = mnJ;
        }
        partial_sort(out, out+ trans, out+cnt,greater<lli>());
        return ceil( (float)( sqrt( (double)out[trans - 1] )  )  );
}

/**Topologicke usporiadanie**/
void topologic(int x){   //uklada do pola out[];

    was[x] = 1;
    REP(i,gc[x]){
        if (!was[  gn[x][i] ]) topologic(gn[x][i]);
    }
    out[cnt++]= x;

}
...
FOR(i,1,m){
            if( !in[i] ) topologic(i);
        }



/** Silne suvisle komponenty **/

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

stack<int> f;

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
