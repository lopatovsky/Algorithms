lli pt[51][51];
int MOD = 1000000007;

void ptfill(){
    
    REP(i,51)FOR(j,0,i){
        if (j==0 || j==i)pt[i][j] = 1;
        else pt[i][j] = ( pt[i-1][j-1] + pt[i-1][j] ) % MOD;
    }

}
