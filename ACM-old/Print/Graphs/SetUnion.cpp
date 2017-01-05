vi pset(1000);
void initSet( int size ){ pset.resize( size ); REP(i,size) pset[i] = i; }
int findSet ( int i ){ return (pset[i] == i) ? i : (pset[i] = findSet( pset[i] )); }
void unionSet ( int i, int j){   pset[findSet(i)] = findSet(j); }
bool isSameSet ( int i, int j){ return findSet(i) == findSet(j); }



int main() {

    initSet(2000);
    unionSet(1,10);//
    unionSet(3,8);//
    unionSet(2,9);//
    unionSet(2,5);//
    unionSet(5,6);//
    unionSet(4,7);//
    unionSet(3,7);//
    unionSet(1,5);//
    unionSet(7,5);//
    unionSet(1,10);//
    unionSet(4,2);//

    cout << isSameSet(1,10) << endl;
    cout << isSameSet(7,3) << endl;
    cout << isSameSet(1,4) << endl;
    cout << isSameSet(1,11) << endl;





    return 0;
}
