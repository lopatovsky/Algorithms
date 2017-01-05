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
double y[1002]; double x1[1002]; double x2[1002];
int gates;

int gn[2004];
int gc[2004][2004];
double sum[2004];
double len[2004][2004];

inline double length(double X, double Y){
    return sqrt(X*X + Y*Y);
}

int vecSucin( double a, double b, double c, double d){
    double vys =  a * d - b * c;
    if (vys < 10e-10 && vys > -10e-10)vys = 0;

    if (vys == 0 ) return 0;
    return (vys > 0) ? 1 : -1;
}
int isVisible(int i ,double stX,double stY, int left, int &leftS, int &rightS){
    double X,Y;

    if (left == 1){
        if (  vecSucin(x1[i] - stX, y[i] - stY, x1[leftS] - stX, y[leftS] - stY)  > 0)return false;
        else if ( vecSucin(x1[i] - stX, y[i] - stY, x2[rightS] - stX, y[rightS] - stY) >= 0){
            leftS = i; return true;
        }
        else return -1;//uz isto nic nebude vidno
    }
    else if (left == 0){
        if (  vecSucin(x2[i] - stX, y[i] - stY, x2[rightS] - stX, y[rightS] - stY)  < 0)return false;
        else if ( vecSucin(x2[i] - stX, y[i] - stY, x1[leftS] - stX, y[leftS] - stY) <= 0){
            rightS = i; return true;
        }
        else return -1;//uz isto nic nebude vidno
    }
    else{
        if (  vecSucin(0, y[i] - stY, x2[rightS] - stX, y[rightS] - stY)  >= 0)
        if (  vecSucin(0, y[i] - stY, x1[leftS] - stX, y[leftS] - stY)  <= 0) return true;
        return false;
    }
}


void findGraph(int uzol,double stX,double stY, int depth){
       int left = depth,
       right = depth, out;
        FOR(i,depth,gates-1){
            if (out = isVisible(i,stX,stY,1,left,right) ){
                if (out < 0)return;
                gc[uzol][ gn[uzol]] = 2*i + 1;
                len[uzol][ gn[uzol]++] = length(stX - x1[i], stY - y[i]) ;
            }

            if (out = isVisible(i,stX,stY,0,left,right) ){
                 if (out < 0)return;
                 gc[uzol][ gn[uzol]] = 2*i + 2;
                 len[uzol][ gn[uzol]++] = length(stX - x2[i], stY - y[i]) ;
            }
        }
        if ( stX > x1[gates-1] && stX < x2[gates - 1]){
            if (isVisible(gates-1,stX,stY,-1,left,right) ){
                 gc[uzol][ gn[uzol]] = 2*gates + 1;
                 len[uzol][ gn[uzol]++] = abs(stY- y[gates-1]);

            }
        }

}


double solve(double stX, double stY){

        double tempSum,ret;

        findGraph(0,stX,stY,0);
        for(int i = 0; i < gates-1; i++){
            findGraph(2*i+1,x1[i],y[i],i+1);
            findGraph(2*i+2,x2[i],y[i],i+1);
        }

        sum[0]= 0;
        for (int i = 1; i <= 2*gates+1; i++) sum[i] = 10000000;
        REP(i,(gates * 2 - 1)){
            REP(j,gn[i]){
                tempSum = sum[i] + len[i][j];
                if (sum[ gc[i][j] ] > tempSum )sum[ gc[i][j] ] = tempSum;
            }
        }
        ret = min (sum[2*gates-1],sum[2*gates]);
        ret = min (ret,sum[2*gates+1]);

        return ret;
}

int main() {
    double stX,stY;
	while(scanf("%d",&gates)){
	    if (!gates) break;
	    memset (gn, 0, sizeof(int)* gates * 2 + 1);
	    scanf("%lf%lf",&stX,&stY);
	    for(int m = 0; m < gates; m++) scanf("%lf%lf%lf",&y[m],&x1[m],&x2[m]);

        printf( "%.11lf\n",solve(stX,stY) );

	}

  return 0;
}
