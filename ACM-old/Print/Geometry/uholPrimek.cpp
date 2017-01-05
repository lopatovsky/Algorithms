struct point{
  double x, y;
};

double len(point a, point b){
    return sqrt( (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y) );
}

double uhol( point a, point b, point c, point d ){

    double ux = b.x - a.x,  //prevod na vektory
    uy = b.y - a.y,
    vx = d.x - c.x,
    vy = d.y - c.y;

    double ret = acos( (ux*vx+uy*vy) / ( len(a,b)*len(c,d) ) );  // skalarny sucin / sucin dlzok

    if (ret > M_PI / 2) ret = M_PI - ret; // ten mensi uhol v radianoch
    return (  ret  * 180 / M_PI  ); // ak chceme stupne
}

