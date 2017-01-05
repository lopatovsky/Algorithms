

P a[1000], b[1000]; // 1. a 2. bod usecky


bool intersect( int i, int j  ){
        P p = lineInter(a[i],b[i],a[j],b[j]);
        double ixn, ixx, jxn, jxx, iyn, iyx, jyn, jyx;

        if( a[i].x > b[i].x){ ixx = a[i].x; ixn = b[i].x;}
                      else  { ixx = b[i].x; ixn = a[i].x; }
        if( a[j].x > b[j].x){ jxx = a[j].x; jxn = b[j].x;}
                      else  { jxx = b[j].x; jxn = a[j].x; }

        if( a[i].y > b[i].y){ iyx = a[i].y; iyn = b[i].y;}
                      else  { iyx = b[i].y; iyn = a[i].y; }
        if( a[j].y > b[j].y){ jyx = a[j].y; jyn = b[j].y;}
                      else  { jyx = b[j].y; jyn = a[j].y; }

        if(isnan(p.x) && isnan(p.y) ) {
            if ( ( ixx < jxn ) || ( ixn > jxx ) ||
            ( iyx < jyn ) || ( iyn > jyx)  ) return false;
            return true;
        }  // su totozne
        else if (!isfinite(p.x) || !isfinite(p.y)) return false; // su rovnobezne
        else{
            if ( p.x >= ixn && p.x <= ixx && p.x >= jxn && p.x <= jxx &&
                p.y >= iyn && p.y <= iyx && p.y >= jyn && p.y <= jyx) return true;
            return false;
        }
}



