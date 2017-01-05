#include <algorithm>
#include <cmath>
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
#include <vector>

using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define MP make_pair
#define PB push_back
#define ff first
#define ss second
#define TR(it,c) for( typeof(c.begin()) it = c.begin(); it != c.end(); ++it )
#define TRR(it,c) for( typeof(c.rbegin()) it = c.rbegin(); it != c.rend(); ++it
#define REP(i,a) for (int i = 0; i < (a); i++)
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FORD(i,a,b) for (int i = (a); i >= (b); i--)

#define DRI(a) int a; scanf("%d", &a);
#define DRII(a, b) int a, b; scanf("%d %d", &a, &b);
#define DRIII(a, b, c) int a, b, c; scanf("%d %d %d", &a, &b, &c);
#define RI(a) scanf("%d", &a);
#define RII(a, b) scanf("%d %d", &a, &b);
#define RIII(a, b, c) scanf("%d %d %d", &a, &b, &c);
#define MM(arr, num) memset((arr), (num), sizeof((arr)))
#define DEB(x) cerr << ">>> " << (#x) << " -> " << (x) << endl;
#define DEBA(x,n) cerr << (#x) << " "; deba((x),(n));
void deba(int * a, int n){ cerr << "| "; REP(i,n) cerr << a[i] << " "; cerr << "|" << endl;}


inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }

const int INF = 1<<30;
typedef long long ll;
typedef unsigned long long ull;
/*******************************************************/
char s[200];
char r[200];

int dp[200][200];

int main() {

  scanf("%s",s+1);
  scanf("%s",r+1);
  int sl = strlen(s+1);
  int rl = strlen(r+1);


  FOR(i,1,sl)FOR(j,1,rl){
    if (s[i]==r[j]){ dp[i][j] = dp[i-1][j-1] + 1;}
    else dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
  }

  int i = sl, j = rl;
  stack<char> st;

  while( dp[i][j] > 0){
         if (dp[i-1][j] == dp[i][j] ) i--;
    else if (dp[i][j-1] == dp[i][j] ) j--;
    else if (dp[i-1][j-1]  == dp[i][j] - 1 ){ st.push(s[i]); i--; j--; }
  }

  cout << dp[sl][rl] << endl;
  while(!st.empty()){ cout << st.top(); st.pop();}
  cout << endl;




  return 0;
}
