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
//////////////EP2////////////////////

char s[200005];

int count(int len){

    int best = 0, fiha = 0, mode = 0, cnt;

    for(int i = 1; i < len; i++,cnt++){
        if (s[best] > s[i]){
            best = i;
            mode = 0;
            continue;
        }
        if (mode){

            if (s[i]< s[ best + cnt ] ){
                best = fiha;
                i = fiha;
                mode = 0;
            }
            else if (s[i] > s[ best + cnt ]){
                mode = 0;
            }
            else if( (best + cnt) == fiha ){
                fiha = i;
            }
        }
        else if (s[i]== s[best]){
            fiha = i;
            mode = 1;
            cnt = 0;
        }
    }
    return best+1;
}

int main() {
    int n,len;

    scanf("%d",&n);

    REP(i,n){
        scanf("%s",s);
        len = strlen(s);
        for (int i = 0; i < len;i++) s[i+len]=s[i];
        s[len*2]='\0';
        printf("%d\n",count(len*2) );
    }

  return 0;
}

