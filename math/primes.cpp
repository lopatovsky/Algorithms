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

const int N = 45000; //45000 = sqrt(2MLD);

int bs[N+1];
vi primes;

void get_primes() {
    bs[0] = bs[1] = 1;
    FOR (i,2,N) if (!bs[i]){
      for (int j = i * i; j <= N; j += i) bs[j] = 1;
      primes.PB(i);
    }
}

vi factorize(ll num) { ///till num <= N*N
    vi factors;
    int i = 0, p = primes[i];
    while (num != 1 && (p * p <= num)) {
        while (num % p == 0) { num /= p; factors.PB(p); }
        p = primes[++i];
    }
    if (num != 1) factors.PB(num); //N is actually a prime
    return factors;
}

bool is_prime(ll num) { ///till num <= N*N
if ( num <= N ) return !bs[num];
REP (i,primes.size()) if (num % primes[i] == 0) return false;
                      else if ( primes[i]*primes[i] > num) return true; // optional line - may be faster.
return true;
}

int EulerPhi(int num) {

    vi factors = factorize(num);
    vi::iterator new_end = unique(factors.begin(), factors.end()); // get unique
    int result = num;
    for (vi::iterator i = factors.begin(); i != new_end; i++)
        result = result - result / *i;
    return result;
}

///factorize in log(n) ... need preprocessing - sieve.
///N - max cca 1e7
int sf[N]; ///smallest factor

void group_factorize(){
	bs[0] = bs[1] = 1;
    FOR (i,2,N) if (!bs[i]){
      sf[i] = i;
      for (int j = i * i; j <= N; j += i){
        if(!bs[j]){
            bs[j] = 1;
            sf[j] = i;
        }
      }
      //primes.PB(i); //optional - get vector of primes.
    }
}


main(){
  get_primes();


  /*group_factorize();
  int num = 47 * 11 * 11;

  while( num > 1){
    cout << sf[num] << " ";
    num/= sf[num];
  }*/

  return 0;
}
