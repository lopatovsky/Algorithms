/** vzdialenost **/
inline double len( double a, double b){ return sqrt(a*a + b*b); }


double len(double a, double b, double c, double d){
    return sqrt( (a-c)*(a-c) + (b-d)*(b-d) );
}

/**Vektorivy Sucin (double,int) **/

int vecSucin( double a, double b, double c, double d){
    double vys =  a * d - b * c;
    return (vys > 0) ? 1 : 0; //vlavo 1 vpravo 0;
}

int vecSucin( int a, int b, int c, int d){

    int vys =  a * d - b * c;
    if (vys > 0) return 1;
    if (vys == 0 ) return 0;
    return -1;
}

/**Vektorovy Sucin (double)  + Epsilon **/
int vecSucin( double a, double b, double c, double d){
    double vys =  a * d - b * c;
    if (vys < 10e-10 && vys > -10e-10)return 0;;
    return (vys > 0) ? -1 : 1; //vlavo -1 vpravo 1;
}

/**Permutacie vsetkych podmonin pola  **/

 for (s = 1; s < n-1;s++){

            for(p = 0; p < n-s; p++) perm[p] = 0;
            for(;p<n;p++) perm[p] = 1;

            do{
                ...

            }while (next_permutation(perm, perm + n) );


